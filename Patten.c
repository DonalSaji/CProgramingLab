#include <stdio.h>
int main() {
    int i;

// Print the pattern 1
printf("Pattern 1:\n");
for(int n=1; n<=5;n++){

    for(int j=5; j>=n; j--){
        printf(" ");
    }
    for(i=1; i<=n; i++){
        printf("%d",i);
    }
    if (n>1){
        for(int k=n-1; k>=1; k--){
            printf("%d",k);
        }
    }
    printf("\n");

}

for(int n=5; n>=1;n--){

    for(int j=5; j>=n; j--){
        printf(" ");
    }
    for(i=1; i<=n; i++){
        printf("%d",i);
    }
    if (n>1){
        for(int k=n-1; k>=1; k--){
            printf("%d",k);
        }
    }
    printf("\n");

}

printf("\nPattern 2:\n");
for(int n=1; n<=5;n++){
    for(i=1; i<=n; i++){
        if (n%2==0){
            if (i%2==0){
            printf("1");
        }
        else{   
        printf("0");
        }
        }
        else{
        
        if (i%2==0){
            printf("0");
        }
        else{   
        printf("1");
        }
    }
    }
    printf("\n");
}
printf("\nPattern 3:\n");
int n = 4;
    int num = 2; 
    for ( int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            // Keep checking numbers until we find the next prime
            while (1) {
                int isPrime = 1;
                for (int k = 2; k * k <= num; k++) {
                    if (num % k == 0) {
                        isPrime = 0; // Not a prime
                        break;
                    }
                }
                if (isPrime == 1) {
                    printf("%d ", num);
                    num++;
                    break; // Move to the next spot in the pyramid
                }
                num++;
            }
        }
        printf("\n");
    }
printf("\nPattern 4:\n");
 n = 6;
    for (int i = 0; i < n; i++) {
        for (int space = 1; space <= n - i; space++) {
            printf(" ");
        }
        int val = 1;
        for (int j = 0; j <= i; j++) {
            printf("%d ", val);
            // Calculate the next number in the row using basic math
            val = val * (i - j) / (j + 1);
        }
        printf("\n");
    }
printf("\nPattern 5:\n");
 num=1;
for(int n=1; n<=5;n++){

    
    for(i=1; i<=n; i++){

        printf("%d ",num);
        num++;
    }
    
    printf("\n");

}
printf("\nPattern 6:\n");
 n = 4;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // Find the minimum distance from all 4 edges to find the "layer"
            int left = j;
            int right = n - j + 1;
            int top = i;
            int bottom = n - i + 1;
            
            int layer = left;
            if (right < layer)  layer = right;
            if (top < layer)    layer = top;
            if (bottom < layer) layer = bottom;
            
            // Calculate sum of elements in all outer layers
            int val = 0;
            for (int k = 1; k < layer; k++) {
                val += 4 * (n - 2 * k + 1);
            }
            
            // Step along the 4 sides of the current layer
            if (i == layer) {
                val += (j - layer + 1);
            } else if (j == n - layer + 1) {
                val += (n - 2 * layer + 1) + (i - layer);
            } else if (i == n - layer + 1) {
                val += 2 * (n - 2 * layer + 1) + (n - layer + 1 - j);
            } else {
                val += 3 * (n - 2 * layer + 1) + (n - layer + 1 - i);
            }
            
            printf("%d\t", val);
        }
        printf("\n");
    }
printf("\nPattern 7:\n");
 n = 5;
    for (int i = 0; i < n; i++) {
        // Increasing letters up to the peak
        for (int j = 0; j <= i; j++) {
            printf("%c", 'A' + j);
        }
        // Decreasing letters back down to 'A'
        for (int j = i - 1; j >= 0; j--) {
            printf("%c", 'A' + j);
        }
        printf("\n");
    }
printf("\nPattern 8:\n");
 n = 5;
    for (int i = 1; i <= n; i++) {
        // Column 1 is i, Column 2 is n-i+1, Column 3 is i
        printf("%d %d %d\n", i, n - i + 1, i);
    }
printf("\nPattern 9:\n");
 n = 5;
    for (int i = 1; i <= n; i++) {
        int val = i;
        for (int j = 1; j <= n; j++) {
            printf("%d ", val);
            val += 4; // Numbers jump by 4 horizontally
        }
        printf("\n");
    }
    return 0;
}
