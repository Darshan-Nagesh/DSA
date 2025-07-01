#include<stdio.h>
int main(){
    int a[50], size, pos, val, i;
    printf("Enter the size of an array: ");
    scanf("%d",&size);
    printf("Enter elements into array: ");
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the position to insert an element: ");
    scanf("%d",&pos);
    if(pos<=0 || pos>size){
        printf("Invalid position");
        return 0;
    }
    printf("Enter the value: ");
    scanf("%d",&val);
    if(pos==size){
        a[pos] = val;
        size++;
    }
    else{
        for(i=size-1; i>=pos-1; i--){
            a[i+1] = a[i];
        }
        a[pos-1] = val;
        size++;
    }
    printf("Elements in array: \n");
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    return 0;
}