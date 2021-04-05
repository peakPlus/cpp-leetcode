#include "data_structure.h"

int main()
{
	LinkList linkList;
	//InitNoneHeadLinkNode(linkList);
	//��ʼ����ͷ���ĵ�����
	InitHaveHeadLinkNode(linkList);
	int arr[7] = { 1, 2, 3, 4, 5, 6,7 };
	for (int i = 1; i <= sizeof(arr) / sizeof(int); i++) {
		// ��λ���������1-7
		ListInsert(linkList, i, arr[i-1]);
	}
	// ������0
	InsertNextNode(linkList, 0);
	// ǰ�����-1
	InsertPriorNode(linkList->next, -1);
	int n = 0;
	// ��λ��ɾ��-1
	ListDelete(linkList, 1, n);
	// ɾ���ڵ�0
	DeleteNode(linkList->next);
	// ��ӡ����
	PrintList(linkList);
	// ��λ����
	cout << GetElem(linkList, 5)->data <<endl;
	// ��ֵ����
	cout << LocateElem(linkList, 5)->data << endl;
	// ���ĳ���
	cout << Length(linkList) << endl;
	// β�巨��������
	/*LinkList linkTailInsertList;
	List_TailInsert(linkTailInsertList);
	PrintList(linkTailInsertList);*/
	// ͷ�巨��������
	LinkList linkTHeadInsertList;
	List_HeadInsert(linkTHeadInsertList);
	PrintList(linkTHeadInsertList);

	return 0;
}
