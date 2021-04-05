#include <iostream>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        else {
            return max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        cout << height(root) << endl;
        return height(root) >= 0;
    }
};

//int main()
//{
//    //Your MyQueue object will be instantiated and called as such:
//    TreeNode* _tree1 = new TreeNode(1);
//    TreeNode* _tree3 = new TreeNode(3);
//    TreeNode* _tree6 = new TreeNode(6);
//    TreeNode* _tree9 = new TreeNode(9);
//    TreeNode* _tree2 = new TreeNode(2, _tree1, _tree3);
//    TreeNode* _tree7 = new TreeNode(7, _tree6, _tree9);
//    TreeNode* _tree4 = new TreeNode(4, _tree2, _tree7);
//    Solution s;
//    bool flag = s.isBalanced(_tree4);
//    cout << flag;
//    return 0;
//}
