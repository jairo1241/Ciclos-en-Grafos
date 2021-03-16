#include <conio.h>
#include <list>
#include <iostream>
#include <limits.h> 
using namespace std;
class Grafo
{
    int V;//Numero de Vertice

    list<int>* adyacencia;//lista de adyacencia

    //Funcion Recursiva
    bool isCicloRec(int v,bool visitado[],int padre);


public:
    Grafo (int V);

    void agregarArista(int vOrigen,int vDestino);
    bool isCiclo();


};

Grafo::Grafo(int V)
{
    this->V=V;
    adyacencia=new list<int>[V];
}

void Grafo::agregarArista(int vOrigen,int vDestino)
{
    adyacencia[vOrigen].push_back(vDestino);

     adyacencia[vDestino].push_back(vOrigen);

}

bool Grafo::isCicloRec(int v,bool visitado[],int padre)
{

    //Marcamos el nodo actual como visitado
    visitado[v]=true;

    //Recorrer para todos los vertices adyacente a este vertice
    list<int>::iterator i;

    for( i= adyacencia[v].begin();i !=adyacencia[v].end();++i)
    {
        //Si no se visita recurrir al adyacente
        if(!visitado[*i])
        {
            if(isCicloRec(*i,visitado,v))
            return true;
        }
        //si visita el adjacente hay un cilo

        else if(*i != padre)
        return true;
    }
    return false;

}

bool Grafo::isCiclo()
{
    //Marcar todos los vertices como no visitados
    bool* visitado = new bool[V];
    for(int i = 0; i < V;i++)
    visitado[i]=false;

    //Llamada recursiva para detectar ciclos 
   for(int u = 0;u <V;u++)
   {
       if(!visitado[u])
       if(isCicloRec(u,visitado,-1))
       return true;
   }
    return false;
}

int main()
{
    Grafo g1(5);

    g1.agregarArista(1, 0);
    g1.agregarArista(0, 2);
    g1.agregarArista(2, 1);
    g1.agregarArista(0, 3);
    g1.agregarArista(3, 4);
   
    g1.isCiclo() ?
        cout << "Graph contains cycle\n" :
        cout << "Graph doesn't contain cycle\n";

    Grafo g2 (4);

    g2.agregarArista(0, 3);
    g2.agregarArista(2, 3);
    g2.agregarArista(3, 1);

    g2.isCiclo() ?
        cout << "Graph contains cycle\n" :
        cout << "Graph doesn't contain cycle\n";
   

}