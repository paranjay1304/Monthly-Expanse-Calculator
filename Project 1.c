#include <stdio.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 20

typedef struct {
    float amount;
    char category[20];
    int day;
} Expense;

Expense expenses[MAX_EXPENSES];
int expenseCount = 0;

char catNames[MAX_CATEGORIES][20];
float catTotals[MAX_CATEGORIES];
int catCount = 0;

float budget;
int currentDay;
int totalDaysInMonth;

void setupBudget() {
    printf("Enter your monthly budget: Rs ");
    scanf("%f", &budget);
    printf("Enter total days in this month: ");
    scanf("%d", &totalDaysInMonth);
    printf("Enter current day of the month: ");
    scanf("%d", &currentDay);
    if (currentDay <= 0) currentDay = 1;   // avoid divide-by-zero
}

void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Expense log full.\n");
        return;
    }
    Expense e;
    printf("Enter amount: Rs ");
    scanf("%f", &e.amount);
    printf("Enter category: ");
    scanf("%19s", e.category);
    printf("Enter day (1-%d): ", totalDaysInMonth);
    scanf("%d", &e.day);

    expenses[expenseCount++] = e;

    // update running category totals
    int found = 0;
    for (int i = 0; i < catCount; i++) {
        if (strcmp(catNames[i], e.category) == 0) {
            catTotals[i] += e.amount;
            found = 1;
            break;
        }
    }
    if (!found && catCount < MAX_CATEGORIES) {
        strcpy(catNames[catCount], e.category);
        catTotals[catCount] = e.amount;
        catCount++;
    }
    printf("Expense added.\n");
}

float getTotalSpent() {
    float total = 0;
    for (int i = 0; i < expenseCount; i++) total += expenses[i].amount;
    return total;
}

void showPrediction() {
    if (expenseCount == 0) {
        printf("No expenses logged yet.\n");
        return;
    }
    float totalSpent = getTotalSpent();
    float dailyAvg = totalSpent / currentDay;
    float projected = dailyAvg * totalDaysInMonth;

    printf("\n--- Budget Prediction ---\n");
    printf("Total spent so far: Rs %.2f\n", totalSpent);
    printf("Daily average: Rs %.2f\n", dailyAvg);
    printf("Projected month-end spend: Rs %.2f\n", projected);

    if (projected > budget) {
        float overspend = projected - budget;
        int runOutDay = (int)(budget / dailyAvg);
        printf("Alert! At this rate, you will overspend by Rs %.2f.\n", overspend);
        printf("You will run out of money around Day %d.\n", runOutDay);
    } else {
        float saved = budget - projected;
        printf("Good job! You are on track to save Rs %.2f this month.\n", saved);
    }
}

void categoryBreakdown() {
    if (expenseCount == 0) {
        printf("No expenses logged yet.\n");
        return;
    }
    float totalSpent = getTotalSpent();
    printf("\n--- Category Breakdown ---\n");
    for (int i = 0; i < catCount; i++) {
        float pct = (catTotals[i] / totalSpent) * 100;
        printf("%-12s Rs %8.2f  (%.1f%%)\n", catNames[i], catTotals[i], pct);
    }
}

int main() {
    int choice;
    setupBudget();

    do {
        printf("\n===== Expense Predictor =====\n");
        printf("1. Add Expense\n");
        printf("2. View Prediction\n");
        printf("3. Category Breakdown\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addExpense(); break;
            case 2: showPrediction(); break;
            case 3: categoryBreakdown(); break;
            case 4: printf("Goodbye.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}