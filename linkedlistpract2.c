#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int value){
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

struct Node* bn(struct Node* head, int value){
    struct Node* newNode=createNode(value);
    newNode->next=head;
    return newNode;
}

struct Node* en(struct Node* head, int value){
    struct Node* newNode=createNode(value);
    if (head==NULL) return newNode;
    struct Node* temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

void pn(struct Node* head){
    struct Node* temp=head;
    while (temp!=NULL){
        printf("%d->", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head=NULL;
    head=bn(head,10);
    head=en(head,11);
    head=en(head,12);
    pn(head);
}