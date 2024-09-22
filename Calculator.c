#include <stdio.h>

int main()
{
    int first;
    int second;
    char operation;

    printf("-----------------------\n");
    printf("\nWelcome to Calculator\n");
    printf("\n-----------------------\n");
    printf("\nEnter equation : ");
    scanf("%d&c%d",&first,&operation,&second);

    switch (operation)
    {
        case '+' :
        printf("\nAnswer : %d ", first + second);
        break;

        case '-' :
        printf("\nAnswer : %d ", first - second);
        break;

        case '*' :
        printf("\nAnswer : %d ", first * second);
        break;

        case '/' :
        printf("\nAnswer : %d ", first / second);
        break;

        default :
        printf("Invalid operator.");
        printf("Ending the program");
        printf("------------------------");
        break;
    }
}