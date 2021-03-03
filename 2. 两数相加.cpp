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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode * p, *head;
		head  = p = new ListNode(0);

		int carry = 0;

		while (l1 || l2) {
			int l1Val = l1? l1->val : 0;
			int l2Val = l2 ? l2->val : 0;
			int sumVal  = l1Val + l2Val + carry;
			carry = sumVal >= 10 ? 1 : 0;
			ListNode* sumNode = new ListNode(sumVal % 10);
			p->next = sumNode;
			p = sumNode;
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
		}
		if (carry > 0) {
			p->next = new ListNode(carry);
		}
		return head->next;
	}
};

//int main()
//{
//	Solution s;
//	//vector<int> subs = s.addTwoNumbers(nums, target);
//	ListNode* head1 = new ListNode(2);
//	head1->next = new ListNode(4);
//	head1->next->next = new ListNode(3);
//	ListNode* head2 = new ListNode(5);
//	head2->next = new ListNode(6);
//	head2->next->next = new ListNode(4);
//	ListNode* head = s.addTwoNumbers(head1, head2);
//	cout << head->val << "->" << head->next->val << "->" << head->next->next->val << endl;
//	return 0;
//}
