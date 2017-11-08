#include <stdlib.h>
#include <stdio.h>

struct no{
    int valor;
    struct no *esq;
    struct no *dir;
};


int buscaArv(struct no** ptrRaiz, int valor);
int insereArv(struct no** raiz, int valor);
struct no** inicializaArv();
int main() {

    struct no** ptrRaiz;
    ptrRaiz = inicializaArv();

    insereArv(ptrRaiz,4);
    insereArv(ptrRaiz,2);
    insereArv(ptrRaiz,1);
    insereArv(ptrRaiz,3);
    insereArv(ptrRaiz,8);
    insereArv(ptrRaiz,7);
    insereArv(ptrRaiz,9);
    insereArv(ptrRaiz,5);
    insereArv(ptrRaiz,6);

    if (buscaArv(ptrRaiz, 15)) printf("Valor encontrado\n");
    else printf("valor não encontrado \n");


}

int insereArv(struct no** raiz, int valor){
    if(raiz == NULL){
       printf("Árvore não inicializada\n");
        return 0;
    }
    if(*raiz == NULL){
        struct no* ptrAux = (struct no*)malloc(sizeof(struct no));
        ptrAux->dir = NULL;
        ptrAux->esq = NULL;
        ptrAux->valor = valor;
        *raiz = ptrAux;

        return 1;
    }
    else{
        if(valor == (*raiz)->valor) return 0;

        else if(valor > (*raiz)->valor){
           return insereArv(&((*raiz)->dir), valor);
       }
        else if(valor < (*raiz)->valor){
           return insereArv(&((*raiz)->esq), valor);
       }
    }

}

int vaziaArv(struct no** ptrRaiz){

    if(ptrRaiz == NULL || *ptrRaiz == NULL){
       printf("Árvore vazia!\n");
        return 1;
    }
    printf("Árvore não vazia!\n");
    return 0;
}
struct no** inicializaArv(){
    struct no** ptrAux = (struct no**)malloc(sizeof(struct no*));
    if(ptrAux != NULL){ *ptrAux = NULL;}

    return ptrAux;
}


int buscaArv(struct no** ptrRaiz, int valor){
    if(*ptrRaiz == NULL){
        return 0;
    }
    if((*ptrRaiz)->valor == valor) return 1;
    else if((*ptrRaiz)->valor > valor) return buscaArv(&((*ptrRaiz)->esq), valor );
    else return (buscaArv(&((*ptrRaiz)->dir), valor));
}
