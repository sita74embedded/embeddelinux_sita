// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    char buffer[1024] = {0};
    char *response = "Hello from server!";
    int addrlen = sizeof(address);

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind to IP/port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Accept any address
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen
    listen(server_fd, 3);

    // Accept connection
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Receive message
    read(new_socket, buffer, sizeof(buffer));
    printf("Client says: %s\n", buffer);

    // Send response
    send(new_socket, response, strlen(response), 0);

    // Close sockets
    close(new_socket);
    close(server_fd);

    return 0;
}

