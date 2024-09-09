#include <iostream>
using namespace std;

void merge(int *p,int *q){        
    int temp;    
    int *ini=p;
    int *end = q+(q-p);
    while(p!=q && q<end){
        if(*q<*p){
            temp=*q;
            for(int *i=q;i>p;i--){
                *i=*(i-1);                
            }
            *p=temp;
            p++;
            q++;       

        }
        else{
            p++;
        }

    }    
    for(int *i=ini;i<end;i++){
        cout<<*i<<" ";
    }

    
}


int main(){
    //int arreglo[10]={2,6,8,12,20,22,1,3,7,11,15};
    int arreglo2[30] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18,20, 22, 24, 26, 28,1, 3, 5, 7, 9, 11,30, 32, 34, 36, 38, 40, 42, 44, 46};
       
    merge(arreglo2,arreglo2+15);
    /*for(int *i=arreglo;i<arreglo+10;i++){
        cout<<*i<<" ";
    }*/






    return 0;
}