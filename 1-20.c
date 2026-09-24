#include <stdio.h>
#include <stdlib.h>

void allocate_memory( int ** ptr){
    int * new_ptr = NULL;
    new_ptr = (int*)malloc(sizeof(int));
    if(new_ptr == NULL){
        *ptr = NULL;
        return;
    }
    *ptr = new_ptr;
    **ptr = 99;
}

void swap_values(int * a, int * b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void find_maxima(int * arr, int len, int * min, int * max){
    *min = *arr;
    *max = *arr;
    for(int i = 0; i < len; i++){
        if(*max < *(arr+i)){
            *max = *(arr+i);
        }
        if(*min > *(arr+i)){
            *min = *(arr+i);
        }
    }
}

int add(int a, int b){
    return a+b;
}

typedef struct{
    int x;
    int y;
}Point;

typedef struct{
    int id;
    float gpa;
}Student;


int main(){
    /* EXERCISE 20
    Declare an integer variable (num), a pointer to the integer (ptr1), and a pointer to the pointer (double pointer, ptr2). 
    Assign addresses correctly and print the final value of num using all three variables: num, *ptr1, and **ptr2.
    */
    int num = 20;
    int * ptr1 = &num;
    int ** ptr2 = &ptr1;
    printf("Num value = %d | num address = %p | ptr1 value = %d | ptr1 address = %p | ptr2 value = %d | ptr2 address = %p\n",num, &num, *ptr1, ptr1, **ptr2, *ptr2);
    
    /* EXERCISE 21
    Write a function allocate_memory that dynamically allocates memory for a single integer and stores the value 99 in it. 
    The function must take a double pointer (int **) as an argument to ensure the pointer variable in the main function is updated with the address of the newly allocated memory.
    */
    int * ptr3 = NULL;
    printf("ptr1 address = %p\n ",ptr3);
    allocate_memory(&ptr3);

    printf("ptr1 value = %d | ptr1 address = %p\n ",*ptr3, ptr3);
    free(ptr3);

    /* EXERCISE 22
    Simulate a 2×3 2D array using a single pointer to dynamically allocated memory. 
    Allocate memory for 6 integers. Use pointer arithmetic to access and print the value at the conceptual row 1, column 2 (index [1][2]).
    */
    const int ROWS = 2;
    const int COLS = 3;
    int * all_ptr = NULL;
    all_ptr = malloc(2*3*sizeof(int));
    if(all_ptr == NULL){
        return 1;
    }
    for(int i = 0;i<ROWS*COLS;i++){
        *(all_ptr+i)= i;
    }

    int col = 2;
    int row = 1;
    printf("Value at index [1][2] = %d\n", *(all_ptr+(row*COLS+col)));
    
    free(all_ptr);

    int a = 101;
    int b = 202;
    printf("a = %d | b = %d\n", a , b);
    swap_values(&a,&b);
    printf("a = %d | b = %d\n", a , b);

    int arr[] = {1,2,3,4,5,6,10,7,8,9};
    int size = 10;
    int min = 0;
    int max = 0;
    int * min_ptr = &min;
    int * max_ptr = &max;
    find_maxima(arr, size, min_ptr, max_ptr);
    printf("Minimum value = %d | Max value = %d\n",min,max);

    /* Exercise 25
    Declare a function pointer that can point to a function that takes two integers and returns an integer. 
    Assign it to a simple add function. 
    Call the add function using both its original name and the function pointer.
    */
    int (*func_ptr)(int, int) = add;

    printf("add = %d | ptr = %d\n" ,add(1,2),func_ptr(1,2));

    /* Exercise 26
    Define a structure Point with members x and y. Declare a variable of this structure and a pointer to it. Access and modify the structure members
    */
    Point pointt;
    Point * p = &pointt;
    p->x = 10;
    p->y = 20;
    printf("%d, %d | %d, %d\n",pointt.x, pointt.y, p->x, p->y);
    p->x = 40;
    printf("%d, %d | %d, %d\n",pointt.x, pointt.y, p->x, p->y);


    /* Exercise 27
    Define a struct Student with id (int) and gpa (float). 
    Create an array of 3 Student structures and initialize them. 
    Use a structure pointer to iterate through the array and print the id and gpa of each student.
    */
    Student Stud_arr[3] = { {1,2.1}, {43,0.1}, {5,6.7}};

    Student * stud_ptr = Stud_arr;

    for(int i = 0; i < 3; i++){
        printf("Student %d | id: %d | gpa: %f\n", i+1, (stud_ptr+i)->id, (stud_ptr+i)->gpa);
    }

    return 0;
}