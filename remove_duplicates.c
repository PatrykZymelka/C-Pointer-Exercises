#include <stdio.h>
#include <stdlib.h>

void remove_duplicates(char * str){
    int read = 0;
    int write = 0;
    uint8_t hash[128] = {0};

    while(str[read] != '\0'){
        uint8_t val = (uint8_t)str[read];
        if(hash[val] == 0){
            hash[val]++;
            str[write] = str[read];
            write++;
        }
        read++;
    }
    str[write] = '\0';

}

int main(){
    char str[100] = "DDupplicaaatessss";
    printf("original = %s\n",str);
    remove_duplicates(str);
    printf("after = %s\n",str);


}