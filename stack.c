#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* top=NULL;

void push(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=top;
    top=newNode;
    printf("\n Pushed : %d", value);
}

void pop(){
    //struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(top==NULL){
        printf("Stack is underflow");
        return;
    }
    struct Node* temp=top;
    printf("\nPopped: %d", temp->data);
    top=temp->next;
    free(top);
}

int main(){
    pop();
    push(10);
    push(20);
    push(30);
    pop();
}



