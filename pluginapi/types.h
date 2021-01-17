#ifndef TYPES_H
#define TYPES_H

typedef struct {
    const char *libPath;
    int port;
    int maxLineLength;
    int maxConnections;
    const char *displayName;
    int version;

    const char *startup;
    const char *packetRecieved;
    const char *newConnection;
    const char *error;
    const char *disconnect;
} pluginConfiguration;

typedef char * request;

#endif