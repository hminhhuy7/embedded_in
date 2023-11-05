#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


int arrange (int array1[], int n){
    for (int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if ( array1[i] > array1[j]){
                int temp = array1[i];
                array1[i] = array1[j];
                array1[j] = temp;
            }
        }
        //printf ("%d  ",array1[i]);
    }     }

int count (int array2[], int n){
    int i = 1, j = 0;
  for(j = 0; j < n; j++){
  if (array2[j] == array2[j+1]){
    i++;
       
  }
  else if ( (array2[j] != array2[j+1])){
  printf("\nSo lan xuat hien cua %d: %d\n", array2[j],i);
  i=1;
   
   }
   }
}

int main(int argc, char const *argv[])
{
   int array[]={1, 2, 4, 5, 6, 2, 3, 4, 8, 9, 3, 5, 6, 5, 6, 4,3,7 ,4,3};
    int n = sizeof(array)/sizeof(array[0]);
    arrange(array,n);
    count(array,n);
    
    
    
}