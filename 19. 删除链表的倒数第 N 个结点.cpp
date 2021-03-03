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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(0, head);

		ListNode* first = dummy;
		ListNode* second = dummy;
		for (int i = 0; i < n; i++) {
			second = second->next;
		}
		while (second) {
			first = first->next;
			second = second->next;
		}
		first->next = first->next->next;
		return dummy->next;
	}
};

int main()
{
	Solution s;
	//vector<int> subs = s.addTwoNumbers(nums, target);
	ListNode* head1 = new ListNode(1);
	head1->next = new ListNode(2);
	head1->next->next = new ListNode(3);
	head1->next->next->next = new ListNode(4);
	head1->next->next->next->next = new ListNode(5);
	ListNode* head = s.removeNthFromEnd(head1, 2);
	cout << head->val << "->" << head->next->val << "->" << head->next->next->val << endl;
	return 0;
}
