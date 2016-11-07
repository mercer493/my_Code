/* Billy Brown
   UTA ID: 1000955609
   4/7/15
   Description: An extra credit program in which the interactive menu from the previous has been implemented using a one-dimensional
		array of integers, also known as "records".
*/
#include <stdio.h>
#include <string.h>
#define LEN 10
void print_array(int rgnArray[LEN])
{
	int x;
	for(x=0;x<LEN;x++)
	{
		if (rgnArray[x] == 0)
			continue;
		printf("%d ",rgnArray[x]);
	}
}
int main(void)
{
        char *pszMessage[4] = {"Please add a record: ",
                              "Please change a record.",
                              "Please delete a record.",
                              "Bye Bye!"};
	int rgnArray[LEN] = {1,2,3,4,5};
	int *pnArray = rgnArray;	
        int i;
        char cKey;
        while (i!=4)
        {
		int nInput,nIndex,nIndex2;
                printf("1 - Add a record\n");
                printf("2 - Change a record\n");
                printf("3 - Delete a record\n");
                printf("4 - Quit\n");
                printf("Enter a selection: ");
                scanf("%d",&i);
                switch(i)
                {
                        case 1:
                           printf("%s",pszMessage[i-1]);
			   scanf("%d",&nInput);
			   if (*(pnArray + (LEN-1)) != 0)
			   {
			   	printf("Error: Record limit reached\n");
				break;
			   }
			   int j;
			   for(j=0;j<LEN;j++)
			   {
				if (*(pnArray + j) == 0)
				{
					*(pnArray + j) = nInput;
					break;
				}
			   }
			   print_array(rgnArray);
                           printf("Press any key to continue...\n");
                           getchar();
                           getchar();
                           break;
                        case 2:
                           printf("%s\n",pszMessage[i-1]);
			   printf("Enter the value of the new record: ");
			   scanf("%d",&nInput);
			   printf("Enter the position of the record you wish to change: ");
			   scanf("%d",&nIndex);
			   *(pnArray + nIndex) = nInput;
			   print_array(rgnArray);
                           printf("Press any key to continue...\n");
                           getchar();
                           getchar();
                           break;
                        case 3:
                           printf("%s\n",pszMessage[i-1]);
			   printf("Enter the Position of the record you wish to delete: ");
			   scanf("%d",&nIndex2);
			   *(pnArray + nIndex2) = 0;
			   print_array(rgnArray);
                           printf("Press any key to continue...\n");
                           getchar();
                           getchar();
                           break;
                        case 4:
                           printf("%s\n",pszMessage[i-1]);
                           break;
                }



        }
        return 0;
}

