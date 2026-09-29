#include <stdio.h>
#include <stdint.h>
#include <math.h>

void reverse_array(uint8_t * arr, uint8_t n){
    for(int i = 0; i < n/2; i++){
        *(arr+i) = *(arr+i) ^ *(arr+n-1-i);
        *(arr+n-1-i) = *(arr+i) ^ *(arr+n-1-i);
        *(arr+i) = *(arr+i) ^ *(arr+n-1-i);
    }
}

void parse_csv_to_array(const char *str, uint8_t *arr, uint8_t *count){
    int digit = 0;
    int len = 0;
    while(*(str+len)!= '\0'){
        len++;
    }
    len--;
    for(int i = len; i >= 0 ; i--){
        if(str[i] == ','){
            digit = 0;
            (*count)++;
        }
        else{
            arr[(*count)] += (uint8_t)str[i] * pow(10,digit);
            digit++;
        }
        
    }
    reverse_array(arr, *count);
}

int main() {
    char str[101];
    fgets(str, sizeof(str), stdin);

    // Remove newline
    uint8_t i = 0;
    while (str[i]) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }

    uint8_t arr[20];
    uint8_t count = 0;

    parse_csv_to_array(str, arr, &count);

    for (uint8_t i = 0; i < count; i++) {
        printf("%u", arr[i]);
        if(i < count - 1){
            printf(" ");
        }
    }
    return 0;
}