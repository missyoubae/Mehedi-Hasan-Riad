#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char items[MAX][MAX];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

void push(Stack *stack, const char *text) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->top++;
    strcpy(stack->items[stack->top], text);
}

char* pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return NULL;
    }
    return stack->items[stack->top--];
}

char* peek(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->items[stack->top];
}

int main() {
    Stack undoStack, redoStack;
    char text[MAX] = "";
    char input[MAX];
    int choice;

    initStack(&undoStack);
    initStack(&redoStack);

    while (1) {
        printf("\nCurrent Text: %s\n", text);
        printf("1. Type text\n2. Undo\n3. Redo\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:

                push(&undoStack, text);

                printf("Enter new text: ");
                fgets(input, MAX, stdin);
                input[strcspn(input, "\n")] = '\0';

                strcat(text, input);


                initStack(&redoStack);
                break;

            case 2:

                if (!isEmpty(&undoStack)) {
                    push(&redoStack, text);
                    strcpy(text, pop(&undoStack));
                } else {
                    printf("No actions to undo.\n");
                }
                break;

            case 3:

                if (!isEmpty(&redoStack)) {
                    push(&undoStack, text);
                    strcpy(text, pop(&redoStack));
                } else {
                    printf("No actions to redo.\n");
                }
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
