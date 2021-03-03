#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
	vector<int> sums;
	/// <summary>
	/// ���Ӷȷ���

	/// ʱ�临�Ӷȣ���ʼ�� O(n)O(n)��ÿ�μ��� O(1)O(1)������ nn ������ \textit{ nums }nums �ĳ��ȡ�
	///	��ʼ����Ҫ�������� \textit{ nums }nums ����ǰ׺�ͣ�ʱ�临�Ӷ��� O(n)O(n)��
	///	ÿ�μ���ֻ��Ҫ�õ������±괦��ǰ׺�ͣ�Ȼ������ֵ��ʱ�临�Ӷ��� O(1)O(1)��

	///	�ռ临�Ӷȣ�O(n)O(n)������ nn ������ \textit{ nums }nums �ĳ��ȡ���Ҫ����һ������Ϊ n + 1n + 1 ��ǰ׺�����顣
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
