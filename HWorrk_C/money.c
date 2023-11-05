#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


typedef enum{
    TRAM = 0, 
    CHUC = 2,
    DONVI = 1,
} unit;

typedef enum{
    mot = '1',
    hai = '2',
    ba  = '3',
    bon = '4',
    nam = '5',
    sau = '6',
    bay = '7',
    tam = '8',
    chin ='9', 
    khong ='0', 
} number;

uint8_t length (char* array){ 
    uint8_t length = 0;
    while (array[length] != '\0'){
        length++;        
    }  
    return length;
}

void print_number (char *arr, uint8_t i, uint8_t unitt){

    switch (arr[i])
    {
    case mot:
         if(unitt == TRAM || unitt == DONVI) printf ("Mot ");
         else if(unitt == CHUC) printf ("Muoi ") ;               
        break;
    case hai:
        printf("Hai ");
        break;
    case ba:
        printf("Ba ");
        break;
    case bon:
        printf("Bon ");
        break;
    case nam:
        if(unitt == TRAM || unitt == CHUC ) printf ("Nam ");
        else if (unitt == DONVI && arr[i-1] != '0') printf ("Lam");
        else printf("Nam ");
        break;
    case sau:
        printf("Sau ");
        break;
    case bay:
        printf("Bay ");
        break;
    case tam:
        printf("Tam ");
        break;
    case chin:
        printf("Chin ");
        break;
    case khong:
        if(unitt == TRAM && arr[i+1] != '0' || unitt == TRAM && arr[i+2] != '0') printf ("Khong ");
        else if(unitt == CHUC && arr[i+1] != '0' ) printf ("Le ");        
        break;    
    default:
        break;
    }
}

void unit1 (char *arr, uint8_t i,uint8_t u){
    switch (u)
    {
    case TRAM:
        if(arr[i+2] != '0' || arr[i] != '0' || arr[i+1] != '0')
        printf ("Tram ");        
        break;
     case CHUC:
        if (arr[i] != '0' && arr[i] != '1') printf (" Muoi ");
        break;
     case DONVI:
        uint8_t locate = length(arr) - i;
        if (locate == 10) printf("Ty ");
        else if (locate == 7 && arr[i] != '0' || locate == 7 && arr[i+1] != '0' || locate == 7 && arr[i+2] != '0') printf(" Trieu ");  
        else if (locate == 4 && arr[i-1] != '0' || locate == 4 && arr[i-2] != '0') printf(" Nghin ");  
        else if (locate == 1)printf ("VND");
        break;    
    default:
        break;
    }
}

int main(int argc, char const *argv[])
{
    char number[] = {"1155095000"}; //1 000 500 000
    for (uint8_t i = 0; i < length(number); i++){
        uint8_t unitt;
        unitt = (length(number) - i) % 3 ;
        print_number(number,i,unitt); 
        unit1(number,i,unitt);                 
    }   
    return 0;
}

