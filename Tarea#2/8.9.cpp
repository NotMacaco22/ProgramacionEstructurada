/* 8.9 Escriba un programa que utilice la funcion strcmp, para comparar 
dos cadenas introducidas por el usuario. El programa debera indicar si la primera cadena 
es menor que, igual que o mayor que la segunda cadena. */

#include <iostream>
#include <string.h>

using namespace std;

int main(){
    char firstSentence[20], secondSentence[20];
    int result;

    cout << "Ingrese la primera cadena de caracteres : ";
    cin >> firstSentence;
    
    cout << endl;

    cout << "Ingrese la segunda cadena de caracteres: ";
    cin >> secondSentence;

    cout << endl;

    result = strcmp(firstSentence, secondSentence);

    if (result == 0){
        cout << "Ambos tienen la misma cantidad de caracteres.\n";
    } else if (result == 1){
        cout << "El primer enunciado: " << firstSentence << " tienen la mayor cantidad de caracteres\n";
    } else{
        cout << "El segundo enunciado: " << secondSentence << " tienen la mayor cantidad de caracteres\n";
    }
    
    return 0;
}
