#include<stdio.h>
#define num 10

int main() {
    int arr[num];
    for (int i = 0; i < num; i++) {
        scanf_s("%d", arr + i);
    }
    printf("%d", sum(arr, 0, 9));
    return 0;
}

int sum(int* arr, int left, int right) {
    int mid = (left + right) / 2;
    if (left == right) {
        return arr[left];
    }
    else {
        return sum(arr, left, mid) + sum(arr, mid + 1, right);

    }
}