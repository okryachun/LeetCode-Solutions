#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *numHead = calloc(sizeof(struct ListNode),1);
    struct ListNode *numList = numHead;
    int a, b, carry = 0, run = 1;
    while (run) {
        //if l1 or l2 is null, then set their value to zero
        a = l1 == NULL ? 0 : l1->val;
        b = l2 == NULL ? 0 : l2->val;
        
        //get the sum, if sum is greater than 10 then set the carry value and subtract 10 from sum
        numList->val = a + b + carry;
        carry = (numList->val > 9) ? 1 : 0;
        numList->val = numList->val > 9 ? numList->val - 10: numList->val;

        //update l1 and l2 if not null
        l1 = l1 != NULL ? l1->next : NULL;
        l2 = l2 != NULL ? l2->next : NULL;
        
        //if more numbers to store
        if(l1 != NULL || l2 != NULL || carry != 0) {
            numList->next = calloc(sizeof(struct ListNode),1);
            numList = numList->next;
        }
        
        //if no more numbers to store, Null the list, and stop the loop
        if(l1 == NULL && l2 == NULL && carry == 0) {
            numList->next == NULL;
            run = 0;
        }
    }
    return numHead;
}

