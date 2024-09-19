# CCOMP3-1
    int tam;
    cout << "Introduzca el tamaño del arreglo" << endl;
    cin >> tam;
    int* arreglo2=new int[tam];     
    int* ptr = arreglo2;
    for (int* i = arreglo2; i < arreglo2+tam;i++) {
        cin >> *i;
        
    }
    cocktail(arreglo2, arreglo2 +tam-1);
    
