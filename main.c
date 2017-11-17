#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <sys/stat.h>

int main(int argc, char** argv) {
    size_t index;

    printf("argc: %d\n", argc);
    for (index = 0; index < argc; index++) {
        printf("argv[%lu]: %s\n", index, argv[index]);
    }

    char* target = argc > 1 ? argv[1] : "/etc/passwd";
    struct stat sb;
    if (stat(target, &sb) == -1) {
        printf("error: %s\n", strerror(errno));
        exit(1);
    }

    printf("file size: %llu\n", (unsigned long long)sb.st_size);
    printf("mode: %o\n", sb.st_mode);

    char timestr[256];
    strftime(timestr, 256, "%a %b %d %H:%M:%S %Y", localtime(&sb.st_atime));
    printf("last accessed: %s\n", timestr);

    return 0;
}
