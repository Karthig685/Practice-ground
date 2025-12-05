#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL){
        printf("Memory Allocation failed... Retry Again\n");
        printf("Function Restarts");
        main();
        return 0;
    }
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
};

struct Node* bn(struct Node* head, int value){
    struct Node* newNode=createNode(value);
    if (head==NULL) return newNode;
    newNode->next=head;
    head->prev=newNode;
    return newNode;
}

struct Node* en(struct Node* head, int value){
    struct Node* newNode=createNode(value);
    if (head==NULL) return newNode;
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    return head;
}

void pr(struct Node* head){
    struct Node* temp=head;
    while (temp!=NULL){
        printf("%d<->", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    free(temp);
}

int main(){
    struct Node* head=NULL;
    head=bn(head, 2000);
    head=en(head,400);
    head=en(head,500);
    pr(head);
    return 0;
}