#include<stdio.h>
#include<stdlib.h>
#include<string.h> //To use the string functions like strcmp and strcpy
#include "projectHeader.h"
#define MAX 10  // This is the default size of every string 


void freeArr(char *arr[], int dataSize)
{
    int i;
    for (i = 0; i < dataSize; i++)
        free(arr[i]);
    free(arr);
}


void merge_str(char *arr[],int low,int mid,int high) //Merging the Array Function
{
    int nL= mid-low+1;
    int nR= high-mid;

    char** L=malloc(sizeof(char *)*nL);
    char** R=malloc(sizeof(char *)*nR);
    int i;
    for(i=0;i<nL;i++)
    {
        L[i]=malloc(sizeof(arr[low+i]));
        strcpy(L[i],arr[low+i]);
    }
    for(i=0;i<nR;i++)
    {
        R[i]=malloc(sizeof(arr[mid+i+1]));
        strcpy(R[i],arr[mid+i+1]);
    }
    int j=0,k;
    i=0;
    k=low;
    while(i<nL&&j<nR)
    {
        if(strcmp(L[i],R[j])<0)strcpy(arr[k++],L[i++]);
        else strcpy(arr[k++],R[j++]);
    }
    while(i<nL)strcpy(arr[k++],L[i++]);
    while(j<nR)strcpy(arr[k++],R[j++]);

}


void mergeSort_str(char *arr[],int low,int high) //Main MergeSort function
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort_str(arr,low,mid);
        mergeSort_str(arr,mid+1,high);
        merge_str(arr,low,mid,high);
    }
}
