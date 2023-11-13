#include <stdio.h>
#define max 100
int push(int stack[100],int top);
int pop(int stack[100],int top);
void peak(int stack[max],int top);

void main()
{
	int stack[max],c,val,top=-1;
	char choice;
	
	
	
	//starting the loop
	do
	{
	printf("1:pop\n2:push\n3:peak\n");
	printf("Input the choice");
	scanf("%d",&c);
	switch (c)
	{
	case 1:
	printf("POP OPERATION");
	//printf("input the value to e popped");
	//scanf("%d",&val);
	top=pop(stack,top);
	break;
	
	case 2:
	printf("PUSH OPERATION");

	top=push(stack,top);
	break;
	
	case 3:
	printf("PEAK OPERATION");
	//printf("input the value to be pushed");
	//scanf("%d",&val);
	peak(stack,top);
	break;
	
	default:
	printf("Invalid choice");
	}
	printf("\ndo you want to continue(input y or n)");
	scanf("%s",&choice);
	}	while (choice=='y');
	
	
}

	int pop(int stack[100],int top)
	{
	if (top<0)
	printf("\nunderflow\n");
	else
	{
	int item=stack[top];
	top--;
	printf("\npopped element will be %d",item);
	}
	return top;
	
	}
	
	int push(int stack[100],int top)
	{
	int item,i;
	printf("\ninput the value to be pushed");
	scanf("%d",&item);
	if (top==max-1)
	printf("\noverflow");
	else
	stack[++top]=item;
	
	printf("\nnew stack will be\n");
	for(i=0;i<=top;i++)
	{
	printf("%d \n",stack[i]);
	}
	return top;
	
	
	
	}
	
	void peak(int stack[max],int top)
	{
	if (top==-1)
	printf("\nunderflow");
	else 
	printf("%d",stack[top]);
	}