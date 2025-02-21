#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define FILENAME_SIZE 256
#define BUFFER_SIZE 1024
#define FAIL -1

// Function declarations (add these if not using a separate header file)
int openSocketConnection(char *host, int port);
int getNextMessage(int socket, char *buffer, int bufferSize);
int openFileToWrite(char *filename);
int writeToFile(char *buffer);
void closeFile();
void closeSocket(int socket);

// Function to write data from a socket to a file
int writeDataFromSocketToFile(char *host, int port) {
    char filename[FILENAME_SIZE];
    char buffer[BUFFER_SIZE];
    
    // Open socket connection
    int socket = openSocketConnection(host, port);
    if (socket < 0) {
        printf("Unable to open socket connection\n");
        return FAIL;
    }

    // Receive the filename
    if (getNextMessage(socket, filename, FILENAME_SIZE) > 0) {
        if (openFileToWrite(filename) > 0) {
            // Receive and write data to file
            while (getNextMessage(socket, buffer, BUFFER_SIZE) > 0) {
                if (!(writeToFile(buffer) > 0))
                    break;
            }
        }
        closeFile();
    }

    // Close socket connection
    closeSocket(socket);
    return 0;
}

// Main function
int main() {
    char *host = "127.0.0.1";  // Modify as needed
    int port = 8080;           // Modify as needed

    printf("Starting socket connection...\n");
    int result = writeDataFromSocketToFile(host, port);

    if (result == FAIL) {
        printf("Error in writing data from socket to file\n");
        return EXIT_FAILURE;
    }

    printf("Data successfully written to file.\n");
    return EXIT_SUCCESS;
}
