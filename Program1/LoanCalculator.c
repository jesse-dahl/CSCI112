/*
 *Jesse Dahl
 *Sam Heutmaker 
 *CSCI112
 *Program1
 *10/12/18
 */
#include <stdio.h>
#include <math.h>

//Function that prompts the user for the necessary information for the program
//We use pointers (*) to point to the variables passed to this function in the main function in order to properly assign the user's values to the variables
//Note that we dont include a return statement in this function. C only allows one return value from a function. This is why we use pointers for this function
void readInputs(double *presentValue, double *rateOfInterest, int *numberOfPayments)
{
    //Print and scan statements that ask for the user to enter values and assigns those values to the pointers above
    printf("Enter the loan amount: ");
    scanf("%lf", presentValue);

    printf("Enter the yearly rate of interest (as a percentage): ");
    scanf("%lf", rateOfInterest);    

    printf("Enter the number of payments: ");
    scanf("%d", numberOfPayments);

}

//Function that calculates the EMI (Equated Monthly Installment AKA monthly payment)
double EMICalculation(double presentValue, double rateOfInterest, int numberOfPayments, double EMI)
{
    EMI = (rateOfInterest*presentValue)/(1-pow((1+rateOfInterest),(-1*numberOfPayments)));
    EMI = floor(EMI*100+0.5)/100;

    return(EMI);
}

//Function that prints out the table
void printTable(double presentValue, double rateOfInterest, int numberOfPayments, double EMI)//Function parameters
{
    double annualInterest = (rateOfInterest*12*100); //Calculates the annual interest and assigns it to variable "annualInterest"
    double interest, principal; //Creates two variables of data type double
    int i; //Creates a variable "i" that will be used in a future for-loop    

    FILE *fp; //Creates a variable "fp" that is assigned to a file type
    
    fp = fopen("loanTable.txt", "w"); //"w" creates a new file named "loanTable.txt" to write to. fopen opens this new file

    if (fp != NULL) //if statement to check if file "fp" exists
    {
        //prints the first three rows in the file
        //Formatting goes as such: "%-15s" will left-justify the column for up to 15 characters. "%5s" will create a new column with a width of 5 characters, etc... "s" is just a placeholder for a variable of string data
        fprintf(fp, "%-15s %5s%.2lf %15s %5s%.2lf\n", "Princpal", "$", presentValue, "Payment", "$", EMI);
        fprintf(fp, "%-15s %5s%.1lf %17s %10d %s\n", "Annual Interest", "%", annualInterest, "Term", numberOfPayments, "months");
        fprintf(fp, "\n%-10s %8s %12s %20s\n", "Payment", "Interest", "Principal", "Principal Balance");
        //for-loop that calculates the interest, principal, and principal balance for each payment you have to make and prints each out for as many times as number of payments the user entered
        for(i=0;i<numberOfPayments;i++) //"i" keeps track of the amount of times the for-loop has looped. Every time the for-loop loops, 1 is added to the value of "i"
        {
            interest=(presentValue*rateOfInterest);
            if(interest<0) interest=0;
            
            principal=(EMI-interest);
            if(principal<0) principal=0;

            presentValue = (presentValue-principal);
            if(presentValue<0) presentValue=0;

            fprintf(fp, "%-6d %10.2lf %13.2lf %16.2lf\n", i+1, interest, principal, presentValue); //We add 1 to "i" because "i" starts as 0 and increments up, when we want it to start at 1 and increment up when printing
        }
        
        fprintf(fp, "\nFinal payment\t $%.2lf\n", interest+principal); //Calculates and prints the final payment
    }
    fclose(fp); //Closes the file

}

//Main function that declares variables to be used throughout the program and prints to the console
int main(void)
{
    double EMI=0;
    double presentValue;
    double  rateOfInterest;
    int numberOfPayments;
    
    //Function call to the function "readInputs" with variables to pass to the function
    readInputs(&presentValue, &rateOfInterest, &numberOfPayments); //We use "&" to pass the ADDRESSES of the pointer variables
    rateOfInterest=(rateOfInterest/100)/12;    

    //Function call to the function "EMICalculation"
    EMI = EMICalculation(presentValue, rateOfInterest, numberOfPayments, EMI);
    
    //Function call to the function "printTable"
    printTable(presentValue, rateOfInterest, numberOfPayments, EMI);

    //Prints the final monthly payment to the console
    printf("\nThe final monthly payment is: $%.2lf\n", EMI);
    
    double totalInterest = (EMI*numberOfPayments-presentValue);
    
    //Prints the total interest paid to the console
    printf("The total interest paid is: $%.2lf\n", totalInterest);    

    return(0);
}
