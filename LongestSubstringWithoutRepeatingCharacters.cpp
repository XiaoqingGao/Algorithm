#include <iostream>
#include <cstdlib>
using namespace std;
class Solution {
public:
	string s;
public:
	int lengthOfLongestSubstring(string s) {
		int i = 0;
		int j = 0;
		int n = s.length();
		cout << n << endl;
		int length = 0;
		bool mark[500] = {false};
		while(j < n) {
			if(mark[s[j]]) {
				length = max(length,j-i);
				while(s[i] != s[j]) {
					mark[s[i]] = false;
					i++;
				}
				i++;
				j++;
			} else {
				mark[s[j]] = true;
				j++;
			}
		}
		length = max(length, n-i);
		return length;
	}
};
int main()
{
	Solution t;
	t.s = "abcabcbb";
	cout << t.lengthOfLongestSubstring(t.s) << endl;
	system("pause");
	return 0;
}