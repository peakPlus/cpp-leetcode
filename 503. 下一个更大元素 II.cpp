#include <iostream>
#include <vector>
#include <stack>

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec)
{
    os << "{";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(os, ","));
    os << "}";
    return os;
}
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        stack<int> stk;
        for (int i = 0; i < n * 2 - 1; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                ret[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ret;
    }
};

//int main()
//{
//	//Your MyQueue object will be instantiated and called as such:
//	Solution s;
//	vector<int> nums = { 1,2,1 };
//    vector<int> num = s.nextGreaterElements(nums);
//	cout << num << endl;
//	return 0;
//}
