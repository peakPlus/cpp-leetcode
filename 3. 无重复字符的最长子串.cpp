#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> hashtable;
		int n = s.length(), ans = 0;
		for (int start = 0, end = 0; end < n; end++) {
			char c = s[end];
			if (hashtable.find(c) != hashtable.end()) {
				start = max(hashtable[c], start); 
			}
			ans = max(end - start + 1, ans);
			hashtable[c] = end + 1;
		}
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	string str = "abcabcbb";
//	int n = s.lengthOfLongestSubstring(str);
//	cout << n << endl;
//	return 0;
//}
