#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <iostream>

#define PORT 8080

int main(int argc, char* argv[]) {

    std::cout << "Program Name: " << argv[0] << std::endl;
    std::cout << "Number of arguments: " << argc << std::endl;

    // Iterate through and print all command-line arguments
    for (int i = 0; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }

    int sock = 0;
    struct sockaddr_in serv_addr;
    const char *hello = argv[1];

    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    //Convert IPv4 & IPv6 addresses from text to binary
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return -1;
    }

    //Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        return -1;
    }

    //Send data
    send(sock, hello, strlen(hello), 0);
    std::cout << "Message sent" << std::endl;

    //Close socket
    close(sock);
    return 0;
}
