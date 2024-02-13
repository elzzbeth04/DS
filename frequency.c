#include <stdio.h>
int main() {
int a[10],n,b[10],c=0,i,j,k=0;
printf("Enter how many times: ");
scanf("%d",&n);
for (i=0;i<n;i++){
    printf("Enter the element: ");
    scanf("%d",&a[i]);}
for(i=0;i<n;i++)
{
    c=0;
    for(j=0;j<=i;j++)
    {
        if(a[i]==b[j])
        {
            c=c+1;
        }
    }
    if (c==0)
    {
    b[k]=a[i];
    k=k+1;
    }
}
for (i=0;i<k;i++)
{
    for(j=0;j<n;j++)
    {
        if(b[i]==a[j])
        {
            c=c+1;
        }
    }
    printf("Frequncy of %d is %d",b[i],c);
    c=0;
    printf("\n");
}
}