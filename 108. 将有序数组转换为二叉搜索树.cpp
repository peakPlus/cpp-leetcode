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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        // 总是选择中间位置左边的数字作为根节点
        int mid = (left + right) / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
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
