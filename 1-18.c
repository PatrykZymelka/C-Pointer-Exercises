#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    int * ptr = NULL;
    ptr = (int *)malloc(2*sizeof(int));
    if(ptr == NULL){
        return 1;
    }
    ptr[0] = 10;
    ptr[1] = 20;
    printf("index 0 = %d | index 1 = %d\n", *ptr, *(ptr+1));
    
    int * temp = NULL;
    temp = realloc(ptr, (4*sizeof(int)));

    if(ptr == NULL){
        free(ptr);
        return 1;
    }
    ptr = temp;

    ptr[2] = 30;
    ptr[3] = 40;
    printf("index 0 = %d | index 1 = %d | index 2 = %d | index 3 = %d\n", *ptr, *(ptr+1),*(ptr+2),*(ptr+3));
    
    
    free(ptr);
    ptr = NULL;
}