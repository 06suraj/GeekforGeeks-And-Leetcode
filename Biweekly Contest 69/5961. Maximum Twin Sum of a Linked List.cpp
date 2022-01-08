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
    int pairSum(ListNode* head) {
        vector<ListNode*>address;
        ListNode*temp=head;
        while(temp){
            address.push_back(temp);
            temp=temp->next;
        }
     temp=head;
       int j=address.size()-1,s=0;
        while(j>=(address.size())/2){
            s=max(s,temp->val+address[j]->val);
            temp=temp->next;
            j--;
        }
        return s;
    }
};
