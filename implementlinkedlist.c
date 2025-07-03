#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL;
int main(){
    int count, choice;
    struct node *temp, *newnode;
    choice = 1;
    count = 0;
    while(choice){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        if(head == NULL){
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
        count++;
        temp->next = NULL;
        printf("Do you want continue(0or1): ");
        scanf("%d",&choice);
    }
    temp = head;
    printf("List have %d items: \n",count);
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    return 0;
}