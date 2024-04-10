#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rename_file(const char *old_name, const char *new_name) {
    if (rename(old_name, new_name) != 0) { // Using rename function to rename the file
        perror("Error renaming file");
        exit(EXIT_FAILURE);
    }
    printf("File successfully renamed.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) { // Checking if enough command-line arguments are provided
        printf("Usage: %s input old_filename new_filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "input") == 0) { // Checking if the command is 'input'
        rename_file(argv[2], argv[3]); // Calling the function to rename the file
    } else {
        printf("Invalid command.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
