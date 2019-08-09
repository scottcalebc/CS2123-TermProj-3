//typedefs

//definitions
#define MAX_LEN 100  
// boolean
#define FALSE           0
#define TRUE            1

//prototypes

//sorting prototypes
//quick sort 
//int
int partition_int (int arr[], int low, int high);
void quickSort_int(int arr[], int low, int high);
//string
int partition_str (char *arr[], int low, int high);
void quickSort_str(char *arr[], int low, int high);

//merge sort 
//int
void merge_int(int arr[],int low,int mid,int high);
void mergeSort_int(int arr[],int low,int high);
//str
void merge_str(char *arr[],int low,int mid,int high);
void mergeSort_str(char *arr[],int low,int high);

//radix sort
//int
void countSort(int arr[], int n, int exp);
int getMax(int arr[], int n);
void radixSort_int(int arr[], int n);
//str
void countSort_str(char *a[], int n, int exp);
int getMax_str(char *a[], int n);
void radixSort_str(char *a[], int n);


//heap sort
//int
void heapify(int arr[], int n, int i);
void heapSort_int(int arr[], int n);
//str
void heapify_str(char *list[], int n, int i);
void heapSort_str(char *list[], int n);

//insertion sort
//str
void insertionSort_str(char *list[], int n);
//int
void insertionSort_int(int arr[], int n);

//selection sort
//int
void selectionSort_int(int arr[], int n);
//str
void selectionSort_str(char *arr[], int n);

//Search algorithms
//linear search
int linearSearchIterative_int(int data[], int n, int target);
int linearSearchIterative_str(char *data[], int n, char *target[]);
//binary search
int BinarySearchIterative_int(int data[], int n, int target);
int BinarySearchIterative_str(char *data[], int n, char *target[]);

void clearbuff();
