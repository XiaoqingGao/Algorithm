#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Solution {
public:
	string s;
public:
	string longestPalindrome(string s) {
		bool dp[1000][1000];
		int max = 0;
		int start;
		int end;
		if(s.length() != 1) {
			for(int i = 1; i < s.length(); i++) {
				if(s[i] != s[i-1]) {
					dp[i][i-1] = false;
				} else {
					dp[i][i-1] = true;
				}
			}
		}
		int j;
		for(int m = 1; m < s.length()+1; m++)
			for(int i = 0; i < s.length()-m+1; i++) {
				 j = i+m-1;
				 if(i == j || (s[i] == s[j] && dp[i+1][j-1] == true)) {
					 dp[i][j] = true;
					 if(max < m) {
						 max = m;
						 start = i;
					 }
				 } else {
					 dp[i][j] = false;
				 }
			}
		return s.substr(start, max);
	}
};
int main() {
	Solution t;
	t.s = "abb";
	cout << t.longestPalindrome(t.s) << endl;
	system("pause");
	return 0;
}