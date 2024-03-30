#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int freeIndex;
int headIndex;

void insertAtBeginning(int* linkedlist, int* prev, int* next, int value) {
    if (freeIndex == -1) {
        printf("List is full. Cannot insert.\n");
        return;
    }
    int newNodeIndex = freeIndex;
    freeIndex = next[freeIndex]; 
    linkedlist[newNodeIndex] = value;
    next[newNodeIndex] = headIndex; 
    prev[newNodeIndex] = -1; 
    if (headIndex != -1) {
        prev[headIndex] = newNodeIndex; 
    }
    headIndex = newNodeIndex; 
}

void deleteNode(int* linkedlist, int* prev, int* next, int value) {
    int currentNode = headIndex;
    while (currentNode != -1 && linkedlist[currentNode] != value) {
        currentNode = next[currentNode];
    }
    if (currentNode == -1) {
        printf("Node with data %d not found.\n", value);
        return;
    }
    int prevIndex = prev[currentNode];
    int nextIndex = next[currentNode];
    if (prevIndex != -1) {
        next[prevIndex] = nextIndex; 
    }
    else {
        headIndex = nextIndex; 
    }
    if (nextIndex != -1) {
        prev[nextIndex] = prevIndex; 
    }
    prev[currentNode] = -1; 
    next[currentNode] = freeIndex; 
    freeIndex = currentNode; 
}
void insertAtMiddle(int* linkedlist, int* prev, int* next, int value, int position) {
    if (freeIndex == -1) {
        printf("List is full. Cannot insert.\n");
        return;
    }
    int newNodeIndex = freeIndex;
    freeIndex = next[freeIndex];
    linkedlist[newNodeIndex] = value; 
    int currentNode = headIndex;
    int count = 1;
    while (currentNode != -1 && count < position) {
        currentNode = next[currentNode];
        count++;
    }
    if (currentNode == -1) {
        printf("Invalid position. Cannot insert.\n");
        return;
    }
    next[newNodeIndex] = next[currentNode];
    prev[newNodeIndex] = currentNode; 
    next[currentNode] = newNodeIndex; 
    if (next[newNodeIndex] != -1) {
        prev[next[newNodeIndex]] = newNodeIndex; 
    }
}

void insertAtEnd(int* linkedlist, int* prev, int* next, int value) {
    if (freeIndex == -1) {
        printf("List is full. Cannot insert.\n");
        return;
    }
    int newNodeIndex = freeIndex;
    freeIndex = next[freeIndex]; 
    linkedlist[newNodeIndex] = value; 
    next[newNodeIndex] = -1; 
    if (headIndex == -1) {
        headIndex = newNodeIndex;
    }
    else {
        int currentNode = headIndex;
        while (next[currentNode] != -1) {
            currentNode = next[currentNode];
        }
        next[currentNode] = newNodeIndex; 
        prev[newNodeIndex] = currentNode; 
    }
}

int search(int* linkedlist, int* next, int value) {
    int currentNode = headIndex;
    while (currentNode != -1 && linkedlist[currentNode] != value) {
        currentNode = next[currentNode];
    }
    return currentNode; 
}

void print(int* linkedlist, int* next) {
    printf("Doubly Linked List: ");
    int currentNode = headIndex;
    while (currentNode != -1) {
        printf("%d ", linkedlist[currentNode]);
        currentNode = next[currentNode];
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the LinkedList: ");
    scanf("%d", &n);
    int* linkedlist = (int*)malloc(n * sizeof(int));
    int* prev = (int*)malloc(n * sizeof(int));
    int* next = (int*)malloc(n * sizeof(int));
    if (linkedlist == NULL || prev == NULL || next == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    freeIndex = 0;
    headIndex = -1;

    for (int i = 0; i < n - 1; i++) {
        next[i] = i + 1;
    }
    next[n - 1] = -1; 

    insertAtBeginning(linkedlist, prev, next, 10);
    insertAtBeginning(linkedlist, prev, next, 20);
    insertAtBeginning(linkedlist, prev, next, 30);
    insertAtEnd(linkedlist, prev, next, 40);
    insertAtMiddle(linkedlist, prev, next, 50, 2);
    print(linkedlist, next);

    int searchData = 20;
    int result = search(linkedlist, next, searchData);
    if (result != -1) {
        printf("Data %d found in the list.\n", searchData);
    }
    else {
        printf("Data %d not found in the list.\n", searchData);
    }


    deleteNode(linkedlist, prev, next, 30);

    print(linkedlist, next);

    free(linkedlist);
    free(prev);
    free(next);

}