#ifndef PLUGIN_H
#define PLUGIN_H

#include "conf.h"
#include <pthread.h>

pthread_t *loadPlugin(pluginConfiguration configuration);

#endif