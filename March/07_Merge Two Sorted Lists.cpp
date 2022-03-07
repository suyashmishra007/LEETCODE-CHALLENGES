class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (!list1) return list2;
        if (!list2) return list1;

        ListNode *head = NULL , *tail = NULL ;

        if (list1->val > list2->val) {
            head = tail = list2 ;
            list2 = list2->next;
        } else {
            head = tail = list1 ;
            list1 = list1->next;
        }

        while (list1 and list2) {
            if (list1->val > list2->val) {
                tail->next = list2 ;
                tail = list2;
                list2 = list2->next;
            } else {
                tail->next = list1 ;
                tail = list1;
                list1 = list1->next;
            }
        }

        if (list1) {
            tail->next = list1;
        }

        if (list2) {
            tail->next = list2;
        }

        return head;
    }
};