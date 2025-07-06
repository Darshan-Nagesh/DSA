#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
}*head, *temp;
void display(){
    temp = head;
    printf("\nElements in list: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void create(){
    int ch;
    do{
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter value: "); scanf("%d",&newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if(head == NULL)
            head = temp = newnode;
        else{
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("\nDo you want to continue: "); scanf("%d",&ch);
    }while(ch);
    display();
}
int linlen(){
    int count = 0;
    temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
void insbeg(){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value: "); scanf("%d",&newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head == NULL)
        head = newnode;
    else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    display();
}
void insend(){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value: ");
    scanf("%d",&newnode->data);
    newnode->prev = newnode->next = 0;
    if(head == NULL)
        head = newnode;
    else{
        temp = head;
        while(temp->next!= NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
    display();
}
void inspos(){
    int pos, i=1;
    struct node *newnode;
    printf("\nEnter posistion to insert: ");
    scanf("%d",&pos);
    if(pos<1 || pos>linlen()){
        printf("Invalid position");
        return;
    }
    if(pos == 1 || head == NULL)
        insbeg();
    else{
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the value: "); scanf("%d",&newnode->data);
        newnode->prev = newnode->next = 0;
        temp = head;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next->prev =newnode;
        temp->next = newnode;
        newnode->prev = temp;
        display();
    }    
}
void delbeg(){
    if(head == NULL){
        printf("\nEmpty list");
        return;
    }
    temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    display();
}
void delend(){
    if(head == NULL){
        printf("\nEmpty list");
        return;
    }
    else{
        temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->prev->next = NULL;
        free(temp);
        display();
    }
}
void delpos(){
    int pos, i=1;
    if(head==NULL){
        printf("\nEmpty list");
        return;
    }
    printf("\nEnter position: "); scanf("%d",&pos);
    if(pos<1 || pos>linlen()){
        printf("\nInvalid position");
    }
    else{
        if(pos == 1)
            delbeg();
        else{
            temp = head;
            while(i<pos){
                temp = temp->next;
                i++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            display();
        }
    }
}
void delkey(){
    int key, flag=0;
    if(head == NULL){
        printf("\nEmpty list");
        return;
    }
    printf("\nEnter the value: "); scanf("%d",&key);
    temp = head;
    if(head->data == key){
        head = head->next;
        if(head!=NULL)
            head->prev = NULL;
        flag = 1;
        free(temp);
    }
    else{
        while(temp!=NULL){
            if(temp->data == key){
                if(temp->next!=NULL){
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                else
                    temp->prev->next = NULL;
                free(temp);
                flag = 1;
            }
            temp = temp->next;
        }
    }
    if(!flag)
        printf("%d is not list",key);
    else
        display();
}
void reverse(){
    struct node *prevnd, *cur;
    if(head == NULL){
        printf("\nEmpty list");
        return;
    }
    cur = head;
    while(cur!=NULL){
        prevnd = cur->prev;
        cur->prev = cur->next;
        cur->next = prevnd;
        cur = cur->prev;
    }
    head = prevnd->prev;
    display();
}
void sort(){
    struct node *nextn;
    temp = nextn = head;
    int val;
    while(temp!=NULL){
        while(nextn!=NULL){
            if(temp->data > nextn->data){
                val = temp->data;
                temp->data = nextn->data;
                nextn->data = val; 
            }
            nextn = nextn->next;
        }
        nextn = temp->next;
        temp = temp->next;
    }
    display();
}
int main(){
    int choice;
    do{
        printf("\nEnter your choice: ");
        printf("\n1. Create\n2. Insert at beginning\n3. Insert at specific pos\n4. Insert at end\n5. Delete at beginning\n6. Delete specific position\n7. Delete at end\n8. Delete by key\n9. Reverse\n10. Sort\n11. Display\n0. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: create(); break;
            case 2: insbeg(); break;
            case 3: inspos(); break;
            case 4: insend(); break;
            case 5: delbeg(); break;
            case 6: delpos(); break;
            case 7: delend(); break;
            case 8: delkey(); break;
            case 9: reverse(); break;
            case 10: sort(); break;
            case 11: display(); break;
            case 0: exit(0); break;
            default: printf("\nInvalid choice"); break;
        }
    }while(choice);
    return 0;
}