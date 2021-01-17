#ifndef TYPES_H
#define TYPES_H

typedef struct {
    const char *libPath;
    int port;
    const char *startup;
    const char *packetRecieved;
    int maxLineLength;
    int maxConnections;
} pluginConfiguration;

typedef char * request;

#endif