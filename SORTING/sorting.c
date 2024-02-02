// Online C compiler to run C program online
#include <stdio.h>
void selectionsort(int a[100],int n)
{
   int i,min,j,temp;
   for(i=0;i<n-1;i++)
   {
       min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[min];
        
        a[min]=a[i];
        a[i]=temp;
   }
}
void insertionsort(int a[100],int n)
{
    int i,j,v;
    i=1;
    while(i<n)
    {
        v=a[i];
        j=i;
        while(a[j-1]>v &&j>0)
        {
            a[j]=a[j-1];
            j=j-1;
        }
        a[j]=v;
        i++;
    }
}
void merge(int a[100],int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=0;
    int temp[100];
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
           
        }
        else
        {
            temp[k++]=a[j++];
            
        }
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while( j<=high)
    {
         temp[k++]=a[j++];
    }
    for(i=low,k=0;i<=high;i++,k++)
    {
        a[i]=temp[k];
    }
}
void mergeSort(int a[100],int low,int high)
{
    if(low<high)
    {
        int mid=(low +high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
        
    }
}

   void printArray(int a[100],int n)
   {
       int i;
       for(i=0;i<n;i++)
       printf("%d\n",a[i]);
       
   }
 
    
    int main() {
    // Write C code here
   int n,i,a[100],choice;
   
   printf("\n\t\tenter no of elements");
   scanf("%d",&n);
   int l=0;
    int r=n-1;
   for(i=0;i<n;i++){
   printf("\n\t\tenter vals");
   scanf("%d",&a[i]);}
       do {
        printf("\nSelect a sorting algorithm:\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Quick Sort\n");
        printf("4. Selection Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Heap Sort\n");
        printf("7. Display Array\n");
        printf("8. Exit the Program.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);




        switch(choice) {
            case 1:
               // bubbleSort(a,n);
            break;
            case 2:
               insertionsort(a,n);
            break;
            case 4:
                selectionsort(a,n);
                break;
               
             case 3:
           //  QuickSort(arr,l,r);
                break;

            case 5:
               mergeSort(a,l,r);
                break;
            case 6:
           //     heapSort(arr,size); 
                break;
            case 7:
                printArray(a,n);
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please choose again.\n");
        }
    } while(choice != 8);

}