#include <iostream>
using namespace std;



string unidades(int u){
    
    if(u==1){
        return "uno";
    }
    else if(u==2){
        return "dos";
    }
    else if(u==3){
        return "tres";
    }
    else if(u==4){
        return "cuatro";
    }
    else if(u==5){
        return "cinco";
    }
    else if(u==6){
        return "seis";
    }
    else if(u==7){
        return "siete";
    }
    else if(u==8){
        return "ocho";
    }
    else if(u==9){
        return "nueve";
    }
    else{
        return "";
    }
    
}

string exp(int d){
    if(d==10){
        return "diez";
    }
    else if(d==11){
        return "once";
    }
    else if(d==12){
        return "doce";
    }
    else if(d==13){
        return "trece";
    }
    else if(d==14){
        return "catorce";
    }
    else if(d==15){
        return "quince";
    }
    else if(d==16){
        return "dieciseis";
    }
    else if(d==17){
        return "diecisiete";
    }
    else if(d==18){
        return "dieciocho";
    }
    else if(d==19){
        return "diecinueve";
    }
    else{
        return "exp";
    }
}

string decenas(int d){
     
    if(d==20){
        return "veinte";
    }
    else if(d==30){
        return "treinta";
    }
    else if(d==40){
        return "cuarenta";
    }
    else if(d==50){
        return "cincuenta";
    }
    else if(d==60){
        return "sesenta";
    }
    else if(d==70){
        return "setenta";
    }
    else if(d==80){
        return "ochenta";
    }
    else if(d==90){
        return "noventa";
    }
    else{
        return "";
    }
    

}

string centenas(int c){
    if(c==100){
        return "cien";
    }
    else if(c==200){
        return "doscientos";
    }
     else if(c==300){
        return "trescientos";
    }
     else if(c==400){
        return "cuatrocientos";
    }
     else if(c==500){
        return "quinientos";
    }
     else if(c==600){
        return "seiscientos";
    }
     else if(c==700){
        return "setecientos";
    }
     else if(c==800){
        return "ochocientos";
    }
     else if(c==900){
        return "novecientos";
    }
    else{
        return "";
    }
}

/*string uMillar(int um){
    if(um==1000){
        return "mil";
    }    
    else{
        return "";
    }
}
*/


//Desde el 1 hasta el 99
string numeros_1(int num){
    if(num<10){
        return unidades(num);
    }
    if(num<100){
        if(num<20){
            return exp(num);
            
        }
        else if(num>=20){
            int v=(num/10)*10;            
            int res=num%10;
            if(v==20 && res!=0){
                return "veinti"+unidades(res);
            }
            if(res!=0){
                return decenas(v)+" y "+unidades(res);
            }
            else{
                return decenas(num);
            }

            
        }

    }
    return "";
    
}

//Del 1 al 999
string numeros_2(unsigned int num){  
    if (num < 100) {
        return numeros_1(num);
    }  
    
    if(num<1000){
        if(num>100){
            int v=(num/100)*100;            
            int res=num%100;
            if(v==100 && res!=0){
                return centenas(v)+"to "+numeros_1(res);
            }
            
            else if(v>=200 && res!=0){
                return centenas(v)+" "+numeros_1(res);
            }
            else{
                return centenas(num);
            }
            
        }
        else{
            return centenas(num);
        }
    }else{
        return "fuera de rango num2";
    }
}
string especial(int num){
    if(num%10==1){
        int c=(num/100)*100;
        int d=((num%100)/10)*10;
        //int u=d%10;
        //centenas(c)+ decenas(d);
        if(d==20){
            return centenas(c)+ "to veintiun mil ";
        }
        else{
            return centenas(c)+"to "+decenas(d)+" y un mil ";
        }
    }
}

//Del 1 al 999,999
string numeros_3(int num){
    if(num>=1 && num<100){
        return numeros_1(num);
    }

    if(num>=100 && num<1000){
        return numeros_2(num);
    }

    if(num>=1000 && num<1000000){
        int var=num/1000;
        int res=(num%1000);
        if(num==1000){
            return "mil";
        }
        else if(var==1 && res!=0){
            return "mil " + numeros_2(res);
        }
        else if(var==101){
            return "ciento un mil " + numeros_2(res);
        }
        //else if(var<100){
            //return numeros_2(var)+" mil " + numeros_2(res);
        //}
        else if(var%10==1 && var!=111){            
            return especial(var)+numeros_2(res);
        }
        else{

            return numeros_2(var) + " mil " + numeros_2(res);
        }
        /*else if(var<100 && res!=0){
            return numeros_1(var)+" mil #2"+numeros_1(res);
        }
        else if(var<1000 && res!=0){
            return numeros_2(var)+" mil #3"+numeros_2(res);
        }
        else{
            return numeros_1(var)+" mil#";
            //return uMillar(num);
        }*/

    }
    else{
        return "fuera de rango num3";
    }
}



      


int main(){

    int num=0;
    cout<<"Ingresa un numero en el rango del 1 al 999,999"<<endl;
    cin>>num;    
    cout<<numeros_3(num);

    return 0;
}
