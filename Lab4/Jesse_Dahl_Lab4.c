/************************************
 * Jesse Dahl
 * CSCI112 Lab4
 * 10/19/18
 * Program to find the area of a polygon
 ************************************/
//Include the following header files
#include <stdio.h>
#include<stdlib.h>
#include <math.h>

//Declare the functions used in the program
void get_corners(float x[], float y[]);
float polygon_area(float x[], float y[], int k);
void output_corners(FILE *fp, float x[], float y[], int k);

//Define the main function
int main(void)
{
    //Declare requried arrays for the program
    float x[7], y[7];
    
    //Calls the 'get_corners' function
    get_corners(x,y);

    return(0);    
}

//Defines the function 'get_corners'
void get_corners(float x[], float y[])
{
    //Declares required file pointer and variables
    FILE *fp;
    int j=0, k=0, c=0;
    float i, area;

    //Use fscanf() to read the file data
    while(fscanf(stdin,"%f",&i)==1)
    {
        c++;

        //Checks the value of c
        if(c%2!=0)
        {
            //If C isn't even, assign the value of i to array x and increment the k counter
            x[k]=i;
            k++;
        }
        //The else will execute when c is even
        else
        {
            //Assign the value of i to array y and increment the j counter
            y[j]=i;
            j++;
        }
    }

    //Calls the polygon_area function
    area = polygon_area(x,y,k);

    //Prints the area of the polygon    
    printf("Area of the polygon = %.2f\n", area);
    
    //Opens and closes the declared file open just because GCC can be a really stupid compiler and it flags undeclared variables as errors
    fp = fopen("area.txt", "w");
    fclose(fp);

    //Calls the output_corners function
    output_corners(fp,x,y,k);      
}

//Defines the polygon_area function
float polygon_area(float x[], float y[], int k)
{
    //Declaration
    float sum = 0.0, a, a1;
    int i;

    //Starts the for loop
    for(i=0;i<(k-1);i++)
    {
        //Computes the sum of the polygon
        sum = sum + ((x[i+1]+x[i])*(y[i+1]-y[i]));
    }
    //Computes the absolute value of the variable sum
    a1=abs(sum);
    
    //Divide a1 by 2 to calculate the area of the polygon
    a=(a1/2);

return(a);
}

//Defines the function output_corners
void output_corners(FILE *fp, float x[], float y[], int k)
{
    int i;
    
    //Opens the file
    fp = fopen("area.txt", "w");

    //Prints to the file
    fprintf(fp,"X\tY\n");
    fprintf(fp,"------------------");

    //Starts a for loop that prints the data to the file
    for(i=0;i<k;i++)
    {
        fprintf(fp,"\n%.1f\t%.1f\n", x[i],y[i]);
    }

    //Closes the file
    fclose(fp);
}
