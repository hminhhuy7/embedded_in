#include <stdio.h>
#include <stdint.h>

uint64_t a;

void tong(int a, int b){
    printf ("Ket qua la :%d",a+b);
}

void hieu(int a, int b){
    printf ("Ket qua la :%d\n",a-b);
}

void tich(int a, int b){
    printf ("Ket qua la :%d",a*b);
}

void thuong(int a, int b){
    printf ("Ket qua la :%d",a/b);
}

int baso(int a, int b, double c){
    return a+b+c;
}

void tinhtoan (void(*prt)(int,int),int a, int b){
    prt(a,b);
}

int main(int argc, char const *argv[])
{
   void(*ketqua)(int,int)=&tong;
   ketqua(1,5);

   void(*dapan[])(int,int)={&hieu, &tich};
   dapan[1](4,5);

  tinhtoan(&hieu,1,2);
    
    int *pr = NULL;
    printf ("DC :%d\n", pr);

    int d = 10;
    int *prt=&d;
    int **prt2=&prt;
    printf ("DC1 :%d  %d\n", prt2,&prt);// bang nhau        
    printf ("DC2 :%d  %d\n", *prt2,prt);// bang nhau 
    printf ("DC3 :%d  %d\n", **prt2,*prt);//  bang nhau

    int e = 20;
    void *pt;  pt=&e;
    printf ("DC1 :%d %d\n", pt,&e);
    printf ("DC :%d %d\n", *(int*)pt,e);
}
