#include<stdlib.h>
#include<stdio.h>

#define MAX 5

int stack[MAX];
int top=-1;

void push(int value){
    if (top==MAX-1){
        printf("Stack overflow, cant push\n");
        return;
    }
    top++;
    stack[top]=value;
    printf("Pushed : %d\n",value);
}

void pop(){
    if (top==-1){
        printf("Stack underflow, cant pop\n");
        return;
    }
    printf("Popped: %d\n", stack[top]);
    top--;
}

int main(){
    pop();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    pop();
    pop();
    
}