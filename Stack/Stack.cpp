#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int top = -1;

int isempty(int *s)
{
    if (s[top] == 0)return 1;
    else return 0;
}

int push(int* s, int x, int n) {
    if (top == n - 1) {
        printf("Stack overflow!\n");
        return 0; 
    }
    top++;
    s[top] = x;
    return 1; 
}
int pop(int* s) {
    if (isempty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    int temp = s[top];
    top--;
    return temp;
}
void print(int* s) {
    if (isempty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contains:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", s[i]);
    }
}

int main()
{

    printf("\n Number of Elememnts: \n");
    int n; scanf("%d", &n);
    int* s = (int*)malloc(n * sizeof(int));
    if (s == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    if (push(s, 10, n)) {
        printf("Element 10 pushed successfully. \n");
    }
    else {
        printf("Failed to push element 10. Stack is full.\n");
    }

    if (push(s, 20, n)) {
        printf("Element 20 pushed successfully .\n");
    }
    else {
        printf("Failed to push element 20. Stack is full.\n");
    }
    if (push(s, 200, n)) {
        printf("Element 200 pushed successfully .\n");
    }
    else {
        printf("Failed to push element 200. Stack is full.\n");
    }
    if (push(s, 210, n)) {
        printf("Element 210 pushed successfully.\n");
    }
    else {
        printf("Failed to push element 210. Stack is full.\n");
    }

    if (push(s, 30, n)) {
        printf("Element 30 pushed successfully .\n");
    }
    else {
        printf("Failed to push element 30. Stack is full.\n");
    }

    printf("Popped element: %d\n", pop(s));
    printf("Popped element: %d\n", pop(s)); 
  
    print(s);
    free(s);
}
