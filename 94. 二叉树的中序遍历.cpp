#include <iostream>
#include <vector>
#include <stack>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>  res;
        stack<TreeNode*> stack;
        TreeNode* p = root;
        while (p || !stack.empty()) {
            if (p) {
                stack.push(p);
                p = p->left;
            }
            else {
                p = stack.top();
                stack.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
};


//int main()
//{
//	//Your MyQueue object will be instantiated and called as such:
//
//	Solution s;
//	//ListNode* head = s.reverseBetween(head1,2, 4);
//	return 0;
//}
