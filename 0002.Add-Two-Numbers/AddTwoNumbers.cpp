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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        ListNode *res = new ListNode (0);
        ListNode *cur3 = res;
        int carry = 0;
        while (cur1 && cur2) {
            cur3->next = new ListNode((cur1->val + cur2->val + carry) % 10);
            carry = (cur1->val + cur2->val + carry)/10;
            cur1 = cur1->next;
            cur2 = cur2->next;
            cur3 = cur3->next;
        }
        while (cur1) {
            cur3->next = new ListNode((cur1->val + carry) % 10);
            carry = (cur1->val + carry)/10;
            cur1 = cur1->next;
            cur3 = cur3->next;
        }
        while (cur2) {
            cur3->next = new ListNode((cur2->val + carry) % 10);
            carry = (cur2->val + carry)/10;
            cur2 = cur2->next;
            cur3 = cur3->next;
        }
        if (carry != 0){
            cur3->next = new ListNode(carry);
        }
        return res->next;
    }
};