#include <iostream>
#include <cstring>
#define MAX_LENGHT 100
#define MAX_LINES 20

using namespace std;

int main() {
    int cont, aux = 0, contExt = 0;
    char lineas[MAX_LINES][MAX_LENGHT];
    char searchCaracter;

    cout << "Cuantas lineas de texto desea ingresar?" << endl;
    cin >> cont;
    cout << endl;

    if (cont <= 0) {
        system("cls || clear");
        cout << "Valor No Aceptado - Vuelva a intentarlo nuevamente" << endl;
        cout << endl;
        main();
    } else {
        while (aux < cont + 1 && cin.getline(lineas[aux], MAX_LENGHT)) {
            cout << "Ingrese la linea #" << aux + 1 << ": ";
            aux++;
        }

        system("cls || clear");

        cout << "Ingrese que caracter en especifico quiere buscar." << endl;
        cin >> searchCaracter;
        cout << endl;
        cout << searchCaracter << " esta presente en las siguientes lineas: " << endl;
        for (int i = 0; i < aux; i++) {
            if (strchr(lineas[i], searchCaracter) != nullptr) {  // Comprobar si el caracter está presente
                cout << "Linea #" << i <<" : " << lineas[i] << endl;
                contExt++;
            }
        }
        
        cout << endl;

        if (contExt == 0){
            cout << "El caracter " << searchCaracter << " no esta presente en ninguna linea." << endl;
        }
        
    }

    return 0;
}
