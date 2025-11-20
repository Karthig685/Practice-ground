#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int value){
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

struct Node* beg(struct Node *head, int value){
    struct Node *newNode=createNode(value);
    newNode->next=head;
    return newNode;
}

struct Node* end(struct Node *head, int value){
    struct Node *newNode=createNode(value);
    if(head==NULL) return newNode;
    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

void printlist(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d->", temp->data);
        temp=temp->next;
    }
    printf("NULL/n");
}
void printreverse(struct Node *head){
    if (head==NULL) return;
    printreverse(head->next);
    printf("%d->", head->data);
}

int main(){
    struct Node *head=NULL;
    head=beg(head,10);
    head=end(head,30);
    head=end(head,50);
    printlist(head);
    printreverse(head);
    return 0;
}