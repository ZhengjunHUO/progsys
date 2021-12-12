#include <stdio.h>

#define BUF_SIZE 4096

static inline __attribute__ ((always_inline)) int abs(int num) {
	if (num < 0) {
		return -num;
	}
	return num;
}
  
int main() {
	int buf[BUF_SIZE];
	int i;

	for (i=-BUF_SIZE; i<0; i++) {
		buf[i+BUF_SIZE] = abs(i);
	}
	
	printf("The last element of buf: %d\n", buf[BUF_SIZE-1]);
	return 0;
}
