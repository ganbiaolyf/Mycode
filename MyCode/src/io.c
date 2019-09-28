#include "common.h"

/**************************
*��������:ʹ��ϵͳ���ý����ļ���
*param[in]:�ļ�·��
*param[in]:�򿪷�ʽ
*param[out]:�ɹ�:���ļ����ļ�������ʧ��:-1
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
*��������:ʹ��ϵͳ���ý����ļ�����
*param[in]:Դ�ļ����ļ�������
*param[in]:Ŀ���ļ����ļ�������
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