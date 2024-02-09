#include<stdio.h>
int LinearSearch(int arr[],int size,int item){
    int i;
    for(i=0;i<size;i++){
        if(arr[i]==item){
            printf("your element is found at position %d (using linear search)",(i+1));
            return 0; 
        }
    }
    printf("element not found");
    return 0;
    
}

   void binarySearch(int arr[], int size, int x) {
    int l = 0, r = size - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            printf("Element found at position %d (using binary search)\n", (mid+1));
            return;
        }
        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("Element not found in the array.\n");
}

int main() {
    int size, arr[10], x;
    int choice;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: \n");
    for(int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
    }
    int l=0;
    int r=size-1;

    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    do {
        printf("\nSelect a search algorithm:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit the Program.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch(choice) {
            case 1:
                LinearSearch(arr, size, x);
                break;
            case 2:
                binarySearch(arr,size,x);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please choose again.\n");
        }
    } while(choice != 3);

    return 0;
}
