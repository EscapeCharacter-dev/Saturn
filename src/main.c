#include "conf.h"
#include "color_codes.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include "plugin.h"

int main(int argc, char **argv) {
    printf  (HCYN"Thank you for choosing Saturn for your daily server usage! Please support the project by contributing code!\n"reset
            "https://www.github.com/EscapeCharacter-dev/Saturn\n");
    printf(HCYN"NOTE: If you want to use Saturn as a HTTP server, "
            "you should use the official plugin httpsaturn. It's distributed by default.\n"reset);
    saturnConfiguration config = getConfig();
    printf("Starting on address "BBLU"%s"reset".\n", config.ipAddress);
    pthread_t *threads = malloc(sizeof(pthread_t) * argc - 1);
    for (int i = 1; i < argc; i++) {
        char *data = argv[i];
        threads = loadPlugin(getPluginConfiguration(data));
    }
    for (int i = 0; i < argc - 1; i++)
        pthread_join(threads[i], 0);
}