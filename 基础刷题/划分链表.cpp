/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param x int整型
     * @return ListNode类
     */
    ListNode* partition(ListNode* head, int x)
    {
        // write code here
        ListNode* ln1 = new ListNode(0);
        ListNode* ln2 = new ListNode(0);
        ListNode* p = ln1;
        ListNode* pre = ln2;
        ListNode* s = head;
        while (s != nullptr)
        {
            if (s->val < x)
            {
                p->next = s;
                p = p->next;
            }
            else
            {
                pre->next = s;
                pre = pre->next;
            }
            s = s->next;
        }
        p->next = ln2->next;
        pre->next = nullptr;
        return ln1->next;
    }
};
