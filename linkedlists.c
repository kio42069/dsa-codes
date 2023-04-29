#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

int main(){

    int n,q;
    scanf("%d %d", &n, &q);
    Node *head = NULL;
    head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    Node *tail = NULL;
    tail = (Node*)malloc(sizeof(Node));
    tail = head;
    head->next = tail;
    for(int i = 0; i < n; i++){
        Node *temp = NULL;
        temp = (Node*)malloc(sizeof(Node));
        scanf("%d", &(temp->data));
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }

    int count = 1;

    while(count){
        count--;
        int k = 2;
        Node *temp1 = NULL;
        temp1 = (Node*)malloc(sizeof(Node));
        temp1 = head->next;
        Node *prev = NULL;
        prev = (Node*)malloc(sizeof(Node));
        prev = head;
        for(int i = 0; i < k-1; i ++){
            temp1 = temp1->next;
            prev = prev->next;
        }
        prev->next = (temp1->next);
        free(temp1);
    }

    //     PRINT
    Node *temp = NULL;
    temp = (Node*)malloc(sizeof(Node));
    temp = head->next;
    for(int i = 0; i < n; i++){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    


    return 0;
}