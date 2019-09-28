#ifndef _COMMON_H_
#define _COMMON_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <pthread.h>

/*系统标准IO头文件*/
#include <sys/types.h>    
#include <sys/stat.h>    
#include <sys/fcntl.h> 
#include <unistd.h>

#define UINT16                            unsigned int 

#include "list.h"
#include "io.h"
    



#define null                                  NULL



#define ERROR                             -1
#define OK                                   0
#define MASKLENGTH                   0x1000
#define PRT                                 printf

#define BUFFEN_LEN                    1024


typedef struct
{
	UINT16 startX;
	UINT16 startY;
	UINT16 blockLength;
}BLOCK_INFO;

typedef void (* Tsk_Creak)(void)

#endif



