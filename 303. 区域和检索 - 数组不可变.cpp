#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
	vector<int> sums;
	/// <summary>
	/// 复杂度分析

	/// 时间复杂度：初始化 O(n)O(n)，每次检索 O(1)O(1)，其中 nn 是数组 \textit{ nums }nums 的长度。
	///	初始化需要遍历数组 \textit{ nums }nums 计算前缀和，时间复杂度是 O(n)O(n)。
	///	每次检索只需要得到两个下标处的前缀和，然后计算差值，时间复杂度是 O(1)O(1)。

	///	空间复杂度：O(n)O(n)，其中 nn 是数组 \textit{ nums }nums 的长度。需要创建一个长度为 n + 1n + 1 的前缀和数组。
	/// </summary>
	/// <param name="nums"></param>
	NumArray(vector<int>& nums) {
		int n = nums.size();
		sums.resize(n + 1);
		for (int i = 0; i < n; i++) {
			sums[i + 1] = sums[i] + nums[i];
		}
	}

	int sumRange(int i, int j) {
		return sums[j+1] - sums[i];
	}
};

//int main()
//{
//	vector<int> nums = { -2, 0, 3, -5, 2, -1 };
//	int target = 9;
//	NumArray numArray(nums);
//	//NumArray* numArray = new NumArray(nums);
//	cout << numArray.sumRange(0, 2) << endl;
//	cout << numArray.sumRange(2, 5) << endl;
//	cout << numArray.sumRange(0, 5) << endl;
//	return 0;
//}
