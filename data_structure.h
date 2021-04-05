#pragma once
#ifndef _GLOBAL_H
#define _GLOBAL_H
#include <iostream>

using namespace std;
//struct LinkNode {
//	int data;
//	struct LinkNode* next;
//};

typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode, * LinkList;
// ��struct ListNode������ΪLinkNode, *LinkList
// LinkNode*ָ����ڵ�
// LinkListָһ����������

// ��ӡ������
void PrintList(LinkList& L) {
	LinkNode* p = L->next;
	while (p->next != NULL) {
		cout << p->data << "->";
		p = p->next;
	}
	cout << p->data << endl;
}

// ����ͷ�ڵ�ĵ�����
bool InitNoneHeadLinkNode(LinkList &L) {
	L = NULL;
	return true;
}

// ��ͷ�ڵ�ĵ�����
bool InitHaveHeadLinkNode(LinkList& L) {
	L = (LinkNode *) malloc(sizeof(LinkNode));
	if (L == NULL) {
		return false;
	}
	L->next = NULL;
	return true;
}

// ������λ����루��ͷ��㣩
bool ListInsert(LinkList& L, int i, int e) {
	if(i < 1) {
		return false;
	}

	LinkNode* p;
	int j = 0;
	p = L;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	// ���滻�������
	// LinkNode* p = GetElem(L, i - 1);

	if(p == NULL) {
		return false;
	}
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;

	// ���滻�������
	// return InsertNextNode(p, e);
}

// ������λ����루����ͷ��㣩
//bool ListInsert(LinkList& L, int i, int e) {
//	if (i < 1) {
//		return false;
//	}
//	if (i == 1) {
//		LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
//		s->data = e;
//		s->next = L;
//		L = s;
//		return true;
//	}
//	LinkNode* p;
//	int j = 0;
//	p = L;
//	while (p != NULL && j < i - 1) {
//		p = p->next;
//		j++;
//	}
//	if (p == NULL) {
//		return false;
//	}
//	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
//	s->data = e;
//	s->next = p->next;
//	p->next = s;
//	return true;
//}

// ָ���ڵ�ĺ�����
bool InsertNextNode(LinkNode* p, int e) {
	if(p == NULL) {
		return false;
	}
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL) {
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

// ָ���ڵ��ǰ�����
bool InsertPriorNode(LinkNode* p, int e) {
	if (p == NULL) {
		return false;
	}
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL) {
		return false;
	}
	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	return true;
}

// ָ���ڵ��ǰ�����(����ڵ�)
//bool InsertPriorNode(LinkNode* p, LinkNode *s) {
//	if (p == NULL || s == NULL) {
//		return false;
//	}
//	s->next = p->next;
//	p->next = s;
//	int temp = s->data;
//	s->data = p->data;
//	p->data = temp;
//	return true;
//}

// ��λ��ɾ��(��ͷ���)
bool ListDelete(LinkList &L, int i, int &e) {
	if (i < 1) {
		return false;
	}

	LinkNode* p = L;
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	// ���滻�������
	// LinkNode* p = GetElem(L, i - 1);

	if (p == NULL || p->next == NULL) {
		return false;
	}
	LinkNode* q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return true;
}

// ɾ��ָ���ڵ�p�����ڵ�Ϊ���һ���ڵ� ���д���Ӧʹ�ô�ͷ���ҽڵ�ķ�ʽɾ����
bool DeleteNode(LinkNode* p) {
	if (p == NULL) {
		return false;
	}
	LinkNode* q = p->next;
	p->data = p->next->data;
	p->next = q->next;
	free(q);
	return true;
}

// ��λ����
LinkNode* GetElem(LinkList &L, int i) {
	if (i < 1) {
		return NULL;
	}
	LinkNode* p = L;
	int j = 0;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

// ��ֵ����
LinkNode* LocateElem(LinkList &L, int e) {
	LinkNode* p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}

// �����
int Length(LinkList &L) {
	int len = 0;
	LinkNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

// β�巨����������
LinkList List_TailInsert(LinkList& L) {
	int x;
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;
	LinkNode* s, * r = L;
	cin >> x;
	while (x != 9999) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = x;
		r->next = s;
		r = s;
		cin >> x;
	}
	r->next = NULL;
	return L;
}

// ͷ�巨����������
LinkList List_HeadInsert(LinkList& L) {
	int x;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	LinkNode* s;
	cin >> x;
	while (x != 9999) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
	return L;
}
#endif