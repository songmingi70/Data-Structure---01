#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculateAverage(int scores[], int size);
int getStudentScore(int socres[], int size, int studentNumber);
void printScore(int scores[], int size, double average, int option);




int main(){
    int scores[10];
    int studentNumber;
    double average;

    srand(time(0));

    for(int i = 0; i < 10; i++){
        scores[i] = rand() % 101;
    }

    average = calculateAverage(scores, 10);
    printf("학급 평균 점수 : %.2f\n", average);

    printf("학생 번호를 입력하세요 (1 ~ 10): ");
    scanf("%d", &studentNumber);

    int score = getStudentScore(scores, 10, studentNumber);
    if(score != -1){
        printf("%d번 학생의 점수 : %d\n", studentNumber, score);
    }
    else{
        printf("유효하지 않은 학생 번호입니다.\n");
    }


    printScore(scores, 10, average, 0);
    printScore(scores, 10, average, 1);
    printScore(scores, 10, average, 2);
    return 0;

    
}

void printScore(int scores[], int size, double average, int option){
    switch(option){
        case 0:
            for(int i = 0; i < size; i++){
                printf("학생번호 : %d, 점수 : %d\n", i+1, scores[i]);
            }
            break;
        case 1:
            printf("평균 이상 학생\n");
            for(int i = 0; i < size; i++){
                if(scores[i] >= average) printf("학생번호 : %d, 점수 : %d\n", i+1, scores[i]);
            }
            break;
        case 2:
            printf("평균 미만 학생\n");
            for(int i = 0; i < size; i++){
                if(scores[i] < average) printf("학생번호 : %d, 점수 : %d\n", i+1, scores[i]);
            }
            break;
        default:
            printf("유효하지 않은 옵션입니다.\n");
            break;
    }
}

int getStudentScore(int scores[], int size, int studentNumber){
    if(studentNumber < 1 || studentNumber > size){
        return -1;
    }

    return scores[studentNumber - 1];
}

double calculateAverage(int scores[], int size){
    int sum = 0;

    for(int i = 0; i < size; i++){
        sum += scores[i];
    }

    return (double)sum / size;
}