#include <iostream>
#include <cmath>
#include <string>
#include <bitset>
using namespace std;


string aDecimal(int num, int b) {
    string bin = bitset<32>(num).to_string().substr(32 - b,b);
    return bin;
}

string compl_2(const string& binario) {    
    string resultado = binario;    
    
    for (size_t i = 0; i < resultado.size(); ++i) {
        if (resultado[i] == '0') {
            resultado[i] = '1'; 
        } else {
            resultado[i] = '0'; 
        }
    }   
    
    bool acarreo = true; 
    for (int i = resultado.size() - 1; i >= 0; --i) {
        if (acarreo) {
            if (resultado[i] == '0') {
                resultado[i] = '1'; 
                acarreo = false; 
            } else {
                resultado[i] = '0';
                
            }
        }
    }    
    
    return resultado;
}

string binarySum(const string& a, const string& b) {
    int acarr = 0;
    string result;
    for (int i = a.size() - 1; i >= 0; --i) {
        int sum = (a[i] - '0') + (b[i] - '0') + acarr;
        acarr = sum / 2;
        result = std::to_string(sum % 2) + result;
    }
    return result;
}
string restaBin(const string& a, const string& b) {
    return binarySum(a, compl_2(b));
}

string desplazamiento(const string& binario) {
    return binario[0] + binario.substr(0, binario.size() - 1);
}

string boothM(int m, int q, int n) {
    
    string A(n, '0');
    string Q = aDecimal(q, n);
    string M = aDecimal(m, n);
    char Q_1 = '0'; 

    for (int i = 0; i < n; ++i) {
        char Q_0 = Q.back(); 
        
        if (Q_0 == '0' && Q_1 == '1') {
            A = binarySum(A, M); 
        } else if (Q_0 == '1' && Q_1 == '0') {
            A = restaBin(A, M); 
        }
        
        Q_1 = Q_0; 
        string combined = A + Q; 
        
        A = combined.substr(0, n); 
        Q = combined.substr(n); 
        
        if (A[0] == '1') {
            A = A.substr(1) + '1'; 
        } else {
            A = A.substr(1) + '0'; 
        }
    }
    
    return A + Q; 
}



int main() {
    int M, Q, b;
    cout << "Ingrese el multiplicando: ";
    cin >> M;
    cout << "Ingrese el multiplicador: ";
    cin >> Q;
    cout << "Ingrese la cantidad de bits: ";
    cin >> b;

    string result = boothM(M, Q, b);
    cout << "El resultado es: " << result <<endl;
    
    return 0;
}
