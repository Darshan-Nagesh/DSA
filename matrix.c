#include<stdio.h>
int main(){
    int a[50][50], m, n, i, j;
    printf("Enter the size of matrix: ");
    scanf("%d %d",&m,&n);
    printf("Enter %d elements into array: ",m*n);
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    printf("Matrix is as follows: \n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}