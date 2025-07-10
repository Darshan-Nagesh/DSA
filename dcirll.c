#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
}*head, *temp;
void display(){
    if(head == NULL){
        printf("\nEmpty list");
        return;
    }
    temp = head;
    printf("\nElements in linked list: ");
    while(temp->next!=head){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
}
void create(){
    int ch;
    struct node *newnode;
    do{
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter data: "); scanf("%d",&newnode->data);
        if(head==NULL){
            temp = head = newnode;
        }
        else{
            temp->next  = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        temp->next = head;
        head->prev = temp;
        printf("\nDo you want to continue: "); scanf("%d",&ch);
    }while(ch);
    display();
}
int linlen(){
    int count=1;
    temp = head;
    while(temp->next!=head){
        count++;
        temp = temp->next;
    }
    return count;
}
void insbeg(){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value: "); scanf("%d",&newnode->data);
    if(head==NULL){
        head = newnode;
        head->next = head->prev = head;
    }
    else if(head->next == head){
        newnode->next = head;
        newnode->prev = head;
        head->prev = newnode;
        head->next = newnode;
        head = newnode;
    }
    else{
        temp = head;
        while(temp->next!=head)
            temp = temp->next;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        temp->next = head;
        head->prev = temp;
    }
    display();
}
void insend(){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value: "); scanf("%d",&newnode->data);
    if(head==NULL)
        insbeg();
    else if(head->next == head){
        head->next = newnode;
        newnode->prev = head;
        head->prev = newnode;
        newnode->next = head;
    }
    else{
        temp = head;
        while(temp->next!=head)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = head;
        head->prev = newnode;
    }
    display();
}
void inspos(){
    int pos, i=1;
    struct node *newnode;
    printf("\nEnter position to insert value: "); scanf("%d",&pos);
    if(pos<1 || pos>linlen()){
        printf("\nInvalid position");
        return;
    }
    else if(head==NULL){
        printf("\nEmpty list");
        return;
    }
    if(pos == 1)
        insbeg();
    else{
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter value: "); scanf("%d",&newnode->data);
        temp = head;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next->prev = newnode;
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
    else if(head->next == head){
        printf("\n%d deleted",head->data);
        free(head);
        head = NULL;
    }
    else{
        temp = head;
        head = head->next;
        head->prev = temp->prev;
        temp->prev->next = head;
        printf("\n%d deleted",temp->data);
        free(temp);
    }
    display();
}
void delend(){
    if(head == NULL || head->next == head)
        delbeg();
    else{
        temp = head;
        while(temp->next!=head)
            temp = temp->next;
            temp->prev->next = head;
            head->prev = temp->prev;
            printf("\n%d deleted",temp->data);
            free(temp);
    }
    display();
}
void delpos(){
    int pos, i=1;
    if(head==NULL){
        printf("Empty list");
        return;
    }
    printf("\nEnter position: "); scanf("%d",&pos);
    if(pos<1 || pos>linlen()){
        printf("\nInvalid position");
        return;
    }
    if(pos==1)
        delbeg();
    else if(pos == linlen())
        delend();
    else{
        temp = head;
        while(i<pos){
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        printf("\n%d deleted",temp->data);
        free(temp);
        display();
    }
}
void delkey(){
    int key, flag = 0;
    struct node *last;
    if(head==NULL){
        printf("\nEmpty list");
        return;
    }
    printf("\nEnter the key: "); scanf("%d",&key);
    if(head->next == head){
        if(head->data == key){
            printf("\n%d deleted",head->data);
            free(head);
            head = NULL;
            display();
        }
        else
            printf("\n%d not found",key);
        return;
    }
    last = head;
    while(last->next!=head)
        last = last->next;
    while(head && head->data == key){
        if(head->next == head){
            printf("\n%d deleted",head->data);
            free(head);
            head = NULL;
            display();
        }
        else{  
            temp = head;
            head = head->next;
            last->next = head;
            head->prev = last;
            printf("\n%d deleted",temp->data);
            flag = 1;
            free(temp);
        }
    }
    if(head){
        last = head;
        while(last->next!=head){
            if(last->data == key){
                temp = last->next;
                last->next->prev = last->prev;
                last->prev->next = last->next;
                printf("%d deleted",last->data);
                flag = 1;
                free(last);
                last = temp;
            }
            last = last->next;
        }
        if(last->data == key){
            last->prev->next = last->next;
            last->next->prev = last->prev;
            printf("%d deleted",last->data);
            free(last);
            flag = 1;
        }
    }
    if(!flag)
        printf("%d not found",key);
}
void reverse(){
    struct node *cur, *nextnd;
    cur = head;
    nextnd = NULL;
    if(head==NULL){
        printf("\nEmpty list");
        return;
    }
    while(cur->next!=head){
        nextnd = cur->next;
        cur->next = cur->prev;
        cur->prev = nextnd;
        cur = nextnd;
    }
    cur->next = cur->prev;
    cur->prev = head;
    head = cur;
    display();
}
void sort(){
    temp = head;
    struct node *nextnd;
    int tempdt;
    if(head==NULL){
        printf("\nEmpty list");
        return;
    }
    while(temp->next!=head){
        nextnd = temp->next;
        while(nextnd!=head){
            if(temp->data > nextnd->data){
                tempdt = temp->data;
                temp->data = nextnd->data;
                nextnd->data = tempdt;
            }
            nextnd = nextnd->next;
        }
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