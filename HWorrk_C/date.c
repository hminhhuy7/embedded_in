#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

uint8_t date_sample[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct 
{
    uint8_t date;
    uint8_t month;
    uint16_t year;
    uint8_t *date_sample;

}date;

uint16_t calculate_year (date date_sample1, date date_sample2);
uint16_t calculate_month (date date_sample2);
uint8_t calculate_date (date date_sample2);
uint16_t calculate_day(date date_sample1, date date_sample2);

uint8_t main(int argc, char const *argv[])
{
    
    date date_set = {1,1,2010};
    date date_current = {5,10,2023};

    calculate_year (date_set, date_current);
    calculate_month (date_current);
    calculate_date (date_current);
    calculate_day(date_set, date_current);   
    return 0;
}

uint16_t calculate_year (date date_sample1, date date_sample2){    // tong nam 
    uint16_t year_total = 0;
    while ( date_sample1.year < date_sample2.year){                  
      if((date_sample1.year % 4 == 0 && date_sample1.year % 100 != 0) || date_sample1.year % 400 == 0 ){ 
         year_total +=366; 
         //return year_total;        
         //printf ("%d  %d nhuan\n",date_sample1.year, year_total);         
        }                
      else {         
          year_total +=365;          
          //printf ("%d %d khong nhuan\n",date_sample1.year,year_total);       
          //return year_total;
          }                     
         date_sample1.year++;                      
}
         uint16_t save = year_total;
         return save;
         //printf ("%d \n",save);
}

uint16_t calculate_month (date date_sample2){
     uint16_t total_month = 0 , j = 0;
     date_sample2.date_sample = date_sample; // gan con tro
     for(uint8_t i = 1; i <= date_sample2.month; i++){          
     if((date_sample2.year % 4 == 0 && date_sample2.year % 100 != 0) || date_sample2.year % 400 == 0 ){
        date_sample2.date_sample[1] = 29;
        total_month += date_sample2.date_sample[j];
        j++;
        //return total_month;
        //printf ("%d \n",total_month);    
    }
    else {
         date_sample2.date_sample[1] = 28;       
         total_month += date_sample2.date_sample[j];
         j++;
         //return total_month;
         //printf ("%d \n",total_month);
    }
}
         uint16_t save1 = total_month;
         return save1;
}

uint8_t calculate_date (date date_sample2){
    uint8_t total_date = 0;
    
    for(uint8_t i = 1; i <= date_sample2.date;i++){
        total_date +=1;
        //printf ("%d \n",total_date);
        //return total_date;
    }
     uint8_t save2 = total_date;
     return save2;
}

uint16_t calculate_day(date date_sample1, date date_sample2){
    uint16_t total =0, s=0;
    total = calculate_year (date_sample1, date_sample2) + calculate_month (date_sample2) + calculate_date (date_sample2);
    s=((total)%7);  
    switch (s){
      case 0:   printf ("Today is Monday");
      break;
      case 1:   printf ("Today is Tuesday^^^^");
      break;
      case 2:   printf ("Today is Wednesday");
      break;
      case 3:   printf ("Today is Thursday");
      break;
      case 4:   printf ("Today is Friday");
      break;
      case 5:   printf ("Today is Saturday");
      break;
      case 6:   printf ("Today is Sunday");
      break;
      default:
         printf("Khong co !");
         break;  
    }
}









