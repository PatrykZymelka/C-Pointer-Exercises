#include <stdio.h>
#include <string.h>

void printArrElements(int * arr){
    for(int i = 0; i < 10; i++){
        printf("%d ",*arr);
        arr++;
    }
    
}

int sumArray(int * arr, int n){
    int result = 0;
    for(int i = 0; i < n ; i++){
        result += *(arr+i);
    }
    return result;


}

char reverseArray(char * arr){
    int len = strlen(arr);
    for(int i = 0; i < len/2; i++){
        arr[i] = arr[i] ^ arr[len-1-i];
        arr[len-1-i] = arr[i] ^ arr[len-1-i];
        arr[i] = arr[i] ^ arr[len-1-i];
    }
}

int stringLength(const char * arr){
    int i = 0;
    while(*(arr+i) != '\0'){
        i++;
    }
    return i;
}

void stringCopy( const char * source, char * dest){
    int i = 0;
    while(*(source+i) != '\0'){
        *(dest+i) = *(source+i);
        i++;
    }
}
int main(){
    /* EXERCISE 6
    Use pointer arithmetic to traverse an integer array and print all its elements.
    */
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    printArrElements(arr);

    /*
    Given an array, access and print the third element (index 2) using three different methods: 
    -subscript notation, 
    -pointer notation with the base address, 
    -pointer notation with an offset pointer.
    */
    int * ptr = arr;
    printf("Sub notation %d | POinter base address %d | Pointer offset %d\n",arr[2],*(arr+2),*(ptr+2));
    printf("sizeof arr %zu\n", sizeof(arr));
    printf("Sum of the array is = %d\n",sumArray(arr,10));

    /* EXERCISE 10
    Write a program to reverse an integer array in place (without using a second array) by swapping elements using pointers.
    */
    char carr[] = "Hello World";
    printf("%s\n",carr);
    reverseArray(carr);
    printf("%s\n",carr);

    /* EXERCISE 11
    Write a function custom_strlen to calculate the length of a string (null-terminated character array) without using the standard C library function strlen(). 
    The function must use a character pointer to traverse the string until it finds the null terminator (\0)
    */
    char str[] = "This is a very long string";
    int lenz = stringLength(str);
    printf("String len = %d \n", lenz);

    /* EXERCISE 12
    Implement a function custom_strcpy that copies the content of a source string (src) to a destination string (dest) using only character pointers.
    */
    char source[] = "asdasdasd";
    char dest[40];
    
    printf("source = %s | destination = %s\n", source, dest);

    stringCopy(source,dest);

    printf("source = %s | destination = %s\n", source, dest);
    return 0;
}