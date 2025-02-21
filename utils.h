#ifndef UTILS_H
#define UTILS_H

int openSocketConnection(char *host, int port);
int getNextMessage(int socket, char *buffer, int bufferSize);
int openFileToWrite(char *filename);
int writeToFile(char *buffer);
void closeFile();
void closeSocket(int socket);

#endif // UTILS_H
