#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = head;
		ListNode* pre = dummyNode;
		for (int i = 1; i < left; i++) {
			pre = pre->next;
		}
		ListNode* cur = pre->next;
		ListNode* next;
		for (int i = left; i < right; i++) {
			next = cur->next;
			cur->next = next->next;
			next->next = pre->next;
			pre->next = next;
		}
		return dummyNode->next;
	}
};


//int main()
//{
//	//Your MyQueue object will be instantiated and called as such:
//	ListNode* head1 = new ListNode(1);
//	head1->next = new ListNode(2);
//	head1->next->next = new ListNode(3);
//	head1->next->next->next = new ListNode(4);
//	head1->next->next->next->next = new ListNode(5);
//	head1->next->next->next->next->next = nullptr;
//	Solution s;
//	ListNode* head = s.reverseBetween(head1,2, 4);
//	cout << head->val << "->" << head->next->val << "->" << head->next->next->val << "->" << head->next->next->next->val << "->" << head->next->next->next->next->val << endl;
//	return 0;
//}
