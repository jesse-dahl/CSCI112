#include <stdio.h>
#include <stdlib.h>

#define YEARS 5

//Function that prints program instructions to the user
int userInput(void){
    
    printf("Please provide the following inputs: house cost, annual fuel cost, and tax rate.\n");
    printf("Provide house cost and fuel costs an an integer - no commas.\n");
    printf("Provide tax rate as a decimal value with 0 followed by a . \n");
    printf("Example - 2-and-a-half percent would be entered as: 0.025.\n");
    
    return(0);
}

//Function that asks the user to input values and calculates the cost of their house over five years according to the respected values
int calculateCost(void){
    
    int houseCost,
            fuelCost; //Creates int data type variables "houseCost" and "fuelCost"
    
    float taxRate; //Creates a variable, "taxRate" as a float data type
    double totalCost; //Creates a variable, "totalCost" as a double data type
    
    printf("Initial house cost: "); //Prompts the user to enter the initial house cost
    scanf("%d", &houseCost); //Stores the value entered by the user above in the "houseCost" variable
    
    printf("Annual fuel cost: "); //Prompts the user to enter the annual fuel cost
    scanf("%d", &fuelCost); //Stores the value entered by the user above in the "fuelCost" variable
    
    printf("Tax rate: "); //Prompts the user to enter the tax rate
    scanf("%f", &taxRate); //Stores the value entered by the user above in the "taxRate" variable
    
    totalCost = ((houseCost+(fuelCost*YEARS)) + ((houseCost*taxRate)*YEARS)); //Calculates the total cost of the house over 5 years
    
    printf("The house cost after 5 years is $%.2f \n", totalCost); //prints the total cost of the house to the user
    return(0);
}

//Main function that calls the two functions above
int main(int argc, char** argv) {
    
    userInput();
    calculateCost();
    
    return (0);
}

