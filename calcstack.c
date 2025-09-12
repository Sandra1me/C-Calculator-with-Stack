/*
    Calculator with Stack
    ----------------------
    Performs operations (+, -, *, /), stores them in a stack, allows undo and review of all past operations.

    Author: [Sandra Martin Elias]
    Date: [2025/09/09]
*/

#include <stdio.h>

#define MAX 100

// Struct to store a single operation and its result
typedef struct
{
    char operation;
    float number1;
    float number2;
    float result;
} Operation;

// Struct to represent the stack of operations
typedef struct
{
    Operation saved[MAX]; // Stack of operations
    int top;              // Index of the top element in the stack
} History;

// Stack management functions
void initialize(History *history);
void push(History *history, char operValue, float number1, float number2, float result);
Operation pop(History *history);
Operation peek(History *history);
int isEmpty(History *history);

// Calculator-specific functions
void operate(History *history);
void showAll(History *history);

// Utility function
void clearInputBuffer();

// Main function: shows menu and handles user input
int main()
{
    History history;
    int option;
    Operation undone;

    initialize(&history);

    while (1)
    {
        // Show menu and get user input
        option = 0;
        printf("----- Main menu -----\n");
        printf("1. Operate\n");
        printf("2. Show all operations.\n");
        printf("3. Undo last operation.\n");
        printf("4. Clear all.\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%i", &option);
        clearInputBuffer();

        // Handle user-selected menu option
        switch (option)
        {
        case 1:
            operate(&history);
            break;
        case 2:
            showAll(&history);
            break;
        case 3:
            undone = pop(&history);
            if (undone.operation != '\0')
            {
                printf("Last operation undone: %.2f %c %.2f = %.2f\n", undone.number1, undone.operation, undone.number2, undone.result);
            }
            break;
        case 4:
            initialize(&history);
            printf("All cleared.\n");
            break;
        case 5:
            printf("Thank you. Have a nice day.\n");
            return 0;
        default:
            printf("Invalid option.\n");
        }
    }
}

// Initialize the stack (empty it)
void initialize(History *history)
{
    history->top = -1;
}

// Push a new operation onto the stack
void push(History *history, char operValue, float number1, float number2, float result)
{
    history->top++;
    history->saved[history->top].operation = operValue;
    history->saved[history->top].number1 = number1;
    history->saved[history->top].number2 = number2;
    history->saved[history->top].result = result;
}

// Pop (remove) the most recent operation from the stack
Operation pop(History *history)
{
    int empty = isEmpty(history);

    if (empty == 1)
    {
        Operation popped = history->saved[history->top];
        history->top--;
        return popped;
    }
    else
    {
        printf("There are no operations to remove.\n");
        Operation empty = {'\0', 0.0, 0.0, 0.0};
        return empty;
    }
}

// Peek at the most recent operation without removing it
Operation peek(History *history)
{
    int empty = isEmpty(history);

    if (empty == 1)
    {
        Operation peeked = history->saved[history->top];
        return (peeked);
    }
    else
    {
        printf("There are no operations to show.\n");
        Operation empty = {'\0', 0.0, 0.0, 0.0};
        return empty;
    }
}

// Check if the stack is empty
int isEmpty(History *history)
{
    if (history->top == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Perform an operation selected by the user and store it in the stack
void operate(History *history)
{
    float number1, number2, result;
    char operation;

    if (history->top < MAX - 1)
    {
        printf("Insert the first number: ");
        if (scanf("%f", &number1) != 1)
        {
            printf("Invalid input.\n");
            clearInputBuffer();
            return;
        }

        printf("Insert the second number: ");
        if (scanf("%f", &number2) != 1)
        {
            printf("Invalid input.\n");
            clearInputBuffer();
            return;
        }

        printf("Select the operation (+ - * /): ");
        scanf(" %c", &operation);

        // Execute and print result of the selected operation
        switch (operation)
        {
        case '+':
            result = number1 + number2;
            printf("%.2f + %.2f = %.2f\n", number1, number2, result);
            break;
        case '-':
            result = number1 - number2;
            printf("%.2f - %.2f = %.2f\n", number1, number2, result);
            break;
        case '*':
            result = number1 * number2;
            printf("%.2f * %.2f = %.2f\n", number1, number2, result);
            break;
        case '/':
            if (number2 != 0)
            {
                result = number1 / number2;
                printf("%.2f / %.2f = %.2f\n", number1, number2, result);
            }
            else
            {
                printf("Error: division by zero.\n");
            }
            break;
        default:
            printf("Not a valid option.\n");
            return;
        }
    }
    else
    {
        printf("The list of operations is full.\n");
        return;
    }

    push(history, operation, number1, number2, result);
}

// Display all stored operations from the stack
void showAll(History *history)
{
    int empty = isEmpty(history);

    if (history->top >= 0)
    {
        printf("Stored values are:\n");
        for (int i = history->top; i >= 0; i--)
        {
            printf("%.2f %c %.2f = %.2f\n", history->saved[i].number1, history->saved[i].operation, history->saved[i].number2, history->saved[i].result);
            printf("-----\n");
        }
    }
    else
    {
        printf("There is no history to show.\n");
    }
}

// Clear leftover characters from the input buffer
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}