#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int value){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
}

struct Node* bg(struct Node *head, int value){
    struct Node *newNode = createNode(value);
    newNode->next=head;
    return newNode;
}

struct Node* ed(struct Node *head, int value){
    struct Node *newNode = createNode(value);
    if (head==NULL) return newNode;
    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

void dis(struct Node *head){
    struct Node *temp=head;
    while (temp!=NULL){
        printf("%d->", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node *head=NULL;
    head=bg(head,10);
    head=ed(head,20);
    head=ed(head,30);
    dis(head);
}