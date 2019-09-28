#include "common.h"

/**************************
*函数功能:使用系统调用进行文件打开
*param[in]:文件路径
*param[in]:打开方式
*param[out]:成功:打开文件的文件描述符失败:-1
*/
int OpenFile(const char * pfileName,int flag,int mode)
{
	int fd = 0;
	if(pfileName == NULL)
	{
		PRT("[%s:%d]pfileName is null\n",__FUNCTION__,__LINE__);
		return ERROR;
	}
	
	fd = open(pfileName,flag,mode);
	if(fd < 0)
	{
		PRT("[%s:%d]open file error\n",__FUNCTION__,__LINE__);
		return ERROR;
	}

	return fd;
}

/**************************
*函数功能:使用系统调用进行文件拷贝
*param[in]:源文件的文件描述符
*param[in]:目标文件的文件描述符
*param[out]:none
*/
int CopyFile(int srcFd,int dstFd)
{
	int len = 0;
	char buffer[BUFFEN_LEN] = {0};
	int ret = OK;

	while((len = read(srcFd,buffer,BUFFEN_LEN)) != 0 )
	{
		PRT("len=%d\n",len);
		ret = write(dstFd,buffer,len);
		if(ret == ERROR)
		{

			PRT("[%s:%d]open file error,ret=%d,srcFd,=%d,dstFd=%d\n",__FUNCTION__,__LINE__,ret,srcFd,dstFd);
			return ERROR;
		}
	}
	return OK;
}