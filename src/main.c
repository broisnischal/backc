#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "../include/router.h"
#include "../include/server.h"

void home_handler(void)
{
    printf("Home page\n");
}

void about_handler(void)
{
    printf("About page\n");
}

void contact_handler(void)
{
    printf("Contact page\n");
}

void handle_client(int client_socket)
{
    char buffer[1024];
    read(client_socket, buffer, sizeof(buffer) - 1);
    printf("Received request:\n%s\n", buffer);

    // Basic HTTP Response
    const char *http_response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "Connection: close\r\n"
        "\r\n"
        "Hello, World!";

    write(client_socket, http_response, strlen(http_response));
    close(client_socket);
}

int main()
{
    Router router;
    router_init(&router);

    // Add routes
    router_add_route(&router, "/", home_handler);
    router_add_route(&router, "/about", about_handler);
    router_add_route(&router, "/contact", contact_handler);

    // TODO: Integrate with your server implementation
    // For demonstration purposes, we'll simulate some requests
    router_handle_request(&router, "/");
    router_handle_request(&router, "/about");
    router_handle_request(&router, "/contact");
    router_handle_request(&router, "/nonexistent");

    return 0;
}
