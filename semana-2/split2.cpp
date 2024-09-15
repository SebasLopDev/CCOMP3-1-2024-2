#include <iostream>
using namespace std;

void split(int *ini,int *fin){
    int temp;
    int *p=ini;
    int tam = (fin - ini +1) / 2;  
    int *mitad = ini + tam;      
    while(ini<mitad){
        if(*ini%2!=0){      
            temp=*ini;
            for(int *i=ini;i<fin;i++){
                *i=*(i+1);                
            }
            *fin=temp;
            ini++;           
                           

        }
        else{

            ini++;
        }
        
    }
    for(int *i=p;i<=fin;i++){
        cout<<*i<<" ";
    }
    
    
   
}

int main(){
     int arreglo[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12,13,14,15,16,17,18,19,20};
     split(arreglo,arreglo+19);


    return 0;
}