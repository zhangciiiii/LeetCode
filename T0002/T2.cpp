#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head, *p;
	    head = new ListNode(0);
	    p = head;
        int carry = 0;

        while (l1 != NULL && l2 != NULL)
        {
            ListNode *new_node;
            new_node = new ListNode(0);
            p->next = new_node;
            p = new_node;

            p->val = (l1->val + l2->val + carry)%10;
            carry = (l1->val + l2->val + carry)/10;
            l1 = l1->next;
            l2 = l2->next;


        }

        if (l1 == NULL && l2 == NULL && carry != 1)
        {
            p->next = NULL;
            return head->next;
        }

        if (l1 == NULL && l2 == NULL && carry == 1 )
        {
            ListNode *new_node;
            new_node = new ListNode(0);
            p->next = new_node;
            p = new_node;
            p->val = 1;
            p->next=NULL;
            return head->next;
        }

        ListNode *remain_num;
        if (l1 == NULL)
            remain_num = l2;

        else            
            remain_num = l1;

        while (remain_num != NULL)
        {
            ListNode *new_node;
            new_node = new ListNode(0);
            p->next = new_node;
            p = new_node;

            p->val = (remain_num->val + carry)%10;
            carry = (remain_num->val + carry)/10;
            remain_num = remain_num->next;
        }

        if(carry==1)
        {
            ListNode *new_node;
            new_node = new ListNode(0);
            p->next = new_node;
            p = new_node;
            p->val = 1;
            p->next=NULL;
            return head->next;
        }
        else 
        {
            p->next = NULL;
            return head->next;
        }

    }

};

int main ()
{
    ListNode *head1, *head2, *p;
    head1=new ListNode(2);
    head2=new ListNode(5);
    p = head1;


    ListNode *new_node;
    new_node = new ListNode(0);
    new_node->val = 4;
    p->next = new_node;
    p = p->next;
    
    p = head1;
    while(p!=NULL)
    {

        cout<<p->val<<endl;
        p = p->next;
    }

    return 0;
}
