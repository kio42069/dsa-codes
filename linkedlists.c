#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

int main(){
    Node *one = NULL;
    one = (Node*)malloc(sizeof(Node));
    one->data = 3;
    one->next = NULL;
    Node *head = one;
    Node *tail = one;
    int len = 0;
    printf("Enter length of linked list to be created initially: ");
    scanf("%d", &len);
    for(int i = 0; i < len; i++){
        int element = 0;
        printf("Enter element: ");
        scanf("%d", &element);
        Node *temp = NULL;
        temp = (Node*)malloc(sizeof(Node));
        temp->data = element;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
    Node *temp = head;
    for(int i = 0; i < len+1; i++){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}