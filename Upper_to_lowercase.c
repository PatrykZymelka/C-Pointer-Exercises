#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void upper_to_lower(char * arr){
    int head = 0;
    while(arr[head] != '\0'){
        uint8_t value = (uint8_t)arr[head];
        if(value >= 'A' && value <= 'Z'){
            arr[head] += ('a' - 'A');
        }
        head++;
    }
}



int main(){

    char arr[100];
    fgets(arr, sizeof(arr), stdin);
    printf("%s\n",arr);

    upper_to_lower(arr);

    printf("%s\n",arr);
}