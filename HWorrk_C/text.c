#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


typedef struct{
    char *base;
    char *located;
    char *move1;
    char *move2;
} array;

uint8_t length (char* array);
uint8_t caps(char *array1, char *array2);
uint8_t located (array arr);
uint8_t movedd (array arr1);

uint8_t main(int argc, char const *argv[])
{      
    char string[]={"to learn around the world learn how to do anything. today we learn ab that"};
    char locate1[]={"anything"};
    char moved1[]={"do anything"}; 
    char moved2[]={"do anything love you"};    
    char duplicate[255];
    array verify[]={string,locate1,moved1,moved2};
    length(string);
    caps(string,duplicate);
    located(*verify);    
    movedd(*verify) ;      
    return 0;
}

uint8_t length (char* array){ 
    uint8_t length = 0;
    while (array[length] != '\0'){
        length++;        
    }    
    return length;
}

 uint8_t caps(char *array1, char *array2){   // caps lock
    uint8_t m = 0;
    while(array1[m] != '\0'){
      array2[m] = array1[m];
      m++;          
    }
     for (uint8_t i = 0; i <= length(array1); i++){            
           if(array2[i] == '.'){
            for (uint8_t j = i; j <= length(array1); j++){
                if(array2[j] >= 'a' && array2[j] <= 'z'){
                    array2[j] = array2[j] - 32;
                }             
            }         
        }         
    } 
        array2[length(array2)]='\0';
          printf("YEU CAU 1: %s", array2) ;
}   

uint8_t located (array arr){   // vi tri
    uint8_t count = 0, j = 0;        
    for (uint8_t i = 0; i <= length(arr.base); i++){
        count++;         
        if(arr.base[i] == arr.located[j]){            
            j++;                         
        }
        else if(arr.base[i] != arr.located[j]){            
            j = 0;                                    
        }                           
        if (arr.located[j] == '\0'){  
             printf("\nYEU CAU 2: %s",arr.located);         
             printf(" - Ket qua: Co"); 
             printf(" - Vi tri: %d",count-j);  
             break;        
        }
        if (arr.base[i] == '\0'){
            printf("\nYEU CAU 2: %s",arr.located); 
            printf(" - Ket qua: Khong");
        }        
    }       
}

uint8_t movedd (array arr1){ //insert
    uint8_t j = 0, count = 0, save, final; 
    uint8_t  length_update = (length(arr1.base) - length(arr1.move1)) + length(arr1.move2);
    for(uint8_t i = 0; i <= length(arr1.base); i++){
        count++;
        if(arr1.base[i] == arr1.move1[j]){
            j++;
        }
        else if(arr1.base[i] != arr1.move1[j]){            
            j = 0;                                    
        }          
        if (arr1.move1[j] == '\0'){  
            final = count;            
            save = count -j;                                                      
        }      
    } 
     if (length(arr1.base) >= length_update){ // chèn vô trước rồi kéo vào
        for (uint16_t m = 0 ; m < length(arr1.move2); m++){     
        arr1.base[save++] = arr1.move2[m]; }  
        while(save < length_update){
        arr1.base[save] = arr1.base[final];
        save++;
        final++;            
        } 
        arr1.base[length_update] = '\0';  
        printf("\nYEU CAU 3: %s",arr1.base);         
    }
      else{//kéo ra ttao khoảng trắng rồi chèn vô
        uint8_t  length_string;
        length_string = length(arr1.base);
        arr1.base[length_update] = '\0';        
         while (length_update > save + length(arr1.move2)-1){
            arr1.base[length_update] =  arr1.base[length_string];
            length_update--;
            length_string--;                        
        } 
        for (uint16_t m = 0 ; m < length(arr1.move2); m++){     
        arr1.base[save++] = arr1.move2[m]; 
        }  
        printf("\nYEU CAU 3: %s",arr1.base);     
    }
}

    
    
    
     
   


         
       



