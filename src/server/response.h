#ifndef RESPONSE_H
#define RESPONSE_H

void response(int client_socket, const char *status, const char *content_type, const char *body);

#endif // RESPONSE_H