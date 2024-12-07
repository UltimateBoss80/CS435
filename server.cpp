#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib") // Link Winsock library

using namespace std;

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // Create a TCP socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Set up the server address structure
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;          // IPv4
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP
    serverAddr.sin_port = htons(12345);      // Port 12345

    // Bind the socket to the server address
    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));

    // Listen for a client connection
    listen(serverSocket, 1);
    cout << "Server is running..." << endl;

    // Accept a connection from a client
    SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
    cout << "Client connected!" << endl;

    char buffer[1024];
    while (true) {
        // Receive a message from the client
        memset(buffer, 0, sizeof(buffer)); // Clear the buffer
        recv(clientSocket, buffer, sizeof(buffer), 0);
        cout << "Received: " << buffer << endl;

        // Echo the message back to the client
        send(clientSocket, buffer, strlen(buffer), 0);

        // Stop if the message is "Bye!"
        if (strcmp(buffer, "Bye!") == 0) 
        {
            cout << "Connection closed. Server shutting down.";
            break;
        }
        
    }

    // Close sockets and clean up
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
