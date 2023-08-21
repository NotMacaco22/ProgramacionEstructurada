#include <iostream>
#define capacity 100

using namespace std;

typedef struct{
    char studentName[250];
    float notas;
} estudiantes;

estudiantes student[capacity];

void principalMenu(int cantEst,float sum);
void backToMenu(int cantEst, float sum);

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
            while (student[i].notas > 100 || student[i].notas < 0){
                cout << "Nota No Valida - Intente Nuevamente" << endl;
                cout << "Ingrese la nota correspondiente al PRIMER CORTE del estudiante #" << i + 1 << endl;
                cin >> student[i].notas; 
            }
            sum = sum + student[i].notas;
        }

        system("cls");
        principalMenu(cantEst,sum);
    }
    
    else{
        system("cls");
        cout << "Cantidad de Estudiantes NO Valida - Vuelva a Intentarlo\n" << endl;
        main();
    }
    
    return 0;
}

void principalMenu(int cantEst, float sum){
    int opcMenu, position, bestGrade = -10000, worstGrade, opcEdit, posName, posGrade;
    float aux;
    
    cout << "* * * MENU PRINCIPAL - NOTAS PRIMER CORTE * * *\n" << endl;
    cout << "   1. Mostrar Nombre y Nota mas Alta" << endl;
    cout << "   2. Mostrar Nombre y Nota mas Baja" << endl;
    cout << "   3. Mostrar Promedio de Notas" << endl;
    cout << "   4. Editar Nombre o Nota" << endl;
    cout << "   5. Mostrar Notas de Menor a Mayor" << endl;
    cout << "\n* * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cin >> opcMenu;
    
    switch (opcMenu){
    
    case 1:
        system("cls");
        for (int i = 0; i < cantEst; i++){
            if (student[i].notas > bestGrade){
                bestGrade = student[i].notas;
                position = i;
            }
        }
        
        cout << "\tNOTA MAS ALTA" << endl;
        cout << "Nombre: " << student[position].studentName << "    Nota: " << student[position].notas << endl;
        cout << "* * * * * * * * * * * * * * * *" << endl;

        backToMenu(cantEst, sum);

        break;

    case 2: //nota mas baja
    worstGrade = student[0].notas;  // Inicializa worstGrade con la primera nota

    for (int i = 1; i < cantEst; i++) {  // Comienza desde el segundo estudiante
        if (student[i].notas < worstGrade) {
            worstGrade = student[i].notas;  // Actualiza worstGrade si se encuentra una nota menor
            position = i;
        }
    }

    cout << "\tNOTA MAS BAJA" << endl;
        cout << "Nombre: " << student[position].studentName << "    Nota: " << student[position].notas << endl;
        cout << "* * * * * * * * * * * * * * * *" << endl;

        backToMenu(cantEst, sum);

    break;

    
    case 3:
        system("cls");
        sum = sum / cantEst;
        cout << "El promedio de las notas es igual a: " << sum << endl << endl;

        backToMenu(cantEst, sum);

        break;

    case 4: 
        system("cls");
        cout << "Que desea editar ?" << endl;
        cout << "1. Editar Nombre" << endl;
        cout << "2. Editar Nota" << endl;
        cin >> opcEdit;
        system("cls");
        switch (opcEdit){
        case 1:
            cout << "Estos son los estudiantes registrados: " << endl;
            cout << "Nombres: ";
            for (int i = 0; i < cantEst; i++){
                cout << student[i].studentName << "\t";
            }
            cout << endl;
            cout << endl;

            cout << "Notas: ";
            for (int i = 0; i < cantEst; i++){
                cout << student[i].notas << "\t";
            }
            cout << endl;
            cout << endl;

            cout << "Digite la posicion del nombre que desea editar" << endl;
            cin >> posName;

            if (posName <= cantEst ){
                cout << "Escriba el nuevo nombre para el estudiante: ";
                scanf(" %[^\n]", student[posName-1].studentName);

                system("cls");
                cout << "Asi quedarian los nuevos datos:" << endl;
                cout << "Nombre: " << student[posName-1].studentName << endl;
                cout << "Nota: " << student[posName-1].notas << endl;
                cout << endl;

                backToMenu(cantEst, sum);
            }

            else{
                cout << "OPCION NO VALIDA - VOLVIENDO AL MENU PRINCIPAL" << endl;
                principalMenu(cantEst,sum);
            }
            
            break;
        
        case 2:
            cout << "Estos son los estudiantes registrados: " << endl;
            cout << "Nombres: ";
            for (int i = 0; i < cantEst; i++){
                cout << student[i].studentName << "\t";
            }
            cout << endl;
            cout << endl;

            cout << "Notas: ";
            for (int i = 0; i < cantEst; i++){
                cout << student[i].notas << "\t";
            }
            cout << endl;
            cout << endl;
            
            cout << "Digite la posicion de la nota que desea editar" << endl;
            cin >> posGrade;

            if (posGrade <= cantEst ){
                cout << "Escriba la nueva nota para el estudiante: ";
                cin >> student[posGrade-1].notas;

                system("cls");
                cout << "Asi quedarian los nuevos datos:" << endl;
                cout << "Nombre: " << student[posGrade-1].studentName << endl;
                cout << "Nota: " << student[posGrade-1].notas << endl;
                cout << endl;
                
                backToMenu(cantEst, sum);
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
        cout << endl;
        backToMenu(cantEst, sum);

        break;
    
    default:
    system("cls");
        cout << "      OPCION NO VALIDA REGRESANDO AL MENU\n" << endl;
        principalMenu(cantEst,sum);
        break;
    }

}

void backToMenu(int cantEst, float sum){
    int opc;
    cout << "Desea volver al Menu Principal?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No / Salir" << endl;
    cin >> opc;
    
    switch (opc){
    case 1:
        system("cls");
        principalMenu(cantEst,sum);
        break;
    
    case 2:
        cout << endl;
        cout << "Adioos" << endl;
        break;
    default:
        system("cls");
        cout << "Opcion no Valida - Intente Nuevamente" << endl;
        backToMenu(cantEst, sum);
        break;
    }
}