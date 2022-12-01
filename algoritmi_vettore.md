# Algoritmi C++ vettori con allocazione statica

## Riempimento vettore
Prototipo funzione:
```c++
void riempimento(int &);
```
Cotenuto del main:
```c++
int riemp;
...
cout << "Inserire le dimensioni del vettore";
riempimento(riemp);
```
Codice funzione:
```c++
void riempimento(int &riemp) {
    do {
        cin>>riemp;
        if (0<riemp || riemp>maxDim) {
            cout << "Errore!";
        }
    } while (0<riemp || riemp>maxDim);
}
```

## Inserimento elementi di un vettore
Prototipo funzione:
```c++
void inserimentoElementiVettore (int [], int);
```
Cotenuto del main:
```c++
int riemp;
int v[maxDim];
...
cout << "Inserire gli elementi del vettore";
inserimentoElementiVettore (vettore, riemp);
```
Codice funzione:
```c++
void inserimentoElementiVettore(int vettore[], int riemp) {
    for (int i = 0; i<riemp; i++) {
        cin >> vettore[i];
    }
}
```

## Stampa elmenti di un vettore
Prototipo funzione:
```c++
void stampaVettore (int [], int);
```
Cotenuto del main:
```c++
int riemp;
int vettore[maxDim];
...
cout << "Vettore inserito:";
stampaVettore (vettore, riemp);
```
Codice funzione:
```c++
void stampaVettore (int vettore[], int riemp) {
    for (int i = 0; i<riemp; i++) {
        cout << vettore[i] << endl;
    }
}
```

## Elemento massimo vettore
Prototipo funzione:
```c++
int ricercaMassimoVettore (int [], int);
```
Contenuto del main:
```c++
int riemp;
int vettore[maxDim];
...
cout << "Il massimo elemento del vettore è: " << ricercaMassimoVettore (vettore, riemp);
```
Codice funzione:
```c++
int ricercaMassimoVettore (int vettore[], int riemp) {
    int max = vettore[0];
    for (int i = 0; i<riemp; i++) {
        if (max>vettore[i]) {
            max = vettore[i];
        }
    }
    return max;
}
```

## Elemento minimo vettore
Prototipo funzione:
```c++
int ricercaMinimoVettore (int [], int);
```
Contenuto del main:
```c++
int riemp;
int vettore[maxDim];
...
cout << "Il minimo elemento del vettore è: " << ricercaMinimoVettore (vettore, riemp);
```
Codice funzione:
```c++
int ricercaMinimoVettore (int vettore[], int riemp) {
    int min = vettore[0];
    for (int i = 0; i<riemp; i++) {
        if (min<vettore[i]) {
            min = vettore[i];
        }
    }
    return min;
}
```

## Aggiungere elemento in un vettore
Prototipo funzione:
```c++
int aggiungiElementoVettore (int [], int &, int, int);
```
Contenuto del main:
```c++
int riemp, posizione, elemento, esito;
int vettore[maxDim];
...
cout<<"Immettere la posizione in cui inserire l'elemento"<<endl;
cin>>posizione;
cout<<"Inserire l'elemento da inserire"<<endl;
cin>>elemento;
esito = aggiungiElementoVettore(vettore, riemp, posizione, elemento);
if (esito==-1) {
        cout<<"Errore!!! la posizione inserita supera la dimensione del vettore, oppure e' negativa"<<endl;
} else {
        cout<<"Il nuovo vettore e':"<<endl;
        stampaVettore (vettore, riemp);
        cout<<endl;
}
```
Codice funzione:
```c++
int aggiungiElementoVettore (int vettore[], int &riemp, int posizione, int elem) {
    if(posizione>=0 && posizione<riemp+1){
            //possibile inserire
            riemp++;
            for(int i=riemp-1; i>riemp; i--) {
                    vettore[i]=vettore[i-1];
            }
            vettore[posizione]=elem;
            return 0;
    } else {
            return -1;
    }
}
```


## Rimuovere elemento in un vettore
Prototipo funzione:
```c++
int rimuoviElementoVettore(int [], int &, int);
```
Contenuto del main:
```c++
int riemp, posizione, esito;
int vettore[maxDim];
...
cout<<"Inserire la posizione dell'elemento da eliminare"<<endl;
cin>>posizione;
esito = rimuoviElementoVettore(vettore, riemp, posizione);
if (esito==-1) {
        cout<<"Errore!!! la posizione inserita supera la dimensione del vettore, oppure e' negativa"<<endl;
} else {
        cout<<"Il nuovo vettore e':"<<endl;
        stampaVettore (vettore, riemp);
        cout<<endl;
}
```
Codice funzione:
```c++
int rimuoviElementoVettore(int vettore[], int &riemp, int posizione) {
    if(posizione>=0 && posizione<riemp){
            //possibile eliminare
            for(int i=posizione; i<riemp-1; i++) {
                    vettore[i]=vettore[i+1];
            }
            riemp--;
            return 0;
    } else {
            return -1;
    }
}
```

## Ricerca di un elemento in un vettore
Prototipo funzione:
```c++
bool ricercaLineareVettore (int [], int , int , int &);
```
Contenuto del main:
```c++
int riemp, elemento, posizioneElemento;
int vettore[maxDim];
...
cout<<"Inerire l'elemento da cercare"<<endl;
cin>>elemento;
if(ricercaLineareVettore(vettore, riemp, elemento, posizioneElemento)) {
        cout<<"Elemento trovato in posizione: "<<posizioneElemento<<endl;
} else {
        cout<<"Elemento non trovato"<<endl;
        cout<<endl;
}
```
Codice funzione:
```c++
bool ricercaLineareVettore(int vettore[], int riemp, int elem, int &posizione){
    bool trovato = false;
    posizione=0;
    while (!trovato && posizione<riemp) {
            if(vettore[posizione]==elem) {
                    trovato=true;
            } else {
                    posizione++;
            }
    }
    return trovato;
}
```

## Ordinamento elementi di un vettore (selection sort)
Prototipo funzione:
```c++
void ordinamentoElementiVettore(int [], int );
```
Contenuto del main:
int riemp;
int vettore[maxDim];
...
```c++
ordinamentoElementiVettore(vettore, riemp);
cout<<"Ordinamento..."<<endl;
cout<<"Il vettore ordinato in senso crescente e':"<<endl;
stampaVettore(vettore, riemp);
cout<<endl;
```
Codice funzione:
```c++
void ordinamentoElementiVettore(int vettore[], int riemp) {
    int temp, min, pos;
    for(int i=0; i<riemp-1; i++) {
        min=vettore[i];
        pos=i;
        for (int j=i+1; j<riemp; j++){
                if (vettore[j]<min) {
                        min=vettore[j];
                        pos=j;
                }
        }
        //algoritmo di scambio
        if (i!=pos){
            temp=vettore[i];
            vettore[i]=vettore[pos];
            vettore[pos]=temp;
        }
}
}
```
# Algoritmi C++ vettori con allocazione dinamica

## Inserimento elementi di un vettore
Prototipo funzione:
```c++
void inserimentoElementiVettore (int *, int);
```
Cotenuto del main:
```c++
int riemp;
int *vettore;
...
vettore = new int[riemp]; //allocazione memoria
...
cout << "Inserire gli elementi del vettore";
inserimentoElementiVettore (vettore, riemp);
```
Codice funzione:
```c++
void inserimentoElementiVettore(int *vettore, int riemp) {
    for (int i = 0; i<riemp; i++) {
        cin >> *(vettore+i);
    }
}
```

## Stampa elementi di un vettore
Prototipo funzione:
```c++
void stampaVettore (int *, int);
```
Cotenuto del main:
```c++
int riemp;
int *vettore;
...
vettore = new int[riemp]; //allocazione memoria
...
cout << "Inserire gli elementi del vettore";
inserimentoElementiVettore (vettore, riemp);
```
Codice funzione:
```c++
void inserimentoElementiVettore(int *vettore, int riemp) {
    for (int i = 0; i<riemp; i++) {
        cout << *(vettore+i);
    }
}
```

## Elemento minimo vettore
Prototipo funzione:
```c++
int ricercaMinimoVettore (int *, int);
```
Contenuto del main:
```c++
int riemp;
int *vettore;
int min;
...
cout << "Il minimo elemento del vettore è: " << ricercaMinimoVettore (vettore, riemp);
```
Codice funzione:
```c++
int ricercaMinimoVettore (int *vettore, int riemp) {
    int min = *vettore;
    for (int i = 0; i<riemp; i++) {
        if (min>*(vettore+i)) {
            min = *(vettore + i);
        }
    }
    return min;
}
```

## Aggiungere elemento in un vettore
Prototipo funzione:
```c++
int* aggiungiElementoVettore (int *, int &, int, int, bool &);
```
Contenuto del main:
```c++
int *vettore;
int riemp;
inr posizione;
int elemento;
bool esito;
...
cout<<"Immettere la posizione in cui inserire l'elemento"<<endl;
cin>>posizione;
cout<<"Inserire l'elemento da inserire"<<endl;
cin>>elemento;
vettore = aggiungiElementoVettore(vettore, riemp, posizione, elemento, esito);
if (esito) {
    cout<<"Il nuovo vettore e':"<<endl;
    stampaVettore(vettore, riemp);
    cout<<endl;

} else {
    cout<<"Errore!!! la posizione inserita supera la dimensione del vettore, oppure e' negativa"<<endl;
}
```
Codice funzione:
```c++
int* aggiungiElementoVettore (int *vet, int &dim, int pos, int elem, bool &esito) {
    if(pos>=0 && pos<dim+1){
        //possibile inserire
        dim++;
        int *nuovoVet;
        nuovoVet = new int[dim];
        for(int i=0; i<pos; i++) {
               *(nuovoVet+i) = *(vet+i);
            }   
        for (int i=pos+1; i<dim; i++) {
            *(nuovoVet+i+1) = *(vet+i);
        }
        *(nuovoVet+pos)=elem;
         esito = true;
        delete[] vet;
        return nuovoVet;
    } else {
        esito = false;
        return vet;
    }
}
```

## Ordinamento elementi di un vettore (selection sort)
Prototipo funzione:
```c++
void ordinaElementiVettore (int *, int);
```
Contenuto del main:
```c++
int riemp;
int *vettore;
...
ordinaElementiVettore(vettore, riemp);
cout<<"Ordinamento..."<<endl;
cout<<"Il vettore ordinato in senso crescente e':"<<endl;
stampaVettore(vettore, riemp);
cout<<endl;
```
Codice funzione:
```c++
void ordina(int *vettore, int riemp) {
    int temp, min, pos;
    for(int i=0; i<riemp-1; i++) {
        min=*(vettore+i);
        pos=i;
        for (int j=i+1;j<riemp;j++){
            if (*(vettore+j)<min) {
                min=*(vettore+j);
                pos=j;
            }
        }
        //algoritmo di scambio
        if (i!=pos){
            temp=*(vettore+i); 
            *(vettore+i)=*(vettore+pos);
            *(vettore+pos)=temp;
        }
    }
}
```
