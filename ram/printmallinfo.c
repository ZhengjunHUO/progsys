#include <malloc.h>
#include <stdio.h>

void printmallinfo() {
	struct mallinfo m = mallinfo();
	printf("free chunks: %d\nfast bins: %d\nanony maps: %d\nanonymapsize: %d\n", 
			m.ordblks, m.smblks, m.hblks, m.hblkhd);
}
