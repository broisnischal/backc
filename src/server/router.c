#include <stdio.h>
#include <string.h>
#include "router.h"

typedef struct
{
    char path[100];
    char method[10];
    void (*handler)();
} Route;

Route routes[100];
int route_count = 0;

void add_route(char path[], char method[], void (*handler)(void))
{
    strcpy(routes[route_count].path, path);
    strcpy(routes[route_count].method, method);
    routes[route_count].handler = handler;
    route_count++;
}

void handle_request(char path[], char method[])
{
    for (int i = 0; i < route_count; i++)
    {
        if (strcmp(routes[i].path, path) == 0 && strcmp(routes[i].method, method) == 0)
        {
            routes[i].handler();
            return;
        }
    }
    printf("No route found for %s %s\n", method, path);
}

void get(char path[], void (*handler)(void))
{
    add_route(path, "GET", handler);
}

void post(char path[], void (*handler)(void))
{
    add_route(path, "POST", handler);
}

void put(char path[], void (*handler)(void))
{
    add_route(path, "PUT", handler);
}

void delete(char path[], void (*handler)(void))
{
    add_route(path, "DELETE", handler);
}
