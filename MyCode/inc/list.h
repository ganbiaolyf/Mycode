#ifndef __LIST_H__
#define __LIST_H__

#include "common.h"


typedef struct _NODE_ NODE;
struct _NODE_
{
	NODE *next;
	int value;
	int id;
};

extern NODE listHead;

 
/**************************
*��������:���β��������
*param[in]:����ӵĽ��
*param[in]:�����ͷ���
*param[out]:none
*/
extern int AddListEndNode(NODE *pnode,NODE *plistHead);

/**************************
*��������:ɾ��β��������
*param[in]:�����ͷ���
*param[out]:none
*/
extern int DelListEnd(NODE *plistHead);

/**************************
*��������:������ͷ����ӽ��
*param[in]:����ӵĽ��
*param[in]:�����ͷ���
*param[out]:none
*/
extern int AddListHead(NODE *pnode,NODE *plistHead);

/**************************
*��������:ɾ��ͷ��������
*param[in]:�����ͷ���
*param[out]:none
*/
extern int DelListHeadNode(NODE *plistHead);


/**************************
*��������:ɾ�������ָ�����
*param[in]:��ɾ���Ľ��
*param[in]:�����ͷ���
*param[out]:none
*/
extern int DelListNode(NODE *pnode,NODE *plistHead);

/**************************
*��������:ͳ��������
*param[in]:�����ͷ���
*param[out]:plistNum������ĳ���
*/
extern int GetListCnt(NODE *plistHead);

/**************************
*��������:��������
*param[in]:�����ͷ���
*param[out]:none
*/
extern int ShowList(NODE *plistHead);

/**************************
*��������:��������value��С��������
*param[in]:�����ͷ���
*param[out]:none
*/
extern int SortList(NODE *plistHead);

/**************************
*��������:���մ�С�����˳�������
*param[in]:������Ľ��
*param[in]:�����ͷ���
*param[out]:none
*/
extern int InsertList(NODE *pnode,NODE *plistHead);

#endif

