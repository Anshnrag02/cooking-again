/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    unordered_map<Node*,Node*>dc;
    
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node*head2=head;
        while(head2){
            Node* copyNode = new Node(head2->val);
            copyNode->next=head2->next;
            head2->next = copyNode;
            head2 = copyNode->next;
        }
        Node*head3=head->next;
        head2 = head;
        while(head2) {
            if (head2->random)
                head2->next->random = head2->random->next;
            head2 = head2->next->next; 
        }
        head2=head;
        while(head2) {
            Node* temp = head2->next;
            head2->next = temp->next;
            if (temp->next) temp->next = temp->next->next;
            head2 = head2->next;
        }
        return head3;
    }
};
