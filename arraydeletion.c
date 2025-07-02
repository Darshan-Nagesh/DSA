#include<stdio.h>
int delbypos(int a[], int size){
    int i, pos;
    printf("Enter the position to delete: ");
    scanf("%d",&pos);
    if(pos<0 || pos>=size){
        printf("Invalid position");
        return size;
    }
    else{
        for(i=pos-1; i<size; i++)
            a[i] = a[i+1];
        return size-1;
    }
}
int delbyval(int a[], int size){
    int i, val, pos;
    printf("Enter the element to del: ");
    scanf("%d",&val);
    pos = -1;
    for(i=0;i<size;i++){
        if(a[i] == val){
            pos = i;
            break;
        }
    }
    if(pos == -1){
        printf("Element %d not found in array",val);
        return size;
    }
    else{
        for(i=pos; i<size; i++)
            a[i] = a[i+1];
        return size-1;
    }
}
int main(){
    int a[50], size, i, ch;
    printf("Enter the size of an array: ");
    scanf("%d",&size);
    printf("Enter elemts into array: ");
    for(i=0; i<size; i++)
        scanf("%d",&a[i]);
    printf("Enter choice: \n1. Delete by pos\n2. Delete by value\n");
    scanf("%d",&ch);
    switch(ch){
        case 1: size = delbypos(a,size); break;
        case 2: size = delbyval(a,size); break;
        default : printf("Invalid case"); break;
    }
    printf("Array after deletion: ");
        for(i=0; i<size; i++)
            printf("%d",a[i]);    
    return 0;
}