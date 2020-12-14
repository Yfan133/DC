/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    struct ListNode* fast = head;
    //struct ListNode* slow=head;
    while (k-- > 0)
    {
        fast = fast->next;
        if (!fast)
            return head;
    }
    while (fast)
    {
        head = head->next;
        fast = fast->next;
    }
    return head;

}