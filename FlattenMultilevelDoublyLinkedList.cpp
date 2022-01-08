class Solution {
public:
    Node* flatten(Node* head) {
        for (Node* h = head; h; h = h->next) {
            if (h->child) {
                // Save NEXT pointer
                Node* next = h->next;
                // Point curr's next to curr's child
                h->next = h->child;
                h->next->prev = h;
                // Remove curr's 'child'
                h->child = NULL;
                // Reach last node of curr's child
                Node* p = h->next;
                while (p->next) {
                    p = p->next;
                }
                // Link last node of child to curr's next
                p->next = next;
                if(next) {
                    next->prev = p;
                }
            }
        }
        return head;
    }
};