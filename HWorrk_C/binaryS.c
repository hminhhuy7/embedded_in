#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


uint8_t arrange (uint8_t array1[], uint8_t n){
    for (uint8_t i = 0; i < n; i++){
        for(uint8_t j = i+1; j < n; j++){
            if ( array1[i] > array1[j]){
                uint8_t temp = array1[i];
                array1[i] = array1[j];
                array1[j] = temp;
            }
        }
        printf ("%d  ",array1[i]);
    }
}

uint8_t binary (uint8_t arr[], uint8_t left, uint8_t right, uint8_t num){
    uint8_t mid;       
    while (left <= right){     
        mid = left + (right - left) / 2;   
        if (arr[mid] == num) return mid;
        else if (arr[mid] < num) left = mid + 1;
        else if (arr[mid] > num) right = mid - 1;               
    };    
    return -1;
}

uint8_t main(int argc, char const *argv[])
{
    uint8_t array[]={11, 25, 44, 53, 67, 22, 31};
    uint8_t n = sizeof(array)/sizeof(array[0]);
    uint8_t S, num;
    arrange(array,n);
    num = 25;
    S = binary(array,0,n-1,num);
    printf("\n%d vi tri: %d",num,S);
    return 0;
    
    
    
    
}