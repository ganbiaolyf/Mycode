/**************************
*函数功能:单向有头链表
*author:干彪
*时间:2019/08/04
*/

#include "list.h"
#include "common.h"


NODE listHead;


/**************************
*函数功能:添加尾部链表结点
*param[in]:待添加的结点
*param[in]:链表的头结点
*param[out]:none
*/
int AddListEndNode(NODE *pnode,NODE *plistHead)
{
	NODE *plist = plistHead;
	if(plist == NULL || pnode == NULL)
	{
		PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);
		return ERROR;
	}
	
	while(plist->next)
	{
		plist = plist->next;
	}

	plist->next = pnode;
	pnode->next = NULL;
	return OK;
}

/**************************
*函数功能:删除尾部链表结点
*param[in]:链表的头结点
*param[out]:none
*/
int DelListEnd(NODE *plistHead)
{
	NODE *pPreNode = plistHead;
	NODE *pCurNode = plistHead->next;
	if(pPreNode == NULL)
	{
		PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);
		return ERROR;
	}

	while(pCurNode)
	{
		//找到最后一个结点
		if(pCurNode->next == NULL)
		{
			//删除最后一个结点
			pPreNode->next = pCurNode->next;
			free(pCurNode);
			pCurNode = NULL;
			break;
		}
		else
		{
			pPreNode = pCurNode;
			pCurNode = pCurNode->next;
		}
		
	}
	return OK;
}

/**************************
*函数功能:在链表头部添加结点
*param[in]:待添加的结点
*param[in]:链表的头结点
*param[out]:none
*/
int AddListHead(NODE *pnode,NODE *plistHead)
{
	NODE *pPreNode = plistHead;
	NODE *pCurNode = plistHead->next;

	if(pPreNode == NULL)
	{
		PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);
		return ERROR;
	}

	pnode->next = pCurNode;
	pPreNode->next = pnode;
		
	return OK;
}
/**************************
*函数功能:删除头部链表结点
*param[in]:链表的头结点
*param[out]:none
*/
int DelListHeadNode(NODE *plistHead)
{
	NODE *pPreNode = plistHead;
	NODE *pCurNode = plistHead->next;

	if(pPreNode == NULL)
	{
		PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);
		return ERROR;
	}

	if(pCurNode ==NULL)
	{
		PRT("[%s:%d]list is NULL\n",__FUNCTION__,__LINE__);
		return OK;
	}
	else
	{
		pPreNode->next = pCurNode->next;
		free(pCurNode);
		pCurNode = NULL;
	}

	return OK;
}

/**************************
*函数功能:删除链表的指定结点
*param[in]:待删除的结点
*param[in]:链表的头结点
*param[out]:none
*/
int DelListNode(NODE *pnode,NODE *plistHead)
{
	NODE *pPreNode = plistHead;
	NODE *pCurNode = plistHead->next;

	if(pPreNode == NULL)
	{
		PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);
		return ERROR;
	}

	while(pCurNode)
	{
		/*找到当前待删除的节点*/
		if(pCurNode->value == pnode->value)
		{
			pPreNode->next = pCurNode->next;
			free(pCurNode);
			pCurNode = NULL;
			break;
		}
		else
		{
			pPreNode = pCurNode;
			pCurNode = pCurNode->next;
		}
	}
	return OK;
}

/**************************
*函数功能:统计链表长度
*param[in]:链表的头结点
*param[out]:plistNum，链表的长度
*/
int GetListCnt(NODE *plistHead)
{
	NODE *pPreNode = plistHead;
	NODE *pCurNode = plistHead->next;
	UINT16 listNum = 0;
	if(pPreNode == NULL)
	{
		PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);
		return ERROR;
	}

	while(pCurNode)
	{
		PRT("[%s:%d]pCurNode->id=%d,pCurNode->value=%d,pCurNode=%p\n",__FUNCTION__,__LINE__,
					pCurNode->id,pCurNode->value,pCurNode);

		listNum++;
		pCurNode = pCurNode->next;
		
	}
	
	return listNum;
}


/**************************
*函数功能:遍历链表
*param[in]:链表的头结点
*param[out]:none
*/
int ShowList(NODE *plistHead)
{
	NODE *pPreNode = plistHead;
	NODE *pCurNode = plistHead->next;
	
	if(pPreNode == NULL)
	{
		PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);
		return ERROR;
	}

	while(pCurNode)
	{
		PRT("[%s:%d]List id=%d,List value=%d\n",__FUNCTION__,__LINE__,pCurNode->id,pCurNode->value);
		pCurNode = pCurNode->next;
	}
	return OK;
}


/**************************
*函数功能:将链表按照value从小到大排序
*param[in]:链表的头结点
*param[out]:none
*/
#if 0
int SortList(NODE *plistHead)
{
	NODE *pPreNode = plistHead;
	NODE *pCurNode = plistHead->next;
	NODE  *pTempNode;

	if(pPreNode == NULL)
	{
		PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);
		return ERROR;
	}
	
	pPreNode = pCurNode;
	pCurNode = pCurNode->next;
	//pTempNode =  pCurNode->next；
	while(pCurNode)
	{
		if(pPreNode->value > pCurNode->value)
		{
			PRT("[%s:%d]pCurNode->id=%d,pCurNode->value=%d\n",__FUNCTION__,__LINE__,
					pCurNode->id,pCurNode->value);
			PRT("[%s:%d]pPreNode->id=%d,pPreNode->value=%d\n",__FUNCTION__,__LINE__,
					pPreNode->id,pPreNode->value);
			/*两个节点值需要在链表中的位置互换*/
			pTempNode = pCurNode;
			/*将前一个节点信息给后一个节点*/
			pCurNode = pPreNode;
			pCurNode->next = pPreNode->next;
			
			pPreNode = pPreNode->next;
			pPreNode->next = pTempNode->next;

			PRT("[%s:%d]pCurNode->id=%d,pCurNode->value=%d\n",__FUNCTION__,__LINE__,
					pCurNode->id,pCurNode->value);
			PRT("[%s:%d]pPreNode->id=%d,pPreNode->value=%d\n",__FUNCTION__,__LINE__,
					pPreNode->id,pPreNode->value);

			/*将节点往后移1个*/
			pPreNode = pPreNode;
			pCurNode = pPreNode->next;
			
		}
		else
		{
			pPreNode = pCurNode;
			pCurNode = pCurNode->next;
		}
	
	}
	return OK;
}
#else

//选择排序不改变链表结构只是修改链表中携带的数据
int SortList(NODE *plistHead)
{
	NODE *pPreNode = plistHead;
	NODE *pCurNode = plistHead->next;
	NODE  *pTempNode;
	NODE  *pSmallNode;
	int       tempValue;
	
	int listNum = 0;
	UINT16 i = 0,k = 0;
	
	if(pPreNode == NULL)
	{
		PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);
		return ERROR;
	}

	pPreNode = pCurNode;//第一个节点
	pCurNode = pCurNode->next;//第2个节点
	pTempNode =  pCurNode->next;


	for(pCurNode =  plistHead->next;pCurNode != NULL ;pCurNode =  pCurNode->next)
	{
		pSmallNode = pCurNode;

		for(pTempNode =  pCurNode->next;pTempNode != NULL; pTempNode = pTempNode->next)
		{
			if(pTempNode->value < pSmallNode->value)
			{
				pSmallNode = pTempNode;
			}
		}

		if(pSmallNode != pCurNode)
		{
			tempValue = pCurNode->value;
			pCurNode->value = pSmallNode->value;
			pSmallNode->value = tempValue;
		}
	}

	return OK;
}

#endif



/**************************
*函数功能:按照从小到大的顺序插入结点
*param[in]:待插入的结点
*param[in]:链表的头结点
*param[out]:none
*/
int InsertList(NODE *pnode,NODE *plistHead)
{
	NODE *pPreNode = plistHead;
	NODE *pCurNode = plistHead->next;

	if(pPreNode == NULL || pnode == NULL)
	{
		PRT("[%s:%d]param is NULL\n",__FUNCTION__,__LINE__);
		return ERROR;
	}

	while(pCurNode)
	{
		if(pnode->value < pCurNode->value)
		{
			break;
		}
		
		pPreNode = pCurNode;
		pCurNode = pCurNode->next;

	}

	pnode->next = pPreNode->next;
	pPreNode->next = pnode;
	return OK;
}
















