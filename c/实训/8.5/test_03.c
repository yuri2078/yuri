#include <stdio.h>
#include <stdlib.h>

void getInformation(float *student, int n)
{
    int i, maxScore = 0, minScore = 0;
    float sum = 0;
    int ScoreTotal[4] = {0};
    for (i = 0; i < n; i++)
    {
        printf("请输入第%d个学生的成绩 : ", i + 1);
        scanf("%f", &student[i]);
        sum += student[i];
        if(student[maxScore] < student[i]){
            maxScore = i;
        }
        if(student[minScore] > student[i]){
            minScore = i;
        }

        if(student[i] > 85){
            ScoreTotal[0]++;
        }
        else if(student[i] > 70){
            ScoreTotal[1]++;
        }
        else if(student[i] > 60){
            ScoreTotal[2]++;
        }
        else{
            ScoreTotal[3]++;
        }
    }

    printf("学生的总成绩是: %f 平均分是: %f\n", sum, sum / n);
    printf("成绩最高分是 %.1f, 是编号为 %d 的学生\n", student[maxScore], maxScore);
    printf("成绩最低分是 %.1f, 是编号为 %d 的学生\n", student[minScore], minScore);
    printf("学生成绩的分数段统计：\n");
    printf("85分以上的人数: %d\t占总人数的: %d%%\n", ScoreTotal[0], ScoreTotal[0] * 100 / n);
    printf("70-85分的人数: %d\t占总人数的: %d%%\n", ScoreTotal[1], ScoreTotal[1] * 100 / n);
    printf("60-75分的人数: %d\t占总人数的: %d%%\n", ScoreTotal[2], ScoreTotal[2] * 100 / n);
    printf("60分以下的人数: %d\t占总人数的: %d%%\n", ScoreTotal[3], ScoreTotal[3] * 100 / n);
}

int main(void)
{
    int n;
    printf("请输入一共有多个学生 : ");
    scanf("%d", &n);
    float *student = (float *)malloc(sizeof(float) * n);
    getInformation(student, n);
    free(student);
    return 0;
}