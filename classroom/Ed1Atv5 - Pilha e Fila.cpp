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

};

Fila inverterFila(Fila f){
	Pilha p;
	
	while(f.n>0){
		cout<<"frente "<<f.frente()<<" foi empilhado na pilha"<<endl;
		p.inserir(f.frente());
		f.desenfileirar();
	}
	cout<<endl;
	
	cout<<"Pilha:"<<endl;
	p.imprimir();
	cout<<endl;
	
	while(p.n>0){
		cout<<"topo "<<p.topoPilha()<<" foi enfileirado na fila"<<endl;
		f.enfileirar(p.topoPilha());
		p.remover();
	}
	
	return f;
}

int main() {
    
    Fila f;
	
	//fila não vazia
    f.enfileirar(10);
    f.enfileirar(20);
    f.enfileirar(30);
    f.enfileirar(40);
    f.enfileirar(50);
    
    cout<<"Fila antes de inverter"<<endl;
    f.imprimir();
    
    f = inverterFila(f);
    
    cout<<"Fila depois de inverter"<<endl;
    f.imprimir();

    return 0;
}
