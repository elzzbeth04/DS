// Online C compiler to run C program online
#include <stdio.h>
#define max 1

int stack[max],top=-1;
void push()
{
    int data;
    printf("\n input");
    scanf("%d",&data);
    if(top==max-1)
    printf("\nover");
    else
    {
        stack[++top]=data;
    }
}
int pop()
{
    int item;
    if(top<0)
    {
        printf("underflow");
        return 0;
    }
    else
    {
        item=stack[top--];
        return item;
    }
}
void main()
{
	int c,val;
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
	int popped=pop();
	printf("\npopped=%d",popped);
	//printf("input the value to e popped");
	//scanf("%d",&val);
	
	break;
	
	case 2:
	printf("PUSH OPERATION");
    push();

	break;
	
	case 3:
	printf("PEAK OPERATION");
	printf("%d",stack[top]);
	//printf("input the value to be pushed");
	//scanf("%d",&val);
	
	break;
	
	default:
	printf("Invalid choice");
	}
	printf("\ndo you want to continue(input y or n)");
	scanf("%s",&choice);
	}	while (choice=='y');
	
	
}