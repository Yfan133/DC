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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* phead = new ListNode(-1);
        ListNode* cur = phead;
        int car = 0;
        while (l1 || l2 || car)
        {
            int a = 0, b = 0;
            if (l1)
            {
                a = l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                b = l2->val;
                l2 = l2->next;
            }
            int sum = a + b + car;
            car = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            cur->next = node;
            cur = cur->next;
        }
        return phead->next;
    }
};