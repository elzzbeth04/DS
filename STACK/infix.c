#include <stdio.h>
#define max 10
int push(char value);
char pop();
void peak(char stack[max],int top);
void infix_to_postfix(char infix[max],char postfix[max]);
char is_operator(char c);
int precedence(char op);
// declared as global variables hence any changes made to it in functions will be reflected
char stack[max];
int top=-1;

char infix[max], postfix[max];
//main function
void main()
{
    printf("input the infix expression");
    scanf("%[^\n]",infix);
    infix_to_postfix(infix,postfix);
    printf("%s",postfix);
}
//infix to postfix
void infix_to_postfix(char infix[max],char postfix[max])
{
    int i=0,j=0;
    while (infix[i]!='\0')
    {
	    if (infix[i]>='a'&&infix[i]<='z')
	    postfix[j++]=infix[i++];
	else if (is_operator(infix[i]))
    {
	    while(top!=-1 && precedence(stack[top])>=precedence(infix[i]))
	{
		postfix[j++]=pop();
	}
        push(infix[i++]);
    }   
    
    else if(infix[i]==')')
    {
        {
        	while (top!=-1 && stack[top]!='(')
        	postfix[j++]=pop();
        }
        if (top!=-1 && stack[top]=='(')
          {
          pop();
          }
        i++;
    }

    else 
     printf("invalid");
        
    }
        while (top!=-1)
        {
             postfix[j++]=pop();
        }
             postfix[j]='\0';
}
       // pop operation
       
       
        char pop(char stack[max],int top)
    	{
	    if (top<0)
	        {
            	printf("\nunderflow\n");
	            return 0;
	        }
	    else
	        {
	            return stack[top--];
        	}
	    }
	
	//push operation
	
	   int push(char value)
	    {
	    int i;
	        if (top==max-1)
	        {
	             printf("\noverflow");
	             return 0;
	        }
	        else
	        stack[++top]=value;
	      
	    }
	
	//isoperator function
	
	char is_operator(char c)
	{
	    return c=='+'||c=='-'||c=='*'||c=='/' ;
	}
	//precedence function
	    int precedence(char op)
	    {
	    if (op=='+' || op=='-')
	    {
	    return 1;
	    }
    	if (op=='/'||op=='*')
    	{return 2;}
    	return 0;
	    }