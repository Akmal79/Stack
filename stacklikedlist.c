#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a Stack structure
struct Stack {
    struct Node* top;
};

// Function to create a new Node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push a new element onto the stack
void push(struct Stack* stack, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedValue;
}

// Function to display the elements of the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function to test the linked list-based stack
int main() {
    struct Stack stack;
    stack.top = NULL;

    // Example usage

    push(&stack, 11);
    push(&stack, 22);
    push(&stack, 33);
    push(&stack, 44);
    display(&stack);
    int poppedValue = pop(&stack);
    printf("Popped value: %d\n", poppedValue);
    int poppedValue1 = pop(&stack);
    printf("Popped value: %d\n", poppedValue1);
    display(&stack);

    return 0;
}
