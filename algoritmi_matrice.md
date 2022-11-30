# C++ algoritmi matrice con allocazione statica

## Riempimento matrice
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

## Inserimento elementi matrice
Prototipo funzione:
```c++
void inserimentoElementiMatrice (int [][maxDim], int);
```
Cotenuto del main:
```c++

```
Codice funzione:
```c++
void inserimentoElementiMatrice (int matrice[][maxDim], int riemp) {
    for (int i = 0; i<riemp; i++) {
        for (int j = 0; j<riemp; j++) {
            cin >> matrice[i][j];
        }
    }

}
```

