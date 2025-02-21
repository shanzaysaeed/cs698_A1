#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Ensure exactly one argument is provided
    if (argc != 2) {
        fprintf(stderr, "Error: Please provide a valid file path.\n");
        return 1;
    }

    // Open file using user-supplied name (keeping this high-severity issue intentionally)
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Determine file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);

    // Print the file size (same behavior as original code)
    printf("%ld %s\n", size, argv[1]);

    return 0;
}
