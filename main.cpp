#include "data_structure.h"

int main()
{
	LinkList linkList;
	//InitNoneHeadLinkNode(linkList);
	//初始化带头结点的单链表
	InitHaveHeadLinkNode(linkList);
	int arr[7] = { 1, 2, 3, 4, 5, 6,7 };
	for (int i = 1; i <= sizeof(arr) / sizeof(int); i++) {
		// 按位序插入数据1-7
		ListInsert(linkList, i, arr[i-1]);
	}
	// 后插插入0
	InsertNextNode(linkList, 0);
	// 前插插入-1
	InsertPriorNode(linkList->next, -1);
	int n = 0;
	// 按位序删除-1
	ListDelete(linkList, 1, n);
	// 删除节点0
	DeleteNode(linkList->next);
	// 打印链表
	PrintList(linkList);
	// 按位查找
	cout << GetElem(linkList, 5)->data <<endl;
	// 按值查找
	cout << LocateElem(linkList, 5)->data << endl;
	// 求表的长度
	cout << Length(linkList) << endl;
	// 尾插法建立链表
	/*LinkList linkTailInsertList;
	List_TailInsert(linkTailInsertList);
	PrintList(linkTailInsertList);*/
	// 头插法建立链表
	LinkList linkTHeadInsertList;
	List_HeadInsert(linkTHeadInsertList);
	PrintList(linkTHeadInsertList);

	return 0;
}
