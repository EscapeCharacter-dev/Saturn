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

static void pluginStart(pluginConfiguration *conf) {
    __label__ jump;
    void *library = dlopen(conf->libPath, RTLD_LAZY);
    void (*startup)(pluginConfiguration conf) = dlsym(library, conf->startup);
    request (*packetRecieved)(request req) = dlsym(library, conf->packetRecieved);

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
    startup(*conf);
    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(listenfd, conf->maxConnections);
    printf(HCYN"Server is up, waiting for connections...\n"reset);
    while (1) {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &clilen);
        printf(HGRN"Recieved request.\n"reset);
        if ((childpid = fork()) == 0) {
            printf(BHGRN"Created child thread to handle client requests.\n"reset);
            close(listenfd);

            while ((n = recv(connfd, buf, conf->maxLineLength, 0)) > 0) {
                printf(HGRN"Recieved request "BHCYN"%s"HGRN".\n"reset, buf);
                request ret = packetRecieved(buf);
                if (ret || *ret == '\0') send(connfd, ret, strlen(ret), 0);
                memset(ret, '\0', strlen(ret)); /* for some reason, this is required. :/ */
            }

            if (n < 0) {
                fprintf(stderr, "Error while reading.\n");
                goto jump;
            }
        }
        continue;
jump:
        kill(childpid, SIGKILL);
        close(connfd);
        listen(listenfd, conf->maxConnections);
        printf(HCYN"Server is up, waiting for connections...\n"reset);
    }
    close(connfd);
    close(listenfd);

    dlclose(library);
}

pthread_t *loadPlugin(pluginConfiguration configuration) {
    pthread_t *t = malloc(4);
    pluginStart(&configuration);
    pthread_create(t, 0, (void *(*)(void*))&pluginStart, &configuration);
    return t;
}