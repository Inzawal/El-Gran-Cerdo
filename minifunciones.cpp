#include <iostream>
using namespace std;
#include <cstdlib>
#include "Cabezera.h"
#include <cstring>
#include <ctime>
#include <windows.h>

///TODO: FUNCION QUE BUSCA EL MAYOR DE 2 VALORES
int mayor(int a, int b){
    if(a>b){
        return a;
    }
    else{
        if(b>a){
            return b;
        }
        else{
            return a-b;
        }
    }
}

///TODO: FUNCION QUE TIRA LOS DADOS
int tirada_dado(int a){



        a=1+rand()%6;
    ///a=3+rand()%3;

    switch(a){
    case 1: cout << "+-------+"<< endl;
            cout << "|       |"<< endl;
            cout << "|   0   |"<< endl;
            cout << "|       |"<< endl;
            cout << "+-------+"<< endl;
    break;
    case 2: cout << "+-------+"<< endl;
            cout << "|     0 |"<< endl;
            cout << "|       |"<< endl;
            cout << "| 0     |"<< endl;
            cout << "+-------+"<< endl;
    break;
    case 3: cout << "+-------+"<< endl;
            cout << "|     0 |"<< endl;
            cout << "|   0   |"<< endl;
            cout << "| 0     |"<< endl;
            cout << "+-------+"<< endl;
    break;
    case 4: cout << "+-------+"<< endl;
            cout << "| 0   0 |"<< endl;
            cout << "|       |"<< endl;
            cout << "| 0   0 |"<< endl;
            cout << "+-------+"<< endl;
    break;
    case 5: cout << "+-------+"<< endl;
            cout << "| 0   0 |"<< endl;
            cout << "|   0   |"<< endl;
            cout << "| 0   0 |"<< endl;
            cout << "+-------+"<< endl;
    break;
    case 6: cout << "+-------+"<< endl;
            cout << "| 0   0 |"<< endl;
            cout << "| 0   0 |"<< endl;
            cout << "| 0   0 |"<< endl;
            cout << "+-------+"<< endl;
    break;
    }
    return a;
}


///TODO: ACCIONES DE LAS RONDAS
int tiradaturno(int A, int& dado1, int& dado2, int& dado3, int triple_dado){

    if(triple_dado==0){
        dado1=tirada_dado(dado1);
        dado2=tirada_dado(dado2);

        cout << "Total [" <<dado1+dado2 << "]" << endl << endl;

        if(dado1==1&&dado2==1){ //SI AMBOS DADOS TIRAN UN AS
            return 0;
        }
        else{
            if(dado1==1||dado2==1){ //SI UNO DE LOS DADOS TIRA UN AS
                return 1;
            }
            else{
                if(dado1==dado2){ //SI AMBOS DADOS SON IGUALES Y NO SON ASES ESTAS OBLIGADO A TIRAR OTRA VEZ
                    return 2;
                }
                else{
                    return 3; // SI LOS DADOS SON DIFERENTES Y NO HAY ASES
                }
            }
        }
    }
    else{
        dado1=tirada_dado(dado1);
        dado2=tirada_dado(dado2);
        dado3=tirada_dado(dado3);

        cout << "Total [" <<dado1+dado2+dado3 << "]" << endl << endl;

        if(dado1==1&&dado2==1&&dado3==1){ //SI LOS 3 DADOS TIRAN UN AS
            return 4;
        }
        else{
            if(dado1==1||dado2==1||dado3==1){ //SI UNO DE LOS 3 DADOS TIRA UN AS
                return 5;
            }
            else{
                if(dado1==dado2&&dado1==dado3){ //SI LOS 3 DADOS SON IGUALES Y NO SON ASES ESTAS OBLIGADO A TIRAR OTRA VEZ
                    return 6;
                }
                else{
                    return 7; // SI LOS 3 DADOS SON DIFERENTES Y NO HAY ASES
                }
            }
        }
    }

}
