#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void cocktail(int *ini,int *fin){
    int *start=ini;
    int *end=fin;
    bool flag=true;
    while(flag){
        flag=false;
        for(int *p=ini;p<fin;p++){
            if(*p>*(p+1)){
                swap(p,(p+1));
                flag=true;
            }
           

        }
        fin--;

        if (!flag) break;

        flag = false;

        for(int *q=fin;q>ini;q--){
            if(*q<*(q-1)){
                swap(q,q-1);
                flag=true;
            }
            
        }
        ini++;        

    }

    for(int *i=start;i<=end;i++){
        cout<<*i<<" ";
    }
}

int main(){
    int arreglo[20] = {24, 12, 1, 6, 2, 66, 7, 8, 9, 23,21,31,13,32,67,16,11,18,19,15};
    cocktail(arreglo,arreglo+19);



    return 0;
}