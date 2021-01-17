#include <stdio.h>

#include "../pluginapi/types.h"

void start(pluginConfiguration conf) {
    printf("Hello, %s!\n", conf.libPath);
}

request packet_recieved(request req) {
    printf("Request: %s\n", req);
    return req;
}