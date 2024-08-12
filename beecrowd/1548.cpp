#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<ctype.h>

using namespace std;

struct No {

    int valor;
    No* prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Fila {

    No* inicio;
    No* fim;
    int n;

    Fila() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void enfileirar(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void desenfileirar(){
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    int frente() {
        if (inicio == NULL) return 0;
        return inicio->valor;
    }
    
    void imprimir() {
        No* aux = inicio;
        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        cout<<endl;
    }
    
    int troca() {
    	if (n == 0 || n == 1) return 0;
        int trocas=0;
        
        No* aux = inicio;
        No* anterior = inicio;
        No* anterior2 = inicio;
        while (aux != NULL) {
            if(aux->valor >= aux->prox->valor){
				aux = aux->prox;
			}else if(aux->prox != NULL){
				cout<<"precisa trocar"<<endl;
				//anterior aponta para o próximo do atual
				anterior->prox = aux->prox;
				//o meu atual passa a apontar para o próximo do próximo
				aux->prox = aux->prox->prox;
				//o meu próximo passa a apontar para o autal
				aux->prox->prox = anterior2->prox;
				cout<<"trocou"<<endl;
				
				trocas++;
			}
			anterior = anterior->prox;
			anterior2 = anterior2->prox;
        }
        
        return trocas;
    }

};

int main() {

	int filas;
	
	//rode n filas
	cin>>filas;
	while(filas--){
		int qtd=0, totalTrocas=0;
		Fila f;
		
		//criando a fila
		cin>>qtd;
		while(qtd--){
			int nota=0;
			cin>>nota;
			f.enfileirar(nota);
		}
		
		f.imprimir();
		f.troca();
		f.imprimir();
		
		//totalTrocas += f.troca();
		
		//cout<<totalTrocas<<endl;
	}

    return 0;
}
