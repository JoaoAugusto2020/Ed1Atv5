#include<iostream>
#include<bits/stdc++.h>

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
    
    void ordenar() {
    	if (n == 0 || n == 1) return;
        
        No* aux = inicio;
        while (aux->prox != NULL) {
            if(aux->valor >= aux->prox->valor){
				aux = aux->prox;
			}else{
				//troca
				int auxInt=0;
				auxInt = aux->valor;
				aux->valor = aux->prox->valor;
				aux->prox->valor = auxInt;
				//fimtroca
			}
			
        }
    }

};

int main() {

	int filas;
	
	//rode n filas
	cin>>filas;
	while(filas--){
		int qtd=0, totalTrocas=0;
		Fila f, fmolde;
		
		//criando a fila
		cin>>qtd;
		for(int i=0; i<qtd; i++){
			int nota=0;
			cin>>nota;
			f.enfileirar(nota);
			fmolde.enfileirar(nota);
		}
		
		for(int i=0; i<qtd; i++) f.ordenar();
		
		//confere mudanças
		for(int i=0; i<qtd; i++){
			//cout<<f.frente()<<" == "<<fmolde.frente()<<endl;
			if(f.frente() != fmolde.frente()){
				totalTrocas++;
			}
			
			f.desenfileirar();
			fmolde.desenfileirar();
		}
		
		cout<<qtd-totalTrocas<<endl;
	}

    return 0;
}
