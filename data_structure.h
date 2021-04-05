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
// 将struct ListNode重命名为LinkNode, *LinkList
// LinkNode*指链表节点
// LinkList指一整个单链表

// 打印单链表
void PrintList(LinkList& L) {
	LinkNode* p = L->next;
	while (p->next != NULL) {
		cout << p->data << "->";
		p = p->next;
	}
	cout << p->data << endl;
}

// 不带头节点的单链表
bool InitNoneHeadLinkNode(LinkList &L) {
	L = NULL;
	return true;
}

// 带头节点的单链表
bool InitHaveHeadLinkNode(LinkList& L) {
	L = (LinkNode *) malloc(sizeof(LinkNode));
	if (L == NULL) {
		return false;
	}
	L->next = NULL;
	return true;
}

// 单链表按位序插入（带头结点）
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
	// 可替换上面代码
	// LinkNode* p = GetElem(L, i - 1);

	if(p == NULL) {
		return false;
	}
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;

	// 可替换上面代码
	// return InsertNextNode(p, e);
}

// 单链表按位序插入（不带头结点）
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

// 指定节点的后插操作
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

// 指定节点的前插操作
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

// 指定节点的前插操作(传入节点)
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

// 按位序删除(带头结点)
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
	// 可替换上面代码
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

// 删除指定节点p（若节点为最后一个节点 会有错误，应使用从头查找节点的方式删除）
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

// 按位查找
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

// 按值查找
LinkNode* LocateElem(LinkList &L, int e) {
	LinkNode* p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}

// 求表长度
int Length(LinkList &L) {
	int len = 0;
	LinkNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

// 尾插法建立单链表
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

// 头插法建立单链表
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