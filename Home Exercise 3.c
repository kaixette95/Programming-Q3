#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//self-referential structure
struct listnode {
	int data; //listnode contains a number
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
int determine(ListNodePtr *sPtr, char expression);

int main()
{
	ListNodePtr startPtr = NULL;
	char data[200]; //user's expression
	int option;
	int *length;
	
	//prompt user to enter expression
	printf("Enter an expression: ");
	scanf("%s", data)
	
	*length = strlen(data);


	//determine user's expression whether is it pre, in or postfix
	determine(&startPtr, data);
	
	//menu
	printf("\nEnter your option: ");
	printf("\n1. Infix to postfix");
	printf("\n2. Infix to prefix");
	printf("\n3. Postfix to prefix");
	printf("\n4. Postfix to infix");
	printf("\n5. Prefix to postfix");
	printf("\n6. Prefix to infix");
	
	scanf("%d", &option);
	
	if(option == 1)
	{
		IntoPost(&startPtr, data);
	}
	else if(option == 2)
	{
		IntoPre(&startPtr, data);
	}
	
	else if(option == 3)
	{
		PosttoPre(&startPtr, data);
	}
	
	else if(option == 4)
	{
		PosttoIn(&startPtr, data);
	}
	
	else if(option == 5)
	{
		PretoPost(&startPtr, data);
	}
	
	else if(option == 6)
	{
		PretoIn(&startPtr, data);
	}
	
	else if(option == 7)
	{
		return 0;
	}
}

determine(ListNodePtr *sPtr, char expression)
{
	int i;
	int openbracket;
	int closebracket;
	
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
	
		if(openbracket != closebracket)
		{
			printf("Invalid expression\n");
			return 0;
		}
		
		if((isdigit(expression[0]) || expression[0] == '(') && (isdigit(expression[length-1]) || expression[length-1] == ')') )
		{
			printf("\n%s\n This is an infix expression", expression);
		}
}

/*IntoPost(ListNodePtr *sPtr, char expression)
{
	
}*/
