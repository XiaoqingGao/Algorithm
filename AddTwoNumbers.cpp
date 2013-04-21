#include <iostream>
#include <cstdlib>
using namespace std;
	struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
	};
class Solution {
public:

public:
	ListNode *inita() {
		ListNode *a = new ListNode(9);
		ListNode *b = new ListNode(9);
		a->next = b;
		return a;
	}
	ListNode *initb() {
		ListNode *b = new ListNode(1);
		return b;
	}
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *s = new ListNode(0);
		ListNode *c = s;
		bool f1 = (NULL != l1);
		bool f2 = (NULL != l2);
		while(1) {
			if(f1) {
				c->val += l1->val;
				l1 = l1->next;
				f1 = (NULL != l1);
			}
			if(f2) {
				c->val += l2->val;
				l2 = l2->next;
				f2 = (NULL != l2);
			}
			bool carry = c->val / 10;
			c->val %= 10;
			if(f1 || f2 || carry) {
				c->next = new ListNode(carry);
				c = c->next;
			} else
				break;
		}
		return s;
	}

};
int main() {
	Solution t;
	ListNode *c = t.addTwoNumbers(t.inita(), t.initb());
	while(c) {
		cout << c->val << endl;
		if(!c->next)
			break;
		c = c->next;
	}
	system("pause");
	return 0;
}