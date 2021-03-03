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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) {
			return l2;
		} if (l2 == nullptr) {
			return l1;
		}
		if (l1->val > l2->val) {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}else {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
	}
};

//int main()
//{
//	Solution s;
//	//vector<int> subs = s.addTwoNumbers(nums, target);
//	ListNode* head1 = new ListNode(1);
//	head1->next = new ListNode(2);
//	head1->next->next = new ListNode(4);
//	ListNode* head2 = new ListNode(1);
//	head2->next = new ListNode(3);
//	head2->next->next = new ListNode(4);
//	ListNode* head = s.mergeTwoLists(head1, head2);
//	cout << head->val << "->" << head->next->val << "->" << head->next->next->val << endl;
//	return 0;
//}
