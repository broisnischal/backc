#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "../hello/hello.h"
#include "router.h"

// Example handler function for GET request
void hello_handler()
{
    hello(); // Call the hello function from the library
}

// Function to handle client connections
void handle_client(int client_socket)
{
    char buffer[1024];
    int read_size;

    // Receive request from client
    read_size = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (read_size > 0)
    {
        buffer[read_size] = '\0'; // Null-terminate the string

        // Parse the request line (basic GET request)
        char *method = strtok(buffer, " ");
        char *path = strtok(NULL, " ");

        // Only handle GET requests
        if (strcmp(method, "GET") == 0)
        {
            // Call the router to handle the request path
            handle_request(path, method);
        }
        else
        {
            printf("405 Method Not Allowed\n");
        }
    }

    // Close the client socket
    close(client_socket);
}

// Main function to set up server and routes
int main()
{
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on any IP address
    server_addr.sin_port = htons(8080);       // Listen on port 8080

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0)
    {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port 8080\n");

    // Add a route
    get("/hello", hello_handler);

    while (1)
    {
        addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);
        if (client_socket < 0)
        {
            perror("Accepting connection failed");
            continue; // Move to the next iteration
        }

        // Handle the client connection
        handle_client(client_socket);
    }

    // Close the server socket
    close(server_socket);
    return 0;
}
