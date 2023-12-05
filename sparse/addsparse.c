//To find the addition pf two sparse matrix
#include <stdio.h>
void sparse(int A[10][10],int m, int n,int S[20][3]);
void Input(int A[10][10],int m,int n);
 void AddSparse(int S[20][3],int T[20][3],int m,int n,int m2,int n2);
void main()
	{
		int  f=0,i,j,m,n,m2,n2,k=0,A[10][10],B[10][10],S[20][3],T[20][3];
		printf("INPUT THE VALUE OF ROWS AND COLUMNS FROM THE USER FOR MATRIX1:");
		scanf("%d %d",&m ,&n);
		printf("INPUT THE VALUE OF ROWS AND COLUMNS FROM THE USER FOR MATRIX1:");
		scanf("%d %d",&m2 ,&n2);
		Input(A,m,n);
		Input(B,m2,n2);
		sparse(A,m,n,S);
		sparse(B,m2,n2,T);
		AddSparse(S,T,m,n,m2,n2);
	}
	
	//FUNCTION FOR INPUTTING ELEMENTS IN THE ARRAY
	void Input(int A[10][10],int m,int n)
	{
		int i,j;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
			printf("INPUT THE ARRAY ELEMENTS FROM THE USER for %d %d :",i,j);
			scanf("%d",&A[i][j]);
			}
		}
	}
	
	//FUNCTION FOR SPARSE REPRESENTATION
	void sparse(int A[10][10],int m, int n,int S[20][3])
	{
	int k=1,i,j;
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
		
		//printf("\n    %d",k);
		printf("THE SPARSE REPRESENTATION FOR THE MATRIX WILL BE \n");
		
		for(i=0;i<k;i++)
		{
		for(j=0;j<3;j++)
		{
		printf("%d \t",S[i][j]);
		}
		printf("\n");
	}
	}
	//FUNCTION FOR SPARSE ADDITION
	 void AddSparse(int S[20][3],int T[20][3],int m,int n,int m2,int n2)
	 {
	 int k=1,l=1,p=1,i,j,R[20][3];
	 R[0][0]=S[0][0];
	 R[0][1]=S[0][1];
	 for(i=0;i<m;i++)
		{
		for(j=0;j<n;j++)
	 		{
				if(S[k][0]==i && S[k][1]==j && T[l][0]==i && T[l][1]==j)
				{
					R[p][0]=S[k][0];
					R[p][1]=S[k][1];
					R[p][2]=S[k][2]+T[p][2];
					k++;
					p++;
					l++;
	                	}
	                	else if(S[k][0]==i && S[k][1]==j)
	                	{
					R[p][0]=S[k][0];
					R[p][1]=S[k][1];
					R[p][2]=S[k][2];
					k++;
					p++;
				}
				else if(T[l][0]==i && T[l][1]==j)
				{
					R[p][0]=T[l][0];
					R[p][1]=T[l][1];
					R[p][2]=T[l][2];
					l++;
					p++;
				}
			}
		}
		R[0][2]=p-1;
		printf("FINAL MATRIX\n");
		for(i=0;i<p;i++)
		{
		for(j=0;j<3;j++)
		{
		printf("%d \t",R[i][j]);
		}
		printf("\n");
		}
		}