#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

typedef struct{
    int data[SIZE];
    int front;
    int rear;
} LinearQueue;

void initQueue(LinearQueue *q){
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(LinearQueue *q){
    return q->rear < q->front;
}

bool isFull(LinearQueue *q){
    return q->rear == SIZE - 1;
}

bool enqueue(LinearQueue *q, int value){
    if(isFull(q)){
        printf("큐가 가득 찼습니다.\n");
        return false;
    }
    q->rear++;
    q->data[q->rear] = value;
    return true;
}

int dequeue(LinearQueue *q){
    if(isEmpty(q)){
        printf("큐가 비어 있습니다.\n");
        return false;
    }
    int value = q->data[0];
    
    for(int i = 0; i < q->rear; i++){
        q->data[i] = q->data[i + 1];
    }
    q->rear--;
    return value;
}

int main(){
    LinearQueue q;
    initQueue(&q);
    int select;

    while(1){
        printf("-------큐 수정 간단 메뉴-------\n");
        printf("1. Add Queue\n");
        printf("2. Del Queue\n");
        printf("3. Print Queue\n");
        printf("4. End Queue\n");
        if(scanf("%d", &select) != 1){
            printf("유효하지 않은 수\n");
            while(getchar() != '\n');
            continue;
        }

        switch(select){
            case 1:
                if(isFull(&q)){
                    printf("큐가 꽉 차있습니다.\n");
                    break;
                }
                else{
                    int data;
                    printf("추가할 데이터 :\n");
                    scanf("%d", &data);
                    enqueue(&q, data);
                    printf("데이터가 추가 되었습니다.\n");
                }break;
            case 2:
                if(isEmpty(&q)){
                    printf("큐가 비어있습니다.\n");
                    break;
                }
                else{
                    int removed = dequeue(&q);
                    printf("삭제된 데이터 : %d\n", removed);
                }break;
            case 3:
                if(isEmpty(&q)){
                    printf("큐가 비어있습니다.\n");
                    break;
                }
                else if(isFull(&q)){
                    printf("큐가 꽉 차있습니다.\n");
                    break;
                }
                else
                    printf("큐가 현재 %d까지 차있습니다.\n", q.rear - q.front + 1);
                    break;
            case 4:
                printf("프로그램 종료\n");
                return 0;
            default:
                printf("잘못된 접근입니다.");
                break;
        }
    }
}