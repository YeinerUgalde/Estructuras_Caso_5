#include <iostream>
#include "../grafo/grafo_N/grafo.h"


class User_matches {

    private:
        grafo usuarios;

    public:


        void generate_(string pUsuario){
        
            grafo.addNode(nick);    
            //generate_relacion();
                    
        }

        void generate_relacion(int pID_1, int pID_2, int pImportancia){
            grafo.addArcInt(pID_1, pID_2, pImportancia);
        }


        void getRelaciones(int pID){
            grafo.path(); // devuelve un vector
            grafo.printCounters(); //Para ver las relaciones en formato print
        }

};