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

        if (line.empty()){ //Identifica cuando el usuraio ingresa una linea vacia para cambiar la variable booleana continueProgram a false y asi detener el ciclo
            continueProgram = false;

            if (readLines == 0){ //Si no se ingresa ninguna linea se mostrara el siguiente mensaje en pantalla
                cout << "Usted no ha ingresado ninguna linea." << endl;
            }

            else{
                system("cls"); 
                promedio = TotalCaracteres / readLines;
                cout << "El promedio de caracteres de las lineas que ingreso es igual a: " << promedio << "." << endl;
            }    
        }
        TotalCaracteres += line.length(); //Acumulador que todo el contenido de un enunciado para posteriormente ocuparlo para el promedio
        readLines++; //Luego de ingresar una linea exitosamente se suamara el acumulador readLines que leera las lineas leidas que ayudara para el promedio
    }
    
    return 0;
}
