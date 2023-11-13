#include <stdio.h>
int sparse(int A[10][10],int m, int n,int S[20][3]);
void transpose (int S[20][3],int m,int n,int T[20][3]);
void checksymmetry(int S[20][3],int T[20][3],int m,int n,int w);
void main()
	{
		int  i,j,m,n,k=0,A[10][10],S[20][3], T[20][3];
		
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
		
	    int w=	sparse(A,m,n,S);
		transpose(S,m,n,T);
		checksymmetry(S,T,m,n,w);
	}
	
	//FUNCTION FOR SPARSE REPRESENTATION
	int sparse(int A[10][10],int m, int n,int S[20][3])
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
	return k;
	}
void transpose(int S[20][3], int m, int n,int T[20][3]) {
    int i, j, k = 1;
    T[0][0] = n;  // Swap rows and columns
    T[0][1] = m;
    T[0][2] = S[0][2];  // Number of non-zero elements remains the same

    for (i = 0; i < n; i++) {
        for (j = 1; j <= S[0][2]; j++) {
            if (S[j][1] == i) {
                T[k][0] = S[j][1];
                T[k][1] = S[j][0];
                T[k][2] = S[j][2];
                k++;
            }
        }
    }

    printf("Transposed sparse matrix:\n");
    for (i = 0; i < k; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d \t", T[i][j]);
        }
        printf("\n");
    }
}
void checksymmetry(int S[20][3],int T[20][3],int m,int n,int w)
{
    int i,j,flag=0;
     for (i = 0; i < w; i++) {
        for (j = 0; j < 3; j++) {
           // if (S[i][0] != T[i][0] || S[i][1] != T[i][1] || S[i][2] != T[i][2])
           if(S[i][j]!=T[i][j])
            {
                flag++;
                break;
            }
         
}
}
if (flag!=0)
{
    printf("not symmetric");
    
}
else 
    printf(" symmetric");
    
}