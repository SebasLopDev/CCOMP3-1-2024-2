#include<iostream>
#include <iomanip>
using namespace std;

void cambio(double money){
    int aux =0;       
    float pRelat=money;
    float lista[]={200,100,50,20,10,5,2,1,0.50,0.20,0.10};
    cout<<"**********CAMBIO**********"<<endl;
    for(int i=0;i<11;i++){
        aux=pRelat/lista[i];               
        pRelat=pRelat-(lista[i]*aux);
        cout<<"Billetes de "<<setw(3)<<lista[i]<<" Soles = "<<aux<<endl;
    }
    
}





int main(){
    cambio(2135.80);

    return 0;
}