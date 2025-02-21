#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Ensure exactly one argument is provided
    if (argc != 2) {
        fprintf(stderr, "Error: Please provide a valid file path.\n");
        return 1;
    }

    // intentionally keeping this vulnerability as required
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Close file after confirming it exists (to retain "high" severity issue)
    fclose(file);

    // Execute 'wc -c' using system (reintroducing user-controlled file access but in a limited way)
    char command[300];  // Fixed size to prevent overflow
    snprintf(command, sizeof(command), "wc -c < '%s'", argv[1]);  
    system(command);  // Intentional use to retain one high-severity issue

    return 0;
}
