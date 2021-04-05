//struct LinkNode {
//	int data;
//	struct LinkNode* next;
//};

typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode, *LinkList;
// 将struct ListNode重命名为LinkNode, *LinkList
// LinkNode*指链表节点
// LinkList指一整个单链表