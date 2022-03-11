    /**
     * Definition for singly-linked list.
     * struct ListListNode {
     *     int val;
     *     ListListNode *next;
     *     ListListNode() : val(0), next(nullptr) {}
     *     ListListNode(int x) : val(x), next(nullptr) {}
     *     ListListNode(int x, ListListNode *next) : val(x), next(next) {}
     * };
     */
    class Solution {

    public:
        int getlen(ListNode * list) {
            int len = 0 ;
            while (list != NULL) {
                len += 1 ;
                list = list->next;
            }
            return len;
        }
        ListNode* rotateRight(ListNode* head, int k) {

            //  Two cases
            // case 1-> k < len of list
            // case 2-> k >= len of list , then k = k % len of list

            // overall question comes into case 1

            // Code :
            // 1. Find the len of list
            // 2. mark the last node next to head , like circular linked list
            // 3. k = len -  k
            // 4. for(i = 0 , i < k ; ++i) prev = curr ; curr = curr->next;
            // prev ->next = NULL , return curr

            // egde cases
            if (!head or !head->next or k == 0) {
                return head ;
            }

            // compute the len
            ListNode * curr = head ;
            int len  = 1 ;
            while (curr->next and ++len) {
                curr = curr->next ;
            }

            // go till that node 
            curr->next = head ;
            k = k % len ;
            k = len - k ;
            while(k--){
                curr = curr->next ;
            }

            // make the node head and break connection
            head = curr->next ;
            curr->next = NULL ;

            return head;
        }
    };