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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = 0;
        ListNode*temp = head;
        while(1) {
            if (!temp) break;
            ++k;
            temp = temp->next;
        }
        k = k - n;
        cout<<k;
        if (k == 0) {
            return head->next;
        }
        temp = head;
        while(1) {
            cout<<k;
            if (k == 1){
                ListNode*deltptr = temp->next;
                temp->next = temp->next->next;
                delete deltptr;
                break;
            }
            --k;
            temp = temp->next;
        }
        return head;
    }
};
