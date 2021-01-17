#include "conf.h"
#include "file.h"
#include "color_codes.h"
#include "../ext/cjson/cJSON.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

saturnConfiguration getConfig() {
    saturnConfiguration config = {};
    char *content = getFileContents("conf.json");
    if (!content) {
        fprintf(stderr, RED"Something went wrong while reading config file!\n"reset);
        abort();
    }
    cJSON *json = cJSON_Parse((const char*)content);
    if (!json) {
        fprintf(stderr, RED"Can't read any JSON!\n"reset);
        abort();
    }
    cJSON *name = cJSON_GetObjectItem(json, "ipAddress");
    if (!name) {
        fprintf(stderr, RED"Error while reading JSON!\n"reset);
        abort();
    }
    cJSON *maxLineLength = cJSON_GetObjectItem(json, "maxLineLength");
    if (!maxLineLength) {
        fprintf(stderr, RED"Error while reading JSON!\n"reset);
        abort();
    }
    cJSON *maxConnections = cJSON_GetObjectItem(json, "maxConnections");
    if (!maxConnections) {
        fprintf(stderr, REDB"Error while reading JSON!\n"reset);
        abort();
    }
    config.ipAddress = name->valuestring;
    config.maxLineLength = maxLineLength->valueint;
    config.maxConnections = maxConnections->valueint;
    free(content);
    return config;
}

pluginConfiguration getPluginConfiguration(const char *pluginPath) {
    pluginConfiguration null = {};
    pluginConfiguration config = null;
    DIR *d = opendir(pluginPath);
    if (d) {
        char *confPath = malloc(strlen(pluginPath) + strlen("/plugin.json"));
        strcpy(confPath, pluginPath);
        strcpy(confPath + strlen(pluginPath), "/plugin.json");
        char *content = getFileContents(confPath);
        if (!content) {
            fprintf(stderr, REDB"Invalid plugin.\n"reset);
            return null;
        }
        cJSON *json = cJSON_Parse(content);
        if (!json) {
            fprintf(stderr, REDB"Invalid JSON!\n"reset);
            return null;
        }
        cJSON *libPath = cJSON_GetObjectItem(json, "libPath");
        if (!libPath) {
            fprintf(stderr, REDB"Invalid JSON!\n"reset);
            return null;
        }
        cJSON *port = cJSON_GetObjectItem(json, "port");
        if (!port) {
            fprintf(stderr, REDB"Invalid JSON!\n"reset);
            return null;
        }
        cJSON *maxLineLength = cJSON_GetObjectItem(json, "maxLineLength");
        if (!maxLineLength) {
            fprintf(stderr, REDB"Invalid JSON!\n"reset);
            return null;
        }
        cJSON *maxConnections = cJSON_GetObjectItem(json, "maxConnections");
        if (!maxConnections) {
            fprintf(stderr, REDB"Invalid JSON!\n"reset);
            return null;
        }
        cJSON *version = cJSON_GetObjectItem(json, "version");
        if (!version) {
            fprintf(stderr, REDB"Invalid JSON!\n"reset);
            return null;
        }
        cJSON *displayName = cJSON_GetObjectItem(json, "displayName");
        if (!displayName) {
            fprintf(stderr, REDB"Invalid JSON!\n"reset);
            return null;
        }


        cJSON *startup = cJSON_GetObjectItem(json, "onStartup");
        cJSON *packetRecieved = cJSON_GetObjectItem(json, "onPacketRecieved");
        cJSON *newConnection = cJSON_GetObjectItem(json, "onNewConnection");
        cJSON *error = cJSON_GetObjectItem(json, "onError");
        cJSON *disconnect = cJSON_GetObjectItem(json, "onDisconnect");


        config.libPath = libPath->valuestring;
        config.port = port->valueint;
        config.maxLineLength = maxLineLength->valueint;
        config.maxConnections = maxConnections->valueint;
        config.displayName = displayName->valuestring;
        config.version = version->valueint;


        config.startup          = startup           ? startup->valuestring          : 0;
        config.packetRecieved   = packetRecieved    ? packetRecieved->valuestring   : 0;
        config.newConnection    = newConnection     ? newConnection->valuestring    : 0;
        config.error            = error             ? error->valuestring            : 0;
        config.disconnect       = disconnect        ? disconnect->valuestring       : 0;

        closedir(d);
        free(confPath);
        free(content);
        cJSON_free(json);
        return config;
    }
    fprintf(stderr, REDB"Couldn't find plugin.\n"reset);
    return null;
}