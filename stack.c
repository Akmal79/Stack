#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int* arr;
};

int isfull(struct stack* ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }return 0;
}

int isempty(struct stack* ptr){
    if(ptr->top==-1){
        return 1;
    }return 0;
}

void push(struct stack* ptr,int val){
    if(isfull(ptr)){
        printf("Stack overflow \n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int pop(struct stack* ptr){
    if(isempty(ptr)){
        printf("Stack underflow \n");
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
void display(struct stack* ptr) {
    if (ptr->top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= ptr->top; i++) {
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
}

int main(){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size= 20;
    s->top=-1;
    s->arr = (int*)malloc(s->size*sizeof(int));
    push(s,44);
    push(s,55);
    int popedvalue = pop(s);
    if (popedvalue!=-1){
        printf("poped value: %d ",popedvalue);
    }
    display(s);
}