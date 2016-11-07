/* Billy Brown
   UTA ID: 1000955609
   4/8/15
   Description: An interactive menu, in which user selects a number between 1 and 4.The program then responds 
		with a corresponding message depending on which number is chosen.
*/
#include <stdio.h>
#include <string.h>
int main(void)
{
	char *pszMessage[4] = {"Please add a record.",
			      "Please change a record.",
			      "Please delete a record.",
			      "Bye Bye!"};
	int i;
	char cKey;
	while (i!=4)
	{
		printf("1 - Add a record\n");
		printf("2 - Change a record\n");
		printf("3 - Delete a record\n");
		printf("4 - Quit\n");
		printf("Enter a selection: ");
		scanf("%d",&i);
		
		switch(i)
		{
			case 1:
			   printf("%s\n",pszMessage[i-1]);
			   printf("Press any key to continue...\n");
			   getchar();
			   getchar();
			   break;
			case 2:
                           printf("%s\n",pszMessage[i-1]);
			   printf("Press any key to continue...\n");
			   getchar();
			   getchar();
                           break;
			case 3:
                           printf("%s\n",pszMessage[i-1]);
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
