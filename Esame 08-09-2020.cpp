/*
Scrivere un programma per la simulazione di un gioco Arcade il cui obiettivo è quello di distruggere navicelle spaziali aliene nemiche posizionate 
 * sullo schermo. Le navicelle posizionate sullo schermo sono memorizzate in un vettore gestito tramite allocazione statica. Sullo schermo non 
 * possono essere mostrate più di 30 navicelle contemporaneamente. Ogni navicella è caratterizzata da tre campi di valori interi. Due campi 
 * denominati xPos ed yPos rappresentano rispettivamente le coordinate x ed y che la navicella occupa sullo schermo. L’ultimo campo denominato 
 * punteggio rappresenta il punteggio conseguito in caso la navicella venga colpita.

Il programma deve fornire le funzionalità descritte di seguito, tenendo presente che i primi due requisiti sono precondizioni per l’esecuzione dei
 *  rimanenti. Il programma deve essere strutturato utilizzando i prototipi di funzione. 

1. Lettura dei dati delle navicelle presenti sullo schermo da un file di testo. Il programma deve generare il vettore delle navicelle leggendo i valori 
 * da un file di testo denominato navicelle.txt. Il file deve essere strutturato riportando nella prima linea il numero totale delle navicelle presenti nel file. 
 * Le linee rimanenti riportano le caratteristiche delle navicelle da mostrare sul video. Nel caso in cui il file non sia presente o il numero di navicelle 
 * contenuti nel file sia maggiore di 30 allora il programma deve terminare la propria esecuzione e mostrare un messaggio di errore. 
 * N.B. il programma NON deve chiedere all’utente di inserire nuovamente il file.

 2. Stampa a video delle caratteristiche delle navicelle mostrate sul video e memorizzate nel file. Il programma mostra a video le caratteristiche 
 * di tutte le navicelle memorizzate nel file e caricate nel vettore.

 3. Lancio di un missile. Il programma deve fornire all’utente la possibilità di lanciare un missile che esploderà in una data posizione dello schermo
 *  A tal fine il programma dovrà chiedere all’utente di inserire le coordinate dello schermo in cui vuole far esplodere il missile. Assumendo che il 
 * missile abbia un campo di azione circolare di 10 pixel dal punto dell’esplosione, il programma automaticamente valuterà il numero di navicelle 
 * colpite dal missile e il punteggio ottenuto. Tutte le navicelle che si trovano nel cerchio generate dall’esplosione sono distrutte. Il programma 
 * mostrerà a video il numero di navicelle esplose e il punteggio ottenuto dall’utente.

 4. Cattura della navicella con bonus. Il programma fornisce la funzionalità di catturare la prima navicella bonus mostrata a video. Una navicella 
 * bonus è caratterizzata da avere un punteggio superiore a mille. Il programma cerca la prima navicella bonus memorizzata nel vettore e la 
 * cancella dal vettore. Se a monitor non è presente una navicella bonus allora il programma mostra a video il messaggio 
 * “Navicella Bonus Non Presente a Video”.
 */

 #include <iostream>
using namespace std;

#define maxDim 30

struct strutturaNavicella {
    int xPos;
    int yPos;
    int punteggio;
};

typedef strutturaNavicella navicella;

void inserimentoRiemp (int &);
void inserimentoCarat (navicella [], int);
void stampa(navicella [], int);
void esplosione (navicella [], int, int, int, int &, int &);
bool ricercaBonus (navicella [], int, int &);
void elimina (navicella [], int &, int);

int main() {
    int riemp;
    int x, y, colpite = 0;
    int punteggio = 0;
    int posizione = 0;
    navicella nav [maxDim];
    
    cout << "Inserire il numero di navicelle: ";
    inserimentoRiemp(riemp);
    
    cout << "Inserimento delle caratteristiche delle navicelle." << endl;
    inserimentoCarat(nav, riemp);
    
    cout << "Navicelle inserite: " << endl;
    stampa(nav, riemp);
    
    cout << "Inserire le coordinate dove lanciare il missile." << endl;
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    cout << "Esplosione..." << endl;
    esplosione (nav, riemp, x, y, punteggio, colpite);
    cout << "Navicelle esplose: " << colpite << endl;
    cout << "Punteggio ottenuto: " << punteggio << endl;
    
    cout << "Ricerca navicella bonus..." << endl;
    if (ricercaBonus(nav, riemp, posizione)==true) {
        cout << "Navicella trovata! Eliminiazione..." << endl;
        elimina(nav, riemp, posizione);
        stampa(nav, riemp);
    } else {
        cout << "Navicella bonus non presente a video";
    }
    

    return 0;
}

void inserimentoRiemp (int &riemp) {
    do {
        cin>>riemp;
        if (riemp<=0 || riemp>maxDim) {
            cout << "Errore!";
        }
    } while (riemp<=0 || riemp>maxDim);
}

void inserimentoCarat (navicella nav[], int riemp) {
    for (int i=0; i<riemp; i++) {
        cout << "Inserire la x della navicella di indice " << i << ": ";
        cin >> nav[i].xPos;
        cout << "Inserire la y della navicella di indice " << i << ": ";
        cin >> nav[i].yPos;
        cout << "Inserire il punteggio della navicella di indice " << i << ": ";
        cin >> nav[i].punteggio;
        cout << endl;
    }
}

void stampa (navicella nav[], int riemp) {
    for (int i=0; i<riemp; i++) {
        cout << "(" << nav[i].xPos << ", " << nav[i].yPos << ", " << nav[i].punteggio << ")" << endl;
    }
}

void esplosione (navicella nav[], int riemp, int x, int y, int &punteggio, int &colpite) {
    for (int i=0; i<riemp; i++) {
        if (nav[i].xPos>=(x-10) && nav[i].xPos<=(x+10) && nav[i].yPos>=(y-10) && nav[i].yPos<=(y+10)) {
            colpite++;
            punteggio = punteggio + nav[i].punteggio;
        }
    }
}

bool ricercaBonus (navicella nav[], int riemp, int &posizione) {
    bool trovato = false;
    while (!trovato && posizione<riemp) {
        if (nav[posizione].punteggio>1000) {
            trovato = true;
        } else {
            posizione++;
        }
    }
    return trovato;
}

void elimina (navicella nav[], int &riemp, int posizione) {
    for (int i=posizione; i<riemp-1; i++) {
        nav[i]=nav[i+1];
    }
    riemp--;
}
