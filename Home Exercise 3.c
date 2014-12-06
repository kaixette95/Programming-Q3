#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//global variable


//self-referential structure
struct listnode {
	char data[200]; //listnode contains a number
	struct listnode *nextPtr; //pointer to next node
};

typedef struct listnode ListNode;
typedef ListNode *ListNodePtr;

// function prototypes
int insert(ListNodePtr *sPtr, char expression);
int IntoPost(ListNodePtr *sPtr, char expression);
int IntoPre(ListNodePtr *sPtr, char expression);
int PosttoPre(ListNodePtr *sPtr, char expression);
int PosttoIn(ListNodePtr *sPtr, char expression);
int PretoPost(ListNodePtr *sPtr, char expression);
int PretoIn(ListNodePtr *sPtr, char expression);
int evaluate(char expression[200]);
int determine(char expression[200]);

int main(void)
{
	ListNodePtr startPtr = NULL;
	char data[200]; //user's expression
	int option;
	int condition;
	
	//prompt user to enter expression
	printf("Enter an expression: ");
	scanf("%s", data);
	

	//determine user's expression whether is it pre, in or postfix
	condition = determine(data);
	
	if(condition == 1)
	{
		return 0;
	}
	//menu
	printf("==============================================");
	printf("\n   %s", data);
	printf("\n==============================================");
	printf("\nEnter your option: ");
	printf("\n1. Infix to postfix");
	printf("\n2. Infix to prefix");
	printf("\n3. Postfix to prefix");
	printf("\n4. Postfix to infix");
	printf("\n5. Prefix to postfix");
	printf("\n6. Prefix to infix");
	printf("\n7. Evaluate the expression");
	printf("\n8. Exit");
	printf("\n\nYour option: ");
	
	scanf("%d", &option);
	
	if(condition == 2)
	{
		if(option == 1)
		{
			//IntoPost(&startPtr, data);
		}
		
		else if(option == 2)
		{
			//IntoPre(&startPtr, data);
		}
	
		else if(option == 3)
		{
			printf("This option is invalid");
		}
	
		else if(option == 4)
		{
			printf("This option is invalid");
		}
	
		else if(option == 5)
		{
			printf("This option is invalid");
		}
	
		else if(option == 6)
		{
			printf("This option is invalid");
		}
	
		else if(option == 7)
		{
			//evaluate(data);
		}
	
		else if(option == 8)
		{
			return 0;
		}
	}
	
	if(condition == 3)
	{
		if(option == 1)
		{
			printf("This option is invalid");
		}
		
		else if(option == 2)
		{
			printf("This option is invalid");
		}
	
		else if(option == 3)
		{
			printf("This option is invalid");
		}
	
		else if(option == 4)
		{
			printf("This option is invalid");
		}
	
		else if(option == 5)
		{
			//PretoPost(&startPtr, data);
		}
	
		else if(option == 6)
		{
			//PretoIn(&startPtr, data);
		}
	
		else if(option == 7)
		{
			//evaluate(data);
		}
	
		else if(option == 8)
		{
			return 0;
		}
	}
	
	if(condition == 4)
	{
		if(option == 1)
		{
			printf("This option is invalid");
		}
		
		else if(option == 2)
		{
			printf("This option is invalid");
		}
	
		else if(option == 3)
		{
			//PosttoPre(&startPtr, data);
		}
	
		else if(option == 4)
		{
			//PosttoIn(&startPtr, data);
		}
	
		else if(option == 5)
		{
			printf("This option is invalid");
		}
	
		else if(option == 6)
		{
			printf("This option is invalid");
		}
	
		else if(option == 7)
		{
			//evaluate(data);
		}
	
		else if(option == 8)
		{
			return 0;
		}
	}
}

int determine(char expression[200])
{
	int i;
	int openbracket=0;
	int closebracket=0;
	
	for(i=0; expression[i] != '\0'; i++)
	{
		if(expression[i] == '(')
		{
			openbracket++;
		}
		
		if(expression[i] == ')')
		{
			closebracket++;
		}
		
	}
	
		//if number of openbracket is different from closing bracket, invalid expression
		if(openbracket != closebracket)
		{
			printf("Invalid expression\n");
			return 1;
		}
		else
		{
		//determine whether expression is infix
		if((isdigit(expression[0]) || expression[0] == '(') && (isdigit(expression[strlen(expression)-1]) || expression[strlen(expression)-1] == ')') )
		{
			printf("\nThis is an infix expression\n", expression);
			return 2;
		}
		
		//if the 1st character is punctuation but not '(' and ')', and the last character is digit (prefix)
		else if((ispunct(expression[0]) && (expression[0] != '(' && expression[0] != ')')) && isdigit(expression[strlen(expression)-1]) ) 
  		{
    		printf("\nThis is an prefix expression\n", expression);
    		return 3;
  		}
  		
  		//if the 1st character is digit, last character is punctuation but not '(' and ')' (postfix)
  		else if ( isdigit(expression[0]) && (ispunct(expression[strlen(expression)-1]) && (expression[strlen(expression)-1] != '(' && expression[strlen(expression)-1] != ')')) ) 
    	{
     		printf("\nThis is an postfix expression\n", expression);
       		return 4;
       	}
       	else
       	{
       		printf("\nInvalid expression\n");
       	}
		}
}

/*IntoPost(ListNodePtr *sPtr, char expression)
{
	
}*/
