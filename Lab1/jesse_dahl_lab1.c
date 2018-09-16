/* Jesse Dahl
 * Lab1, CSCI112
 * 8/28/18
 */

//This program converts a number given by the user from feet to miles

#include<stdio.h> //includes printf and scanf definitions

#define MILE_PER_FOOT 0.000189394 //conversion constant

int main(void) {
	
	int feet; //Creates int variable 'feet' to store distance in feet
	double miles; //Creates double variable 'miles' to store the equivalent distance in miles

	//Get the distance in feet from user
	printf("Enter the distance in feet: ");
	scanf("%d", &feet);

	//Converts the distance to miles
	miles = (feet * MILE_PER_FOOT);

	//display the distance in miles

	printf("%d feet is equal to %.2f miles.\n", feet, miles);
	return(0);

}
