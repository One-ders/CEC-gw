/* $Nosix/Leanaux: , v1.1 2014/04/07 21:44:00 anders Exp $ */

/*
 * Copyright (c) 2014, Anders Franzen.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @(#)io.h
 */

/*  for select */
typedef unsigned int fd_set;

#define FD_SET(a,b)	((*(b))|=(1<<a))
#define FD_CLR(a,b)	((*(b))&=~(1<<a))
#define FD_ISSET(a,b)	((*(b))&(1<<a))
#define FD_ZERO(a)	((*(b))=0)

/* for lseek */
#define SEEK_SET	0
#define SEEK_CUR	1
#define SEEK_END	2

#ifndef O_RDONLY
#define O_RDONLY        00
#endif

#ifndef O_WRONLY
#define O_WRONLY        01
#endif

#ifndef O_RDWR
#define O_RDWR          02
#endif

#ifndef O_CREAT
#define O_CREAT         0100
#endif

#ifndef O_EXCL
#define O_EXCL          0200
#endif

#ifndef O_TRUNC
#define O_TRUNC         01000
#endif
#ifndef O_APPEND
#define O_APPEND        02000
#endif

#ifndef SEEK_SET
#define SEEK_SET        0
#endif

#ifndef SEEK_CUR
#define SEEK_CUR        1
#endif

#ifndef SEEK_END
#define SEEK_END        2
#endif

#ifndef EBUSY
#define EBUSY   16
#endif

#ifndef ENODEV
#define ENODEV  19
#endif

#ifndef EINVAL
#define EINVAL  22
#endif

#ifndef ENFILE
#define ENFILE  23
#endif

#ifndef EBADF
#define EBADF   9
#endif

#ifndef EACCES
#define EACCES  13
#endif

#ifndef EXDEV
#define EXDEV   18
#endif
#ifndef ENOENT
#define ENOENT  2
#endif

#ifndef ENOSPC
#define ENOSPC  28
#endif

#ifndef EROFS
#define EROFS   30
#endif

#ifndef ERANGE
#define ERANGE 34
#endif

#ifndef ENODATA
#define ENODATA 61
#endif

#ifndef ENOTEMPTY
#define ENOTEMPTY 39
#endif

#ifndef ENAMETOOLONG
#define ENAMETOOLONG 36
#endif

#ifndef ENOMEM
#define ENOMEM 12
#endif

#ifndef EFAULT
#define EFAULT 14
#endif

#ifndef EEXIST
#define EEXIST 17
#endif

#ifndef ENOTDIR
#define ENOTDIR 20
#endif

#ifndef EISDIR
#define EISDIR 21
#endif

#ifndef ELOOP
#define ELOOP   40
#endif



void init_io(void);
int io_add_c(const char c);
int io_setpolled(int enabled);

int sys_printf(const char *format, ...);

unsigned long int strtoul(char *str, char **endp, int base);

#define sys_read(a,b,c) yaffs_read(a,b,c)
#define sys_lseek(a,b,c) yaffs_lseek(a,b,c)
#define sys_open yaffs_open
#define sys_close(a) yaffs_close(a)

