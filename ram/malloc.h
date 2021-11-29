extern void * xmalloc(size_t size);
extern void * xmalloc0(size_t size);
extern void printmallinfo();
extern int open_etc_config(const char *filename, int flags, mode_t mode);
extern int open_etc_config2(const char *filename, int flags, mode_t mode);
extern int open_etc_config3(const char *filename, int flags, mode_t mode);
