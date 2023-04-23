#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}Node;

struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (Node **)malloc(q->size*sizeof(Node *));
}

void enqueue(struct Queue *q, Node *x)
{
    if((q->rear + 1) % q->size == q->front){
        printf("Queue is full");
    }
    else{
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

Node * dequeue(struct Queue *q)
{
    Node * x = NULL;
    if(q->front == q->rear){
        printf("Queue is empty\n");
    }
    else{
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}

struct Node *root = NULL;

void createTree()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);

    root = (struct Node *) malloc (sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q)){
        p = dequeue(&q);
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *) malloc (sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *) malloc (sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p)
{
    if(p)
    {        
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void postorder(struct Node *p)
{
    if(p)
    {        
        postorder(p->lchild);
        postorder(p->rchild);        
        printf("%d ", p->data);

    }
}



void LevelOrder(struct Node *p)
{
    struct Queue q;
    create(&q, 100);

    printf("%d ", root->data);
    enqueue(&q, root);

    while(!isEmpty(q))
    {
        root = dequeue(&q);
        if(root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }

        if(root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}


int main()
{
    createTree();

    printf("Preorder traversal is : ");
    preorder(root);

    printf("\nPostorder traversal is : ");
    postorder(root);

    printf("\nInorder Traversal is : ");
    inorder(root);

    printf("\nLevelOrder Traversal is : ");
    LevelOrder(root);
    
    return 0;
}