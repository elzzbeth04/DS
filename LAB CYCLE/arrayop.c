// Online C compiler to run C program online
#include <stdio.h>
int delete(int n,int a[],int s)
{
    //printf("shit");
    int pos,i,temp;
    for( i=0;i<s;i++)
    {
       if(a[i]==n)
       {
           pos=i;
           break;
       }
    }
    for( i=pos;i<s-1;i++)
     
    {
        a[i]=a[i+1];
    }
    return s-1;
    
    
}
void display(int new,int a[])
{
    
    for(int i=0;i<new;i++){
         printf("%d\n",a[i]);
     }
}
int main() {
    // Write C code here
    int s,a[100],n,c;
    char ch;
    
    do{
    printf("\n 1:input\n2:delete\n3:display");
    printf("\ninput choice");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        printf("rnter size of array");
    scanf("%d",&s);
         for(int i=0;i<s;i++)
        {
        printf("input%d",i);
        scanf("%d",&a[i]);
        }
        break;
        
        case 2:
         printf("\nenter the element to be deleted");
         scanf("%d",&n);
        int new=delete(n,a,s);
        break;
        
        case 3:
         display(new,a);
         break;
    }printf("\n continue?");
    scanf("%s",&ch);
    }while(ch=='y');
    
   
   
   
     
    
    

    return 0;
}