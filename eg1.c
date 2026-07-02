#include <stdio.h>
#include <string.h>
int main() {
    int marks, age;
    char name[20], con='y';

    do{
        if (con!='y'){
            printf("you can't exit\n");
        }
    for (int i=0; i<1;i++){
        printf("Enter your name ");
        scanf("%s",name);
        printf("Enter your age ");
        scanf("%d",&age);
        printf("Enter your marks ");
        scanf("%d",&marks);

        printf("\nName: %s",name);
        printf("\nAge: %d",age);
        printf("\nMarks: %d",marks);

    }
    printf("\nDo you want to con... (y/n)");
    scanf(" %c",&con);
    }
    while(con=='y' || con=='n');
    
    
    
    
    
    

return 0;

}