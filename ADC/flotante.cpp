#include <iostream>
#include <bitset>
#include <cmath>
#include <cstdint>

using namespace std;


void mostrarBits(float num) {
    union {
        float input;
        int32_t bits;
    } data;
    
    data.input = num;    
    
    cout << "Bits de " << num << ": " << bitset<32>(data.bits) << endl;
}

// Función para separar los componentes de un número flotante
void descomponer(float num, int &signo, int &exponente, int &significando) {
    union {
        float input;
        int32_t bits;
    } data;
    
    data.input = num;

    signo = (data.bits >> 31) & 1; 
    exponente = (data.bits >> 23) & 0xFF; 
    significando = data.bits & 0x7FFFFF;     
    
    significando |= 1 << 23;
}

// Función para multiplicar dos números en punto flotante usando su descomposición
void multiplicacion(float x, float y) {
    int signo1, exponente1, significando1;
    int signo2, exponente2, significando2;
    
    const int bias = 127;
   
    descomponer(x, signo1, exponente1, significando1);
    descomponer(y, signo2, exponente2, significando2);
   
    cout << "Numero 1: Signo=" << signo1 << ", Exponente=" << exponente1 - bias 
         << ", Significando=" << significando1 << endl;
    cout << "Numero 2: Signo=" << signo2 << ", Exponente=" << exponente2 - bias 
         << ", Significando=" << significando2 << endl;

    // Verificar si alguno de los números es cero
    if (x == 0.0f || y == 0.0f) {
        cout << "Resultado:" << endl;
        return;
    }
    
    int signo_resultado = signo1 ^ signo2;
    
    int exponente_resultado = (exponente1 - bias) + (exponente2 - bias) + bias;

    uint64_t producto_significando = static_cast<uint64_t>(significando1) * significando2;

    if (producto_significando & (1ULL << 47)) {
        producto_significando >>= 1;
        exponente_resultado++;
    }

    // Verificar overflow/underflow de exponente
    if (exponente_resultado >= 255) {
        cout << "Overflow " << endl;
        return;
    } else if (exponente_resultado <= 0) {
        cout << "Underflow " << endl;
        return;
    }

    
    int significando_resultado = (producto_significando >> 24) & 0x7FFFFF;

    // Ensamblar el número flotante resultante
    union {
        float resultado;
        int32_t bits;
    } res;

    res.bits = (signo_resultado << 31) | (exponente_resultado << 23) | significando_resultado;
   
    cout << "Resultado en bits: " << bitset<32>(res.bits) << endl;
    
    cout << "Resultado en decimal: " << res.resultado << endl;
    
    float resultado_directo = x * y;
    cout << "Resultado directo de la multiplicacion: " << resultado_directo << endl;
}


int main() {
    float num1, num2;    
    cout << "Ingrese el primer numero flotante: ";
    cin >> num1;
    cout << "Ingrese el segundo numero flotante: ";
    cin >> num2;
    
    mostrarBits(num1);
    mostrarBits(num2);
    
    multiplicacion(num1, num2);

    return 0;
}
