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
    int isBalanced = 1;

    printf("괄호를 포함한 문자를 입력하세요 : ");
    scanf("%s", str);
    
    int len = strlen(str);

    for(int i = 0; i < len; i++){
        char ch = str[i];

        if(ch == '(' || ch == '[' || ch == '{'){
        push(&s, str[i]);
        }

        else if (ch == ')' || ch == ']' || ch =='}'){
            if(isEmpty(&s)){
                isBalanced = 0;
                break;
            }

            char open = (char)pop(&s);

            if((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{')){
                    isBalanced = 0;
                    break;
                }
        }
    }

    if (isBalanced && isEmpty(&s)){
        printf("성공 : 괄호의 짝이 맞습니다.\n");
    }
    else{
        printf("실패 : 괄호의 짝이 맞지 않습니다.\n");
    }
    

    return 0;
}