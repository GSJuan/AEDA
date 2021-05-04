#include "nodeB.h"
#include <utility>
#include <queue>

template <class Clave>
class BTree {

protected:
  nodeB<Clave> *root;

public: // Constructor y destructor

  BTree() : root(NULL) {}

  ~BTree() { 
    Podar(root); 
  }

//Metodos iniciales

  void Podar(nodeB<Clave>* nodo) {
    if (nodo == NULL) return;
    Podar(nodo->izdo); // Podar subarbol izquierdo
    Podar(nodo->dcho); // Podar subarbol derecho
    delete nodo; // Eliminar nodo
    nodo = NULL;
  }

  bool EsVacio(nodeB<Clave> *nodo) {
    return nodo == NULL;
  }

  bool EsHoja(nodeB<Clave> *nodo) {
    return !nodo->dcho && !nodo->izdo;
  }

  const int Tam() {
    return TamRama(root); 
  }

  const int TamRama(nodeB<Clave>* nodo) {
    if (nodo == NULL) return 0 ;
    return (1 + TamRama(nodo->izdo) + TamRama(nodo->dcho) );
  }

  const int Alt() {
    return AltN(root);
  }

  const int AltN(nodeB<Clave>* nodo) {
  if (nodo == NULL)
    return 0 ;
  int alt_i = AltN(nodo->izdo);
  int alt_d = AltN(nodo->dcho);
  if (alt_d > alt_i)
    return alt_d ++ ;
  else
    return alt_i ++ ;
}

//comprobaciones de equilibrio
  const bool Equilibrado() {
    return EquilibrioRama(root); 
  }

  const bool EquilibrioRama(nodeB<Clave> *nodo) {
    if (nodo == NULL) return true ;
    int eq = TamRama(nodo->izdo) - TamRama(nodo->dcho);
    switch (eq) {
      case -1:
      case 0:
      case 1:
        return EquilibrioRama(nodo->izdo) && EquilibrioRama(nodo->dcho);
      default: return false;
    }
  }

//inserciones
  void InsertaEquil(Clave& dato) {
    if (root == NULL)
      root = new nodeB<Clave> (dato, NULL, NULL);
    else InsertaEquilRama(dato, root);
  }

  void InsertaEquilRama(Clave& dato, nodeB<Clave>* nodo) {
    if (TamRama(nodo->izdo) <= TamRama(nodo->dcho)) {
      if (nodo->izdo != NULL)
        InsertaEquilRama(dato, nodo->izdo);
      else
        nodo->izdo = new nodeB<Clave>(dato, NULL, NULL);
    }
    else {
      if (nodo->dcho != NULL)
        InsertaEquilRama(dato, nodo->dcho);
      else
        nodo->dcho = new nodeB<Clave>(dato, NULL, NULL);
    }
  }

//búsqueda
nodeB<Clave>* buscar(Clave& dato) {
    return buscarRama(dato, root);
}

nodeB<Clave>* buscarRama(Clave& dato, nodeB<Clave>* nodo) {
    if(nodo) {
        if(nodo->dato == dato) return nodo; 
        else {
            nodeB<Clave>* a = buscarRama(dato, nodo->izdo);
            nodeB<Clave>* b = buscarRama(dato, nodo->dcho);
            if(a != NULL && a->dato == dato) return a;
            if(b != NULL &&  b->dato == dato) return b;
        }  
    } 
    return NULL;
}

void ImprimirArbol() { //recorrido por niveles
    std::queue<std::pair<nodeB<Clave>* , int>> Q;
    std::pair<nodeB<Clave>*, int> temp;
    nodeB<Clave>* nodo;
    int actual = 0;
    int nv = actual;

    Q.push(std::pair<nodeB<Clave>*, int>(root, actual)); // insertar raiz
    std::cout << "\nNivel " << actual << ": ";
    while(!Q.empty()) { // mientras haya nodos que explorar
        
        nodo = Q.front().first; // actualizar nodo y nivel
        nv = Q.front().second;
        Q.pop();
        if(nv > actual) { // cuando el nivel supere el actual
            actual = nv;
            std::cout << "\nNivel " << actual << ": ";
        } 
        if(nodo) {
            std::cout << nodo;
            Q.push(std::pair<nodeB<Clave>*, int>(nodo->izdo, nv+1));
            Q.push(std::pair<nodeB<Clave>*, int>(nodo->dcho, nv+1));
            
        } else std::cout << "[.] "; // imprimir nodo vacío
    }
    std::cout << std::endl;
}

};