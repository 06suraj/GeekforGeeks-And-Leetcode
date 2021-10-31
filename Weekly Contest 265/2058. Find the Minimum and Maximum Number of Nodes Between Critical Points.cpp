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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>critical;
        int cnt=2;
        ListNode*curr=head->next,*prev=head;
        if(curr==0)return {-1,-1};
        while(curr->next){
            if(curr->val>prev->val and curr->val>curr->next->val)critical.push_back(cnt);
            if(curr->val<prev->val and curr->val<curr->next->val)critical.push_back(cnt);
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        sort(critical.begin(),critical.end());
        if(critical.size()<=1)return {-1,-1};
        int largest=critical[critical.size()-1]-critical[0],smallest=INT_MAX;
        for(int i=0;i<critical.size()-1;i++)smallest=min(smallest,critical[i+1]-critical[i]);
        return {smallest,largest};
    }
};
