#include<stdio.h>
#include<stdlib.h>

/********************************
 * Jesse Dahl
 * Lab 5
 * October 23, 2018
 *******************************/

//Function Calls
void selectionSort(char *array, int N);
void Swap(char *a, char *b);

//Main function
int main(void)
{
    
    //Initialization
    int count=0;
    int i;
    char array[100];
    
    //Reads in the input file and adds each character in each row to the array, until the loop hits '0'
    while(fscanf(stdin, "%c", &array[count])&&array[count]!='0')
    {
        count++;
    }

    //Function call to selectionSort() with the array and number of values in the array as parameters
    selectionSort(array, count);
    
    //For loop that prints each value of the array
    for(i=0;i<count;i++)
    {
        printf("%c ", array[i]);
    }

return(0);
}

//Function that implements the selection sorting algorithm to sort the characters in the array
void selectionSort(char *array, int N)
{
    //Initialization
    int i, j;

    //Selection sorting algorithm
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(array[i]>array[j])
            {
                Swap(&array[i], &array[j]);//Function call to Swap()
            }
        }
    }
} 

//Function that 'swaps' the characters in order from greaatest to leasr
void Swap(char *a, char *b)
{
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
}

