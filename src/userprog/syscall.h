#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H
#include <stdbool.h>
#include <list.h>
#include "threads/synch.h"

struct lock files_sync_lock;
struct fd_element
{
    int fd;                        /*file descriptors ID*/
    struct file *file;            /* the real file*/
    struct list_elem element;      /*list elem to add fd_element in fd_list*/
};

void syscall_init (void);
int read (int fd, void *buffer, unsigned size);
int open (const char *file);
#endif /* userprog/syscall.h */
