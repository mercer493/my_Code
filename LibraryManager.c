#include <stdio.h>
#include <string.h>
#define SIZE 5
typedef struct
{
	int nYear;
	int nMonth;
	int nDay;
}DATE;

typedef struct
{
	unsigned long luISBN;
	char cTitle[100];
	char cType[50];
	char cPublisher[50];
	int nPages;
	float fPrice;
	int nPublication;
	int nStatus;
	char cUser[25];
	DATE date;
	int nActive; 
	
}BOOK;

typedef enum 
{
	ADD = 1,
	REMOVE,
	CHECKOUT,
	CHECKIN,
	DETAILS,
	AVAILABLE_DETAILS,
	BOOK_UNAVAILABLE,
	EXIT
}ACTION;

void Library_Menu()
{
	printf("1. Add a new book\n");
	printf("2. Remove a book (input ISBN)\n");
	printf("3. Check out a book (input ISBN and the due date)\n");
	printf("4. Check in a book (input ISBN)\n");
	printf("5. Display all book details (along with their specialization)\n");
	printf("6. Display all available book details\n");
	printf("7. Display all checked out books\n");
	printf("8. Exit the program\n\n");
}

int User_Input()
{
	int nNum;
	printf("How can I help you today? ");
	scanf("%d",&nNum);
	return nNum;
}

int Check_Duplicate(BOOK *pTemp,unsigned long new_ISBN)
{
	while(1)
	{
		if (pTemp->luISBN == new_ISBN)
			return 1;

		if (pTemp->luISBN == 0)
			return 0;
		pTemp++;
	}	
}

void Remove_Book(BOOK *pTemp,unsigned long luInput)
{
	while(1)
	{
		if (pTemp->luISBN == luInput)
		{	
			pTemp->nActive = 0;
			break;
		}
		pTemp++;
	}
	printf("%s was removed from this library.",pTemp->cTitle);
	
}

void Checkout_Information(BOOK *pTemp)
{
	DATE *pDate = &pTemp->date;
	
	printf("And who currently has this book? ");
        fgets(pTemp->cUser,100,stdin);
	getchar();
	

        printf("Ok, and when will this book be due?\n");

       	printf("Enter a year: ");
       	scanf("%d",&pDate->nYear);
       	getchar();

       	printf("Enter a month: ");
     	scanf("%d",&pDate->nMonth);
       	getchar();

        printf("Enter a day: ");
        scanf("%d",&pDate->nDay);
        getchar();

        printf("%s has now been checked out to %s.\n",pTemp->cTitle,pTemp->cUser);
	
}


void Checkout_Book(BOOK *pTemp,unsigned long luInput)
{
        while(1)
        {
                if (pTemp->luISBN == luInput)
                {
                        pTemp->nStatus = 1;
                        break;
                }
                pTemp++;
        }
	Checkout_Information(pTemp);
}
	


void Decision_Tree(int nInput,BOOK *pBook,BOOK *pTemp)
{
	int i = 1;
	unsigned long luUser,luInput;
	switch(nInput)
	{
		case ADD:
		   while(i)
		   {
		   	printf("Enter an ISBN: ");
		   	scanf("%lu",&luUser);
		   	getchar();
			if (Check_Duplicate(pTemp,luUser) == 1)
			{
				printf("Please enter another ISBN. This ISBN already exists in this library.\n");
				continue;
			}
			pBook->luISBN = luUser;
			i = 0;	
		   }
		   printf("Enter a Title: ");
		   fgets(pBook->cTitle,100,stdin);

		   printf("What type of book is this? ");
		   fgets(pBook->cType,100,stdin);

		   printf("Publisher Name: ");
		   fgets(pBook->cPublisher,100,stdin);

		   printf("Number of Pages: ");
		   scanf("%d",&pBook->nPages);
		   getchar();

		   printf("Price of book: ");
		   scanf("%f",&pBook->fPrice);
		   getchar();

		   printf("Publication Date: ");
		   scanf("%d",&pBook->nPublication);
		   getchar();

		   printf("What is this book's status(enter either a one or a zero)? ");
		   scanf("%d",&pBook->nStatus);
		   getchar();
		   printf("\n");

		   if (pBook->nStatus == 1)
		   {
		   	printf("And who currently has this book? ");
			fgets(pBook->cUser,100,stdin);

			printf("Ok, and when will this book be due?\n");
			DATE *pdate = &(pBook->date);

			printf("Enter a year: ");
			scanf("%d",&pdate->nYear);
			getchar();

			printf("Enter a month: ");
                        scanf("%d",&pdate->nMonth);
			getchar();

			printf("Enter a day: ");
                        scanf("%d",&pdate->nDay);
			getchar();
			
		   }
		   pBook->nActive = 1;
		   pBook++;		
		   break;

		case REMOVE:
		   printf("Enter an ISBN: ");
		   scanf("%lu",&luInput);
		   Remove_Book(pTemp,luInput);
                   break;

		case CHECKOUT:
		   printf("Enter an ISBN: ");
		   scanf("%lu",&luInput);
		   Checkout_Book(pTemp,luInput);
                   break;

		case CHECKIN:
                   break;

		case DETAILS:
                   break;

		case AVAILABLE_DETAILS:
                   break;

		case BOOK_UNAVAILABLE:
                   break;

		case EXIT:
                   break;		
	}
}

int main(void)
{
	int nInput = 0;
	BOOK book[SIZE];
	BOOK *pBook = book;
	BOOK *pTemp = pBook;
	while(nInput != 8)
	{	
		Library_Menu();
		nInput = User_Input();
		Decision_Tree(nInput,pBook,pTemp);
		if (nInput == 1)
			pBook++;
	}
	return 0;	
}
