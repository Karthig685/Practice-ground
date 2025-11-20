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

struct Node* insertatbegin(struct Node *head, int value){
    struct Node *newNode=createNode(value);
    newNode->next=head;
    return newNode;
}

struct Node* insertatend(struct Node *head, int value){
    struct Node *newNode=createNode(value);
    if (head==NULL) return newNode;
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
        printf("%d-> ", temp->data);
        temp=temp->next;
    }
    free(temp);
    printf("NULL\n");
}

int main(){
    struct Node *head=NULL;
    head=insertatend(head,18);
    head=insertatend(head,20);
    head=insertatbegin(head,30);
    printlist(head);
    return 0;
}