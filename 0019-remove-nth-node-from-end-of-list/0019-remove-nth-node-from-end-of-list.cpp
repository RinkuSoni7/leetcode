/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
int getlength(ListNode*head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;

    }
    return count;

}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int sum=getlength(head);

        if(n==sum){
            ListNode*temp=head->next;
            delete(head);

            return temp;

        }

        int len=sum-n;
        ListNode*curr=head;
        ListNode*prev=NULL;

        while(len--){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        delete (curr);

        return head;

    }
    
};