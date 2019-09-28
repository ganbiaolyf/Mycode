#include "common.h"



/*验证链表功能函数*/
void ListCtrl()
{
	NODE *pNode = NULL;
	UINT16 listNum = 0;
	memset(&listHead,0,sizeof(NODE));

	pNode = malloc(sizeof(NODE));
	pNode->id = 0;
	pNode->value = 10;
	pNode->next = NULL;
	AddListHead(pNode,&listHead);

	pNode = malloc(sizeof(NODE));
	pNode->id = 5;
	pNode->value = 100;
	pNode->next = NULL;
	AddListHead(pNode,&listHead);

	pNode = malloc(sizeof(NODE));
	pNode->id = 10;
	pNode->value = 3;
	pNode->next = NULL;
	AddListHead(pNode,&listHead);

	pNode = malloc(sizeof(NODE));
	pNode->id = 20;
	pNode->value = 32;
	pNode->next = NULL;
	AddListEndNode(pNode,&listHead);
	ShowList(&listHead);
	PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);

	listNum = GetListCnt(&listHead);
	
	PRT("[%s:%d]listNum = %d\n",__FUNCTION__,__LINE__,listNum);

#if 1	
	pNode = malloc(sizeof(NODE));
	pNode->id = 22;
	pNode->value = 99;
	pNode->next = NULL;
	InsertList(pNode,&listHead);
#endif
	PRT("[%s:%d]listNum = %d\n",__FUNCTION__,__LINE__,listNum);
	
	listNum = GetListCnt(&listHead);
	
	PRT("[%s:%d]listNum = %d\n",__FUNCTION__,__LINE__,listNum);
	ShowList(&listHead);
	PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);

	SortList(&listHead);
	PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);
	ShowList(&listHead);
	PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);

	DelListEnd(&listHead);
	PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);
	ShowList(&listHead);

	DelListHeadNode(&listHead);
	PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);
	ShowList(&listHead);
	DelListNode(pNode,&listHead);
		PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);
	ShowList(&listHead);
}

/*
*验证对文件的拷贝相关功能函数
*argc:main函数中第一个参数，标书传进来的参数个数
*再传入两个文件名
*************************************/
int StandarIoCtrl(int argc,char *argv[])
{
	int flag;
	int mode = 0;
	int fdRead = 0;
	int fdWrite = 0;

	if(argc < 3)
	{
		fprintf(stderr,"tool param error.usage %s srcFile destFile\n",argv[0]);
		exit(1);
	}
	
	flag = O_RDONLY;
	mode = 0777;
	fdRead = OpenFile(argv[1],flag,mode);
	if(fdRead == ERROR)
	{
		PRT("[%s:%d]open file error,srcFd,=%d\n",__FUNCTION__,__LINE__,fdRead);
		fprintf(stderr,"open file error:%s\n",strerror(errno));
		exit(1);
	}
	
   	flag = O_RDWR | O_CREAT |O_TRUNC;
	mode = 0777;
	fdWrite = OpenFile(argv[2],flag,mode);
	if(fdWrite == ERROR)
	{
		PRT("[%s:%d]open file error,srcFd,=%d\n",__FUNCTION__,__LINE__,fdWrite);
		fprintf(stderr,"open file error:%s\n",strerror(errno));
		exit(1);
	}
	
	CopyFile(fdRead,fdWrite);

}


/**************************
*函数功能:创建线程
*param[in]:源文件的文件描述符
*param[in]:目标文件的文件描述符
*param[out]:none
*/
int CreatThreat(Tsk_Creak pFun)
{
	pthread_t  *restrict tidp;
	if(pthread_creat(&tidp,NULL,pFun,NULL) != 0)
	{
		printf("[%s:%d]creat error!\n",__FUNCTION__,__LINE__);
		return -1;
	}

	return 0;
}


#if 0

int InitModules()
{
	pthread_t  tipid;
	
}

//消息队列模块初始化
int InitMsgModules()
{
	pthread_t  *restrict tidp;
	int ret;
	if(pthread_creat(&tidp,NULL,MsgQueueTsk,NULL) != 0)
	{
		printf("[%s:%d]creat error!\n",__FUNCTION__,__LINE__);
		return -1;
	}
}


#endif

void MsgQueueTsk()
{
	int msgid = -1;
	//key_t keyMsg = -1
	//keyMsg = ftok("./",0);
	
	//建立消息队列
	//msgid = msgget((key_t)keyMsg, 0666 | IPC_CREAT);
	
	while(1)
	{
		sleep(5);
	}

	
}


int main(int argc,char *argv[])
{
	

	//StandarIoCtrl(argc,argv);
	//ListCtrl();


	for ( i=0;i<1024;i++ )
	{
		PRT("[%s:%d]CreatThreat i=%d\n",__FUNCTION__,__LINE__,i);
		CreatThreat(MsgQueueTsk);
	}


	return 0;
}
















