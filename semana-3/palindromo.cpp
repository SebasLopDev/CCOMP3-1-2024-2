#include <iostream>
using namespace std;
void upercase(char *pb){
    for(char *i=pb;*i!='\0';i++){
        if(*i>'a' && *i<'z'){
            *i=*i-32;
        }
    }
}

bool palindromo(char *p){
    char *ini=p;
    char *end;
    upercase(p);
    for(char *q=p;*q!='\0';q++){
        end=q;
    }
    while(ini<end){
        if(*ini==' '){
            ini++;
            continue;
        }
        if(*end==' '){
            end--;
            continue;
        }
        if(*ini==*end){
            ini++;
            end--;
            continue;
        }else{
            return false;
        }

    }
    return true;
  

}

int main(){

    char A[]="Amo LA PALOMA";
    cout<<palindromo(A);
    
    

    return 0;
}