/*
 Scrivere un programma per la gestione dei codici operativi di un file assembly memorizzato su memoria di massa. Il file assembly può essere memorizzato come un array. Ogni codice operativo è 
 * descritto dal suo comando assembly, stringa di non più 5 caratteri, un long int, denominato input, che rappresenta l’indirizzo di memoria del parametro di ingresso e un long int, denominato output,
 * che rappresenta l’indirizzo di memoria dove memorizzare il risultato. Per semplicità si può utilizzare anche il comando cin per inserire il comando assembly del codice operativo. Il vettore deve essere 
 * gestito tramite allocazione dinamica. Il programma deve fornire le funzionalità descritte di seguito, tenendo presente che i primi tre requisiti sono precondizioni per l’esecuzione dei rimanenti. 
 * Il programma deve essere strutturato utilizzando i prototipi di funzione. Inoltre, l’accesso agli elementi del vettore deve essere implementato tramite l’utilizzo esplicito di puntatori.

1. Inserimento del numero di codici operativi del file assembly. Il programma chiede all’utente di inserire il numero di codici operativi memorizzati. Se l’utente inserisce un valore di dimensione minore o 
 * uguale di zero allora il programma deve mostrare un messaggio di errore e chiedere all’utente di inserire nuovamente la dimensione fin quando questa non sia corretta. 
 * 
2. Inserimento dei codici operativi. Il programma chiede all’utente di inserire le caratteristiche dei codici operativi. N.B. Per semplicità non si devono eseguire controlli di validità dei valori inseriti dall’utente.
 * 
3. Stampa a video delle caratteristiche dei codici operativi memorizzati nel file. Il programma mostra a video i valori delle caratteristiche dei codici operativi memorizzati nel file.
 * 
4. Codici assembly a minima e massima locazione di memoria di output. Il programma mostra a video i codici assembly che accedono alla minima e massima locazione di memoria di output. 
 * 
5. Occorrenze dei comandi assembly memorizzati. Il programma valuta e stampa a video le occorrenze di ogni comando assembly memorizzato nel file.
 */

#include <iostream>
using namespace std;

struct codiceOperativo {
    char comando [6];
    long int input;
    long int output;
};

typedef codiceOperativo codOp;

void inserimentoDim (int&);
void inserimentoCodici (codOp *, int);
void stampaCodici (codOp *, int);
long int max(codOp *, int);
long int min(codOp *, int);

int main () {
    int riemp;
    long int maxOutput, minOutput;
    codOp *v;
    
    cout << "Inserire il numero di codici operativi del file assembly: ";
    inserimentoDim (riemp);
    
    // allocazione memoria
    v = new codOp[riemp];
    
    inserimentoCodici(v, riemp);
    
    cout << endl;
    
    cout << "Codici operativi memorizzati nel file: " << endl;
    stampaCodici(v, riemp);
    
    cout << "La massima locazione di memoria di output è " << max(v, riemp) << ", la minima è " << min(v, riemp) << ".";
        
}

void inserimentoDim (int& dim) {
    do {
        cin >> dim;
        if (dim<=0) {
            cout << "Errore! Il numero di codici non può essere minore o uguale a zero)";
        }
    } while (dim<=0);
}

void inserimentoCodici (codOp *v, int dim) {
    for (int i = 0; i<dim; i++) {
        cout << "Inserimento caratteristiche codice di indice " << i << endl;
        cout << "Comando: ";
        cin >> (*(v+i)). comando; 
        cout << "Input: ";
        cin >> (*(v+i)).input;
        cout << "Output: ";
        cin >> (v+i)->output;
        cout << endl;
    }
}

void stampaCodici (codOp *v, int dim) {
    for (int i = 0; i<dim; i++) {
        cout << "(" << (*(v+i)).comando << ", " << (*(v+i)).input << ", " << (*(v+i)).output << ")" << endl;
    }
}

long int max(codOp *v, int dim) {
    long int maxO = 0;
    for (int i = 0; i<dim; i++) {
        if ((v+i)->output>maxO) {
            maxO = (v+i)->output;
        }
    }
    return maxO;
}

long int min(codOp *v, int dim) {
    long int minO = v->output;
    for (int i = 0; i<dim; i++) {
        if ((v+i)->output<minO) {
            minO = (v+i)->output;
        }
    }
    return minO;
}
