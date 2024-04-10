User
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // Check if old and new filenames are provided as arguments
    if (argc != 3) {
        printf("Usage: %s <old_filename> <new_filename>\n", argv[0]);
        return 1;
    }

    // Rename file
    if (rename(argv[1], argv[2]) != 0) {
        printf("Failed to rename file: %s\n", strerror(errno));
        return 1;
    }

    printf("File \"%s\" renamed to \"%s\" successfully.\n", argv[1], argv[2]);

    return 0;
}