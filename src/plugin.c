#include "plugin.h"
#include "color_codes.h"
#include <string.h>
#include <dlfcn.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>

static void pluginStart(pluginConfiguration *conf) {
    void *library = dlopen(conf->libPath, RTLD_LAZY);
    void (*startup)(pluginConfiguration conf) = dlsym(library, conf->startup);
    request (*packetRecieved)(request req) = dlsym(library, conf->packetRecieved);
    void (*newConnection)(request ipAddress) = dlsym(library, conf->newConnection);
    void (*error)(int errno) = dlsym(library, conf->error);
    void (*disconnect)(request ipAddress) = dlsym(library, conf->disconnect);

    int listenfd, connfd, n;
    pid_t childpid;
    socklen_t clilen;
    const int len = (const int)conf->maxLineLength;
    char buf[len];
    struct sockaddr_in cliaddr, servaddr;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, REDB"Couldn't create socket.\n"reset);
        abort();
    }
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(conf->port);
    if (startup) startup(*conf);
    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(listenfd, conf->maxConnections);
    printf(HCYN"Server is up, waiting for connections...\n"reset);
    while (1) {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &clilen);
        if (connfd == -1) {
            if (error) error(0);
            continue;
        }

        printf(HGRN"Recieved request.\n"reset);
        if (!(childpid = fork())) {
            if (newConnection) newConnection(inet_ntoa(cliaddr.sin_addr));
            printf(BHGRN"Handling new client...\n"reset);
            close(listenfd);

            while ((n = recv(connfd, buf, conf->maxLineLength, 0)) > 0) {
                printf(HGRN"Recieved request "BHCYN"%s"reset, buf);
                request ret = packetRecieved(buf);
                if (ret || *ret == '\0') send(connfd, ret, strlen(ret), 0);
            }

            if (n < 0) {
                fprintf(stderr, "Error while reading.\n");
                if (error) error(1);
            }
        }
        disconnect(inet_ntoa(cliaddr.sin_addr));
        close(connfd);
    }
    close(connfd);
    close(listenfd);

    dlclose(library);
}

pthread_t *loadPlugin(pluginConfiguration configuration) {
    printf("Loading plugin %s (version %d)...\n", configuration.displayName, configuration.version);
    pthread_t *t = malloc(4);
    pluginStart(&configuration);
    pthread_create(t, 0, (void *(*)(void*))&pluginStart, &configuration);
    return t;
}