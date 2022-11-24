#ifndef _GRAFO_
#define _GRAFO_ 1
#include <vector>
#include <iostream>
#include "NodoGrafo.h"
#include "INodo.h"
#include <map>
#include <queue>
#include "Arco.h"

using namespace std;

class Grafo {
    private:
        vector<NodoGrafo*> listaNodos;
        bool esDirigido = true;
        std::map<int,NodoGrafo*> hashNodos;


        void resetNodes() {
            for (std::vector<NodoGrafo*>::iterator current = listaNodos.begin() ; current != listaNodos.end(); ++current) {
                NodoGrafo* actual = (*current);
                actual->procesado = false;
                actual->visitado = false;
            }
        }

        NodoGrafo* findNotVisited() {
            NodoGrafo* result = nullptr;
            for (std::vector<NodoGrafo*>::iterator current = listaNodos.begin() ; current != listaNodos.end(); ++current) {
                NodoGrafo* actual = (*current);
                if (!actual->visitado) {
                    result = actual;
                    break;
                }
            }
            return result;
        }

    public:
        Grafo(bool pDirigido) {
            this->esDirigido =  pDirigido;
        }

        int getSize() {
            return this->listaNodos.size();
        }

        vector<NodoGrafo*> getListaNodos(){
            return this->listaNodos;
        }


        void addNodeInt(int pId) {
            INodo* nodo = new INodo();
            nodo->setId(pId);
            NodoGrafo* nuevoNodo = new NodoGrafo(nodo);
            this->listaNodos.push_back(nuevoNodo);
            hashNodos.insert(pair<int,NodoGrafo*>(nodo->getId(),nuevoNodo));
        }

        void addNode(INodo* pNodo) {
            NodoGrafo* nuevoNodo = new NodoGrafo(pNodo);
            this->listaNodos.push_back(nuevoNodo);
            hashNodos.insert(pair<int,NodoGrafo*>(pNodo->getId(),nuevoNodo));
        }

        void addArc(INodo* pOrigen, INodo* pDestino) {
            this->addArc(pOrigen, pDestino, 0);
        }

        void addArc(INodo* pOrigen, INodo* pDestino, int pPeso) {
            Arco* newArc = new Arco(pOrigen, pDestino, pPeso);

            getNodo(pOrigen->getId())->addArc(newArc);
            //pOrigen->addArc(newArc);
            if (!this->esDirigido) {
                Arco* reverseArc =  new Arco(pDestino, pOrigen , pPeso);
                getNodo(pDestino->getId())->addArc(reverseArc);
                //pDestino->addArc(reverseArc);
            }
        }

        void addArcInt(int pOrigen, int pDestino, int pPeso) {
            INodo* origen = getNodo(pOrigen)->getInfo();
            INodo* destino = getNodo(pDestino)->getInfo();
            Arco* newArc = new Arco(origen, destino, pPeso);

            getNodo(pOrigen)->addArc(newArc);
            //pOrigen->addArc(newArc);
            if (!this->esDirigido) {
                Arco* reverseArc =  new Arco(destino, origen , pPeso);
                getNodo(pDestino)->addArc(reverseArc);
                //pDestino->addArc(reverseArc);
            }
        }

      
      
     
        NodoGrafo* getNodo(int pId) { 
            return hashNodos.at(pId);
        }

        vector<INodo> deepPath(INodo* pOrigen) {  //recorrido en profundidad
            vector<INodo> result;

            return result;
        } 

        vector<INodo*> broadPath(INodo* pOrigen) {
            vector<INodo*> result;
            queue<NodoGrafo*> nodosProcesados;
            int visitados = 0;
            
            resetNodes();

            NodoGrafo* puntoPartida = this->getNodo(pOrigen->getId());
            nodosProcesados.push(puntoPartida);
            puntoPartida->procesado = true;
            
            do {
                while (!nodosProcesados.empty()) {
                    NodoGrafo* actual = nodosProcesados.front();
                    nodosProcesados.pop();

                    actual->visitado = true;
                    visitados++;
                    result.push_back(actual->getInfo());

                    vector<Arco*> *adyacentes = actual->getArcs();

                    for (int indiceArcos=0; indiceArcos<adyacentes->size(); ++indiceArcos) {
                        Arco* arco = adyacentes->at(indiceArcos);
                        NodoGrafo* adyacente = (NodoGrafo*)arco->getDestino();
                        if (!adyacente->procesado) {
                            nodosProcesados.push(adyacente);
                            adyacente->procesado = true;
                        }
                    }
                }

                if (visitados<this->getSize()) {
                    puntoPartida = this->findNotVisited();
                    nodosProcesados.push(puntoPartida);
                    puntoPartida->procesado = true;
                }
            } while (visitados<this->getSize()); 

            return result;
        }


        vector<INodo> path(INodo* pOrigen, INodo* pDestino) { // debe retornar un camino, el primero que encuentre estre el nodo oriegn y destino
            // en caso de que no haya camino, result se retorna vacío
            vector<INodo> result;

            return result;
        }

        void printCounters() {
            for (std::vector<NodoGrafo*>::iterator current = listaNodos.begin() ; current != listaNodos.end(); ++current) {
                NodoGrafo* actual = (*current);
                cout << actual->getInfo()->getId() << " tiene " << actual->getArcs()->size() << endl;
            }
        }
};

#endif