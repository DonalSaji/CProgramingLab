#include <stdio.h>
#include <time.h>
#define RATE_PER_LITER 45.0   /* Rate per liter of milk */

int main() {
    int n, count, vaccinationCount = 0;
    char choice;

    printf("Enter number of animals: ");
    scanf("%d", &n);

    /* Arrays to store final report data */
    float totalMilkArr[n], earnedArr[n], expenseArr[n], profitArr[n];

    for (count = 1; count <= n; count++) {
        float morningMilk, eveningMilk, totalMilk, amountEarned, feedExpense, profit;
        int age;

        printf("\n--- Animal %d ---\n", count);

        /* ---------- Morning Milk ---------- */
        do {
            printf("Enter morning milk quantity (liters): ");
            scanf("%f", &morningMilk);

            if (morningMilk < 0) {
                printf("Invalid value. Skip this entry and set to 0? (y/n): ");
                scanf(" %c", &choice);
                if (choice == 'y' || choice == 'Y') {
                    morningMilk = 0;
                    break;
                }
            } else {
                break;
            }
        } while (1);

        /* ---------- Evening Milk ---------- */
        do {
            printf("Enter evening milk quantity (liters): ");
            scanf("%f", &eveningMilk);

            if (eveningMilk < 0) {
                printf("Invalid value. Skip this entry and set to 0? (y/n): ");
                scanf(" %c", &choice);
                if (choice == 'y' || choice == 'Y') {
                    eveningMilk = 0;
                    break;
                }
            } else {
                break;
            }
        } while (1);

        /* ---------- Total Milk & Earnings ---------- */
        totalMilk = morningMilk + eveningMilk;
        amountEarned = totalMilk * RATE_PER_LITER;

        printf("Total milk collected: %.2f liters\n", totalMilk);
        printf("Amount earned: %.2f\n", amountEarned);

        /* ---------- Feeding Expense ---------- */
        do {
            printf("Enter feeding expense: ");
            scanf("%f", &feedExpense);

            if (feedExpense < 0) {
                printf("Invalid value. Skip this entry and set to 0? (y/n): ");
                scanf(" %c", &choice);
                if (choice == 'y' || choice == 'Y') {
                    feedExpense = 0;
                    break;
                }
            } else {
                break;
            }
        } while (1);

        /* ---------- Profit ---------- */
        profit = amountEarned - feedExpense;
        printf("Profit: %.2f\n", profit);

        /* Store values for final report */
        totalMilkArr[count - 1] = totalMilk;
        earnedArr[count - 1]    = amountEarned;
        expenseArr[count - 1]   = feedExpense;
        profitArr[count - 1]    = profit;

        /* ---------- Vaccination Check ---------- */
        int lastVaccDay, lastVaccMonth, lastVaccYear;


    printf("Enter last vaccination date (DD MM YYYY): ");
    scanf("%d %d %d", &lastVaccDay, &lastVaccMonth, &lastVaccYear);

    // Create structure for last vaccination date
    struct tm lastVacc = {0};
    lastVacc.tm_mday = lastVaccDay;
    lastVacc.tm_mon = lastVaccMonth - 1;   // Months are 0-11
    lastVacc.tm_year = lastVaccYear - 1900; // Years since 1900

    // Convert to time_t
    time_t lastVaccTime = mktime(&lastVacc);

    // Get current date and time
    time_t currentTime = time(NULL);

    // Calculate difference in seconds and convert to days
    double diffSeconds = difftime(currentTime, lastVaccTime);
    int daysSinceLastVacc = (int)(diffSeconds / (60 * 60 * 24));

    printf("Days since last vaccination: %d\n", daysSinceLastVacc);

    // Assuming vaccination interval is 30 days
    if (daysSinceLastVacc >= 30) {
        printf("Vaccination Needed\n");
        vaccinationCount++;
    } else {
        printf("Vaccination Not Required\n");
    }

    printf("Vaccination Count: %d\n", vaccinationCount);
        
            }

    /* ---------- Final Report ---------- */
    printf("\n========== FINAL REPORT ==========\n");
    for (count = 1; count <= n; count++) {
        printf("\nAnimal %d:\n", count);
        printf("  Total Milk     : %.2f liters\n", totalMilkArr[count - 1]);
        printf("  Amount Earned  : %.2f\n", earnedArr[count - 1]);
        printf("  Feeding Expense: %.2f\n", expenseArr[count - 1]);
        printf("  Profit         : %.2f\n", profitArr[count - 1]);
    }
    printf("\nTotal animals requiring vaccination: %d\n", vaccinationCount);
    printf("===================================\n");

    return 0;
}