#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Ensure exactly one argument is provided
    if (argc != 2) {
        fprintf(stderr, "Error: Please provide a valid file path.\n");
        return 1;
    }

    // Execute 'wc -c' safely using execlp
    execlp("wc", "wc", "-c", argv[1], (char *)NULL);

    // If execlp fails, print an error
    perror("Execution failed");
    return 1;
}
