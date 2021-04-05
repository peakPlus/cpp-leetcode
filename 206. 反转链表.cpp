#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution1 {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;
		while (curr) {
			ListNode* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		ListNode* ret = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return ret;
	}
};


//int main()
//{
//	//Your MyQueue object will be instantiated and called as such:
//	ListNode* head1 = new ListNode(2);
//	head1->next = new ListNode(4);
//	head1->next->next = new ListNode(3);
//	Solution s;
//	Solution s1;
//	ListNode* head = s.reverseList(head1);
//	cout << head->val << "->" << head->next->val << "->" << head->next->next->val << endl;
//	head = s1.reverseList(head);
//	cout << head->val << "->" << head->next->val << "->" << head->next->next->val << endl;
//
//	return 0;
//}
