#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "w");

    if (file == NULL) {
        printf("Failed to create file.\n");
        return 1;
    }

    fclose(file);

    printf("File \"%s\" created successfully.\n", argv[1]);

    return 0;
}
