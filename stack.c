//
// Created by acer on 1/1/2023.
//
#include "stdio.h"
#include "stdlib.h"

#define MAXOFSTACK 10

int tocount = 0;

struct stack{
    int data[MAXOFSTACK];
    int top;
};

typedef struct stack st;

void create_emptyStack(st *myStack){
    myStack->top = -1;
};

int isStackFull(st *myStack){
    if(myStack->top == MAXOFSTACK-1){
        return 1;
    }else{
        return 0;
    }
};

int isStackEmpty(st *myStack){
    if(myStack->top == -1){
        return 1;
    }else{
        return 0;
    }
}

void pushtoStack(st *myStack, int value){
    if(isStackFull(myStack)){
        printf("Stack is FUll\n");
    }else{
        myStack->top++;
        myStack->data[myStack->top] = value;
    }
    tocount++;
};

void popfromStack(st *myStack){
    if(isStackEmpty(myStack)){
        printf("No data to show up\n");
    }else{
        printf("%d\n", myStack->data[myStack->top]);
        myStack->top--;
        tocount--;
    }
}

int main() {
    st *myStack=(st*)malloc(sizeof(st));
    create_emptyStack(myStack);

    pushtoStack(myStack, 10);
    pushtoStack(myStack, 60);
    pushtoStack(myStack, 65);
    pushtoStack(myStack, 40);
    pushtoStack(myStack, 20);
    pushtoStack(myStack, 21);

    // my code
    if(myStack->top == -1){
        printf("No data to display\n");
    }else{
        if(tocount == MAXOFSTACK)
        {
            printf("Stack is full!\n");
        }else{
            printf("There are %d data in stack and %d is empty!\n", tocount, MAXOFSTACK-tocount);
        }
        for(int i=1; i<=MAXOFSTACK; i++)
        {
            printf("in place %d is ",i);
            popfromStack(myStack);
            printf("\n");
        }
    }



    return 0;
}
