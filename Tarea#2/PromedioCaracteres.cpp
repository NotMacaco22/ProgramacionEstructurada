/* Escriba un programa que lea varias líneas de texto y determine el promedio de caracteres 
(incluyendo signos de puntuación y espacios en blanco) en cada línea. Deberá leer líneas hasta 
que encuentre una línea vacía (primer carácter sea \n)*/

#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string line;
    int numLine = 1, readLines = 0, TotalCaracteres = 0;
    float promedio;
    bool continueProgram = true;

    cout << "Ingrese las lineas de texto que desee - Luego sacare un promedio.\nPara finalizar deje el espacio en blanco y presione Enter\n";
    cout << endl;

    while (continueProgram == true){
        cout << "Ingrese la linea #"<<numLine << endl;
        getline(cin,line);
        numLine++;

        if (line.empty()){
            continueProgram = false;

            if (readLines == 0){
                cout << "Usted no ha ingresado ninguna linea." << endl;
            }

            else{
                system("cls");
                promedio = TotalCaracteres / readLines;
                cout << "El promedio de caracteres de las lineas que ingreso es igual a: " << promedio << "." << endl;
            }    
        }
        TotalCaracteres += line.length();
        readLines++;
    }
    
    return 0;
}
