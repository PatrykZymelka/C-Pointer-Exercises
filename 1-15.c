#include <stdio.h>
#include <stdlib.h>

int main(){
    /* EXERCISE 15
    Dynamically allocate memory for a single integer using malloc(). 
    Store the value 108 in this allocated memory, print the value and its memory address, and then free the memory using free().
    */
    int * ptr = NULL;
    int a = 108;
    ptr = malloc(sizeof(a));
    if(ptr == NULL){
        printf("Error ptr is NULL, memory alloc failed");
        return 1;
    }
    *ptr = a;
    printf("Value = %d, address = %p\n\n\n",*ptr, (void*)ptr);

    free(ptr);
    ptr = NULL;

    /*EXERCISE 16
    Dynamically allocate memory for an array of 5 integers using malloc(). 
    Read 5 integer values from the user into the array, print them using pointer arithmetic, and finally, free the allocated memory.
    */
    int arr[5];
    int * ptr2 = NULL;
    ptr2 = malloc(sizeof(arr));

    if(ptr2 == NULL){
        printf("Error ptr is NULL, memory alloc failed");
        return 1;
    }
    for(int i = 0; i < 5; i++){
        printf("Int %d : ", i+1);
        scanf("%d",ptr2+i);
        printf("\n");
    }
    for(int i = 0; i < 5; i++){
        printf("%d", *(ptr2+i));
    }

    free(ptr2);
    ptr2 = NULL;
    /* EXERCISE 17
    Use calloc() to dynamically allocate memory for an array of 10 floating-point numbers. 
    Print the first and last elements to verify that calloc automatically initializes all elements to zero. Then, free the memory.
    */
    float * ptr3 = NULL;
    ptr3 = calloc(10,sizeof(float));
    if(ptr3 == NULL){
        return 1;
    }
    printf("First num = %f and his address = %p | last num = %f and his address = %p", *ptr3, ptr3, *(ptr3+9), (ptr3+9));
    free(ptr3);
    ptr3 = NULL;
    return 0;
}