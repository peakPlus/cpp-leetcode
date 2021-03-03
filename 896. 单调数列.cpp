#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/// <summary>
	/// 时间复杂度：O(n)，其中 nn 是数组 AA 的长度。
	///	空间复杂度：O(1)。
	/// </summary>
	/// <param name="A"></param>
	/// <returns></returns>
	bool isMonotonic(vector<int>& A) {
		int n = A.size();
		if (A[0] < A[n - 1]) {
			for (int i = 1; i < n; i++) {
				if (A[i - 1] > A[i]) {
					return false;
				}
			}
			return true;
		}
		else {
			for (int i = 1; i < n; i++) {
				if (A[i - 1] < A[i]) {
					return false;
				}
			}
			return true;
		}
	}
};

//int main()
//{
//	vector<int> arr = { 1 };
//	Solution s;
//	bool isMonotonicArr = s.isMonotonic(arr);
//	cout << isMonotonicArr;
//	return 0;
//}
