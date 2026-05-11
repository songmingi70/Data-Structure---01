#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    char phone[20];
    struct Node* next;
} Node;

Node* addContact(Node* head, char* name, char* phone) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = head;
    return newNode;
}

void searchContact(Node* head, char* name) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("[%s]님의 전화번호: %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("[%s]님을 찾을 수 없습니다.\n", name);
}

Node* deleteContact(Node* head, char* name) {
    if (head == NULL) return NULL;

    Node* current = head;
    Node* prev = NULL;

    if (strcmp(current->name, name) == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("[%s]님의 연락처가 삭제되었습니다.\n", name);
        return head;
    }

    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("[%s]님을 찾을 수 없습니다.\n", name);
        return head;
    }

    prev->next = current->next;
    free(current);
    printf("[%s]님의 연락처가 삭제되었습니다.\n", name);
    return head;
}

void printAll(Node* head) {
    Node* current = head;
    printf("\n===== 전화번호부 목록 =====\n");
    if (current == NULL) {
        printf("등록된 연락처가 없습니다.\n");
    }
    while (current != NULL) {
        printf("이름: %s | 번호: %s\n", current->name, current->phone);
        current = current->next;
    }
    printf("===========================\n\n");
}

void freeAll(Node* head) {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    Node* head = NULL;

    head = addContact(head, "홍길동", "010-1234-5678");
    head = addContact(head, "이순신", "010-2222-3333");
    head = addContact(head, "강감찬", "010-5555-6666");

    printAll(head);

    searchContact(head, "이순신");
    searchContact(head, "김철수");

    head = deleteContact(head, "홍길동");
    
    printAll(head);

    freeAll(head);
    head = NULL;

    return 0;
}