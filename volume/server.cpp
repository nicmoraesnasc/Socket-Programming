#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <cerrno>

#include <cstring>
#include <iostream>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    //Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        std::cerr << "Socket failed!" << std::endl;
        exit(EXIT_FAILURE);
    }

    //Attach socket to the port
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    //Bind
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        exit(EXIT_FAILURE);
    }
        
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen" << std::endl;
        exit(EXIT_FAILURE);
    }

    while(true) {

        //Accept a connection
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (new_socket < 0) {
            std::cerr << "Accept" << std::endl;
            exit(EXIT_FAILURE);
        }

        //Clear buffer before reading
        memset(buffer, 0, sizeof(buffer));

        //Read data
         ssize_t valread = read(new_socket, buffer, sizeof(buffer) - 1);
        if (valread > 0) {
            buffer[valread] = '\0';  // Null-terminate
            std::cout << "Message from client: " << buffer << std::endl;
        } else {
            std::cerr << "Read error or connection closed" << std::endl;
        }

        //Close socket
        close(new_socket);
    }
    close(server_fd);
    return 0;
}