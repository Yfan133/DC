/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val)
    {
        // 1.双指针
        // if (head == NULL)
        //     return head;
        // if (head->val == val)
        //     return head->next;
        // ListNode* pre = head, * cur = head->next;
        // while (cur != nullptr && cur->val != val)
        // {
        //     cur = cur->next;
        //     pre = pre->next;
        // }
        // if (cur != nullptr)
        // {
        //     pre->next = cur->next;
        // }
        // return head;


        // 2.带头结点的单指针,缺点：内存泄露
        // ListNode* pre = new ListNode(0);
        // pre->next = head;
        // ListNode* cur = head;
        // head = pre;
        // while (cur != nullptr && cur->val != val)
        // {
        //     cur = cur->next;
        //     pre = pre->next;
        // }
        // if (cur != nullptr)
        // {
        //     pre->next = cur->next;
        // }
        // return head->next;

        // 3.单指针
        if (head == nullptr)
            return head;
        if (head->val == val)
            return head->next;
        ListNode* cur = head;
        while (cur->next != nullptr && cur->next->val != val)
        {
            cur = cur->next;
        }
        if (cur->next != nullptr)
            cur->next = cur->next->next;
        return head;
    }
};