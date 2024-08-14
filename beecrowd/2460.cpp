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
	
	void removerVal(int val){
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }
        
        No* aux = inicio;
        while(aux->prox!=NULL){
        	//o que quero remover é o primeiro?
        	if(val==frente()){
        		desenfileirar();
        		return;
			}else
        	//o meu próximo é o que quero remover?
        	if(aux->prox->valor == val){
        		//o próximo do que quero remover é NULL?
        		if(aux->prox->prox == NULL){
        			aux->prox = NULL;
				}else{
					aux->prox = aux->prox->prox;
				}
				n--;
				return;
			}else{
				aux = aux->prox;
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
	
//	cout<<"ANTES DE REMOVER: "<<endl;
//	f.imprimir();
	
	cin>>tam;
	while(tam--){
		cin>>val;
		f.removerVal(val);
	}
	
//	cout<<"DEPOIS DE REMOVER: "<<endl;
	f.imprimir();

    return 0;
}
