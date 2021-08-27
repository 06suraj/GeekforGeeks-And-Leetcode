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
    ListNode* rotateRight(ListNode* head, int k) {
        int cnt=0;
        if(head==0)return 0;
        ListNode*temp=head;
        while(temp and ++cnt)temp=temp->next;
        k=k%cnt;
        if(k==0)return head;
        k=cnt-k;
        temp=head;
        k--;
        while(k>0)
         {
            temp=temp->next;
            k--;
         }
        ListNode*temp1=temp->next;
        while(temp1->next!=0)temp1=temp1->next;
        temp1->next=head;
        head=temp->next;
        temp->next=0;
        return head;
       }
};
