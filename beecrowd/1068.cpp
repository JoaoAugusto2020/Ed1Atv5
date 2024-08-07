#include <stdio.h>
#include <bits/stdc++.h>
#include <string.h>

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

    int topoPilha() {
        if (topo == NULL) return 0;
        return topo->valor;
    }

};

int main() {

    Pilha p;
	char entrada[1000];
	
	while(cin>>entrada){
		for(int i=0; i<strlen(entrada); i++){
			
			if(entrada[i]=='('){
				p.inserir(1);
			}
			
			if(entrada[i]==')'){
				if(p.n>0){
					p.remover();
				}else{
					p.n=-1;
					break;
				}
			}
		}
		
		if(p.n==0){
    		cout<<"correct"<<endl;
		}else{
			cout<<"incorrect"<<endl;
		}
		
		p.n=0;
	}

    return 0;
}
