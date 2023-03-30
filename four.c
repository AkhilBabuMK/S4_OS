#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;

    // Check if filename was provided
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Retrieve file information
    if (stat(argv[1], &fileStat) < 0) {
        printf("Error: Could not retrieve file information\n");
        return 1;
    }

    // Print protection mode
    printf("Protection mode: %lo\n", (unsigned long) (fileStat.st_mode & 0777));

    // Print size
    printf("Size: %lld bytes\n", (long long) fileStat.st_size);

    // Print last access time
    printf("Last access time: %s", ctime(&fileStat.st_atime));

    // Print time of last modification
    printf("Time of last modification: %s", ctime(&fileStat.st_mtime));

    return 0;
}

