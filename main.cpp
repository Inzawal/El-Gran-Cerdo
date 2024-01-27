#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include "Cabezera.h"
#include <cstring>
#include <windows.h>

int main(){

    srand(time(NULL));
    char seleccion_numero;
    char salir_del_juego;

    string name=" ", bestname;
    int num_estadistica = 0, mayor=0;

  while(salir_del_juego!='S'){

///TODO:INICIO DEL JUEGO
    cout << "BIENVENIDOS A: EL GRAN CERDO" << endl;
    cout << "===================================" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CERDITOS" << endl;
    cout << "===================================" << endl;
    cout << "0 - SALIR" << endl;

///PRECIONE UN NUMERO PARA ELEGIR
    cout << endl << "PRECIONE UN N"<< char(233) <<"MERO: ";
    cin >> seleccion_numero;
    cout << endl;

///SWITCH PARA ELEGIR UNA OPCION DEL JUEGO
    switch(seleccion_numero){

///TODO:0 SALIR DEL JUEGO
    case '0' :

        cout << char(168) <<"ESTA SEGURO QUE DESEA SALIR DEL JUEGO? (S / N) : ";
        cin >> salir_del_juego;

        salir_del_juego = toupper(salir_del_juego); //PONE EN MAYUSCULA LAS LETRAS
        cout << endl;

        //Opcion por si se apreta una tecla incorrecta.
        while(salir_del_juego != 'S' && salir_del_juego != 'N'){

            cout << "OPCION INCORRECTA VUELVA A INTENTARLO\n"<<endl;
            cout << char(168) <<"ESTA SEGURO QUE DESEA SALIR DEL JUEGO? (S / N): ";
            cin >>salir_del_juego;

            salir_del_juego = toupper(salir_del_juego);
            cout << endl;
        }

        if(salir_del_juego == 'S'){
            cout << "SALISTE DEL JUEGO" << endl; //Sale del juego, finaliza el switch.
        }
        else{
            system("cls"); //No sale del juego, limpia la pantalla, llama a la funcion principal y finaliza el switch.
        }
    break;

///TODO: 1 JUGAR
    case '1' :
        //Sonidito canchero
        Beep (700,300);
        Beep (700,300);

        /// Inicia el juego
        name=jugar(num_estadistica, salir_del_juego);

        break;

///TODO: 2 ESTADISTICAS
    case '2' :

        system("cls");

        cout << char(186)<< "ESTADISTICAS:"<< char(186) << endl;
        cout << char(200);  for(int x=0;x<13;x++){   cout<< char(205);   }   cout << char(188) << endl;
        if(num_estadistica==0&&mayor==0){    // Si esta en cero no hay puntaje aun.
            cout << endl<< "==================|AUN NO HAY PUNTUACION|=================="<<endl;
        }
        else{
            if(num_estadistica>mayor){  //Compara estadisticas y guarda la mas grande.
            mayor=num_estadistica;
            bestname=name;

            cout << endl << "===============================|LA PUNTUACION MAS ALTA ES DE|==============================="<<endl;
            cout << "                         =================| " << bestname<< " |==================               " << endl<< endl;
            cout << "=====================================| CON UN TOTAL DE|====================================="<< endl;
            cout << "                         ==================| " << mayor << " PTS |=================                " << endl;
            }
            else{  // Muestra la estadistica mas alta.
            cout << endl << "===============================|LA PUNTUACION MAS ALTA ES DE|==============================="<<endl;
            cout << "                         =================| " << bestname<< " |==================               " << endl<< endl;
            cout << "======================================| CON UN TOTAL DE|======================================"<< endl;
            cout << "                         ==================| " << mayor << " PTS |===============                " << endl;

            }
        }

        //Vuelve al menú
        cout << endl << "Presione una tecla para volver al men"<< char(163)<<"...";
        system("pause>nul");
        system("cls");

        break;

///TODO: 3 CREDITOS
    case '3':
        system("cls");

        cout << char(186)<< "CERDITOS:"<< char(186) << endl;
        cout << char(200);  for(int x=0;x<9;x++){   cout<< char(205);   }   cout << char(188) << endl << endl;
        cout << "Team Oinkless\n----------------" << endl;
        cout << "Maria Quimey Buczy"<< char(164) <<"ski \nlegajo:26887\n----------------" << endl;
        cout << "Walter Ezequiel Inzaurralde \nlegajo:26973\n----------------" << endl;
        cout << "Enzo Roberto Bogado \nlegajo:26995\n----------------" << endl;
        cout << "Santiago Mendoza \nlegajo:26965\n----------------" << endl;
        cout << "Matias Nicolas Soubelet \nlegajo:26922\n----------------" << endl;

        cout << endl << "Presione una tecla para volver al men"<< char(163)<<"...";
        system("pause>nul");
        system("cls");

        break;

///TODO: POR SI SE PRECIONA CUALQUIER OTRA TECLA
    default:
        cout << "PRESIONASTE UNA TECLA INCORRECTA, VUELVA A INTENTARLO... ";

        system("pause>nul");

        system("cls");
    break;
    }//FIN DEL SWITCH.

  }//FIN DEL WHILE.
 system("pause>nul");
 return 0;
}

