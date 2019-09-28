/**************************
*��������:������ͷ����
*author:�ɱ�
*ʱ��:2019/08/04
*/

#include "list.h"
#include "common.h"


NODE listHead;


/**************************
*��������:���β��������
*param[in]:����ӵĽ��
*param[in]:�����ͷ���
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
*��������:ɾ��β��������
*param[in]:�����ͷ���
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
		//�ҵ����һ�����
		if(pCurNode->next == NULL)
		{
			//ɾ�����һ�����
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
*��������:������ͷ����ӽ��
*param[in]:����ӵĽ��
*param[in]:�����ͷ���
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
*��������:ɾ��ͷ��������
*param[in]:�����ͷ���
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
*��������:ɾ�������ָ�����
*param[in]:��ɾ���Ľ��
*param[in]:�����ͷ���
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
		/*�ҵ���ǰ��ɾ���Ľڵ�*/
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
*��������:ͳ��������
*param[in]:�����ͷ���
*param[out]:plistNum������ĳ���
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
*��������:��������
*param[in]:�����ͷ���
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
*��������:��������value��С��������
*param[in]:�����ͷ���
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
	//pTempNode =  pCurNode->next��
	while(pCurNode)
	{
		if(pPreNode->value > pCurNode->value)
		{
			PRT("[%s:%d]pCurNode->id=%d,pCurNode->value=%d\n",__FUNCTION__,__LINE__,
					pCurNode->id,pCurNode->value);
			PRT("[%s:%d]pPreNode->id=%d,pPreNode->value=%d\n",__FUNCTION__,__LINE__,
					pPreNode->id,pPreNode->value);
			/*�����ڵ�ֵ��Ҫ�������е�λ�û���*/
			pTempNode = pCurNode;
			/*��ǰһ���ڵ���Ϣ����һ���ڵ�*/
			pCurNode = pPreNode;
			pCurNode->next = pPreNode->next;
			
			pPreNode = pPreNode->next;
			pPreNode->next = pTempNode->next;

			PRT("[%s:%d]pCurNode->id=%d,pCurNode->value=%d\n",__FUNCTION__,__LINE__,
					pCurNode->id,pCurNode->value);
			PRT("[%s:%d]pPreNode->id=%d,pPreNode->value=%d\n",__FUNCTION__,__LINE__,
					pPreNode->id,pPreNode->value);

			/*���ڵ�������1��*/
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

//ѡ�����򲻸ı�����ṹֻ���޸�������Я��������
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

	pPreNode = pCurNode;//��һ���ڵ�
	pCurNode = pCurNode->next;//��2���ڵ�
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
*��������:���մ�С�����˳�������
*param[in]:������Ľ��
*param[in]:�����ͷ���
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
















