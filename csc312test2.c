#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int size;
} Stack;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack* stack, char value) {
    Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

char pop(Stack* stack) {
    if (stack->size == 0) {
        return '\0';
    }

    Node* temp = stack->top;
    char poppedValue = temp->data;
    stack->top = stack->top->next;
    stack->size--;
    free(temp);
    return poppedValue;
}

int isPalindrome(char* string) {
    Stack* stack = createStack();
    int length = strlen(string);
    int start = 0;

    while (start < length) {
        push(stack, string[start]);
        start++;
    }

    start = 0;
    while (start < length / 2) {
        if (string[start] != pop(stack)) {
            return 0;
        }
        start++;
    }

    return 1;
}

int main() {
    char string[100];
    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';

    if (isPalindrome(string)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
