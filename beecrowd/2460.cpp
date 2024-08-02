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

struct Pilha {

    No* topo;
    int n;

    Pilha() {
        topo = NULL;
        n = 0;
    }
	
	//inserindo no inicio(topo)
    //por praticidade na hora de remover é melhor inserir no inicio
	void inserir(int valor) {
        No* novo = new No(valor);
        if (topo == NULL) {
            topo = novo;
        } else {
            novo->prox = topo;
            topo = novo;
        }
        n++;
    }

	//removendo no inicio(topo)
    void remover() {
        if (n == 0) return;
        if (n == 1) {
            delete(topo);
            topo = NULL;
            n = 0;
            return;
        }
        No* aux = topo;
        topo = topo->prox;
        delete(aux);
        n--;
    }
	
	//o que está no inicio
    int topoPilha() {
        if (topo == NULL) return 0;
        return topo->valor;
    }
    
    void imprimir(){
    	No* aux = topo;
    	for(int i=0; i<n; i++){
    		cout<<aux->valor<<endl;
    		aux = aux->prox;
		}
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
	
	//inserindo no final
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
	
	//removendo no inicio
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
	
	//o que está no inicio
    int frente() {
        if (inicio == NULL) return 0;
        return inicio->valor;
    }
    
    void imprimir(){
    	No* aux = inicio;
    	for(int i=0; i<n; i++){
    		if(i!=0) cout<<" ";
    		cout<<aux->valor;
    		aux = aux->prox;
		}
		cout<<endl;
	}
	
	void removerValor(int val){
		if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }
		No* aux = inicio;
		if(aux->valor == val){
			inicio = inicio->prox;
		}else{
			if(aux->prox->valor == val){
				if(aux->prox->prox == NULL){
					aux->prox = NULL;
				}else{
					aux->prox = aux->prox->prox;
				}
			}
		}
		
		n--;
	}

};

int main() {
	
    Fila f;
	int tam=0, val=0;
	
    cin>>tam;
    while(tam--){
    	cin>>val;
    	f.enfileirar(val);
	}
	
	//f.imprimir();
	
	cin>>tam;
	while(tam--){
		cin>>val;
		f.removerValor(val);
	}
	
	f.imprimir();

    return 0;
}
