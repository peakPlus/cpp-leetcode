#include <iostream>
#include <queue>
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
    /// <summary>
    /// ≤„–Ú±È¿˙
    /// </summary>
    /// <param name="root"></param>
    /// <returns></returns>
    int BFS(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q; q.push(root);
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            int sz = q.size();
            while (sz--) {
                TreeNode* x = q.front();
                q.pop();
                if (x->left) q.push(x->left);
                if (x->right) q.push(x->right);
            }
        }
        return ans;
    }
    /// <summary>
    /// ∫Û–Ú±È¿˙
    /// </summary>
    /// <param name="root"></param>
    /// <returns></returns>
    int DFS(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = DFS(root->left);
        int rightHeight = DFS(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    int maxDepth(TreeNode* root) {
        return BFS(root);
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
//    int height = s.maxDepth(_tree4);
//    cout << height;
//    return 0;
//}
