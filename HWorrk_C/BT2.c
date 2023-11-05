#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint8_t length (char* array){ 
    uint8_t length = 0;
    while (array[length] != '\0'){
        length++;        
    }    
    return length;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

