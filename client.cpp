#include <iostream>
#include <string>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib") // Link Winsock library

using namespace std;

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // Create a TCP socket
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Set up the server address structure
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;           // IPv4
    serverAddr.sin_port = htons(12345);        // Port 12345
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Connect to localhost

    // Connect to the server
    connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    cout << "Connected to the server!" << endl;

    char buffer[1024];
    string message;
    while (true) {
        // Get input from the user
        cout << "Enter message: ";
        getline(cin, message);

        // Send the message to the server
        send(clientSocket, message.c_str(), message.length(), 0);

        // Receive the server's response
        memset(buffer, 0, sizeof(buffer)); // Clear the buffer
        recv(clientSocket, buffer, sizeof(buffer), 0);
        cout << "Server replied: " << buffer << endl;

        // Stop if the message is "Bye!"
        if (message == "Bye!") 
        {
            cout << "Disconnected from server.";
            break;
        }
        
    }

    // Close socket and clean up
    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
