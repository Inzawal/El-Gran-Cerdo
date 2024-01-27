#include <iostream>
using namespace std;
#include <cstdlib>
#include "Cabezera.h"
#include <cstring>
#include <ctime>
#include <windows.h>


string jugar(int& num_ganador, char& salir_del_juego){

///TODO: REGISTRO DE NOMBRE
    system("cls");
    bool empate;
    string jugador1, jugador2, arranca;

    cout << "==========|COMIENZA EL JUEGO|========== "<<endl;
    cout << "=======================================" << endl << endl;
    cin.ignore();

    cout << "Ingrese el nombre del jugador 1: ";
    getline(cin,jugador1);

    cout << "Ingrese el nombre del jugador 2: ";
    getline(cin,jugador2);

    //system("pause>nul");
    system("cls");


///TODO: LLAMA AL JUGADOR QUE COMIENZA
    cout << "EL JUGADOR QUE SAQUE EL NUMERO MAS GRANDE ES MANO" << endl;
    cout << "=================================================" << endl << endl;

    //Llama al funcion para tirar los dados y ver cual jugador es mano.
    arranca = quien_comienza(jugador1, jugador2);

    system("cls");


///TODO: COMIENZA LA RONDA
    int puntos_de_ronda=0, lanzamientos=0, triple_dado=0, mostrador=1, marrano=0, marrano2=0;
    int trufas=0, oinks=0, pdv=0, cerdocodi=0;
    int trufas2=0, oinks2=0, pdv2=0, cerdocodi2=0;

    ///Si es mano el jugador 1.
    if(arranca==jugador1){
        empate=true;

        for(int x=0; x<5; x++){ //5 Turnos.

            /*PLAYER 1*/
            //Llama a la funcion ronda.
            ronda(trufas,oinks, puntos_de_ronda, lanzamientos, x,triple_dado,trufas2,jugador1,jugador2, mostrador, marrano);

            //Guarda la cantidad mas alta de lanzamientos.
            if(cerdocodi==0){
                cerdocodi=lanzamientos;
            }
            else{
                if(cerdocodi<lanzamientos){
                    cerdocodi=lanzamientos;
                }
            }

            //Resetea los lanzamientos.
            lanzamientos=0;
            system("cls");


          /*PLAYER 2*/
            //Llama a la funcion ronda.
            ronda(trufas2, oinks2, puntos_de_ronda, lanzamientos, x,triple_dado, trufas, jugador2, jugador1, mostrador, marrano2);

            //Guarda la cantidad mas alta de lanzamientos.
            if(cerdocodi2==0){
                cerdocodi2=lanzamientos;
            }
            else{
                if(cerdocodi2<lanzamientos){
                    cerdocodi2=lanzamientos;
                }
            }

            //Resetea los lanzamientos.
            lanzamientos=0;
            system("cls");
        }
    }
    ///Si es mano el jugador 2.
    else{
        empate=false;
        for(int x=0; x<5; x++){ //5 turnos

            /*PLAYER 2*/
            //Llama a la funcion ronda.
            ronda(trufas2,oinks2, puntos_de_ronda, lanzamientos, x,triple_dado, trufas, jugador2, jugador1, mostrador, marrano2);

            //Guarda la cantidad mas alta de lanzamientos.
            if(cerdocodi2==0){
                cerdocodi2=lanzamientos;
            }
            else{
                if(cerdocodi2<lanzamientos){
                    cerdocodi2=lanzamientos;
                }
            }

            lanzamientos=0;
            system("cls");

            /*PLAYER 1*/
            //Llama a la funcion ronda.
            ronda(trufas, oinks, puntos_de_ronda, lanzamientos, x,triple_dado,trufas2, jugador1, jugador2, mostrador, marrano);

            //Guarda la cantidad mas alta de lanzamientos.
            if(cerdocodi==0){
                cerdocodi=lanzamientos;
            }
            else{
                if(cerdocodi<lanzamientos){
                    cerdocodi=lanzamientos;
                }
            }

            lanzamientos=0;
            system("cls");
        }
    }


///TODO:  HITOS

    int mtt=0, c50t=0, pdoink=0, cerd=0, Maxrrano1=0;
    int mtt2=0, c50t2=0, pdoink2=0,cer2=0,Maxrrano2=0;

    //BUSCA EL MAXRRANO
    if(marrano>marrano2){
        Maxrrano1=1;
        Maxrrano2=0;
    }
    else{
        if(marrano<marrano2){
        Maxrrano1=0;
        Maxrrano2=1;
        }
        else{
            if(marrano==marrano2){
                Maxrrano1=0;
                Maxrrano2=0;
            }
        }
    }

    //OINKS TOTALES
    pdoink=oinks*2;
    pdoink2=oinks2*2;

    //CADA 50 TRUFAS
    c50t=trufas/50;
    c50t2=trufas2/50;

    //EL QUE MAS TRUFAS CONSIGUIO
    if(trufas>trufas2){
    mtt=5;
    mtt2=0;
        if(Maxrrano2==1){
        mtt-=1;
        }
    }
    else{
        if (trufas<trufas2){
            mtt2=5;
            mtt=0;
            if(Maxrrano1==1){
                mtt2-=1;
            }

        }
        else{
            if (trufas+trufas2!=0){
                mtt2=5;
                mtt=5;
                    if(Maxrrano1==1){
                    mtt2-=1;
                    }
                    else{
                            if(Maxrrano2==1){
                    mtt-=1;
                    }
                    }
            }
        }
    }


    if(cerdocodi>cerdocodi2){
        cerd=2;
        cer2=0;
                if(Maxrrano2==1){
        cerd-=1;
        }
    }
    else{
        if(cerdocodi<cerdocodi2){
        cerd=0;
        cer2=2;
                if(Maxrrano1==1){
        cer2-=1;
        }
        }
        else{
            if(cerdocodi+cerdocodi2!=0){
                cerd=2;
                cer2=2;
                                    if(Maxrrano1==1){
                    cer2-=1;
                    }
                    else{
                            if(Maxrrano2==1){
                    cerd-=1;
                    }
                    }

            }
        }
    }

    //SUMA DE TODOS LOS PUNTOS DE VICTORIA
    pdv=c50t+pdoink+mtt+cerd+Maxrrano1;
    pdv2=c50t2+pdoink2+mtt2+cer2+Maxrrano2;

    cout << "                               EL GRAN CERDO                               " << endl << endl;
    cout << "----------------------------------------------------------------------------"<< endl;
    cout << "HITO                   " << jugador1 << "                           " << jugador2 << "" << endl;
    cout << "----------------------------------------------------------------------------"<< endl;
    cout << "Mas trufas en total    "<<mtt<<" PDV ("<<trufas<<" trufas)             "<<mtt2<<" PDV ("<<trufas2<<" trufas)"<< endl;
    cout << "Cada 50 trufas         "<<c50t<<" PDV ("<<c50t*50<<" trufas)              "<<c50t2<<" PDV ("<<c50t2*50<<" trufas)"<< endl;
    cout << "Oinks                  "<<pdoink<<" PDV ("<<oinks<<" oinks)               "<<pdoink2<<" PDV ("<<oinks2<<" oinks)"<<endl;
    cout << "Cerdo codicioso        "<<cerd<<" PDV ("<<cerdocodi<<" lanzamientos)        "<<cer2<<" PDV ("<<cerdocodi2<<" lanzamientos)"<<endl;

    cout << "Maxrrano               "<<Maxrrano1<<" PDV ("<<marrano<<")              "<<Maxrrano2<<" PDV ("<<marrano2<<")"<<endl;
    cout << "----------------------------------------------------------------------------"<<endl;
    cout << "TOTAL                  "<<pdv<<" PDV                    "<<pdv2<<" PDV"<<endl;

///TODO: REVELAR EL GANADOR

    /*GANADOR JUGADOR 1*/
    if(pdv> pdv2){

        cout << endl << "GANADOR: "<<jugador1<<" con "<<pdv<<" puntos de victoria.  " << endl;
        //SEGUIR JUGANDO
        cout <<endl << "PARA SEGUIR JUGANDO ESCRIBA LA PALABARA OINK... ";
        string palabra_oink;
        cin >> palabra_oink;

        if(palabra_oink=="oink"|| palabra_oink=="OINK"){        //SIGUE JUGANDO
            cout << endl << endl << "PERFECTO, SEGUIMOS JUGANDO... ";

            system("pause>nul");
            system("cls");
        }

        else{           //DEJA DE JUGAR
            cout << endl << endl << "GRACIAS POR JUGAR AL GRAN CERDO..." << endl;

            salir_del_juego='S';
            system("pause>nul");
        }

        //DA POR REFERENCIA EL PUNTAJE DEL GANADOR
        num_ganador=pdv;

        //DA POR REFERENCIA EL NOMBRE DEL GANADOR
        return jugador1;
    }

    /*GANADOR JUGADOR 2*/
    else{
        if(pdv<pdv2){
            cout << endl << "GANADOR: "<<jugador2<<" con "<<pdv2<<" puntos de victoria.  ";
            //SEGUIR JUGANDO
            cout <<endl << "PARA SEGUIR JUGANDO ESCRIBA LA PALABARA OINK... ";
            string palabra_oink;
            cin >> palabra_oink;

            if(palabra_oink=="oink"|| palabra_oink=="OINK"){        //SIGUE JUGANDO
                cout << endl << endl << "PERFECTO, SEGUIMOS JUGANDO... ";

                system("pause>nul");
                system("cls");
            }
            else{       //DEJA DE JUGAR
            cout << endl << endl << "GRACIAS POR JUGAR AL GRAN CERDO..." << endl;

            salir_del_juego='S';
            system("pause>nul");
            }

            //DA POR REFERENCIA EL PUNTAJE DEL GANADOR
            num_ganador=pdv2;

            //DA POR REFERENCIA EL NOMBRE DEL GANADOR
            return jugador2;
        }

        /*EMPATE*/
        else{
            cout << "ES UN EMPATE PARA AMBOS";
            //SEGUIR JUGANDO
            cout <<endl << "PARA SEGUIR JUGANDO ESCRIBA LA PALABARA OINK... ";
            string palabra_oink;
            cin >> palabra_oink;

            if(palabra_oink=="oink"|| palabra_oink=="OINK"){        //SIGUE JUGANDO
                cout << endl << endl << "PERFECTO, SEGUIMOS JUGANDO... ";

                system("pause>nul");
                system("cls");
            }
            else{       //DEJA DE JUGAR
                cout << endl << endl << "GRACIAS POR JUGAR AL GRAN CERDO..." << endl;

                salir_del_juego='S';
                system("pause>nul");
            }

            if(empate==true){
                //DA POR REFERENCIA EL PUNTAJE DEL GANADOR
                num_ganador=pdv;
                //DA POR REFERENCIA EL NOMBRE DEL GANADOR
                return jugador1;
            }
            else{
                //DA POR REFERENCIA EL PUNTAJE DEL GANADOR
                num_ganador=pdv2;
                //DA POR REFERENCIA EL NOMBRE DEL GANADOR
                return jugador2;
            }

            system("pause>nul");
            system("cls");
        }

    }

}
