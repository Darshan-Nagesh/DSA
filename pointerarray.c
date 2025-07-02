#include<stdio.h>
int main(){
    int a[50], size, *p, i;
    p = a;
    printf("Enter the size of an array: ");
    scanf("%d",&size);
    printf("Enter elements into array: ");
    for(i=0;i<size;i++)    
        scanf("%d",&p[i]);
    printf("Printing array elements with help of a pointer\n");
    for(i=0;i<size;i++)
        printf("%d ",p[i]);
    printf("\na - %d\np - %d\n&a - %d\n&p - %d\na[2] - %d\np[2] - %d\n&a[2] - %d\n&p[2] - %d",a,p,&a,&p,a[2],p[2],&a[2],&p[2]);
    return 0;
}