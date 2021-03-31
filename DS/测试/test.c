//#include"test.h"
//typedef struct TreeNode
//{
//    char data;
//    struct TreeNode* left;
//    struct TreeNode* right;
//}TreeNode;
//////////////////////////////////////////////////////////////////
//typedef struct LinkQueueNode
//{
//    struct TreeNode* data;
//    LinkQueueNode* next;
//}LinkQueueNode;
//typedef struct LinkQueue
//{
//    LinkQueueNode* head;
//    LinkQueueNode* tail;
//}LinkQueue;
//void QueueInit(LinkQueue* Q)
//{
//    assert(Q != NULL);
//    Q->head = Q->tail = NULL;
//}
//void QueueEn(LinkQueue* Q, struct TreeNode* p)
//{
//    assert(Q != NULL);
//    LinkQueueNode* s = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
//    s->data = p;
//    s->next = NULL;
//    if (Q->head == NULL)
//    {
//        Q->head = Q->tail = s;
//    }
//    else
//    {
//        Q->tail->next = s;
//        Q->tail = s;
//    }
//}
//struct TreeNode* QueuePop(LinkQueue* Q)
//{
//    assert(Q != NULL);
//    if (Q->head == NULL)
//        return NULL;
//    if (Q->head == Q->tail)
//    {
//        LinkQueueNode* s = Q->head;
//        Q->head = Q->tail = NULL;
//        return s;
//    }
//    else {
//        LinkQueueNode* s = Q->head;
//        Q->head = Q->head->next;
//        return s;
//    }
//}
//bool QueueEmpty(LinkQueue* Q)
//{
//    assert(Q != NULL);
//    return Q->head == NULL;
//}
//void LinkQueueDestroy(LinkQueue* pq)
//{
//    assert(pq != NULL);
//    LinkQueueNode* p = pq->head;
//    while (p != NULL)
//    {
//        pq->head = p->next;
//        free(p);
//        p = pq->head;
//    }
//}
//void BinTreeLevel(TreeNode* t)
//{
//    if (t != NULL)
//    {
//        LinkQueue Q;
//        QueueInit(&Q);
//        QueueEn(&Q, t);
//        while (!QueueEmpty(&Q))
//        {
//            TreeNode* p = QueuePop(&Q);
//            printf("%c ", p->data);
//            if (p->left != NULL)
//                LinkQueueEn(&Q, p->left);
//            if (p->right != NULL)
//                LinkQueueEn(&Q, p->right);
//        }
//        LinkQueueDestroy(&Q);
//    }
//}
//void BinTreeInit(TreeNode** t)
//{
//    assert(t != NULL);
//    *t = NULL;
//}
//TreeNode* BinTreeCreate_2(const char* s, int* i)
//{
//    assert(s != NULL);
//    if (s[*i] == '\0' || s[*i] == '#')
//        return NULL;
//    else
//    {
//        TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
//        assert(p != NULL);
//        p->data = s[*i];
//        (*i)++;
//        p->left = BinTreeCreate_2(s, i);
//        (*i)++;
//        p->right = BinTreeCreate_2(s, i);
//        return p;
//    }
//}
//void main()
//{
//    TreeNode* Q;
//    BinTreeInit(&Q);
//    int index = 0;
//    const char* str = "ABC##DE##F##G#H##";
//    Q = BinTreeCreate_2(str, &index);
//    BinTreeLevel(Q);
//    printf("\n");
//}

