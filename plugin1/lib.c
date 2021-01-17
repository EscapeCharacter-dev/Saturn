#include <stdio.h>

#include "../pluginapi/types.h"

void start(pluginConfiguration conf) {
    printf("Hello, %s!\n", conf.libPath);
}

request packet_recieved(request req) {
    printf("Request: %s\n", req);
    return req;
}

void new_connection(request ipAddr) {
    printf("New connection emerging from %s!\n", ipAddr);
}

void error() {}
void disconnect(request ipAddr) {
    printf("Client %s disconnected!\n", ipAddr);
}