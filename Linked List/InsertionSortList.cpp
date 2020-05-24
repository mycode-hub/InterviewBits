/*Insertion Sort List
Asked in:  
Microsoft
Google
Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3*/



  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode* Solution::insertionSortList(ListNode* head) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(!head) return head;
        if(!head->next) return head;

        ListNode *sorted = NULL;
        ListNode *list = head,*curr;
    
        while(list) {
            curr = list;
            list = list->next;
            if(sorted == NULL || sorted->val > curr->val) {
                // first lookup
            
                curr->next = sorted; //this indicates the end of sorted list
                sorted = curr;
            } 
            else 
            {
                ListNode * tmp=sorted;
                while(tmp ->next  && tmp->next-> val  < curr->val)
                {
                    tmp=tmp->next;
                }
                curr->next=tmp->next;
                tmp->next=curr;
                
                
            }
        }
        return sorted;
}
  
