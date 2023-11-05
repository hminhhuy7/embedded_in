#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define USA 1
#define EUR 2
#define VND 3

typedef union 
{
    double usa;
    double eur;
    double vnd;
} prices;

typedef enum
{
    SINGLE,
    DOUBLE
} roomTypes;

typedef enum
{   BOOKED,
    AVAILABLE
} roomStatus;

typedef struct 
{
    uint8_t roomNumber[255];
    roomTypes type;
    roomStatus status;
    prices pay;
    //double currencyType;
} room_properties;

uint8_t rooms_status(uint8_t i){
    if (i % 2 == 0)
         return true;
    else    return false;    
}

void book_room (uint8_t* room){  
    uint8_t n,p,t,s1=-1; 
    room_properties number;    
    printf ("Room Number");
    printf ("   Status");
    for (uint8_t i = 0; i < 10; i++){
        number.roomNumber[i] = room[i];
        printf ("\n|____%d____|",number.roomNumber[i]);           
        if(rooms_status(number.roomNumber[i])){
            printf("_Available_");
        }    else printf("_____X_____");
    }
    back:
    printf("\n_________________________________________"); 
    printf("\nBAN MUON THUE PHONG SO:"); 
    scanf("%d",&n);
    for(uint8_t j = 0; j < 10; j++){
      s1++;
      if( n == number.roomNumber[j] && rooms_status(number.roomNumber[j]) == AVAILABLE){
             
            //printf("\nSo phong: %d",j); 
            printf("CHON LOAI PHONG (0 PHONG DON/ 1 PHONG DOI):");
            scanf("%d", &p);
            
            if(p == SINGLE){
                  printf("Chon loai don vi tien te de thanh toan (1 USA/ 2 EUR/ 3 VND):");
                  scanf("%d", &t);
                  
                  switch (t)
                  {
                  case 1:{
                         number.pay.usa = 5.0;                         
                         printf("\n_________________________________________"); 
                         printf("\nSo phong: %d",number.roomNumber[s1-1]);
                         printf("\nLoai phong: Phong don");
                         printf("\nGia tien: %.2f USA",number.pay.usa);                  
                  }
                  break;
                  case 2:
                           number.pay.eur = 7.0;
                           printf("\n_________________________________________"); 
                           printf("\nSo phong: %d",number.roomNumber[s1-1]);
                           printf("\nLoai phong: Phong don");
                           printf("\nGia tien: %.2f EUR",number.pay.eur);  
                  break;
                  case 3:
                            number.pay.vnd = 100.0;
                            printf("\n_________________________________________"); 
                            printf("\nSo phong: %d",number.roomNumber[s1-1]);
                            printf("\nLoai phong: Phong don");
                            printf("\nGia tien: %.2f VND",number.pay.vnd); 
                  break;                  
            }
            }
            else if(p == DOUBLE){
                  printf("Chon loai don vi tien te de thanh toan (1 USA/ 2 EUR/ 3 VND):");
                  scanf("%d", &t);
                  
                  switch (t)
                  {
                  case 1:{
                         number.pay.usa = 10.0;                         
                         printf("\n_________________________________________"); 
                         printf("\nSo phong: %d",number.roomNumber[s1-1]);
                         printf("\nLoai phong: Phong doi");
                         printf("\nGia tien: %.2f USA",number.pay.usa);                  
                  }
                  break;
                  case 2:
                           number.pay.eur = 12.0;
                           printf("\n_________________________________________"); 
                           printf("\nSo phong: %d",number.roomNumber[s1-1]);
                           printf("\nLoai phong: Phong doi");
                           printf("\nGia tien: %.2f EUR",number.pay.eur);  
                  break;
                  case 3:
                            number.pay.vnd = 220.0;
                            printf("\n_________________________________________"); 
                            printf("\nSo phong: %d",number.roomNumber[s1-1]);
                            printf("\nLoai phong: Phong doi");
                            printf("\nGia tien: %.2f VND",number.pay.vnd); 
                  break;                  
            }          
            }
      }
      else  if( n == number.roomNumber[j] && rooms_status(number.roomNumber[j]) == BOOKED){            
            printf("_PHONG DA DUOC THUE, VUI LONG CHON PHONG KHAC_");           
            goto back; 
      }
      }
}

int main(int argc, char const *argv[])
{
    uint8_t room[]={101, 102, 103, 104, 105, 106, 107, 108, 109, 200};   
    book_room(room);

    return 0;
}

