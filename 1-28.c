#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float radius;
}Circle;

void print_generic_data(void * ptr, int type){
    if(type == 0){
        printf("%p\n", ptr);
    }
    if(type == 1){
        printf("%d\n", *(int*)ptr);
    }
    if(type == 2){
        printf("%f\n", *(float*)ptr);
    }
}


int main(){
    /* Exercise 28
    Define a struct Circle with a radius (float). 
    Dynamically allocate memory for a single Circle structure using malloc(). 
    Populate its members, print the area (Area = π×r2), and then free the memory.
    */
    Circle * circle_ptr = NULL;
    circle_ptr = malloc(sizeof(Circle));
    if(circle_ptr == NULL){
        return 1;
    }
    
    circle_ptr->radius = 5.5;
    
    float area = circle_ptr->radius*circle_ptr->radius*3.14159;

    printf("circle radius = %f, circle area = %f\n",circle_ptr->radius,area);
    
    free(circle_ptr);


    /* Exercise 29
     Write a function print_generic_data that takes a generic pointer (void *) and an integer indicating the data type (1 for int, 2 for float). 
     Inside the function, cast the void * to the correct data type pointer and print the value it holds.
    */
    int i_val = 123;
    float f_val = 45.67f;

    void * gen_ptr_i = &i_val;
    void * gen_ptr_f = &f_val;

    print_generic_data(gen_ptr_i, 0);
    print_generic_data(gen_ptr_f, 0);

    print_generic_data(gen_ptr_i, 1);
    print_generic_data(gen_ptr_f, 2);

    print_generic_data(gen_ptr_i, 2);
    print_generic_data(gen_ptr_f, 1);

    return 0;
}