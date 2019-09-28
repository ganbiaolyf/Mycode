#ifndef __IO_H__
#define __IO_H__

#include "common.h"

extern int OpenFile(const char * pfileName,int flag,int mode);

extern int CopyFile(int srcFd,int dstFd);

#endif
