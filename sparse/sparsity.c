//To find the sparsity of a matrix and to represent it in sparse form
#include <stdio.h>
void sparse(int A[10][10],int m, int n);
void main()
	{
		int  i,j,m,n,k=0,A[10][10];
		float f=0,s,o;
		printf("INPUT THE VALUE OF ROWS AND COLUMNS FROM THE USER :");
		scanf("%d %d",&m ,&n);
		
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("INPUT THE ARRAY ELEMENTS FROM THE USER for %d %d :",i,j);
				scanf("%d",&A[i][j]);
			}
		}
		
		sparse(A,m,n);
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
			if(A[i][j]==0)
			f++;

			}
		}
		 o=m*n;
		 s=f/o;
		printf("sparsity =%f",s);
	}
	void sparse(int A[10][10],int m, int n)
	{
	int S[20][3],k=1,i,j;
	S[0][0]=m,S[0][1]=n;
	for(i=0;i<m;i++)
		{
		for(j=0;j<n;j++)
			{
			  if(A[i][j]!=0)
			  {
	       		  S[k][0]=i;
			  S[k][1]=j;
	                  S[k][2]=A[i][j];
			  k=k+1;
			  }
			}
		}
		S[0][2]=k-1;
		printf("THE SPARSE REPRESENTATION FOR THE MATRIX WILL BE \n");
		
		for(i=0;i<3;i++)
		{
		for(j=0;j<k;j++)
		{
		printf("%d \t",S[i][j]);
		}
		printf("\n");
	}
	}