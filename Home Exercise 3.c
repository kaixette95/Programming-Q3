
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


//self-referential structure
struct node {
	int data; //listnode contains a number
	struct node *next; //pointer to next node
};


struct node *top = NULL;

//operators and its precedence
char priority[7][2] = {{'(', 0}, {'+', 1}, {'-', 1},
                             {'*', 2}, {'/', 2}, {'%', 2},
                             {')', 3}};

//creating node with the given data
struct node* createNode(int data)
{
	struct node *ptr = (struct node *) malloc(sizeof(struct node));
	ptr->data=data;
	ptr->next=NULL;
}

// function prototypes
void push(char data[200]); //insert operands and operators to stack
char pop(); //remove operators from stack
void IntoPost(char infix[], char postfix[]);
void IntoPre(char infix[], char postfix[]);
/*int PosttoPre();
int PosttoIn();
int PretoPost();
int PretoIn();*/
int evaluate(char str[200]);
int determine(char expression[200]);
int pop_evaluate(); //remove operands and operators from stack for evaluating expression


int main(void)
{
	FILE *inputPtr;
	FILE *outputPtr;
	
	char character[200]; //user's expression
	char output[200]; //output of conversion
	int option;
	int condition;
	int choice;
	int decide;
	char file[200];
	
	
	printf("Please enter your choice: ");
	printf("\n1. Get expression from file");
	printf("\n2. Enter expression from keyboard");
	printf("\nYour choice: ");
	
	scanf("%d", &choice);
	
	//get expression from file
	if(choice == 1)
	{
		if ((inputPtr=fopen("input.txt","r"))==NULL)
		{
			printf("File cannot be found!\n");
		}
		else
		{
			while(!feof(inputPtr))
			{
				fscanf(inputPtr, "%s", character);
			}
		}
		fclose(inputPtr); //closes file
	}
	else if(choice == 2)
	{
		//prompt user to enter expression
		printf("Enter an expression: ");
		scanf("%s", character);
	}

	//determine user's expression whether is it pre, in or postfix
	condition = determine(character);
	
	do
	{
	//print menu if expression is valid
	if(condition == 1)
	{
		return 0;
	}
	//menu
	printf("==============================================");
	printf("\n   %s", character);
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
	
	//menu for infix
	if(condition == 2)
	{
		if(option == 1)
		{
			IntoPost(character, output);
			printf("%s\n", output);
		}
		
		else if(option == 2)
		{
			strrev(character);
			IntoPre(character, output);
			strrev(output);
			printf("%s\n", output);
			
		}
	
		else if(option == 3)
		{
			printf("This option is invalid\n");
		}
	
		else if(option == 4)
		{
			printf("This option is invalid\n");
		}
	
		else if(option == 5)
		{
			printf("This option is invalid\n");
		}
	
		else if(option == 6)
		{
			printf("This option is invalid\n");
		}
	
		else if(option == 7)
		{
			evaluate(character);
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
			printf("This option is invalid\n");
		}
		
		else if(option == 2)
		{
			printf("This option is invalid\n");
		}
	
		else if(option == 3)
		{
			printf("This option is invalid\n");
		}
	
		else if(option == 4)
		{
			printf("This option is invalid\n");
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
			evaluate(character);
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
			printf("This option is invalid\n");
		}
		
		else if(option == 2)
		{
			printf("This option is invalid\n");
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
			printf("This option is invalid\n");
		}
	
		else if(option == 6)
		{
			printf("This option is invalid\n");
		}
	
		else if(option == 7)
		{
			evaluate(character);
			
		}
	
		else if(option == 8)
		{
			return 0;
		}
	}
	//open output file
	outputPtr = fopen("output.txt","a");
	//store output to file
	fprintf(outputPtr,"%s\n", output);
	fclose(outputPtr);
	
	printf("\nDo you want to continue?");
	printf("\n1.Yes\n2.No");
	printf("\nYour decision?: ");
	scanf("%d", &decide);
	
	
	}while(decide == 1);
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
			printf("Imbalanced Brackets\n");
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


int getIndex(char data[200])
{
	int i;
	for(i=0; i<7; i++)
	{
		if(data == priority[i][0])
		{
			return i;
		}
	}
}

void push(char data[200])
{
	struct node *ptr = createNode(data);
	
	if(top == NULL)
	{		
		top = ptr;
		return;
	}
	
	ptr->next = top;
	top = ptr;
}

//pop top data from stack
char pop()
{
	struct node *ptr;
	char data;
	
	if(top == NULL)
	{
		return -1;
	}
	ptr = top;
	top = top->next;
	data = ptr->data;
	free(ptr);
	return(data);
}

void IntoPost(char infix[], char postfix[])
{
	int i = 0;
	int j = 0;
	int index1;
	int index2;
	int data;
	
	for (i=0;i < strlen(infix); i++)
	{
		//check given input is operator or not
		if (isalnum(infix[i]))
		{
			postfix[j++] = infix[i];
		}
		else if (infix[i] == ')')
		{
			data = pop();
   			while (data != '(' && data != -1) 
		   	{
   				postfix[j++] = data;
      			data = pop();
		   	}
		}
		else if (infix[i] == '(')
		{
			{
				push(infix[i]);
			}
		}
		else
		{
			data = pop();
			if(data == -1)
			{
				push(infix[i]);
				continue;
			}
			else if(data == '(')
			{
				push(data);
				push(infix[i]);
				continue;
			}
			
			index1 = getIndex(data);
			index2 = getIndex(infix[i]);
			while(priority[index1][1] >= priority[index2][1])
			{
				postfix[j++] = data;
				data = pop();
				if (data == -1)
				{
					push(infix[i]);
					break;
				}
				else if(data == '(')
				{
					push(data);
					push(infix[i]);
					data = -1;
					break;
				}
				index1 = getIndex(data);
			}
			if(data != -1)
			{
				push(data);
				push(infix[i]);
			}
		}
	}
	
	//after processing all inputs, pop all other data from stack
	while (1)
	{
		if((data = pop()) == -1)
		{
			break;
		}
		postfix[j++] = data;
	}
	postfix[j] = '\0';
}

void IntoPre(char infix[], char postfix[])
{
	
	
	int i = 0;
	int j = 0;
	int index1;
	int index2;
	int data;
	
	for (i=0;i < strlen(infix); i++)
	{
		//check given input is operator or not
		if (isalnum(infix[i]))
		{
			postfix[j++] = infix[i];
		}
		else if (infix[i] == '(')
		{
			data = pop();
   			while (data != ')' && data != -1) 
		   	{
   				postfix[j++] = data;
      			data = pop();
		   	}
		}
		else if (infix[i] == ')')
		{
			{
				push(infix[i]);
			}
		}
		else
		{
			data = pop();
			if(data == -1)
			{
				push(infix[i]);
				continue;
			}
			else if(data == ')')
			{
				push(data);
				push(infix[i]);
				continue;
			}
			
			index1 = getIndex(data);
			index2 = getIndex(infix[i]);
			while(priority[index1][1] >= priority[index2][1])
			{
				postfix[j++] = data;
				data = pop();
				if (data == -1)
				{
					push(infix[i]);
					break;
				}
				else if(data == ')')
				{
					push(data);
					push(infix[i]);
					data = -1;
					break;
				}
				index1 = getIndex(data);
			}
			if(data != -1)
			{
				push(data);
				push(infix[i]);
			}
		}
	}
	
	//after processing all inputs, pop all other data from stack
	while (1)
	{
		if((data = pop()) == -1)
		{
			break;
		}
		postfix[j++] = data;
	}
	postfix[j] = '\0';
	
	
}

int pop_evaluate()
{
	 int data;
        struct node *temp;
        if (top == NULL)
        return -1;
        data = top->data;
        temp = top;
        top =  top->next;
        free(temp);
        return (data);
}

int evaluate(char str[200])
{
	int i, data = -1, operand1, operand2, result;
	for (i = 0; i < strlen(str); i++) {
                if (isdigit(str[i])) {
                        
 				//if the character is digit, parse character by character to get complete operand
                        data = (data == -1) ? 0 : data;
                        data = (data * 10) + (str[i] - 48);
                        continue;
                }

                /* push the operator into the stack */
                if (data != -1) {
                        push(data);
                }

                if (str[i] == '+' || str[i] == '-'
                        || str[i] == '*' || str[i] == '/') 
							{
//if character is an operator, then pop two elements from the stack, apply operator and push the result into the stack
						operand2 = pop_evaluate();
                        operand1 = pop_evaluate();
                        if (operand1 == -1 || operand2 == -1)
                                break;
                        switch (str[i]) {
                                case '+':
                                        result = operand1 + operand2;
                                        /* pushing result into the stack */
                                        push(result);
                                        break;
                                case '-':
                                        result = operand1 - operand2;
                                        push(result);
                                        break;
                                case '*':
                                        result = operand1 * operand2;
                                        push(result);
                                        break;
                                case '/':
                                        result = operand1 / operand2;
                                        push(result);
                                        break;
                        }
                }
                data = -1;
        }
        if (top != NULL && top->next == NULL)
                printf("Output:%d\n", top->data);
        else
                printf("You've entered wrong expression\n");
        return 0;
}


