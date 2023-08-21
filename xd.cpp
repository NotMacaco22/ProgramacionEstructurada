#include <iostream>
#define capacity 100

using namespace std;

typedef struct{
    char studentName[250];
    float notas;
} estudiantes;

estudiantes student[capacity];

void principalMenu(int cantEst,float sum);

int main(){
    int cantEst;
    float sum;

    cout << "Ingrese la Cantidad de Estudiantes a Ingresar" << endl;
    cin >> cantEst;

    cin.ignore();

    if (cantEst > 0){
        for (int i = 0; i < cantEst; i++){
            cout << "Ingrese el nombre del Estudiante #" << i + 1 << " : " << endl;
            scanf(" %[^\n]", student[i].studentName);
            cout << "Ingrese la nota correspondiente al PRIMER CORTE del estudiante #" << i + 1 << endl;
            cin >> student[i].notas;
            sum = sum + student[i].notas;
        }

        for (int i = 0; i < cantEst; i++){
        cout << "Nombre: " <<student[i].studentName << "\t" << "Nota: " << student[i].notas << endl;
        }
        principalMenu(cantEst,sum);
    }
    
    else{
        system("cls");
        cout << "Cantidad NO Valida - Vuelva a Intentarlo\n" << endl;
        main();
    }
    
    return 0;
}

void principalMenu(int cantEst, float sum){
    int opcMenu, position, bestGrade = -10000, worstGrade = 10000, opcEdit, posName, posGrade;
    float aux;
    
    cout << "MENU PRINCIPAL" << endl;
    cout << "1. Mostrar Nombre y Nota mas Alta" << endl;
    cout << "2. Mostrar Nombre y Nota mas Baja" << endl;
    cout << "3. Mostrar Promedio de Notas" << endl;
    cout << "4. Editar Nombre o Nota" << endl;
    cout << "5. Mostrar Notas de Menor a Mayor" << endl;
    cin >> opcMenu;
    
    switch (opcMenu){
    
    case 1:
        for (int i = 0; i < cantEst; i++){
            if (student[i].notas > bestGrade){
                bestGrade = student[i].notas;
                position = i;
            }
        }
        
        cout << "La nota mas alta pertenece a " << student[position].studentName << " y es de " << student[position].notas;
        
        break;

    case 2: //nota mas baja
        for (int i = 0; i < cantEst; i++){
            if (student[i].notas < worstGrade){
                worstGrade = student[i].notas;
            }
        }
        for (int i = 0; i < cantEst; i++){
            if ( (worstGrade = student[i].notas) ){
                position = i;
            }
        }
        cout << endl;
        cout << "----NOTA MAS BAJA----" << endl;
        cout << "Estudiante: " << student[position].studentName << endl;
        cout << "Nota: " << student[position].notas << endl;
        break;
    
    case 3:
        sum = sum / cantEst;
        cout << "El promedio de las notas es igual a: " << sum;
        break;

    case 4: 
        cout << "Que desea editar ?" << endl;
        cout << "1. Editar Nombre" << endl;
        cout << "2. Editar Nota" << endl;
        cin >> opcEdit;

        switch (opcEdit){
        case 1:
            cout << "Estos son los estudiantes: " << endl;
            for (int i = 0; i < cantEst; i++){
                cout << student[i].studentName << "\t";
            }
            cout << endl;

            for (int i = 0; i < cantEst; i++){
                cout << student[i].notas << "\t";
            }
            cout << endl;

            cout << "Digite la posicion del nombre que desea editar" << endl;
            cin >> posName;

            if (posName <= cantEst ){
                cout << "Escriba el nuevo nombre para el estudiante: ";
                scanf(" %[^\n]", student[posName-1].studentName);

                cout << "Asi quedarian los nuevos datos:" << endl;
                cout << "Nombre: " << student[posName-1].studentName << endl;
                cout << "Nota: " << student[posName-1].notas << endl;
            }

            else{
                cout << "OPCION NO VALIDA - VOLVIENDO AL MENU PRINCIPAL" << endl;
                principalMenu(cantEst,sum);
            }
            
            break;
        
        case 2:
            cout << "Estos son los estudiantes: " << endl;
                for (int i = 0; i < cantEst; i++){
                    cout << student[i].studentName << "\t";
            }
                cout << endl;

            for (int i = 0; i < cantEst; i++){
                    cout << student[i].notas << "\t";
            }
            cout << endl;
            
            cout << "Digite la posicion de la nota que desea editar" << endl;
            cin >> posGrade;

            if (posGrade <= cantEst ){
                cout << "Escriba la nueva nota para el estudiante: ";
                cin >> student[posGrade-1].notas;

                cout << "Asi quedarian los nuevos datos:" << endl;
                cout << "Nombre: " << student[posGrade-1].studentName << endl;
                cout << "Nota: " << student[posGrade-1].notas << endl;
            }

            else{
                cout << "OPCION NO VALIDA - VOLVIENDO AL MENU PRINCIPAL" << endl;
                principalMenu(cantEst,sum);
            }
            
            break;

        default:
            system("cls");
            cout << "OPCION NO VALIDA - VOLVIENDO AL MENU PRINCIPAL" << endl;
            principalMenu(cantEst,sum);
            break;
        }

        break;

    case 5:
        system("cls"); 
        cout << "Notas ordenadas de menor a mayor: " << endl;
        for (int i = 0; i < cantEst; i++){
            for (int j = i+1; j < cantEst; j++){
                if (student[i].notas > student[j].notas){
                    aux = student[j].notas;
                    student[j].notas = student[i].notas;
                    student[i].notas = aux;
                }
            }
        }

        for (int i = 0; i < cantEst; i++){
            cout << student[i].notas << endl;
        }

        break;
    
    default:
        cout << "OPCION NO VALIDA - VOLVIENDO AL MENU" << endl;
        principalMenu(cantEst,sum);
        break;
    }

}