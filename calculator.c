#include<stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, float b);


int main(){
    int a, b,op;
    float ans;
    printf("Enter the 1st number ");
    scanf("%d",&a);
    printf("Enter the 2nd number ");
    scanf("%d",&b);
    printf("1. Addition \n2. Subtraction \n3. Multiplication \n4. Division \nEnter the opration number ");
    scanf("%d",&op);
    
    switch(op){
        case 1: ans=add(a,b);
        printf("%d + %d = %.2f",a,b,ans);
        break;
        case 2: ans=subtract(a,b);
        printf("%d - %d = %.2f",a,b,ans);
        break;
        case 3: ans=multiply(a,b);
        printf("%d * %d = %.2f",a,b,ans);
        break;
        case 4: ans=divide(a,b);
        printf("%d / %d = %.2f",a,b,ans);
        break;
        default:
    printf( "  Invalid choice.\n" );
    }
    return 0;
}

int add(int a, int b){
    return (a+b);
}
int subtract(int a, int b){
    return (a-b);
}
int multiply(int a, int b){
    return (a*b);
}
float divide(int a, float b){
    return (a/b);
}  