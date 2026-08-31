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
        vector<int> ans(2,-1);
        vector<int> criticalPoints;
        int size=1;
        ListNode* temp =head->next;
        int prev =head->val;
        while(temp!=NULL){
            if((temp->next) && ((temp->val>prev && temp->val>temp->next->val) || (temp->val<prev &&temp->val < temp->next->val))){
                criticalPoints.push_back(size+1);

            }
            prev=temp->val;
            temp=temp->next;
            size++;
        }
        if(criticalPoints.size()<=1){
            return ans;
        }
        int s= criticalPoints.size();
        ans[1]=criticalPoints[s-1]-criticalPoints[0];
        int mini=1e9;
        for(int i=0;i<s-1;i++){
            if(criticalPoints[i+1]-criticalPoints[i] < mini){
                mini=criticalPoints[i+1]-criticalPoints[i];
            }
        }
        ans[0]=mini;
        return ans;

    }
};