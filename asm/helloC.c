#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    write(1, "Hello C!\n", 9);
    return EXIT_SUCCESS;
}
