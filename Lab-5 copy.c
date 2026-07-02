/*
 * ============================================================
 *   DAIRY FARM MANAGEMENT SYSTEM
 *   String & Math Functions - Menu-Based Program
 *   Demonstrates 15 functions across math.h and string.h
 * ============================================================
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

/* ── ANSI colour helpers ─────────────────────────────────── */
#define CLR_RESET  "\033[0m"
#define CLR_GREEN  "\033[1;32m"
#define CLR_CYAN   "\033[1;36m"
#define CLR_YELLOW "\033[1;33m"
#define CLR_RED    "\033[1;31m"
#define CLR_BLUE   "\033[1;34m"
#define CLR_BOLD   "\033[1m"

/* ── Utility: clear screen ───────────────────────────────── */
void clearScreen(void) {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[H\033[2J");
#endif
}

/* ── Utility: print section header ──────────────────────── */
void printHeader(const char *title) {
    printf("\n" CLR_CYAN "╔══════════════════════════════════════════╗\n");
    printf(           "║  %-40s  ║\n", title);
    printf(           "╚══════════════════════════════════════════╝\n" CLR_RESET);
}

/* ── Utility: print divider ─────────────────────────────── */
void printDivider(void) {
    printf(CLR_BLUE "  ──────────────────────────────────────────\n" CLR_RESET);
}

/*
 *  ══════════════════════════════════════════
 *  STRING FUNCTIONS  (1 – 8)
 *  ══════════════════════════════════════════
 */

/* 1. strlen – Show the length of a breed name */
void fn_strlen(void) {
    printHeader("1. strlen  – Breed Name Length");
    char breed[100];
    printf("  Enter cow breed name: ");
    scanf(" %[^\n]", breed);
    int len = strlen(breed);
    printf(CLR_GREEN "\n  Breed : \"%s\"\n" CLR_RESET, breed);
    printf(CLR_YELLOW "  Length: %d characters\n" CLR_RESET, len);
}

/* 2. strcpy – Copy a breed name to a backup variable */
void fn_strcpy(void) {
    printHeader("2. strcpy  – Copy Breed Record");
    char original[100], backup[100];
    printf("  Enter original breed name: ");
    scanf(" %[^\n]", original);
    strcpy(backup, original);
    printf(CLR_GREEN "\n  Original : \"%s\"\n" CLR_RESET, original);
    printf(CLR_YELLOW "  Backup   : \"%s\"\n" CLR_RESET, backup);
    printf("  (Both stored independently in memory)\n");
}

/* 3. strcat – Build a full cow profile string */
void fn_strcat(void) {
    printHeader("3. strcat  – Build Cow Profile");
    char name[50], breed[50], profile[150] = "";
    printf("  Enter cow name  : ");
    scanf(" %[^\n]", name);
    printf("  Enter breed name: ");
    scanf(" %[^\n]", breed);
    strcat(profile, "Name: ");
    strcat(profile, name);
    strcat(profile, " | Breed: ");
    strcat(profile, breed);
    printf(CLR_GREEN "\n  Full Profile: \"%s\"\n" CLR_RESET, profile);
}

/* 4. strcmp – Compare two breed names */
void fn_strcmp(void) {
    printHeader("4. strcmp  – Compare Two Breeds");
    char b1[100], b2[100];
    printf("  Enter first  breed: ");
    scanf(" %[^\n]", b1);
    printf("  Enter second breed: ");
    scanf(" %[^\n]", b2);
    int result = strcmp(b1, b2);
    printf("\n  Comparing \"%s\" vs \"%s\"\n", b1, b2);
    if (result == 0)
        printf(CLR_GREEN "  Result: Breeds are IDENTICAL\n" CLR_RESET);
    else if (result < 0)
        printf(CLR_YELLOW "  Result: \"%s\" comes BEFORE \"%s\" alphabetically\n" CLR_RESET, b1, b2);
    else
        printf(CLR_YELLOW "  Result: \"%s\" comes AFTER \"%s\" alphabetically\n" CLR_RESET, b1, b2);
}

/* 5. strcmpi / manual case-insensitive – Search breed tag */
void fn_strncmp(void) {
    printHeader("5. strncmp – Prefix-Match Breed Tag");
    char tag[50], database[50];
    int n;
    printf("  Enter breed tag stored in DB : ");
    scanf(" %[^\n]", database);
    printf("  Enter search prefix          : ");
    scanf(" %[^\n]", tag);
    printf("  Compare first N characters   : ");
    scanf("%d", &n);
    int result = strncmp(database, tag, n);
    printf("\n  Comparing first %d chars of \"%s\" with \"%s\"\n", n, database, tag);
    if (result == 0)
        printf(CLR_GREEN "  Result: PREFIX MATCHES – breed found!\n" CLR_RESET);
    else
        printf(CLR_RED "  Result: PREFIX DOES NOT MATCH\n" CLR_RESET);
}

/* 6. toupper (via loop) – Standardise breed name to uppercase */
void fn_toupper(void) {
    printHeader("6. toupper – Standardise Breed to Uppercase");
    char breed[100];
    printf("  Enter breed name (any case): ");
    scanf(" %[^\n]", breed);
    printf(CLR_GREEN "\n  Original  : \"%s\"\n" CLR_RESET, breed);
    for (int i = 0; breed[i]; i++) breed[i] = toupper(breed[i]);
    printf(CLR_YELLOW "  Uppercase : \"%s\"\n" CLR_RESET, breed);
}

/* 7. tolower (via loop) – Convert tag to lowercase for storage */
void fn_tolower(void) {
    printHeader("7. tolower – Convert Tag to Lowercase");
    char tag[100];
    printf("  Enter cow tag / ID (any case): ");
    scanf(" %[^\n]", tag);
    printf(CLR_GREEN "\n  Original  : \"%s\"\n" CLR_RESET, tag);
    for (int i = 0; tag[i]; i++) tag[i] = tolower(tag[i]);
    printf(CLR_YELLOW "  Lowercase : \"%s\"\n" CLR_RESET, tag);
}

/* 8. strrev (manual) – Reverse-encode a cow ID for archiving */
void fn_strrev(void) {
    printHeader("8. strrev  – Reverse-Encode Cow ID");
    char id[100], rev[100];
    printf("  Enter cow ID to reverse-encode: ");
    scanf(" %[^\n]", id);
    int len = strlen(id);
    for (int i = 0; i < len; i++) rev[i] = id[len - 1 - i];
    rev[len] = '\0';
    printf(CLR_GREEN "\n  Original ID : \"%s\"\n" CLR_RESET, id);
    printf(CLR_YELLOW "  Archived ID : \"%s\"\n" CLR_RESET, rev);
}

/*
 *  ══════════════════════════════════════════
 *  MATH FUNCTIONS  (9 – 15)
 *  ══════════════════════════════════════════
 */

/* 9. sqrt – Estimate optimal pen size from area */
void fn_sqrt(void) {
    printHeader("9. sqrt  – Pen Side Length from Area");
    double area;
    printf("  Enter total pen area (sq. metres): ");
    scanf("%lf", &area);
    if (area < 0) { printf(CLR_RED "  Error: area cannot be negative.\n" CLR_RESET); return; }
    double side = sqrt(area);
    printf(CLR_GREEN "\n  Pen area    : %.2f sq. m\n" CLR_RESET, area);
    printf(CLR_YELLOW "  Side length : %.2f m  (for a square pen)\n" CLR_RESET, side);
}

/* 10. pow – Compound milk-production growth forecast */
void fn_pow(void) {
    printHeader("10. pow  – Milk Production Growth Forecast");
    double currentYield, growthRate;
    int years;
    printf("  Current daily yield (litres) : ");
    scanf("%lf", &currentYield);
    printf("  Expected annual growth rate %%: ");
    scanf("%lf", &growthRate);
    printf("  Forecast for N years         : ");
    scanf("%d", &years);
    double rate = 1.0 + growthRate / 100.0;
    double forecast = currentYield * pow(rate, years);
    printf(CLR_GREEN "\n  Current yield : %.2f L/day\n" CLR_RESET, currentYield);
    printf(CLR_GREEN "  Growth rate   : %.1f%% per year\n" CLR_RESET, growthRate);
    printf(CLR_YELLOW "  Forecast in %d year(s): %.2f L/day\n" CLR_RESET, years, forecast);
}

/* 11. ceil – Round up feed quantity to whole bags */
void fn_ceil(void) {
    printHeader("11. ceil – Round Up Feed to Whole Bags");
    double feedNeeded;
    printf("  Enter exact feed needed (kg): ");
    scanf("%lf", &feedNeeded);
    double bags = feedNeeded / 25.0;    /* each bag = 25 kg */
    double bagsNeeded = ceil(bags);
    printf(CLR_GREEN "\n  Feed required         : %.2f kg\n" CLR_RESET, feedNeeded);
    printf(CLR_GREEN "  Bag size              : 25 kg\n" CLR_RESET);
    printf(CLR_YELLOW "  Bags to purchase      : %.0f bag(s)  (rounded up)\n" CLR_RESET, bagsNeeded);
    printf("  Actual feed delivered : %.2f kg\n", bagsNeeded * 25.0);
}

/* 12. floor – Floor daily earnings to whole rupees */
void fn_floor(void) {
    printHeader("12. floor – Floor Daily Earnings");
    double liters, ratePerLiter;
    printf("  Litres collected today  : ");
    scanf("%lf", &liters);
    printf("  Rate per litre (Rs.)    : ");
    scanf("%lf", &ratePerLiter);
    double earned = liters * ratePerLiter;
    double floored = floor(earned);
    printf(CLR_GREEN "\n  Gross earnings : Rs. %.4f\n" CLR_RESET, earned);
    printf(CLR_YELLOW "  Settled amount : Rs. %.2f  (paisa dropped)\n" CLR_RESET, floored);
}

/* 13. fabs – Absolute deviation of actual vs target yield */
void fn_fabs(void) {
    printHeader("13. fabs – Yield Deviation from Target");
    double actual, target;
    printf("  Target daily yield (L): ");
    scanf("%lf", &target);
    printf("  Actual daily yield (L): ");
    scanf("%lf", &actual);
    double deviation = fabs(actual - target);
    printf(CLR_GREEN "\n  Target yield    : %.2f L\n" CLR_RESET, target);
    printf(CLR_GREEN "  Actual yield    : %.2f L\n" CLR_RESET, actual);
    printf(CLR_YELLOW "  Absolute deviation: %.2f L (%s target)\n" CLR_RESET,
           deviation, actual >= target ? "above" : "below");
}

/* 14. log / log10 – Log-scale milk trend analysis */
void fn_log(void) {
    printHeader("14. log / log10 – Milk Trend Analysis");
    double yield;
    printf("  Enter total monthly yield (litres): ");
    scanf("%lf", &yield);
    if (yield <= 0) { printf(CLR_RED "  Error: yield must be positive.\n" CLR_RESET); return; }
    printf(CLR_GREEN "\n  Monthly yield : %.2f L\n" CLR_RESET, yield);
    printf(CLR_YELLOW "  log (natural) : %.4f\n" CLR_RESET, log(yield));
    printf(CLR_YELLOW "  log10 (base-10): %.4f\n" CLR_RESET, log10(yield));
    printf("  (Log values used for trend-line scaling)\n");
}

/* 15. round – Round average milk yield to nearest 0.5 L */
void fn_round(void) {
    printHeader("15. round – Round Average Yield to 0.5 L");
    double total;
    int days;
    printf("  Total milk collected (L): ");
    scanf("%lf", &total);
    printf("  Number of days          : ");
    scanf("%d", &days);
    if (days <= 0) { printf(CLR_RED "  Error: days must be > 0.\n" CLR_RESET); return; }
    double avg = total / days;
    double rounded = round(avg * 2.0) / 2.0;   /* round to nearest 0.5 */
    printf(CLR_GREEN "\n  Total collected    : %.2f L over %d days\n" CLR_RESET, total, days);
    printf(CLR_GREEN "  Raw average        : %.4f L/day\n" CLR_RESET, avg);
    printf(CLR_YELLOW "  Rounded avg (0.5 L): %.1f L/day\n" CLR_RESET, rounded);
}

/*
 *  ══════════════════════════════════════════
 *  MAIN MENU
 *  ══════════════════════════════════════════
 */
void printMenu(void) {
    clearScreen();
    printf(CLR_BOLD CLR_CYAN);
    printf("\n  ╔═══════════════════════════════════════════════════╗\n");
    printf(  "  ║       DAIRY FARM MANAGEMENT SYSTEM               ║\n");
    printf(  "  ║       String & Math Function Showcase            ║\n");
    printf(  "  ╠═══════════════════════════════════════════════════╣\n");
    printf(CLR_RESET);
    printf(CLR_YELLOW "  ─── STRING FUNCTIONS ─────────────────────────────\n" CLR_RESET);
    printf("   1.  strlen  – Breed name length\n");
    printf("   2.  strcpy  – Copy breed record\n");
    printf("   3.  strcat  – Build cow profile string\n");
    printf("   4.  strcmp  – Compare two breed names\n");
    printf("   5.  strncmp – Prefix-match breed tag\n");
    printf("   6.  toupper – Standardise breed to uppercase\n");
    printf("   7.  tolower – Convert tag to lowercase\n");
    printf("   8.  strrev  – Reverse-encode cow ID\n");
    printf(CLR_YELLOW "  ─── MATH FUNCTIONS ────────────────────────────────\n" CLR_RESET);
    printf("   9.  sqrt   – Pen side length from area\n");
    printf("  10.  pow    – Milk production growth forecast\n");
    printf("  11.  ceil   – Round up feed bags to purchase\n");
    printf("  12.  floor  – Floor daily earnings\n");
    printf("  13.  fabs   – Yield deviation from target\n");
    printf("  14.  log    – Milk trend log-scale analysis\n");
    printf("  15.  round  – Round average yield to 0.5 L\n");
    printf(CLR_YELLOW "  ───────────────────────────────────────────────────\n" CLR_RESET);
    printf("   0.  Exit\n\n");
    printf(CLR_BOLD "  Enter choice: " CLR_RESET);
}

int main(void) {
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        if (choice != 0) {
            printf("\n");
            switch (choice) {
                case  1: fn_strlen();  break;
                case  2: fn_strcpy();  break;
                case  3: fn_strcat();  break;
                case  4: fn_strcmp();  break;
                case  5: fn_strncmp(); break;
                case  6: fn_toupper(); break;
                case  7: fn_tolower(); break;
                case  8: fn_strrev();  break;
                case  9: fn_sqrt();    break;
                case 10: fn_pow();     break;
                case 11: fn_ceil();    break;
                case 12: fn_floor();   break;
                case 13: fn_fabs();    break;
                case 14: fn_log();     break;
                case 15: fn_round();   break;
                default:
                    printf(CLR_RED "  Invalid choice. Please enter 0–15.\n" CLR_RESET);
            }
            printDivider();
            printf("  Press ENTER to return to menu...");
            getchar(); getchar();   /* consume newline + wait */
        }
    } while (choice != 0);

    printf(CLR_GREEN "\n  Exiting Dairy Farm Management System. Goodbye!\n\n" CLR_RESET);
    return 0;
}
