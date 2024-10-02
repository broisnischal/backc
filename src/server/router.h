#ifndef ROUTER_H
#define ROUTER_H

// Update the function signature to accept a handler that takes an int parameter
void get(char path[], void (*handler)(int));

// Update this function signature as well
void handle_request(char *path, char *method, int client_socket);

#endif