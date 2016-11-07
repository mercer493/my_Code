/* Billy Brown
   Student ID: 1000955609
   4/6/15
   Description: A program which asks the user for 10 different integers,stores the integers into an array,
		and then gives the user the option to swap the positions of any two integers in that array.
*/
#include <stdio.h>
void swap(int *pnArray,int nIndex1,int nIndex2)
{
	int nTemp = *(pnArray + nIndex1);
	*(pnArray + nIndex1) = *(pnArray + nIndex2);
	*(pnArray + nIndex2) = nTemp;
	
}

int main(void)
{
	int rgnArray[10],nSize = (sizeof(rgnArray)/sizeof(int));
	printf("Please input 10 integer values: ");
	int i;
	for(i = 0;i < nSize;i++)
	{
		scanf("%d",&rgnArray[i]);
	}
	int nIndex1,nIndex2;
	printf("Please enter an integer value between 0 and 9: ");
	scanf("%d",&nIndex1);
	printf("Please enter another integer value between 0 and 9: ");
	scanf("%d",&nIndex2);
	int *pnArray = rgnArray;
	swap(pnArray,nIndex1,nIndex2);
	int j;
	for(j = 0;j < nSize;j++)
        {
		if (j == (nSize - 1))
			printf("%d",rgnArray[j]);
                else
			printf("%d,",rgnArray[j]);
        }

	return 0;
}
