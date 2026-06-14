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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int minval = INT_MAX;
        int idx = -1;
        for(int i = 0  ; i <lists.size(); ++i){ 
            if(lists[i]){
                if(minval > lists[i]->val){
                    idx = i;
                    minval = lists[i]->val;
                }
            }
        }
        if(idx==-1){
            return nullptr;
        }
        ListNode* ans = new ListNode(minval);
        lists[idx] = lists[idx]->next;
        ans->next = mergeKLists(lists);
        return ans;
    }
};
