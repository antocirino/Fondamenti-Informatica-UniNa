# Esercitazione 2
main.cpp
```c++
#include <iostream>
#include <fstream>
// Per l'istruzione exit in caricaFile
#include <cstdlib>

using namespace std;

struct strutturaDocumento {
    char nome[17];
    float dimensione;
    char creazione[7];
    char modifica[7];
};

typedef strutturaDocumento documento;

documento* caricaFile (int&);
void stampa (int, documento *);
void ordinamentoCrescente (int, documento *);
void ordinamentoDecrescente (int, documento *);
documento* nuovoVettore(int, documento *, int&);

int main () {
    int riemp, riemp2;
    char senso;
    documento *vettore, *vettore2;

    vettore = caricaFile(riemp);
    
    cout << "Elenco documenti presenti: " << endl;
    stampa (riemp, vettore);
    
    do {
        cout << "Ordinare gli elementi per dimensione in senso crescente(c) o decrescete(d)? ";
        cin >> senso;
        if (senso!='c' && senso!='d') {
            cout << endl <<"Errore! Carattere non valido." << endl;
        }
    } while (senso!='c' && senso!='c');
    cout << endl;
    if (senso == 'c') {
        ordinamentoCrescente(riemp, vettore);
        cout << "Ordinamento crescente: " << endl;
        stampa(riemp, vettore);
    } else if(senso == 'd') {
        ordinamentoDecrescente(riemp, vettore);
        cout << "Ordinamento deccrescente: " << endl;   
        stampa(riemp, vettore);
    }
    
    cout << endl << "Documenti con dimensione maggiore di 2 megabyte: " << endl;
    vettore2 = nuovoVettore(riemp, vettore, riemp2);
    stampa(riemp2, vettore2);
    
    cout<< endl << "Programma Terminato"<<endl;
    return 0;
}

documento* caricaFile (int &riemp) {
    fstream mioFile;
    documento *vet;
    mioFile.open("cartella.txt", ios::in);
    
    if(!mioFile) {
        cout << "Errore! File mancante.";
        exit(-1);
    }
    
    mioFile >> riemp;
    
    vet = new documento [riemp];
    
    for (int i=0; i<riemp; i++) {
        mioFile >> (vet+i)->nome;
        mioFile >> (vet+i)->dimensione;
        mioFile >> (vet+i)->creazione;
        mioFile >> (vet+i)->modifica;
    }
    
    mioFile.close();
    
    return vet;
}

void stampa (int riemp, documento *vettore) {
    for (int i=0; i<riemp; i++) {
        cout << "(" <<(vettore+i)->nome << ", " << (vettore+i)->dimensione << " mb, ";
        cout << (vettore+i)->creazione[0] << (vettore+i)->creazione[1]<< "/" << (vettore+i)->creazione[2] << (vettore+i)->creazione[3]<< "/" << (vettore+i)->creazione[4] << (vettore+i)->creazione[5] << ", ";  
        cout << (vettore+i)->modifica[0] << (vettore+i)->modifica[1]<< "/" << (vettore+i)->modifica[2] << (vettore+i)->modifica[3]<< "/" << (vettore+i)->modifica[4] << (vettore+i)->modifica[5] << ")" << endl;
    }
}

void ordinamentoCrescente (int riemp, documento *vettore) {
    float min;
    int pos;
    documento *temp;
    for (int i=0; i<riemp-1; i++) {
        min = (vettore+i)->dimensione;
        pos = i;
        for (int j=i+1; j<riemp; j++) {
            if ((vettore+j)->dimensione < min) {
                min = (vettore+j)->dimensione;
                pos = j;
            }
        }
        if(i!=pos) {
            *temp = *(vettore+i);
            *(vettore+i) = *(vettore+pos);
            *(vettore+pos) = *temp;
        }
    }
    
}

void ordinamentoDecrescente (int riemp, documento *vettore) {
    float max;
    int pos;
    documento *temp;
    for (int i=0; i<riemp-1; i++) {
        max = (vettore+i)->dimensione;
        pos = i;
        for (int j=i+1; j<riemp; j++) {
            if ((vettore+j)->dimensione > max) {
                max = (vettore+j)->dimensione;
                pos = j;
            }
        }
        if(i!=pos) {
            *temp = *(vettore+i);
            *(vettore+i) = *(vettore+pos);
            *(vettore+pos) = *temp;
        }
    }
    
}

documento* nuovoVettore (int riemp, documento *vettore, int &riemp2) {
    documento *vettore2;
    riemp2=0;
    for (int i=0; i<riemp; i++) {
        if ((vettore+i)->dimensione > 2) {
            riemp2++;
        }
    }
    
    vettore2 = new documento [riemp2];
    
    for (int i=0; i<riemp2; i++) {
        for (int j=0; j<riemp; j++) {
            if ((vettore+j)->dimensione > 2) {
                *(vettore2+i) = *(vettore+j);
                i++;
            }
        }
    }
    return vettore2;
}
```
cartella.txt
```
6
spotify
21.4
170812
221203
appunti
0.3
220313
221201
libri
9.7
180505
200714
film
67.9
150922
221129
musica
0.9
160416
221203
chrome
10.8
221204
150321
```
