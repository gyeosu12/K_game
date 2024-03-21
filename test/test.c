#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int fill[4][4];
int AD[4][4];

void ADnum(int x, int y)
{
    if (AD[x][y] == 0)
        printf("A");
    else if (AD[x][y] == 1)
        printf("D");
}

void printfill()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ADnum(i, j);
            printf("%-2d ", fill[i][j]);
        }
        printf("A%d", sumI(i));
        printf("\n");
    }
    for (int i = 0; i < 4; i++)
        printf("D%-2d ", sumJ(i));
    printf("\n");
}
void newfill()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int a = (rand() % 15) + 5;
            int b= (rand() % 2);
            fill[i][j] = a;
            AD[i][j] = b;
        }
    }
}
int sumI(int a)
{
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        if (AD[a][i] == 0)//좌우 공격
            sum += fill[a][i];
        else if (AD[a][i] == 1)//상하 공격
            sum += 1;
    }
    return sum;
}
void fillI(int a)
{
    for (int i = 0; i < 4; i++) {
        int x = (rand() % 15) + 5;
        int y = (rand() % 2);
        fill[a][i] = x;
        AD[a][i] = y;
    }
}
int sumJ(int a)
{
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        if (AD[i][a] == 1)//상하 수비
            sum += fill[i][a];
        else if (AD[i][a] == 0)
            sum += 1;
    }
    return sum;
}
void fillJ(int a)
{
    for (int i = 0; i < 4; i++) {
        int x = (rand() % 15) + 5;
        int y = (rand() % 2);
        fill[i][a] = x;
        AD[i][a] = y;
    }
}
int main(void)
{
    srand(time(NULL));
    newfill();
    while (1) {
        char A;
        int B;

        printfill();
        printf("action ,line :");
        scanf("%c %d", &A, &B);
        getchar();
        B--;
        if (A == 'A') {
            printf("A%d\n", sumI(B));
            fillI(B);
        }
        else if (A == 'D') {
            printf("D%d\n", sumJ(B));
            fillJ(B);
        }
       // system("cls");
        printf("\n \n");
    }
}
