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
    printf("\n"  "╔══════════════════════════════════════════╗\n");
    printf(           "║  %-40s  ║\n", title);
    printf(           "╚══════════════════════════════════════════╝\n" );
}

/* ── Utility: print divider ─────────────────────────────── */
void printDivider(void) {
    printf( "  ──────────────────────────────────────────\n" );
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
    printf( "\n  Breed : \"%s\"\n" , breed);
    printf( "  Length: %d characters\n" , len);
}

/* 2. strcpy – Copy a breed name to a backup variable */
void fn_strcpy(void) {
    printHeader("2. strcpy  – Copy Breed Record");
    char original[100], backup[100];
    printf("  Enter original breed name: ");
    scanf(" %[^\n]", original);
    strcpy(backup, original);
    printf( "\n  Original : \"%s\"\n" , original);
    printf( "  Backup   : \"%s\"\n" , backup);
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
    printf( "\n  Full Profile: \"%s\"\n" , profile);
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
        printf( "  Result: Breeds are IDENTICAL\n" );
    else if (result < 0)
        printf( "  Result: \"%s\" comes BEFORE \"%s\" alphabetically\n" , b1, b2);
    else
        printf( "  Result: \"%s\" comes AFTER \"%s\" alphabetically\n" , b1, b2);
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
        printf( "  Result: PREFIX MATCHES – breed found!\n" );
    else
        printf( "  Result: PREFIX DOES NOT MATCH\n" );
}

/* 6. toupper (via loop) – Standardise breed name to uppercase */
void fn_toupper(void) {
    printHeader("6. toupper – Standardise Breed to Uppercase");
    char breed[100];
    printf("  Enter breed name (any case): ");
    scanf(" %[^\n]", breed);
    printf( "\n  Original  : \"%s\"\n" , breed);
    for (int i = 0; breed[i]; i++) breed[i] = toupper(breed[i]);
    printf( "  Uppercase : \"%s\"\n" , breed);
}

/* 7. tolower (via loop) – Convert tag to lowercase for storage */
void fn_tolower(void) {
    printHeader("7. tolower – Convert Tag to Lowercase");
    char tag[100];
    printf("  Enter cow tag / ID (any case): ");
    scanf(" %[^\n]", tag);
    printf( "\n  Original  : \"%s\"\n" , tag);
    for (int i = 0; tag[i]; i++) tag[i] = tolower(tag[i]);
    printf( "  Lowercase : \"%s\"\n" , tag);
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
    printf( "\n  Original ID : \"%s\"\n" , id);
    printf( "  Archived ID : \"%s\"\n" , rev);
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
    if (area < 0) { printf( "  Error: area cannot be negative.\n" ); return; }
    double side = sqrt(area);
    printf( "\n  Pen area    : %.2f sq. m\n" , area);
    printf( "  Side length : %.2f m  (for a square pen)\n" , side);
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
    printf( "\n  Current yield : %.2f L/day\n" , currentYield);
    printf( "  Growth rate   : %.1f%% per year\n" , growthRate);
    printf( "  Forecast in %d year(s): %.2f L/day\n" , years, forecast);
}

/* 11. ceil – Round up feed quantity to whole bags */
void fn_ceil(void) {
    printHeader("11. ceil – Round Up Feed to Whole Bags");
    double feedNeeded;
    printf("  Enter exact feed needed (kg): ");
    scanf("%lf", &feedNeeded);
    double bags = feedNeeded / 25.0;    /* each bag = 25 kg */
    double bagsNeeded = ceil(bags);
    printf( "\n  Feed required         : %.2f kg\n" , feedNeeded);
    printf( "  Bag size              : 25 kg\n" );
    printf( "  Bags to purchase      : %.0f bag(s)  (rounded up)\n" , bagsNeeded);
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
    printf( "\n  Gross earnings : Rs. %.4f\n" , earned);
    printf( "  Settled amount : Rs. %.2f  (paisa dropped)\n" , floored);
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
    printf( "\n  Target yield    : %.2f L\n" , target);
    printf( "  Actual yield    : %.2f L\n" , actual);
    printf( "  Absolute deviation: %.2f L (%s target)\n" ,
           deviation, actual >= target ? "above" : "below");
}

/* 14. log / log10 – Log-scale milk trend analysis */
void fn_log(void) {
    printHeader("14. log / log10 – Milk Trend Analysis");
    double yield;
    printf("  Enter total monthly yield (litres): ");
    scanf("%lf", &yield);
    if (yield <= 0) { printf( "  Error: yield must be positive.\n" ); return; }
    printf( "\n  Monthly yield : %.2f L\n" , yield);
    printf( "  log (natural) : %.4f\n" , log(yield));
    printf( "  log10 (base-10): %.4f\n" , log10(yield));
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
    if (days <= 0) { printf( "  Error: days must be > 0.\n" ); return; }
    double avg = total / days;
    double rounded = round(avg * 2.0) / 2.0;   /* round to nearest 0.5 */
    printf( "\n  Total collected    : %.2f L over %d days\n" , total, days);
    printf( "  Raw average        : %.4f L/day\n" , avg);
    printf( "  Rounded avg (0.5 L): %.1f L/day\n" , rounded);
}

/*
 *  ══════════════════════════════════════════
 *  MAIN MENU
 *  ══════════════════════════════════════════
 */
void printMenu(void) {
    clearScreen();
    printf("\n  ╔═══════════════════════════════════════════════════╗\n");
    printf(  "  ║       DAIRY FARM MANAGEMENT SYSTEM               ║\n");
    printf(  "  ║       String & Math Function Showcase            ║\n");
    printf(  "  ╠═══════════════════════════════════════════════════╣\n");
    printf( "  ─── STRING FUNCTIONS ─────────────────────────────\n" );
    printf("   1.  strlen  – Breed name length\n");
    printf("   2.  strcpy  – Copy breed record\n");
    printf("   3.  strcat  – Build cow profile string\n");
    printf("   4.  strcmp  – Compare two breed names\n");
    printf("   5.  strncmp – Prefix-match breed tag\n");
    printf("   6.  toupper – Standardise breed to uppercase\n");
    printf("   7.  tolower – Convert tag to lowercase\n");
    printf("   8.  strrev  – Reverse-encode cow ID\n");
    printf( "  ─── MATH FUNCTIONS ────────────────────────────────\n" );
    printf("   9.  sqrt   – Pen side length from area\n");
    printf("  10.  pow    – Milk production growth forecast\n");
    printf("  11.  ceil   – Round up feed bags to purchase\n");
    printf("  12.  floor  – Floor daily earnings\n");
    printf("  13.  fabs   – Yield deviation from target\n");
    printf("  14.  log    – Milk trend log-scale analysis\n");
    printf("  15.  round  – Round average yield to 0.5 L\n");
    printf( "  ───────────────────────────────────────────────────\n" );
    printf("   0.  Exit\n\n");
    printf( "  Enter choice: " );
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
                    printf( "  Invalid choice. Please enter 0–15.\n" );
            }
            printDivider();
            printf("  Press ENTER to return to menu...");
            getchar(); getchar();   /* consume newline + wait */
        }
    } while (choice != 0);

    printf( "\n  Exiting Dairy Farm Management System. Goodbye!\n\n" );
    return 0;
}
