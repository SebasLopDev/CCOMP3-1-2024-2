#include <iostream>
using namespace std;



bool par(int p) {
    return p % 2 == 0;
}

bool impar(int q) {
    return q % 2 != 0;
}
void split(bool(*pI)(int), int* ini, int* fin) {
    int temp;
    int* p = ini;
    int tam = (fin - ini + 1) / 2;
    int* mitad = ini + tam;
    while (ini < mitad) {
        if (pI(*ini)) {
            temp = *ini;
            for (int* i = ini; i < fin; i++) {
                *i = *(i + 1);
                
            }
            *fin = temp;
            ini++;
        }
        else {

            ini++;
        }

    }
    for (int* i = p; i < fin; i++) {
        cout << *i << " ";
    }



}



int main()
{
    /*char c[][200] = {"La alegría es contagiosa. Pásalo","No se trata de entender la vida, sino de vivirla","Merece tu sueño"};
    imprimir(c,3);
    procesar(c,3,cipher,21);
    imprimir(c, 3);
    procesar(c, 3, cipher, 61);
    imprimir(c, 3);*/

    int a[] = { 1,2,3,4,5,6,7,8,9,10 };
    split(impar,a,a+9);


}


// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

char cipher(char ent,int key) {
    return ent * key % 256;


}
void imprimir(char(*Mat)[200],int tam) {
    for (char(*p)[200] = Mat; p < Mat + tam;p++) {
        cout << *p << endl;
    }


}

void procesar(char(*MatCad)[200], int Mattam,char(*oper)(char,int),int key) {
    for (char(*p)[200] = MatCad; p < MatCad + Mattam;p++) {
        for (char* q = *p; *q;q++) {
            
            *q=oper(*q,key);
           
        }
    }
    //imprimir(MatCad,Mattam);

}

bool par(int p) {
    return p % 2 == 0;
}

bool impar(int q) {
    return q % 2 != 0;
}
void split(bool(*pI)(int), int* ini, int* fin) {
    int temp;
    int* p = ini;
    int tam = (fin - ini + 1) / 2;
    int* mitad = ini + tam;
    while (ini < mitad) {
        if (pI(*ini)) {
            temp = *ini;
            for (int* i = ini; i < fin; i++) {
                *i = *(i + 1);
            }
            *fin = temp;
            ini++;


        }
        else {

            ini++;
        }

    }
    for (int* i = p; i <= fin; i++) {
        cout << *i << " ";
    }



}



int main()
{
    /*char c[][200] = {"La alegría es contagiosa. Pásalo","No se trata de entender la vida, sino de vivirla","Merece tu sueño"};
    imprimir(c,3);
    procesar(c,3,cipher,21);
    imprimir(c, 3);
    procesar(c, 3, cipher, 61);
    imprimir(c, 3);*/

    int a[10] = { 1,2,3,4,5,6,7,8,9,10};
    split(par,a,a+10);


}


