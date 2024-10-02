#include "router.h"
#include <string.h>

typedef struct
{
    char path[100];
    void (*handler)(int);
} Route;

#define MAX_ROUTES 100
Route routes[MAX_ROUTES];
int route_count = 0;

void get(char path[], void (*handler)(int))
{
    if (route_count < MAX_ROUTES)
    {
        strcpy(routes[route_count].path, path);
        routes[route_count].handler = handler;
        route_count++;
    }
}

void handle_request(char *path, char *method, int client_socket)
{
    (void)method; // This line marks the 'method' parameter as intentionally unused
    for (int i = 0; i < route_count; i++)
    {
        if (strcmp(routes[i].path, path) == 0)
        {
            routes[i].handler(client_socket);
            return;
        }
    }
    // Handle 404 Not Found
}
