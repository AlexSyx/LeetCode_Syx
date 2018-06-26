#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int sum;
		sum = l1->val + l2->val;
		ListNode* lbegin = new ListNode(sum%10);
		ListNode* l = lbegin;
		int jinwei=sum/10;
		l1 = l1->next;
		l2 = l2->next;
		while ((l1 != NULL) && (l2 != NULL))
		{
			sum = l1->val + l2->val + jinwei;
			ListNode* ltemp = new ListNode(sum % 10);
			jinwei = sum / 10;
			l->next = ltemp;
			l = ltemp;		
			l1 = l1->next;
			l2 = l2->next;
		}
		if (l1 != NULL)
		{
			while (l1!=NULL)
			{
				sum = l1->val + jinwei;
				ListNode* ltemp = new ListNode(sum % 10);
				jinwei = sum / 10;
				l->next = ltemp;
				l = ltemp;
				l1 = l1->next;
			}
		}
		else if(l2!=NULL){
			while (l2 != NULL)
			{
				sum = l2->val + jinwei;
				ListNode* ltemp = new ListNode(sum % 10);
				jinwei = sum / 10;
				l->next = ltemp;
				l = ltemp;
				l2 = l2->next;
			}

		}
		if (jinwei != 0)
		{
			ListNode* ltemp = new ListNode(1);
			l->next = ltemp;
		}

		return lbegin;
	}
} solution;
int main()
{
	
	
	int c = 5555555;
	ListNode* lbegin=new ListNode(c %10);
	ListNode* l = lbegin;
	c = c / 10;
	while (c != 0)
	{
		ListNode* ltemp = new ListNode(c % 10);
		c = c / 10;
		l->next = ltemp;
		l = ltemp;
	}

	ListNode* lresult=solution.addTwoNumbers(lbegin, lbegin);
	int a = 0;
	int ten = 1;
	while (lresult != NULL)
	{
		a = a + lresult->val*ten;
		ten = ten * 10;
		lresult = lresult->next;
	}
	cout << a;

}