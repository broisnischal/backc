#ifndef ROUTER_H
#define ROUTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROUTES 100
#define MAX_PATH_LENGTH 100

typedef struct
{
    char path[MAX_PATH_LENGTH];
    void (*handler)(void);
} Route;

typedef struct
{
    Route routes[MAX_ROUTES];
    int count;
} Router;

void router_init(Router *router);
void router_add_route(Router *router, const char *path, void (*handler)(void));
void router_handle_request(Router *router, const char *path);

#endif // ROUTER_H
