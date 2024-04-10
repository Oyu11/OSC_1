#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void change_directory(const char *path) {
    if (chdir(path) != 0) { 
        perror("Error changing directory");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", path); 
}

int main(int argc, char *argv[]) {
    if (argc != 2) { 
        printf("Usage: %s directory_path\n", argv[0]);
        return EXIT_FAILURE;
    }

    change_directory(argv[1]); 

    return EXIT_SUCCESS;
}
