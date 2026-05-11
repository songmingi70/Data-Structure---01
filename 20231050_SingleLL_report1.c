#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertFirst(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

Node* insertLast(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void insertAfterValue(Node* head, int targetValue, int newData) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == targetValue) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = newData;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("값 %d를 가진 노드를 찾을 수 없습니다.\n", targetValue);
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int searchValue1(Node* head, int val) {
    Node* current = head;
    int pos = 1;

    while (current != NULL) {
        if (current->data == val) {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1;
}

void searchValue2(Node* head, int val) {
    Node* prev = NULL;
    Node* current = head;

    while (current != NULL) {
        if (current->data == val) {
            printf("[%d] 탐색 성공!\n", val);
            
            if (prev != NULL) printf("앞 노드의 값: %d\n", prev->data);
            else printf("앞 노드가 없습니다 (Head 노드).\n");

            if (current->next != NULL) printf("뒤 노드의 값: %d\n", current->next->data);
            else printf("뒤 노드가 없습니다 (Tail 노드).\n");
            
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("값 %d를 가진 노드를 찾을 수 없습니다.\n", val);
}

void freeList(Node* head) {
    Node* current = head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    printf("모든 노드의 메모리가 해제되었습니다.\n");
}

int main() {
    Node* head = NULL;

    head = insertFirst(head, 30); 
    head = insertFirst(head, 20); 
    head = insertFirst(head, 10); 
    head = insertLast(head, 70); 
    head = insertLast(head, 80); 
    head = insertLast(head, 90); 
    insertAfterValue(head, 30, 40); 
    insertAfterValue(head, 40, 50); 
    insertAfterValue(head, 50, 60); 

    printf("현재 리스트 상태: ");
    printList(head);
    printf("\n");

    int val1 = 30;
    int pos = searchValue1(head, val1);
    if (pos != -1) printf("%d의 위치는 %d번째입니다.\n", val1, pos);
    else printf("%d를 찾을 수 없습니다.\n", val1);
    printf("\n");

    int val2 = 50;
    searchValue2(head, val2);
    printf("\n");

    freeList(head);
    head = NULL;

    return 0;
}