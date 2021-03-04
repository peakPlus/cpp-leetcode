#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		if (envelopes.empty()) {
			return 0;
		}

		int n = envelopes.size();
		sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
			return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
		});
		vector<int> f = { envelopes[0][1] };
		for (int i = 1; i < n; ++i) {
			int num = envelopes[i][1];
			if ( num > f.back()) {
				f.push_back(num);
			}
			else {
				auto it = lower_bound(f.begin(), f.end(), num);
				*it = num;
			}
		}
		return f.size();
	}
};

//int main()
//{
//	vector<vector<int>> envelopes = { {5, 4}, {6, 5}, {6, 7},{8, 7}, {2, 3} };
//	Solution s;
//	int n = s.maxEnvelopes(envelopes);
//	cout << n << endl;
//	return 0;
//}
