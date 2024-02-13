#include <stdio.h>

// Function to perform selection sort
void selectionsort(int a[100], int n) {
    int i, min, j, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}

// Function to perform insertion sort
void insertionsort(int a[100], int n) {
    int i, j, v;
    for (i = 1; i < n; i++) {
        v = a[i];
        j = i;
        // Move elements of a[0..i-1], that are greater than v,
        // to one position ahead of their current position
        while (j > 0 && a[j - 1] > v) {
            a[j] = a[j - 1];
            j = j - 1;
        }
        a[j] = v;
    }
}

// Function to merge two subarrays of a[].
void merge(int a[100], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0, temp[100];
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= high) {
        temp[k++] = a[j++];
    }
    for (i = low, k = 0; i <= high; i++, k++) {
        a[i] = temp[k];
    }
}

// Function to implement merge sort
void mergeSort(int a[100], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

// Function to partition the array and return the partition index
int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low;
    int j = high;
    while (i < j) {
        while (pivot >= A[i])//have look at the = symbol
            i++;
        while (pivot < A[j])
            j--;
        if (i < j) {
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    int temp = A[j];
    A[j] = A[low];
    A[low] = temp;
    return j;
}
void heapify(int a[],int n,int i)
{
    int large=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]>a[large])
    {
        large=l;
    }
     if(r<n && a[r]>a[large])
    {
        large=r;
    }
    if(large!=i)
    {
        int t=a[large];
        a[large]=a[i];
        a[i]=temp;
    }
    heapify(a,n,large);
}
void heapSort(int a[],int n)
{
    for(i=n/2;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(i=n-1;i>=0;i--)
    {
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}

// Function to implement Quick Sort
void Quicksort(int A[], int low, int high) {
    if (low < high) {
        int j = partition(A, low, high);
        Quicksort(A, low, j - 1);
        Quicksort(A, j + 1, high);
    }
}


// Function to print the array
void printArray(int a[100], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
}

int main() {
    int n, i, a[100], choice;
    printf("\n\t\tEnter the number of elements: ");
    scanf("%d", &n);
    int l = 0;
    int r = n - 1;
    for (i = 0; i < n; i++) {
        printf("\n\t\tEnter value: ");
        scanf("%d", &a[i]);
    }
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

        switch (choice) {
            case 1:
                // bubbleSort(a,n);
                break;
            case 2:
                insertionsort(a, n);
                break;
            case 3:
                Quicksort(a, l, r);
                break;
            case 4:
                selectionsort(a, n);
                break;
            case 5:
                mergeSort(a, l, r);
                break;
            case 6:
                // heapSort(arr,size);
                break;
            case 7:
                printArray(a, n);
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please choose again.\n");
        }
    } while (choice != 8);

    return 0;
}
