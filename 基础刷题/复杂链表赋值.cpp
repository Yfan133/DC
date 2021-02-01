/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if (head == NULL)
            return NULL;
        Node* p = head;
        Node* tmp = NULL;
        while (p != NULL)
        {
            tmp = new Node(p->val);   //复制当前节点
            tmp->next = p->next;            //指向当前节点的next
            tmp->random = p->random;        //指向当前节点的random
            p->next = tmp;
            p = tmp->next;
        }
        p = head;
        //random节点单独处理
        while (p != NULL)    //p不为空则p->next一定不空
        {
            if (p->next->random != NULL)
                p->next->random = p->next->random->next;
            p = p->next->next;
        }
        p = head;
        tmp = head->next;
        Node* phead = tmp;
        //把节点分开
        while (p != NULL)
        {
            p->next = tmp->next;
            p = p->next;
            if (p != NULL)
                tmp->next = p->next;
            tmp = tmp->next;
        }
        return phead;
    }
};
