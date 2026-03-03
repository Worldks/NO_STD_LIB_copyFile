#ifndef CALLS_H_SENTRY
#define CALLS_H_SENTRY

extern int sys_errno;

int sys_read(int fd, void *buf, int size);
int sys_write(int fd, const void *buf, int size);
int sys_open_2param(const char *pathname, int flags);
int sys_open_3param(const char *pathname, int flags, int mode);
int sys_close(int fd);
void sys_exit(int status);

#endif
