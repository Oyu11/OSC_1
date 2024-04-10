#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h> // for getcwd()

void list_directory(const char *path) {
    DIR *directory;
    struct dirent *entry;
    struct stat filestat;
    char datestring[256];

    directory = opendir(path);

    if (directory == NULL) {
        perror("Unable to read directory");
        exit(EXIT_FAILURE);
    }

    printf(" Directory of %s\n\n", path);

    while ((entry = readdir(directory)) != NULL) {
        char *name = entry->d_name;
        char fullpath[512];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, name);

        if (stat(fullpath, &filestat) == -1) {
            perror("Unable to get file stats");
            exit(EXIT_FAILURE);
        }

        strftime(datestring, sizeof(datestring), "%m/%d/%Y  %I:%M %p", localtime(&filestat.st_mtime));

        if (S_ISDIR(filestat.st_mode)) {
            printf("%s    <DIR>          %s\n", datestring, name);
        } else {
            printf("%s    %10lld %s    %s\n", datestring, (long long)filestat.st_size, name, (S_ISREG(filestat.st_mode) ? "File" : "Unknown"));
        }
    }

    closedir(directory);
}

int main(int argc, char *argv[]) {
    const char *path;

    if (argc > 1) {
        path = argv[1];
    } else {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            path = cwd;
        } else {
            perror("getcwd() error");
            return EXIT_FAILURE;
        }
    }

    list_directory(path);

    return 0;
}
