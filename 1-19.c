#include <stdio.h>
#include <stdlib.h>

int main(){
    /* Exercise 19
    Write a robust program that attempts to dynamically allocate a very large block of memory (e.g., 1 GB). 
    Include a check for the NULL return value from malloc() 
    handle the memory allocation failure gracefully by printing an error message and exiting with a non-zero status code.
    */
    int * ptr = NULL;
    ptr = (int*)malloc((1073741824 * sizeof(char)));
    if(ptr == NULL){
        printf("Error, memory allocation failed\n");
        return 1;
    }
    printf("Memory allocation successfull at address = %p\n", ptr);
    free(ptr);
    return 0;
}