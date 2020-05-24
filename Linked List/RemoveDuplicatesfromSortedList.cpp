/* Remove Duplicates from Sorted List
Asked in:  
Microsoft
VMWare
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. */



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode * p,*q=A;
    while( q && q->next )
    {
        p=q->next;
        if(p->val==q->val)
        {
            q->next=p->next;
            free(p);
          //  p=q->next;
        }
        else
        {
            q=p;
        }
    }
    return A;
}
