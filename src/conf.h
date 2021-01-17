#ifndef CONF_H
#define CONF_H

#include "../pluginapi/types.h"

typedef struct {
    const char *ipAddress;
    int maxLineLength;
    int maxConnections;
} saturnConfiguration;

saturnConfiguration getConfig();
pluginConfiguration getPluginConfiguration(const char *pluginPath);

#endif