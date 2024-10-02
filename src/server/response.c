#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h> // Add this line to include the socket API
#include "response.h"

void response(int client_socket, const char *status, const char *content_type, const char *body)
{
    char response_buffer[4096];
    int content_length = strlen(body);

    snprintf(response_buffer, sizeof(response_buffer),
             "HTTP/1.1 %s\r\n"
             "Content-Type: %s\r\n"
             "Content-Length: %d\r\n"
             "\r\n"
             "%s",
             status, content_type, content_length, body);

    send(client_socket, response_buffer, strlen(response_buffer), 0);
}