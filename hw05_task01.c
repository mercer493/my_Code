/* Billy Brown
   1000955609
   4/5/15
   Description: A program which prompts the user for a numerical value, and then approximates the value of e^x,
		where x is the numerical value given by the user, using Taylor Series.
*/
#include <stdio.h>
#include <math.h>
//This function simply implements the factorial operation
int Factorial(int i)
{
	if(i == 0)
		return 1;

	return i * Factorial(i - 1);
}

//Returns the value of e^x, calculated using the Taylor Series
double Taylor_Series(double fInput,int i)
{
	if (i ==0)
		return 1;
	return (pow(fInput,(double)i)/(Factorial(i))) + Taylor_Series(fInput,i-1);
}

//Main Function
int main(void)
{
	double fInput,fResult;
	printf("Please input a value for x: ");
	scanf("%lf",&fInput);//Obtain user input for the value of x in e^x
	printf("\n");
	printf("exp(x) == %lf\n",exp(fInput));//Prints the actual value of e^x
	printf("\n");
	int i;
	for(i=0;i<10;i++)
	{
		fResult = Taylor_Series(fInput,i);//Initiates the recursive calls necessary for Taylor Series Approximation
        //Compares the actual vs approximated values of e^x, in order to show the validity of the Taylor Series
        printf("When n == %d,Taylor_Series(x,%d) = %lf\n",i,i,fResult);
	}
	return 0;
}
