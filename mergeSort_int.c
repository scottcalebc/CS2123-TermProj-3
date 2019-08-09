#include<stdio.h>
#include<stdlib.h>
#include<string.h> //To use the string functions like strcmp and strcpy
#include "projectHeader.h"
#define MAX 10  // This is the default size of every string 

//merge sort str
void merge_int(int arr[],int low,int mid,int high) //Merging the Array Function
{
    int nL= mid-low+1;
    int nR= high-mid;

    //allocate memory for left and right
    int* L = (int *) malloc(sizeof(int)*nL);
    int* R = (int *) malloc(sizeof(int)*nR);
    
    int i, j ,k;
    //copy data to left and right
    for(i=0;i<nL;i++)
    {
        //L = malloc(sizeof(arr[low+i]));
        L[i] = arr[low+i];
    }
    for(i=0;i<nR;i++)
    {
        //R = malloc(sizeof(arr[mid+i+1]));
        R[i] = arr[mid+i+1];
    }
    //merge
    j=0;
    i=0;
    k=low;
    
    while(i<nL && j<nR)
    {
        if(L[i] < R[j])
        {
            arr[k++] = L[i++];
        }
        else 
        {
            arr[k++] = R[j++];
        }
    }
    //copy remaining left
    while(i<nL)
    {
        arr[k++] = L[i++];
    }
    //copy remaining right
    while(j<nR)
    {
        arr[k++] = R[j++];
    }
}

//merge sort
void mergeSort_int(int arr[],int low,int high) //Main MergeSort function
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort_int(arr,low,mid);
        mergeSort_int(arr,mid+1,high);
        merge_int(arr,low,mid,high);
    }
}