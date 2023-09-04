/* 8.9 Escriba un programa que utilice la funcion strcmp, para comparar 
dos cadenas introducidas por el usuario. El programa debera indicar si la primera cadena 
es menor que, igual que o mayor que la segunda cadena. */

#include <iostream>
#include <string.h>

using namespace std;

int main(){
    char firstSentence[100], secondSentence[100];
    int result;

    cout << "Ingrese la primera cadena de caracteres : ";
    cin >> firstSentence;
    
    cout << endl;

    cout << "Ingrese la segunda cadena de caracteres: ";
    cin >> secondSentence;

    cout << endl;

    result = strcmp(firstSentence, secondSentence); //Compara ambos enunciados
    /*El strcmp funciona de la siguiente manera, compara ambos enunciados y da un resultado que puede ser -1, 0 o 1
    0 = Ambos enunciados son iguales
    1 = Primera variable posee mayor cantidad de caracteres
    -1 = Segunda varaible posee mayour cantidad de caracteres
    */

    if (result == 0){
        cout << "Ambos tienen la misma cantidad de caracteres.\n";
    } else if (result == 1){
        cout << "El primer enunciado: " << firstSentence << " tienen la mayor cantidad de caracteres\n";
    } else{ //En este else significaria que el valor arrojado por el strcmp es igual a -1, significando asi que la segunda variable (el segundo enunciado) es el que posee mayor caracteres
        cout << "El segundo enunciado: " << secondSentence << " tienen la mayor cantidad de caracteres\n";
    }
    
    return 0;
}
