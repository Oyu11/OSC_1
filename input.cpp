#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if filename is provided as argument
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open file in write mode
    FILE *file = fopen(argv[1], "w");

    // Check if file is opened successfully
    if (file == NULL) {
        printf("Failed to create file.\n");
        return 1;
    }

    // Input sample data
    printf("Enter sample data to write into the file (end input with \"<<P\" on a new line):\n");
    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Check if input is "<<P" to end input
        if (strcmp(buffer, "<<P\n") == 0) {
            break;
        }
        // Write data to the file
        fputs(buffer, file);
    }

    // Close the file
    fclose(file);

    printf("Sample data input to \"%s\" successfully.\n", argv[1]);

    return 0;
}
