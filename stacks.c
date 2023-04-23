#include <stdio.h>

void push(int *arr, int *tail){
    int ele = 0;
    int end = *tail;
    printf("%d\n", end);
    printf("Enter element to be pushed into the stack: ");
    scanf("%d", &ele);
    *(arr+1+end) = ele;
    end++;
    *tail = end;
    printf("tail : %d", *tail);
}

void pop(int* tail){
    if((*tail) > -1)
        (*tail)--;
    else
        printf("Underflow");
}

void display(int *arr, int head, int tail){
    for(int i = head; i <= tail; i++){
        printf("%d ", (*arr+i));
    }
    printf("\n");
}


int main(){
    int len = 0;
    printf("Enter length of stack: ");
    scanf("%d", &len);
    int arr[9999];

    for(int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }
    int head = 0;
    int tail = len-1;
    int flag = 1;

    while(1){
        int e = 0;
        printf("Enter\n1. To push element\n2. To pop element\n3. To display the stack\nAnything else to exit menu: ");
        scanf("%d", &e);
        switch (e){
            case 1:
                push(&arr[0], &tail);
                break;
            case 2:
                pop(&tail);
                break;
            case 3:
                display(&arr[head], head, tail);
                break;
            default:
                flag = 0;
                break;
        }
        if (!flag){
            break;
        }
    }
    return 0;
}
