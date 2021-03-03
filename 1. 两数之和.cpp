#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	/// <summary>
	/// ���Ӷȷ���
	///	ʱ�临�Ӷȣ�O(N)������ N �������е�Ԫ������������ÿһ��Ԫ�� x�����ǿ��� O(1) ��Ѱ�� target - x��
	///	�ռ临�Ӷȣ�O(N)������ N �������е�Ԫ����������ҪΪ��ϣ��Ŀ�����
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
