#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	/// <summary>
	/// 复杂度分析
	///	时间复杂度：O(N)，其中 N 是数组中的元素数量。对于每一个元素 x，我们可以 O(1) 地寻找 target - x。
	///	空间复杂度：O(N)，其中 N 是数组中的元素数量。主要为哈希表的开销。
	/// </summary>
	/// <param name="nums"></param>
	/// <param name="target"></param>
	/// <returns></returns>
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hashtable;
		for (int i = 0; i < nums.size(); i++) {
			auto it = hashtable.find(target - nums[i]);
			if (it != hashtable.end()) {
				return { it->second, i };
			}
			hashtable[nums[i]] = i;
		}

		return {};
	}
};

//int main()
//{
//	vector<int> nums = { 2,7,11,15 };
//	int target = 9;
//	Solution s;
//	vector<int> subs = s.twoSum(nums, target);
//	cout << subs[0] << "," << subs[1] << endl;
//	return 0;
//}
