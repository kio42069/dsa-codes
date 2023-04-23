//this code is bugged??????

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

typedef struct Stack 
{
    int size;
    int top;
    struct Node **S;
}Stack;

void Stackcreate(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct Node **) malloc (st->size * sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *x)
{
    if(st->top == st->size-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node *pop(struct Stack *st)
{
    struct Node *x = NULL;

    if(st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int isEmptyStack(struct Stack *st)
{
    if(st->top == 1){
        return 1;
    }
    return 0;
}

int isFullStack(struct Stack st)
{
    return st.top == st.size-1;
}

void IPreorder(struct Node *p)
{
    struct Stack *stk;
    Stackcreate(&stk, 100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else{
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

void IInorder(struct Node *p)
{
    struct Stack *stk;
    Stackcreate(&stk, 100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else{
            p = pop(&stk);
            p = p->rchild;
        }
    }
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


int main()
{
    createTree();
    IPreorder(root);
    // printf("\n");
    // postorder(root);
    // printf("\n");
    // inorder(root);
    return 0;
}