#include "../include/router.h"

void router_init(Router *router)
{
    router->count = 0;
}

void router_add_route(Router *router, const char *path, void (*handler)(void))
{
    if (router->count >= MAX_ROUTES)
    {
        fprintf(stderr, "Error: Maximum number of routes reached\n");
        return;
    }

    strncpy(router->routes[router->count].path, path, MAX_PATH_LENGTH - 1);
    router->routes[router->count].path[MAX_PATH_LENGTH - 1] = '\0';
    router->routes[router->count].handler = handler;
    router->count++;
}

void router_handle_request(Router *router, const char *path)
{
    for (int i = 0; i < router->count; i++)
    {
        if (strcmp(router->routes[i].path, path) == 0)
        {
            router->routes[i].handler();
            return;
        }
    }

    fprintf(stderr, "Error: No route found for path %s\n", path);
}
