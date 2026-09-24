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

int countVowels(const char * source){
    int count = 0;
    char dest[50];
    int len = strlen(source);
    char data[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i<len;i++){
        
        *(dest+i) = *(source+i);
        
        for(int j = 0; j<10;j++){
            if(*(source+i) == data[j]){
                count++;
            }
        }
    }
    printf("Source = %s | dest = %s\n",source, dest);
    return count;
}

void pointerWalk(const char * source){
    const char * ptr = source;
    while(*ptr != '\0'){
        printf("ptr dereference = %c\n", *ptr);
        ptr++;
    }
}

int count_vowels(const char *s) {
    int count = 0;
    const char *p = s;

    while (*p != '\0') {
        char c = *p;

        // Check if the current character is a vowel (case-insensitive)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
        p++; // Move to the next character
    }
    return count;
}

int constFun(char *s){
    const char * ptr1 = s;
    char const * ptr2 = s;
    char * const ptr3 = s;

    ptr1++;
    ptr2++;
    (*ptr3)++;

    printf("ptr1 = %c, ptr2 = %c, ptr3 = %c", *ptr1, *ptr2, *ptr3);
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

    /* EXERCISE 13
     Count the number of vowels (A, E, I, O, U, and their lowercase counterparts) in a given string using a character pointer for traversal.
    */
    char sentence[] = "The quick brown fox Jumps over the lazy dog";
    printf("number of vowels = %d\n",count_vowels(sentence));

    //pointerWalk(sentence);

    constFun(sentence);

    return 0;
}