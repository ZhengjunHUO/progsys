#include <unistd.h>
#include <stdlib.h>
#include <sys/syscall.h>

int main() {
    syscall(1, 1, "Hello C!\n", 9);
    return EXIT_SUCCESS;
}
