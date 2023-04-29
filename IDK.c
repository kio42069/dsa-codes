#include <stdio.h>

int LBinarySearch(int A[], int l, int h, int key)
{
    int mid = 0;
    int n = l;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if ((key == A[mid]) && ((A[mid - 1] != key) || (mid == n)))
        {
            return mid;
        }
        else if (key <= A[mid])
        {
            h = mid - 1;
        }
        else if (key > A[mid])
        {
            l = mid + 1;
        }

    }

    return l;
}
int main(){
    int n,q;
    scanf("%d %d", &n, &q);
    int arr[n];
    int que[q];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < q; i++){
        scanf("%d", &que[i]);
    }
    for(int i = 0; i < q; i++){
        int element = que[i];
        int count = 0;
        int hell = LBinarySearch(arr, 0, n-1, element);
        printf("%d\n", hell);
    }
    return 0;
}