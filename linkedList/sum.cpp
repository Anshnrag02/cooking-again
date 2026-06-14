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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        if (!l1 and !l2){
            if (carry){
                cout<<"hjejejeje";
                return new ListNode(carry);
            }
            return nullptr;
        }
        if(!l1){
            return new ListNode((l2->val + carry)%10,addTwoNumbers(l1,l2->next,(l2->val + carry)/ 10));
        }
        if (!l2){
            return new ListNode((l1->val + carry)%10,addTwoNumbers(l1->next,l2,(l1->val + carry) / 10));
        }
        ListNode* sum = new ListNode((l1->val + l2->val + carry) % 10);
        sum -> next = addTwoNumbers(l1 -> next,l2 -> next,(l1->val + l2->val + carry) / 10);
        return sum;
    }
};
