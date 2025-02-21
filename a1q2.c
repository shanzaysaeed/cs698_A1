#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Ensure exactly one argument is provided
    if (argc != 2) {
        fprintf(stderr, "Error: Please provide a valid file path.\n");
        return 1;
    }

    // Execute 'wc -c' safely
    if (execlp("wc", "wc", "-c", argv[1], (char *)NULL) == -1) {
        perror("Execution failed");
        return 1;
    }

    return 0; // This will never execute if execlp succeeds
}
