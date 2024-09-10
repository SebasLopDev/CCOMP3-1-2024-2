#include<iostream>
#include <iomanip>
using namespace std;

void cambio(double money){
    int aux =0;       
    int pRelat= static_cast<int>(money*100);
    int lista[]={20000,10000,5000,2000,1000,500,200,100,50,20,10};
    cout<<"**********CAMBIO**********"<<endl;
    for(int i=0;i<11;i++){
        aux=pRelat/lista[i];               
        pRelat=pRelat-(lista[i]*aux);      
        
        cout<<"Billetes de "<<setw(3)<<lista[i]/100.00<<" Soles = "<<aux<<endl;

        
        
    }
}    






int main(){
    double dinero;
    cin>>dinero;
    cambio(dinero);

    return 0;
}