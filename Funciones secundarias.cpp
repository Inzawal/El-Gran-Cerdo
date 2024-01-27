#include <iostream>
using namespace std;
#include <cstdlib>
#include "Cabezera.h"
#include <cstring>
#include <ctime>
#include <windows.h>



///TODO: SE DEFINE QUIEN COMIENZA
    string quien_comienza(string jugador1, string jugador2){

    bool otra_tirada=false;
    do{

    otra_tirada=false;
    int dado1,dado2,dado3,dado4;

    ///TIRADA DEL JUGADOR 1
    cout <<"| " << jugador1 << " | " << "Presione un boton para tirar los dados... ";
    system("pause>nul");
    cout << endl << endl;
    dado1=tirada_dado(dado1);
    dado2=tirada_dado(dado2);
    cout <<"Total [" <<dado1+dado2 << "]" << endl << endl <<endl;

    ///TIRADA DEL JUGADOR 2
    cout <<"| " <<jugador2 << " | " << "Presione un boton para tirar los dados... ";
    system("pause>nul");
    cout << endl<< endl;
    dado3=tirada_dado(dado3);
    dado4=tirada_dado(dado4);
    cout << "Total [" <<dado3+dado4 << "]" << endl;
    cout << endl;


    ///EN CASO DE EMPATE

    if(dado1+dado2==dado3+dado4){
        int dado_mayor_j1, dado_mayor_j2;

        dado_mayor_j1=mayor(dado1,dado2);  //GUARDA EL MAYOR DADO DEL JUGADOR 1
        dado_mayor_j2=mayor(dado3,dado4);  //GUARDA EL MAYOR DADO DEL JUGADOR 2

        if(mayor(dado_mayor_j1,dado_mayor_j2)== 0){  //COMPARA LOS MAYORES PARA VER SI SON IGUALES ENTRE SI

            cout << endl << "==========|EMPATE|==========" << endl;
            cout << "LOS DADOS SE TIRAN DE NUEVO";
            cout << endl << endl;
            cout << "Presione un boton para seguir...";
            system("pause>nul");
            system("cls");

            otra_tirada=true;  //VUELVE AL PRINCIPIO DE LA FUNCION
        }

        else{
            if(mayor(dado_mayor_j1,dado_mayor_j2) == dado_mayor_j1){  //SI ES MAYOR EL JUGADOR 1
            cout << "==========|EL JUGADOR QUE COMIENZA ES"  << "|==========" << endl;
            cout << "       ==========| " <<jugador1 << " |==========" << endl <<endl;
            cout << "Presione un boton para seguir...";
            system("pause>nul");

            return jugador1;
            }

            else{
                if(mayor(dado_mayor_j1,dado_mayor_j2)== dado_mayor_j2){  //SI ES MAYOR EL JUGADOR 2
                cout << "==========|EL JUGADOR QUE COMIENZA ES"  << "|==========" << endl;
                cout << "       ==========| " <<jugador2 << " |==========" << endl <<endl;
                //cout << "==========EL JUGADOR QUE COMIENZA ES: " <<"| " <<jugador2 << " |==========" <<endl  << endl;
                cout << "Presione un boton para seguir...";
                system("pause>nul");

                return jugador2;
                }
            }
        }

    }

    ///EN CASO DE QUE UNO SEA MAYOR
    else{
        if(dado1+dado2>dado3+dado4){
            cout << "==========|EL JUGADOR QUE COMIENZA ES"  << "|==========" << endl;
            cout << "       ==========| " <<jugador1 << " |==========" << endl <<endl; //COMIENZA EL JUGADOR 1
            cout << "Presione un boton para seguir...";
            system("pause>nul");

            return jugador1;
        }

        else{
            cout << "==========|EL JUGADOR QUE COMIENZA ES"  << "|==========" << endl;
            cout << "       ==========| " <<jugador2 << " |==========" << endl <<endl; //COMIENZA EL JUGADOR 2
            cout << "Presione un boton para seguir...";
            system("pause>nul");

            return jugador2;
        }
    }

    }while(otra_tirada!=false);
}

///TODO: FUNCION RONDA
void ronda(int& trufas, int& oinks, int& puntos_de_ronda, int& lanzamientos, int x, int& triple_dado, int& tru2, string playerA,string playerB, int& mostrador, int&marrano){
        int Maxrrano=0;
    mostrador++;

    bool otra_tirada=false;

    do{

    otra_tirada=false;
    Maxrrano=0;

        cout << char(186)<< "RONDA " << x+1 << char(186) << endl;
        cout << char(200);  for(int x=0;x<7;x++){   cout<< char(205);   }   cout << char(188) << endl << endl;

        //Cantidad de trufas de los jugadores.
        if(mostrador%2==0){
            cout << playerA << ": " << trufas << " Trufas acumuladas |====================| " << playerB << ": " << tru2 << " Trufas acumuladas" << endl<< endl ;
        }
        else{
            cout << playerB << ": " << tru2 << " Trufas acumuladas |====================| " << playerA <<": " << trufas << " Trufas acumuladas" << endl<< endl ;
        }

        /*PLAYER 1*/
        cout << "Turno de: | " << playerA << " |   " ;

        cout << "Presione un boton para tirar los dados..."<< endl ;
        system("pause>nul");

        //CAJA DE DATOS
        cout  << "+-------------------------+" << endl;
        cout << "| RONDAS #"<< x+1 <<"               |" << endl;
        if(puntos_de_ronda<=9){
            cout << "| TRUFAS DE LA RONDA: " << puntos_de_ronda << "   |" << endl;

        }
        else{cout << "| TRUFAS DE LA RONDA: " << puntos_de_ronda << "  |" << endl;
        }
        cout << "| LANZAMIENTOS: " << lanzamientos << "         |" << endl;
        cout << "+-------------------------+" << endl;

        cout << endl << "LANZAMIENTO #" << lanzamientos+1 << endl << endl;

    char seguir_tirando;
    int tirada, dado1,dado2,dado3;

    tirada=tiradaturno(tirada,dado1,dado2,dado3,triple_dado);

    switch(tirada){

    ///2 DADOS

///SI AMBOS DADOS TIRAN UN AS
    case 0:
        cout << "EL CERDO SE HUNDE EN EL BARRO" << endl;
        cout <<  "SE PIERDEN TODAS LAS TRUFAS ACUMALADAS" << endl;
        //HABILITA EL TERCER DADO
        triple_dado=1;
        cout << endl << "<A PARTIR DE ESTE MOMENTO SE LANZAN 3 DADOS>" <<endl<< endl;

        trufas=0;
        cout << "Presione un boton para seguir...";
        system("pause>nul");
        system("cls");

        break;

///SI UNO DE LOS DADOS TIRA UN AS
    case 1:
        cout << "SE PIERDEN TODAS LAS TRUFAS DE ESTA RONDA"<<endl;
        cout << "SE LE CEDE EL TURNO AL OTRO JUGADOR"<<endl;

        trufas=trufas-puntos_de_ronda;

        puntos_de_ronda=0;
        cout << "Presione un boton para seguir...";
        system("pause>nul");
        system("cls");

        break;

///SI AMBOS DADOS SON IGUALES Y NO SON ASES ESTAS OBLIGADO A TIRAR OTRA VEZ
    case 2:
        cout << "EL CERDO HIZO UN OINK " << endl;
        cout << "SE TIRA DE NUEVO" << endl;


        Maxrrano=(dado1+dado2)*2;
        if(Maxrrano>marrano){
            marrano=Maxrrano;
        }

        puntos_de_ronda+=(dado1+dado2)*2;
        trufas+=(dado1+dado2)*2;+
        lanzamientos++;
        oinks++;

        //HABILITA EL TERCER DADO
        if(trufas>50&& tru2>50){
            triple_dado=1;
            cout << endl << "<A PARTIR DE ESTE MOMENTO SE LANZAN 3 DADOS>" <<endl<< endl;
        }

        cout << "Presione un boton para seguir..." << endl;
        system("pause>nul");
        system("cls");

        otra_tirada=true;
        break;

/// SI LOS DADOS SON DIFERENTES Y NO HAY ASES
    case 3:
        cout << "SUMASTE " << dado1+dado2 << " TRUFAS " << endl;


        Maxrrano=dado1+dado2;
        if(Maxrrano>marrano){
            marrano=Maxrrano;
        }

        trufas+=dado1+dado2;
        puntos_de_ronda+=dado1+dado2;
        lanzamientos++;

        //HABILITA EL TERCER DADO
        if(trufas>50&& tru2>50){
            triple_dado=1;
            cout << endl << "<A PARTIR DE ESTE MOMENTO SE LANZAN 3 DADOS>" <<endl<< endl;
        }

        do{
            cout << char(168)<< "CONTINUAR? (S/N):   ";
            cin >> seguir_tirando;

            seguir_tirando = toupper(seguir_tirando);

            if(seguir_tirando =='S'){
                system("cls");

                otra_tirada=true;

            }
            else{
                if(seguir_tirando =='N'){
                    system("cls");
                    //CAJA DE DATOS

                }
                else{
                    cout << "PRESIONASTE UNA TECLA INCORRECTA" << endl;
                }
            }
        } while(seguir_tirando!='S'&&seguir_tirando!='N');

        break;

///3 DADOS

///SI LOS 3 DADOS TIRAN UN AS
    case 4:
        cout << "EL CERDO SE HUNDE EN EL BARRO" << endl;
        cout <<  "TODAS LAS TRUFAS ACUMULADAS VAN AL RIVAL " << endl;

        tru2+=trufas;
        trufas=0;
        cout << "Presione un boton para seguir...";
        system("pause>nul");
        system("cls");

        break;

///SI UNO DE LOS 3 DADOS TIRA UN AS
    case 5:
        cout << "SE PIERDEN TODAS LAS TRUFAS DE ESTA RONDA"<<endl;
        cout << "LE CEDE EL TURNO AL OTRO JUGADOR"<<endl;

        trufas=trufas-puntos_de_ronda;

        puntos_de_ronda=0;
        cout << "Presione un boton para seguir...";
        system("pause>nul");
        system("cls");

        break;

///SI LOS 3 DADOS SON IGUALES Y NO SON ASES ESTAS OBLIGADO A TIRAR OTRA VEZ
    case 6:
        cout << "EL CERDO HIZO UN OINK " << endl;


        Maxrrano=(dado1+dado2+dado3)*2;
        if(Maxrrano>marrano){
            marrano=Maxrrano;
        }

        puntos_de_ronda+=(dado1+dado2+dado3)*2;
        trufas+=(dado1+dado2+dado3)*2;
        lanzamientos++;
        oinks++;

        cout << "SE TIRA DE NUEVO" << endl;

        cout << "Presione un boton para seguir...";
        system("pause>nul");
        system("cls");

        otra_tirada=true;
        break;

/// SI LOS 3 DADOS SON DIFERENTES Y NO HAY ASES
    case 7:
        cout << "SUMASTE " << dado1+dado2+dado3 << " TRUFAS " << endl;


        Maxrrano=dado1+dado2+dado3;
        if(Maxrrano>marrano){
            marrano=Maxrrano;
        }

        trufas+=dado1+dado2+dado3;
        puntos_de_ronda+=dado1+dado2+dado3;
        lanzamientos++;

        do{
            cout << char(168) <<"CONTINUAR? (S/N):   ";
            cin >> seguir_tirando;

            seguir_tirando = toupper(seguir_tirando);

            if(seguir_tirando =='S'){
                system("cls");

                otra_tirada=true;
            }
            else{
                if(seguir_tirando =='N'){
                        //CAJA DE DATOS
                        system("cls");
                }
                else{
                    cout << "PRESIONASTE UNA TECLA INCORRECTA" << endl;
                }
            }
        } while(seguir_tirando!='S'&&seguir_tirando!='N');

        break;

    }

    }while(otra_tirada!=false);

    puntos_de_ronda=0;

}


