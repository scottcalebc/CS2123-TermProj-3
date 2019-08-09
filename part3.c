#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "projectHeader.h"



void releaseArr(char **arr, int dataSize)
{
    int i;
    for(i = 0; i < dataSize; i++)
        free(arr[i]);
    free(arr);
}

void fillArray_int(int arr[], int dataSize)
{
    int i = 0;
    srand(time(0));
    while ( i < dataSize)
    {
        arr[i] = 0;
        
        int r = rand();
        arr[i] = r;
        i++;   
    }
}

int getTarget(int dataSize)
{
    srand(time(0));

    return rand() % dataSize;
}



double run_int(int **retarr, int *target, int sort, int dataSize, int (*search)(int[], int, int))
{
    int *arr = malloc(dataSize * sizeof(int));
    int targ;

    fillArray_int(arr, dataSize);

    if (sort)
    {
        printf("sorting\n");
        radixSort_int(arr, dataSize);
    }
    clock_t t;
    t = clock();
    if (search != NULL)
        targ = search(arr, dataSize, *target);
    else 
        return -1;
    t = clock() - t;

    
    if (target != NULL)
        *target = targ;
    
    if (retarr != NULL)
        *retarr = arr;
    else
        free(arr);

    return ((double)t)/CLOCKS_PER_SEC;
}

void writeData(char *algo, int dataSize, double time_taken, char *fileName)
{
    FILE *file;

    if ((file = fopen(fileName, "r")) != NULL)
    {
        file = freopen(fileName, "a", file);
        
        fprintf(stdout, "%s, %d, %lf\n", algo, dataSize, time_taken);
        fprintf(file, "%s, %d, %lf\n", algo, dataSize, time_taken);

        fclose(file);
    } else{
        file = fopen(fileName, "w");
        fprintf(stdout, "algorithm, data_size, avg_time_taken\n");
        fprintf(file, "algorithm, data_size, avg_time_taken\n");
        fclose(file);
        writeData(algo, dataSize, time_taken, fileName);
    }
}

void Run_int(char *algo, int sort, int (*search)(int[],int,int))
{
    int arr[] = {1000, 50000, 75000, 100000, 250000, 500000, 750000, 1000000, 10000000, 50000000, 75000000};
    int i, j;
    double avgTime = 0;
    int target;
    

    for(i = 0; i < sizeof(arr)/sizeof(int); i++)
    {  
        avgTime = 0;
        target = rand(); 
        for(j = 0; j < 5; j++)
        {
              
            if (search != NULL)
                avgTime += run_int(NULL, &target, sort, arr[i], search);
        }
        
        writeData(algo, arr[i], avgTime/5.0, "runtime_int.txt");
    }
    
}

char ** fill(int dataSize, char* fileName)
{
    
    char **names = malloc(dataSize * sizeof(char**));
    if (names == NULL)
    {
        printf("Array not Allocated\n");
    }

    int i = 0;
    char name[MAX_LEN + 1];


    while(i < dataSize )
    {
        FILE* fp = fopen(fileName, "r");
        
        if (fp == NULL)
        {
            fprintf(stderr, "FILE NOT FOUND");
        }

        while(fgets(name, MAX_LEN, fp) != NULL)
        {
            if (i >= dataSize)
            {
                break;
            }
            names[i] = malloc(MAX_LEN * sizeof(char));
            strcpy(names[i], name);
            int j = strcspn(names[i], "\n\r");
            names[i][j] = '\0';
            i++;
        }

        fclose(fp);
        
    }

    return names;
}

double run_str(char **names, char *target, int *targetI, int sort, int dataSize, int (*search)(char *[], int, char *[]))
{
    if (sort)
        heapSort_str(names, dataSize);

    int targ;
    clock_t t;
    t = clock();
    if (search != NULL)
        targ = search(names, dataSize, &target);
    t = clock() - t;

    if (targetI != NULL)
        *targetI = targ;

    return ((double)t)/CLOCKS_PER_SEC;

}

void Run_str(char *algo, int sort, int (*search)(char *[],int,char *[]))
{
    //{10000,78000,156353};
    int dataSize[] = {1000, 50000, 75000, 100000, 250000, 500000, 750000, 1000000, 10000000, 50000000, 75000000};
    int i,j;
    char **names;
    double avgTime;

    int target;
    char name[MAX_LEN+1] = {0};
    

    for(i = 0; i < sizeof(dataSize)/sizeof(int); i++)
    {
        target = rand() % dataSize[i];

        for(j = 0; j < 5; j++)
        {    
            names = fill(dataSize[i], "new_name.txt");
            strcpy(name, names[target]);
            if (search != NULL)
                avgTime += run_str(names, name, NULL, sort, dataSize[i], search);
            
            releaseArr(names, dataSize[i]);
        }  
        writeData(algo, dataSize[i], avgTime/5, "runtime_str.txt"); 
    }
}

void Run_All()
{
    
    Run_int("linear", 0, linearSearchIterative_int);
    Run_int("binary", 1, BinarySearchIterative_int);

    Run_str("linear", 0, linearSearchIterative_str);
    Run_str("binary", 1, BinarySearchIterative_str);

}

void writeArray_int(char *algo, int *arr, int dataSize)
{
    char ext[] = ".txt";
    char *filename = malloc((strlen(algo) + strlen(ext) * sizeof(char)) + 1);
    strcpy(filename, algo);
    strcat(filename, ext);

    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error file %s could not be opened\n", filename);
    }
    int i;
    for(i = 0; i < dataSize; i++)
    {
        fprintf(fp, "%d\n", arr[i]);
    }


}

void writeArray_str(char *algo, char **arr, int dataSize)
{
    char ext[] = ".txt";
    char *filename = malloc((strlen(algo) + strlen(ext) * sizeof(char)) + 1);
    strcpy(filename, algo);
    strcat(filename, ext);

    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error file %s could not be opened\n", filename);
    }
    int i;
    for(i = 0; i < dataSize; i++)
    {
        fprintf(fp, "%s\n", arr[i]);
    }


}

void printResults_int(double time, int *arr, int targetI)
{
    printf("Sort executed in %.4lf seconds\n", time);
    if (targetI != -1)
    {
        printf("Element in Array[%d] = %d\n", targetI, arr[targetI]);
    }
    else 
    {
        printf("Element not found in Array\n");
    }
}

void printResults_str(double time, char **arr, int targetI)
{
    printf("Sort executed in %.4lf seconds\n", time);
    if (targetI != -1)
    {
        printf("Element in Array[%d] = %s\n", targetI, arr[targetI]);
    }
    else 
    {
        printf("Element not found in Array\n");
    }
}

void menu()
{
    char *algorithms[] = {"linear", "binary"};

    int algo;
    int type;
    int size;
    double time;
    int target_int;
    char target_str[MAX_LEN + 1];

    int i;
    for(i = 0; i < 2; i++)
    {
        printf("%d. %-13s ", i + 1, algorithms[i]);

        if ((i+1)%2 == 0)
            printf("\n");
    }
    printf("Choose searching algorithm: ");
    scanf("%d", &algo);
    printf("1. %-13s 2. %-13s\n", "Integer", "String");
    printf("Pick data type: ");
    scanf("%d", &type);
    printf("Enter data size: ");
    scanf("%d", &size);
    printf("Enter target value: ");
   

    if (type == 1)
    {
        //integer
        scanf("%d", &target_int);
        int *arr = malloc(size *sizeof(int));

        switch (algo)
        {
        case 1:
            time = run_int(&arr, &target_int, 0, size, linearSearchIterative_int);
            break;
        case 2:
            time = run_int(&arr, &target_int, 1, size, BinarySearchIterative_int);
            break;
        
        default:
            break;
        }

        printResults_int(time, arr, target_int);
        writeArray_int(algorithms[algo-1], arr, size);
        free(arr);
    } else{
        //string
        printf("Enter file to read strings: ");
        char filename[MAX_LEN];
        scanf("%s", filename);
        char **items = fill(size, filename);

        if (items == NULL)
        {
            printf("Error: File does not exists\n");
            return;
        }
        scanf("%s", target_str);

        switch (algo)
        {
        case 1:
            time = run_str(items, target_str, &target_int, size, linearSearchIterative_str);
            break;
        case 2:
            time = run_str(items, target_str, &target_int, size, BinarySearchIterative_str);
            break;
        default:
            break;
        }

        printResults_str(time, items, target_int);
        writeArray_str(algorithms[algo-1], items, size);
        releaseArr(items, size);
    }
}

int main(){

    printf("1. Run individual sort 2. Run all sorts\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 2)
    {    
        Run_All();
    } 
    else
    {
        while(choice)
        {
            menu();

            printf("Sort again? (y/n): ");
            char again;
            scanf("%*c %c", &again);

            if (again != 'y')
                break;
        }    
    }
    
    return 0;

}



