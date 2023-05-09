#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

struct heapStruct
{
    int* heaparray;
    int capacity;
    int size;
};

struct heapStruct* initHeap(){
    struct heapStruct* h;
    h = (struct heapStruct*)(malloc(sizeof(struct heapStruct)));
    h->capacity = SIZE;
    h->heaparray = (int*)malloc(sizeof(int)*(SIZE+1));
    h->size = 0;
    return h;
}

struct heapStruct * initHeapfromArray(int* values,int length){
    int i;
    struct heapStruct *h;
    h = (struct heapStruct*)(malloc(sizeof(struct heapStruct)));
    h->heaparray = (int*)malloc(sizeof(int)*(length+1));
    for (i = 0; i < length; i++)
    {
        h->heaparray[i] = values[i-1];
    }
    h->size = length;
    // takes random values and rearranges into heap
    heapify(h);
    return h;
}

void percolateUp(struct heapStruct *h,int index){
    if(index>1){
        if(h->heaparray[index/2]>h->heaparray[index]){
            //move node up one level
            swap(h,index,index/2);
            percolateUp(h,index/2);
        }
    }
}

void sort(int values[],int length){
    struct heapStruct *h;
    int i;
    h = initHeapfromArray(values,length);
    length = h->size;
    for (i = 0; i < length; i++)
    {
        values[i] = removeMin(h);
    }
    freeHeap(h);
}