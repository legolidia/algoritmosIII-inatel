#include<iostream>
using namespace std;

struct ponto{
    int x, y;
    ponto *prox;
};

int main(){
    int a; //estático
    //int *p = new int;

    //*p = 5;
    a = 5;

    ponto ponto1;
    ponto1.x = 13;
    ponto1.y = 11;
    ponto1.prox = NULL;

    ponto ponto2;
    ponto2.x = 19;
    ponto2.y = 17;
    ponto2.prox = NULL;

    ponto1.prox = &ponto2;

    ponto *p, *begin;
    //p = new ponto;
    begin = new ponto;

    p->x = 13; //(*p).x = 13;
    p->y = 11;
    p->prox = NULL;

    p->prox = new ponto;
    p = p->prox;
    p->x = 19;
    p->y = 17;
    p->prox = NULL;

    delete p;
    p = begin; 

    delete p;

    return 0;
}