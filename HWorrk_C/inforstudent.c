#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


typedef union 
{  
   char letter;
   double number;
} grade;

typedef enum
{
    NUM,
    CHAR
}typeGrade;

typedef struct
{
    char ten[50];
    char mssv[50];
    grade grade;
    typeGrade type;
} infor_student;

int16_t comparebyName (const infor_student *a, const infor_student *b){
    const char *nameA = a->ten;
    const char *nameB = b->ten;
     
    while (*nameA != '\0' && *nameB != '\0' && *nameA == *nameB){
        nameA++;
        nameB++;
    }
    return (int16_t)(*nameA) - (int16_t)(*nameB);

}

int16_t comparebyId (const infor_student *a, const infor_student *b){
    const char *idA = a->mssv;
    const char *idB = b->mssv;
     
    while (*idA == *idB){
        idA++;
        idB++;
    }
    return (int16_t)(*idA) - (int16_t)(*idB);

}

int16_t comparebyGrade (const infor_student *a, const infor_student *b){
    if (a->type == NUM && b->type == NUM){
        return (int16_t)(a->grade.number) - (int16_t)(b->grade.number);
        }
    else if (a->type == CHAR && b->type == CHAR){
        return (int16_t)(a->grade.letter) - (int16_t)(b->grade.letter);
    }
    else if (a->type == CHAR && b->type == NUM) {
        return (int16_t)(a->grade.letter) - (int16_t)(b->grade.number);
    }
     else if (a->type == NUM && b->type == CHAR) {
        return (int16_t)(a->grade.number) - (int16_t)(b->grade.letter);
    } 
}

void sortStudent(infor_student student[], uint8_t size, int16_t (*compare)(const infor_student*, const infor_student*)){
    for( uint8_t i = 0; i < size - 1; i++){
        for (uint8_t j = i + 1; j < size; j++)
        {
            if (compare(student + i,student + j) > 0){
                infor_student temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }        
    }
}

void printStudents (infor_student *student, uint8_t size){
    for(uint8_t i = 0; i < size; i++){
        printf ("Name: %s - MSSV: %s - Diem:", student[i].ten, student[i].mssv);
        if (student[i].type == CHAR){
            printf (" %c\n",student[i].grade.letter);
        } else printf (" %.2f\n",student[i].grade.number);
    }
}

int main(int argc, char const *argv[])
{
    infor_student student[]={{.ten = "Anh",.mssv = "108",.grade.letter = 'A' ,.type = CHAR},
                             {.ten = "Quan",.mssv = "102",.grade.number = 9.5,.type = NUM },
                             {.ten = "Huy",.mssv = "103",.grade.letter = 'B',.type = CHAR },
                             {.ten = "Cong",.mssv = "105",.grade.number = 8.0,.type = NUM },};
    uint8_t n = sizeof(student)/sizeof(student[0]);
    sortStudent(student, n, comparebyGrade);
    printStudents(student, n);
   
   
    
    return 0;
}


