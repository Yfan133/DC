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
            tmp = new Node(p->val);   //���Ƶ�ǰ�ڵ�
            tmp->next = p->next;            //ָ��ǰ�ڵ��next
            tmp->random = p->random;        //ָ��ǰ�ڵ��random
            p->next = tmp;
            p = tmp->next;
        }
        p = head;
        //random�ڵ㵥������
        while (p != NULL)    //p��Ϊ����p->nextһ������
        {
            if (p->next->random != NULL)
                p->next->random = p->next->random->next;
            p = p->next->next;
        }
        p = head;
        tmp = head->next;
        Node* phead = tmp;
        //�ѽڵ�ֿ�
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
