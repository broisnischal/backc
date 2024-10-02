#ifndef ROUTER_H
#define ROUTER_H

void add_route(char path[], char method[], void (*handler)(void));
void handle_request(char path[], char method[]);
void get(char path[], void (*handler)(void));
void post(char path[], void (*handler)(void));
void put(char path[], void (*handler)(void));

#endif