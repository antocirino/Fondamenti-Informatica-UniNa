/*
 Scrivere un programma per la gestione del menù di un ristorante. Il menù può essere modellato come un vettore di pietanze. Ogni pietanza è 
 * descritta dal prezzo (valore reale) e dal nome (stringa di 15 caratteri).

Il programma deve fornire le funzionalità descritte di seguito, tenendo presente che i primi tre requisiti sono precondizioni per l’esecuzione dei rimanenti. 

Il programma deve essere strutturato utilizzando i prototipi di funzione. Inoltre, l’accesso agli elementi dei vettori deve essere implementato tramite 
 * l’utilizzo esplicito di puntatori. Il vettore deve essere gestito tramite allocazione dinamica. 

N.B. si vedano gli esempi di funzionamento attesi e ci si attenga ai suggerimenti del docente.

1. Inserimento del numero di pietanze del menù. Il programma chiede all’utente di inserire il numero di pietanze del menu. Se l’utente inserisce un valore di dimensione minore
 *  o uguale di zero allora il programma deve mostrare un messaggio di errore e chiedere all’utente di inserire nuovamente la dimensione fin quando questa non sia corretta. 
 * 
2. Inserimento delle pietanze del menu. Il programma chiede all’utente di inserire le pietanze del menu. Suggerimento: si supponga per semplicità che i nomi delle pietanze non 
 * contengano spazi e che vengano inseriti dall’utente solo caratteri alfabetici minuscoli. Si supponga inoltre che il prezzo delle pietanze inserito sia sempre strettamente positivo.
 * 
3. Stampa a video del menù. Il programma mostra a video le pietanze del menù.
 * 
4. Calcolo del totale del prezzo delle pietanze con i primi tre caratteri del nome uguali a una stringa di ricerca. Il programma chiede all’utente di inserire una stringa di ricerca formata
 *  esattamente da 3 caratteri. Il programma calcola e mostra a video della somma dei prezzi delle pietanze il cui nome (primi tre caratteri) inizia con la stringa di ricerca inserita dall’utente. 
 * Se l’utente inserisce una stringa di lunghezza non uguale a tre allora il programma deve mostrare un opportuno messaggio. Inoltre, se non ci sono pietanze che soddisfano la stringa di 
 * ricerca allora il programma deve mostrare un opportuno messaggio.
 * 
5. Evidenziare il nome della pietanza a prezzo massimo. Il programma cerca la prima pietanza del menù con prezzo massimo e ne evidenzia il nome. Il nome è evidenziato trasformando
 *  tutti i caratteri del nome da minuscolo a maiuscolo.
 */

#include <iostream>
#include <string.h>
using namespace std;

struct strutturaPietanze {
    double prezzo;
    char nome[16];
};

typedef strutturaPietanze pietanza;

void inserimentoRiemp (int &);
void inserimentoPietanze (pietanza *, int);
void stampaMenu (pietanza *, int);
int inserimentoStringa (char []);   
bool ricerca (pietanza *, int, char *);
double sommaRicerca (pietanza *, int, char *);
int max(pietanza *, int);
void maiuscolo (pietanza *, int);


int main( ) {
    pietanza *menu;
    int riemp;
    int indice;
    char stringa[4];
    
    cout << "﻿Inserisci il numero di pietanze del menu': ";
    inserimentoRiemp(riemp);
    
    menu = new pietanza [riemp];
    
    inserimentoPietanze(menu, riemp);
    
    cout << "Il menu' inserito e': " << endl;
    stampaMenu (menu, riemp);
    
    cout << "Inserisci la stringa di ricerca: ";
    if (inserimentoStringa(stringa)==1) {
        cout << "Errore la stringa di ricerca deve avere ESATTAMENTE tre caratteri" << endl;
    } else {
        if (ricerca(menu, riemp, stringa)) {
            cout << "Il totale della somma dei prezzi delle pietanze che soddisfano la stringa di ricerca e': " << sommaRicerca (menu, riemp, stringa) << endl;
        } else {
            cout << "Nel menu' non sono presenti pietanze che soddisfano la stringa di ricerca." << endl;
        }
    }
    
    indice = max(menu, riemp);
    maiuscolo(menu, indice);
    cout << "Evidenziando la prima pietanza del menu' con il prezzo massimo si ottiene: " << endl;
    stampaMenu (menu, riemp);
    
}

void inserimentoRiemp (int &riemp) {
    do {
        cin >> riemp;
        if (riemp<=0) {
            cout << "Errore !!! Il menu' non puo' essere vuoto";
        }
    } while (riemp<=0);
}

void inserimentoPietanze (pietanza *menu, int riemp) {
    for (int i=0; i<riemp; i++) {
        cout << "Inserisci il prezzo della pietanza di indice " << i << ":";
        cin >> (menu+i)->prezzo;  
        cout << "Inserisci il nome della pietanza di indice " << i << ":";
        cin >> (menu+i)->nome;
    }
}

void stampaMenu (pietanza *menu, int riemp) {
    for (int i=0; i<riemp; i++) {
        cout << (menu+i)->prezzo << "   " << (menu+i)->nome << endl;
    }
}

int inserimentoStringa (char stringa[]) {
    cin >> stringa;
    if (strlen(stringa) != 3) {
        return 1;
    } else {
        return 0;
    }
}

bool ricerca (pietanza *menu, int riemp, char *stringa) {
    bool trovato = false;
    int pos = 0;
    while (!trovato && pos<riemp)  {
        if (strncmp(stringa, (menu+pos)->nome, 3) == 0) {
            trovato = true;
        } else {
            pos++;
        }
    }
    return trovato;
}

double sommaRicerca (pietanza *menu, int riemp, char *stringa) {
    double somma = 0;
    for (int i=0; i<riemp; i++) {
        if (strncmp(stringa, (menu+i)->nome, 3) == 0) {
            somma = somma + (menu+i)->prezzo;
        }
    }
    return somma;
}

int max (pietanza *menu, int riemp) {
    double massimo = (menu)->prezzo;
    int posizione = 0;
    for (int i=0; i<riemp; i++) {
        if ((menu+i)->prezzo>massimo) {
            massimo = (menu+i)->prezzo;
            posizione = i;
        }
    }
    return posizione;
}

void maiuscolo (pietanza *menu, int i) {
    int lunghezza = strlen((menu+i)->nome);
    for (int j=0; j<lunghezza; j++) {
        (menu+i)->nome[j] = toupper((menu+i)->nome[j]);
    }
}
