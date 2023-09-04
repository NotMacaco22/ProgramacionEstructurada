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

    if (cont <= 0) { //Evita qque se ingresen lineas menores o igual a 0
        system("cls || clear"); //Borra pantalla, cls para windows y clear para Mac OS 
        cout << "Valor No Aceptado - Vuelva a intentarlo nuevamente" << endl;
        cout << endl;
        main();
    } else { //Ciclo While que permite que se ingresen la cantidad de enunciados anteriormente solicitado
        while (aux < cont + 1 && cin.getline(lineas[aux], MAX_LENGHT)) { //El cin.getline() permite al programa leer toda una linea, incluyendo espacios
            cout << "Ingrese la linea #" << aux + 1 << ": ";
            aux++; // Contador que ira sumando segun se ingresen los enunciados, evitando asi que se ingresen mas enunciados de los que el usuario quiere.
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
