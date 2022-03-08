
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if ( !head or !head->next) {
            return 0;
        }

        ListNode *slow = head , *fast = head;

        while (fast and fast->next) {
            slow = slow->next ;
            fast = fast->next->next ;

            if (slow == fast) {
                return 1 ;
            }
        }
        return 0 ;
    }
};