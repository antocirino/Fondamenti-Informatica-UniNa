# Algoritmi C++ con allocazione statica
## Riempimento vettore
Prototipo funzione:
```c++
void riempimento(int &);
```
Cotenuto del main:
```c++
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
## Ordinamento elementi di un vettore
Prototipo funzione:
```c++
void ordinamentoElementiVettore(int [], int );
```
Contenuto del main:
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
