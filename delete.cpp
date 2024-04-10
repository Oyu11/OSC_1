#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delete_file(const char *filename) {
    if (remove(filename) != 0) { 
        perror("Error deleting file");
        exit(EXIT_FAILURE);
    }
    printf("File successfully deleted.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) { 
        printf("Usage: %s delete filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "delete") == 0) { 
        delete_file(argv[2]); 
    } else {
        printf("Invalid command.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
