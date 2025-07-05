#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head, *temp;
void display(){
    temp = head;
    printf("\nElements in linked list: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void create(){
    struct node *newnode;
    int ch=1;
    while(ch){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter value: ");
        scanf("%d",&newnode->data);
        if(head==NULL){
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
        temp->next = NULL;
        printf("\nDo you want to continue(0 or 1): ");
        scanf("%d",&ch);
    }
    display();
}
int lllength(){
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
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value: ");
    scanf("%d",&newnode->data);
    if(head == NULL){
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
    display();
}
void insend(){
    struct node *newnode;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value: ");
    scanf("%d",&newnode->data);
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->next = NULL;
    display();
}
void inspos(){
    struct node *newnode;
    int pos, i=1, linlen;
    printf("\nEnter the position to insert: ");
    scanf("%d",&pos);
    linlen = lllength();
    temp = head;
    if(pos<1 || pos>linlen){
        printf("\nInvalid position");
    }
    else{
        newnode = (struct node  *)malloc(sizeof(struct node));
        printf("\nEnter the value: ");
        scanf("%d",&newnode->data);
        
        if(pos == 1){
            newnode->next= head;
            head = newnode;
        }
        else{
            while(i<pos-1){
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    display();
}
void delbeg(){
    if(head == NULL){
        printf("\nEmpty list");
    }
    else{
        temp = head;
        head = head->next;
        free(temp);
        display();
    }
}
void delpos(){
    struct node *prev;
    int pos, i=1;
    if(head == NULL)
        printf("\nEmpty list");
    else{
        printf("\nEnter position: ");
        scanf("%d",&pos);
        if(pos<1 || pos>lllength()){
            printf("\nInvalid position");
        }
        else{
            temp = head;
            if(pos == 1){
                head = head->next;
            }
            else{
                while(i<pos){
                    prev = temp;
                    temp = temp->next;
                    i++;
                }
                prev->next = temp->next;
            }
            free(temp);
            display();
        }
    }
}
void delend(){
    struct node *prev;
    if(head == NULL){
        printf("\nList is empty");
    }
    else{
        temp = head;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        display();
    }
}
void reverse(){
    struct node *cur, *prev, *nextn;
    cur = nextn = head;
    prev = NULL;
    while(nextn != NULL){
        nextn = nextn->next;
        cur->next = prev;
        prev = cur;
        cur = nextn;
    }
    head = prev;
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
void delkey(){
    struct node *prev;
    int key, found = 0;
    if(head == NULL){
        printf("\nEmpty list");
        return;
    }
    
    printf("Enter the key: ");
    scanf("%d",&key);
    temp = prev = head;
    if(head->data == key){
        head = head->next;
        free(temp);
        found = 1;
    }
    else{
        while(temp!=NULL){
            if(temp->data == key){
                prev->next = temp->next;
                printf("\n%d deleted",key);
                free(temp);
                temp = prev;
                found = 1;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    display();
    if(!found){
        printf("%d is not present",key);
    }
    
}
int main(){
    int ch=1;
    while(ch){
        printf("\nEnter your choice: ");
        printf("\n1. Create\n2. Insert at beginning\n3. Insert at specific pos\n4. Insert at end\n5. Delete at beginning\n6. Delete specific position\n7. Delete at end\n8. Delete by key\n9. Reverse\n10. Sort\n11. Display\n0. Exit\n");
        scanf("%d",&ch);
        switch(ch){
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
            case 0: printf("\nExiting"); exit(0); break;
            default: printf("\nInvalid choice"); break;
        }
    }
    return 0;
}