#include <stdio.h>

void enqueue(int *arr, int *tail, int *len){
    //code
}

void dequeue(int *head, int *len){
    //code
}

void display(int *arr, int *head, int *tail, int *len){
    
}


int main(){
    int len = 0;
    printf("Enter length of stack: ");
    scanf("%d", &len);
    int arr[9999];

    for(int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }
    int flag = 1;

    while(1){
        int e = 0;
        printf("Enter\n1. To enqueue element\n2. To dequeue element\n3. To display the queue\nAnything else to exit menu: ");
        scanf("%d", &e);
        switch (e){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
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

