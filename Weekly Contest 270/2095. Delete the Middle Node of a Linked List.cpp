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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*slow=head,*fast=head,*prev;
        int cnt=0;
        while(fast!=0 and fast->next!=0){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
            cnt++;
        }
        if(cnt==0)return 0;
        prev->next=slow->next;
        return head;
    }
};
