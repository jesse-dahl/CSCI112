#include<stdio.h>
#include<math.h>

//Function calls to avoid "implicit declaration" errors
double largest(double*, int);
double smallest(double*, int);
double average(double*, int);


int main(void) 
{
    int N, i;

    //scans the redirected file and stores the first number in "N"
    fscanf(stdin, "%d", &N);

    //Creates empty array and fills it with values from file
    double array[N];

    for(i=0;i<N;i++)
    {
        fscanf(stdin, "%lf", &array[i]);
    }
    
    //Creates a pointer to the array to pass as a parameter to functions
    double *pointer = &array[0];

    //Outputing results
    double max = largest(pointer, N);
    double min = smallest(pointer, N);
    double avg = average(pointer, N);

    printf("The smallest number in the set of numbers is: %.0lf\n", min);
    printf("The largest number in the set of numbers is: %.0lf\n", max);
    printf("The average of the numbers is: %.2lf\n", avg);        

    //Getting the range
    int range = (max-min);

    //Calculating standard deviation
    double sum_squares = 0;
    //For loop that iterates though the array and squares each index, adding the square of each index to "sum_squares"
    for(i=0;i<N;i++)
    {
        sum_squares = sum_squares+(array[i]*array[i]);
    }
    
    double standardDeviation = sqrt(((sum_squares)/N)-(avg*avg));
    
    //Outputing the rest of the results
    printf("The range of the numbers is: %d\n", range);
    printf("The standard deviation of the numbers is: %.2lf\n", standardDeviation);

return(0);
}

//Function that returns the largest number in the list
double largest(double *pointer,int N)
{
    int i;
    //Sets local variable "largest" to the number in the first index of the array of numbers
    double largest=pointer[0];

    //For loop that iterates through the array of numbers for as many numbers as there are in the list and if a number in the list is greater than the current value of variable "largest", it assigns the greater number to the variable
    for(i=1;i<N;i++)
    {
        if(pointer[i] > largest)
        {
            largest = pointer[i];
        }
    }    

return(largest);
}

//Function that returns the smallest number in the list
double smallest(double *pointer, int N)
{
    int i;

    double smallest=pointer[0];

    //Much like the for loop for the largest function, this loop iterates through the array of numbers and if a number in the array is less than the current value of variable "smallest" it assigns the lesser number to the variable
    for(i=1;i<N;i++)
    {
        if(pointer[i] < smallest)
        {
            smallest = pointer[i];
        }
    }

return(smallest);
}

//Function that returns the average of the numbers in the list
double average(double *pointer, int N)
{
    double sum = 0;
    int i;

    //For loop that iterates through the array of numbers and adds the value at each index to the variable "sum"
    for(i=0;i<N;i++)
    {
        sum += pointer[i];
    }
    //Creates a variable "average" and makes it equal to the sum found above divided by the total items in the list
    double average = sum/N;

return(average);
}
