#include <stdio.h>
#include <math.h>
                                                                      // WEIGHT CALCULATOR
int main(){
    int option = 0;
    float  pound = 0.0f;
    float kilogram = 0.0f;


    printf("========== WEIGHT CALCULATOR===========||\n");
    printf("1. pound to kilogram\n");
    printf("2. kilogram to pound\n");
    printf("Enter 1 or 2 option :");
    scanf("%d",&option);

    if(option == 1){
        printf("Enter the value in pound :");
        scanf("%f",&pound);
        kilogram = pound * 2.2046;
        printf("%.2f pound in kilogram is %.2f ",pound ,kilogram);
    }

    else if (option == 2){
      printf("Enter the value in kilogram :");
      scanf("%f", &kilogram);        
      pound = kilogram * 2.2046 ;
      printf("%f kilogram in pound is %f ",kilogram , pound);
    }

    else {
    printf("Enter valid choice !!!");
    }
    
    return 0;
}