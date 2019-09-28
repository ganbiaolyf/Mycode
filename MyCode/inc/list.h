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
*函数功能:添加尾部链表结点
*param[in]:待添加的结点
*param[in]:链表的头结点
*param[out]:none
*/
extern int AddListEndNode(NODE *pnode,NODE *plistHead);

/**************************
*函数功能:删除尾部链表结点
*param[in]:链表的头结点
*param[out]:none
*/
extern int DelListEnd(NODE *plistHead);

/**************************
*函数功能:在链表头部添加结点
*param[in]:待添加的结点
*param[in]:链表的头结点
*param[out]:none
*/
extern int AddListHead(NODE *pnode,NODE *plistHead);

/**************************
*函数功能:删除头部链表结点
*param[in]:链表的头结点
*param[out]:none
*/
extern int DelListHeadNode(NODE *plistHead);


/**************************
*函数功能:删除链表的指定结点
*param[in]:待删除的结点
*param[in]:链表的头结点
*param[out]:none
*/
extern int DelListNode(NODE *pnode,NODE *plistHead);

/**************************
*函数功能:统计链表长度
*param[in]:链表的头结点
*param[out]:plistNum，链表的长度
*/
extern int GetListCnt(NODE *plistHead);

/**************************
*函数功能:遍历链表
*param[in]:链表的头结点
*param[out]:none
*/
extern int ShowList(NODE *plistHead);

/**************************
*函数功能:将链表按照value从小到大排序
*param[in]:链表的头结点
*param[out]:none
*/
extern int SortList(NODE *plistHead);

/**************************
*函数功能:按照从小到大的顺序插入结点
*param[in]:待插入的结点
*param[in]:链表的头结点
*param[out]:none
*/
extern int InsertList(NODE *pnode,NODE *plistHead);

#endif

