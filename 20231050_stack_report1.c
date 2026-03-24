#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s){
    s -> top = -1;
}

int isEmpty(Stack *s){
    return s -> top == -1;
}

int isFull(Stack *s){
    return s -> top == MAX - 1;
}

void push(Stack *s, char value){
    if (isFull(s)){
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    s -> data[++(s -> top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;  // 에러 값
    }
    return s->data[(s->top)--];
}

int main(){
    Stack s;
    initStack(&s);
    char str[MAX];
    char str1[MAX];

    printf("문자열을 입력하세요 : ");
    scanf("%s", str);
    
    int len = strlen(str);

    for(int i = 0; i < len; i++){
        push(&s, str[i]);
    }

    for(int i = 0; i < len; i++){
        str1[i] = pop(&s);
    }
    

    printf("%s\n", str1);
}