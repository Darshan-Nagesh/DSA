#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head, *temp;
void display(){
    if(head==NULL){
        printf("\nEmpty list");
        return;
    }
    temp = head;
    printf("\nElements in list: ");
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
        if(head==NULL)
            head = temp = newnode;
        else{
            temp->next = newnode;
            temp = newnode;
        }
        printf("\nDo you want to continue: "); scanf("%d",&ch);
    }while(ch);
    newnode->next = head;
    display();
}
int linlen(){
    int count=1;
    temp = head;
    while(temp->next!=head){
        temp = temp->next;
        count++;
    }
    return count;
}
void insbeg(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value : "); scanf("%d",&newnode->data);
    if(head == NULL){
        head = newnode;
        head->next = head;
    }
    else{
        newnode->next = head;
        temp = head;
        while(temp->next!=head)
            temp = temp->next;
        head = newnode;
        temp->next = head;
    }
    display();
}
void insend(){
    struct node *newnode = malloc(sizeof(struct node*));
    printf("\nEnter the value: "); scanf("%d",&newnode->data);
    temp = head;
    while(temp->next!=head)
        temp = temp->next;
    temp->next = newnode;
    newnode->next = head;
    display();
}
void inspos(){
    int pos, i=1;
    struct node *newnode;
    printf("\nEnter the position: "); scanf("%d",&pos);
    if(pos<1 || pos>linlen())
        printf("\nInvalid position");
    else if(pos == 1)
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
        temp->next = newnode;
        display();
    }
}
void delbeg(){
    struct node *prev;
    if(head == NULL)
        printf("\nEmpty list");
    else if(head->next == head){
        printf("%d deleted",head->data);
        free(head);
        head = NULL;
        display();
    }
    else{
        temp = prev = head;
        while(prev->next!=head)
            prev = prev->next;
        head = head->next;
        prev->next = head;
        printf("%d deleted",temp->data);
        free(temp);
        display();
    }
}
void delend(){
    struct node *prev;
    if(head == NULL)
        printf("\nEmpty list");
    else if(head->next == head){
        printf("%d deleted",head->data);
        free(head);
        head = NULL;
        display();
    }
    else{
        temp = prev = head;
        while(temp->next!=head){
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        printf("%d deleted",temp->data);
        free(temp);
        display();
    }
}
void delpos(){
    int pos, i=1;
    struct node *prev;
    printf("\nEnter position: "); scanf("%d",&pos);
    if(pos<1 || pos>linlen())
        printf("\nInvalid position");
    else if(pos==1)
        delbeg();
    else if(pos==linlen())
        delend();
    else{
        temp = head;
        while(i<pos){
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
        printf("\n%d deleted",temp->data);
        display();
    }
}
void delkey(){
    int key, flag=0;
    struct node *prev = NULL;
    if(head == NULL){
        printf("\nEmpty list");
        return;
    }
    printf("\nEnter the value: "); scanf("%d",&key);
    temp = head;
    if(head->next == head){
        if(head->data == key){
            printf("\n%d delete",head->data);
            free(head);
            flag = 1;
            head=NULL;
            display();
        }
        else{
            printf("%d is not present",key);
            return;
        }
    }
    while(head!=NULL && head->data==key){
        prev = head;
        while(prev->next != head)
            prev = prev->next;
        temp = head;
        printf("%d deleted",temp->data);
        head = head->next;
        prev->next = head;
        free(temp);
        flag = 1;
    }
    prev = temp;
    temp = head->next;
    while(temp!=head){
        if(temp->data == key){
            prev->next = temp->next;
            printf("%d deleted",temp->data);
            free(temp);
            flag = 1;
            temp = prev->next;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
    display();
    if(!flag)
        printf("%d is not present",key);
}
void reverse(){
    struct node *cur = head, *prev = NULL, *nextnd = NULL;
    while(cur->next != head){
        nextnd = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextnd;
    }
    cur->next = prev;
    head->next = cur; 
    head = cur;
    display();
}
void sort(){
    int val;
    struct node *cur=head, *next=NULL;
    while(cur->next != head){
        next = cur->next;
        while(next!=head){
            if(cur->data > next->data){
                val = cur->data;
                cur->data = next->data;
                next->data = val;
            }
            next = next->next;
        }
        cur = cur->next;
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