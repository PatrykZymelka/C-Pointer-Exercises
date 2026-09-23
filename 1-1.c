#include <stdio.h>

void changeValue(int *p){
    int new_value = 3333;
    *p = new_value;
}

void incrementValue(int * ptr){
    (*ptr)++;
}

int main(){
    /* EXERCISE 1
    Declare an integer variable, a pointer to an integer, and initialize the pointer to the address of the variable. 
    Print both the variables value and the value accessed via the pointer.
    */
    int value = 1001;
    int * ptr = &value;
    printf("value = %d | value adress = %p | ptr_adress = %p | pointer value = %d\n",value, &value, ptr, *ptr);

    /* EXERCISE 2
    Write a program that uses the dereference operator (*) to change the value of a variable through its pointer.
    */
    changeValue(ptr);

    printf("value = %d | value adress = %p | ptr_adress = %p | pointer value = %d\n",value, &value, ptr, *ptr);

    /* EXERCISE 3
    Print the memory addresses of two different variables (e.g., an int and a float) using the address-of operator (&). 
    Additionally, print the address of a pointer variable itself.
    */
    int i;
    int * ip = &i;
    float f;
    float * fp = & f;
    printf("Int address = %p | Int pointer address = %p | Float address = %p | Float pointer address = %p\n", &i, &ip, &f, &fp); 
    /* EXERCISE 4 
    Write a program to print the size (in bytes) of a pointer to an integer, a pointer to a character, and a pointer to a float on your system.
    */
    char c = 'c';
    char * cp = &c;
    printf("Size of Int = %d | Size of int ptr = %d | size of float = %d | size of float ptr = %d\n", sizeof(i), sizeof(ip), sizeof(f), sizeof(fp));
    int zero = 0;
    int * zp = &zero;
    printf("Zero value = %d | Zero address = %p | Ptr value = %d | Ptr address = %p\n", zero, &zero, *zp, zp);
    incrementValue(zp);
    printf("Zero value = %d | Zero address = %p | Ptr value = %d | Ptr address = %p", zero, &zero, *zp, zp);
    return 0;
}