#include <iostream>
#include <vector>
#include "../arbol/arbol_B_plus/arbol_B_plus.h"


using namespace std;

#define min_matches_x_nick 15 //Cantidad minima de matches para recomendar a alguien 

#ifndef MATCHER
#define MATCHER 1

class matcher{
    private:
        Arbol_B_plus oferta; //SOLO SE LLENA UNA VEZ
        Arbol_B_plus demanda; 

        //Arbol_B_plus arboles[2] = {new Arbol_B_Plus_S, new Arbol_B_Plus_S};

    public:
        //Se tiene una cadena de texto
        //Se utliliza el arbol b+ para ordenar el texto
        //Se compara con el de la otra persona

        void generate_Arbol_demanda_String(string pString){
            //Genera un arbol b+ a partir de un string  

            stringstream stream(pString); 
            string var;  
            vector<string> palabras;

            while (getline(stream, var, ' ')) { // METE LAS PALABRAS EN ..?
                if(T.size() > 0){
                    palabras.push_back(var);
                    //arbol_b_plus.add(var); // AÑADE LAS PALABRAS AL ARBOL B+
                }          
            }  

            /*for(auto var : palabras) // PARA VER LAS PALABRAS SEPARADAS OBTENIDAS DEL STRING
            {
                cout << var << endl;
            }*/

        }


        boolean match(arbol_b_plus pArbol_1, arbol_b_plus pArbol_2){
            int matches = 0;
            for(int i = 0; i < pArbol_1.height; i++){
                if(pArbol_1.get(i) = pArbol_2.get(1)){
                    matches += 1;
                }
            }

            if(matches >= min_matches_x_nick){
                return true;
            }

            return false;
        }
};

#endif