#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculateAverage(int scores[], int size);

int main(){
    int scores[10];
    double average;

    srand(time(0));

    for(int i = 0; i < 10; i++){
        scores[i] = rand() % 101;
    }

    average = calculateAverage(scores, 10);
    printf("학급 평균 점수 : %.2f\n", average);

    return 0;
}

double calculateAverage(int scores[], int size){
    int sum = 0;

    for(int i = 0; i < size; i++){
        sum += scores[i];
    }

    return (double)sum / size;
}