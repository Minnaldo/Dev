#include <stdio.h>
#include <stdlib.h>

int main(){
    int row, col, val = 0;
    int **ptr;

    printf("Please input the size of Row : ");
    scanf("%d", &row);

    printf("Please input the size of Colmn : ");
    scanf("%d", &col);

    printf("To create the %d X %d matrix\n", row, col );

    //동적할당 행 생성
    // ptr = (int*)malloc(sizeof(int)*row);
    //동적할당 열 생성

    ptr = (int**)malloc(sizeof(int)*row);
    for(int i = 0; i<row;i++){
        ptr[i] = (int*)malloc(sizeof(int)*col);
        for(int j = 0; j<col; j++){
            ptr[i][j] = val;
            val++;
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
        {
            printf("%d", ptr[i][j] );
        }
        printf("\n" );
    }
}
