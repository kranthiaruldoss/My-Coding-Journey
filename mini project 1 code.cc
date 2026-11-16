
#include <stdio.h>

#define MAX 100

void displayExpenses(float expenses[], int n);
float calculateTotal(float expenses[], int n);
void findHighest(float expenses[], int n);

int main()
{
    float expenses[MAX];
    int n, i;

    printf("SMART STUDENT EXPENSE TRACKER\n");

    printf("Enter number of expenses: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of expenses!");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nExpense %d\n", i + 1);
        printf("1. Food\n");
        printf("2. Travel\n");
        printf("3. Education\n");

        int choice;
        printf("Select category: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3)
        {
            printf("Invalid category. Enter again.\n");
            i--;
            continue;
        }

        printf("Enter amount: Rs. ");
        scanf("%f", &expenses[i]);
    }

    displayExpenses(expenses, n);

    float total = calculateTotal(expenses, n);

    printf("\nTotal Expense: Rs. %.2f", total);
    printf("\nAverage Expense: Rs. %.2f", total / n);

    findHighest(expenses, n);

    return 0;
}

void displayExpenses(float expenses[], int n)
{
    int i;

    printf("\n--- EXPENSE DETAILS ---\n");

    for (i = 0; i < n; i++)
    {
        printf("Expense %d: Rs. %.2f\n",
               i + 1, expenses[i]);
    }
}

float calculateTotal(float expenses[], int n)
{
    float total = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        total += expenses[i];
    }

    return total;
}

void findHighest(float expenses[], int n)
{
    float highest = expenses[0];
    int i;

    for (i = 1; i < n; i++)
    {
        if (expenses[i] > highest)
        {
            highest = expenses[i];
        }
    }

    printf("\nHighest Expense: Rs. %.2f", highest);
}
