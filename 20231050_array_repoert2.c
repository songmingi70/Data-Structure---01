#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int scores[], int size, double average, int option);
void deleteStudent(int* scores, int size, int studentNumber);



int main(){
    int *scores;
    int size = 30;
    int capacity = 30;
    int choice, studentNumber;

    scores = (int *)malloc(capacity * sizeof(int));
    if(!scores){
        printf("allocation error\n");
        return 1;
    }

    srand(time(0));
    for(int i = 0; i < size; i++) scores[i] = rand() % 101;
    printf("입력 완료\n");

    while(1){
        printf("--- 학 생  성 적  관 리  프 로 그 램 ---\n");
        printf("1. 학 생 정 보  추 가\n");
        printf("2. 학 생 정 보  삭 제\n");
        printf("3. 학 생 정 보  검 색\n");
        printf("4. 학 생 정 보  출 력(옵션 : 0, 1, 2)\n");
        printf("5. 프 로 그 램  종 료\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(capacity - size < 5){
                    capacity += 10;
                    int *newScores = realloc(scores, capacity * sizeof(int));
                    if(!scores){
                        printf("allocation error\n");
                        return 1;
                    }
                    int newScore = rand() % 101;
                    scores[size] = newScore;
                    size++;
                    printf("새 로 운  학 생  추 가 : 번 호 - %d, 점 수 - %d\n", size, newScore);
                }
                break;
            case 2:
                printf("삭 제 할  학 생  번 호  입 력(1 ~ %d): ", size);
                scanf("%d", &studentNumber);
                deleteStudent(scores, size, studentNumber);
                break;
            case 3:
                printf("검 색 할  학 생  번 호  입 력(1 ~ %d): ", size);
                scanf("%d", &studentNumber);
                int score = getStudentScore(scores, size, studentNumber);
                if(score != -1) printf("%d번  학 생  점 수 : %d\n", studentNumber - 1, score);
                else printf("해 당  학 생 은  없 는  학 생 입 니 다.\n");
                break;
            case 4:
                int option;
                scanf("%d", &option);
                double average = calculateAverage(scores, size);
                printScore(scores, size, average, option);
                break;
            case 5:
                free(scores);
                break;
                return 0;
            default:
                printf("잘 못 된  입 력\n");
                break;
        }
    }
    return 0;
}

void deleteStudent(int* scores, int size, int studentNumber){
    if(studentNumber < 1 || studentNumber > size){
        printf("학 생 번 호  오 류\n");
    }
    if(scores[studentNumber - 1] == -1) printf("없 는  학 생 입 니 다.\n");
    else{
        scores[studentNumber - 1] = -1;
        printf("%d 학 생  삭 제 완 료\n", studentNumber);
    }
}

double calculateAverage(int scores[], int size){
    int sum = 0, count = 0;

    for(int i = 0; i < size; i++){
        if(scores[i] != -1){
            sum += scores[i];
            count++;
        }
    }

    if(count == 0) return 0;
    return (double)sum / count;
}

int getStudentScore(int scores[], int size, int studentNumber){
    if(studentNumber < 1 || studentNumber > size) return -1;

    if(scores[studentNumber - 1] == -1) return -1;

    return scores[studentNumber - 1];
}

void printScore(int scores[], int size, double average, int option){
    switch(option){
        case 0:
            for(int i = 0; i < size; i++){
                printf("%d학생의 점수 : %d\n", i+1, scores[i]);
            }
            break;
        case 1:
        printf("평균 이상인 학생\n");    
        for(int i = 0; i < size; i++){
                if(scores[i] >= average) printf("학생 번호 : %d, 점수 : %d\n", i + 1, scores[i]);
            }
            break;
        case 2:
        printf("평균 미만인 학생\n");
            for(int i = 0; i < size; i++){
                if(scores[i] < average) printf("학생 번호 : %d, 점수 : %d\n", i + 1, scores[i]);
            }
            break;
    }
}