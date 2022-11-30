# C++ - Fondamenti di informatica - UniNa

## Indice:


Un programma in C++ assumerà sempre la seguente struttura:

```c++
#include <iostream>
using namespace std;
int main() {
  //programma
Return 0;
}
```

## #include <iostream>
#include è la direttiva in quanto è usata dal compilatore per capire come utilizzare identificatori speciali come main e cout. <iostream> è una libreria, dice al programma c la libreria che deve utilizzare per creare un canale di comunicazione tra input e output. Serve per usare funzioni come cin e cout.

Queste direttiva, così come anche #define, vanno sempre prima del main.

## using namespace std;
Utilizzata per aiutare il compilatore ad includere una parte della libreria iostream, detta standard.
Se non utilizziamo using namespace std, dobbiamo andare a specificare per ogni riga la libreria del comando:
```c++
std::cout<<“Prova”;
```

## int main () {}
Questo blocco è detto main, costituisce il programma principale. Viene eseguito una volta che viene eseguita l’applicazione. Il main ha sempre davanti a sé un int per indicare il fatto che questa funzione restituisce un numero intero.

## return 0;
Il valore restituito dalla funzione, per default è sempre zero. Questo significa che la funzione è andata a buon fine (-1, -2 ecc sono errori).

Come ultima istruzione viene chiamata la funzione system("pause"). Serve semplicemente per evitare di chiudere automaticamente la finestra a fine esecuzione del programma, e quindi per dare la possibilità di leggere l'eventuale output e chiudere la finestra del programma solo dopo l'ulteriore pressione di un tasto.

## Alcuni comandi:

### endl
endl sta ad indicare "end of line" e fa tornare a capo il testo che abbiamo scritto tramite cout. Senza viene stampat tutto sulla stessa riga.

### cout
cout è un’istruzione della libreria "<iostream>". Trasferisce sul terminale tutto quello che si trova alla destra dell’operatore di redirezione (<<). cout apre uno stream, un canale di comunicazione, verso il terminale:
```c++
cout<<“Esempio”;
```

### cin
cin è un’istruzione della libreria "<iostream>". Legge il primo valore in coda dallo standard input (ciò che viene inserito nel terminale tramite tastiera).
L’operatore di redirezione utilizzato è “>>” 
```c++
inx x;
...
cin >> x;
```

### Commenti
Con // viene commentata una sola riga.
Con /*    */ vengono commentate più righe, commento multilinea.

> :warning: Ogni istruzione va terminata con un punto e virgola.

## Simboli speciali
- {}: delinatori 
- ;: 
- <<: indicatore di redirezione 

### Esempio di codice con il cout:
```c++
#include <iostream>
using namespace std;

int main() {
  cout<<"Il mio programma in C++ del corso";
  cout<<endl;
  cout<<"Con questo programma imparo a scrivere testo sul terminale"<<endl;
  cout<<endl;
  cout<<"Ho imparato a gestire il cout";
  return 0;
}
```

## Variabili
Soni contenitori di valori (celle di memoria). Questo valore può cambiare durante l’esecuzione del programma. Il tipo di dato che può contenere deve essere dichiarato all’inizio. Ogni variabile viene memorizzata in memoria.

### Modalità di utilizzo
Innanzitutto dobbiamo definire/dichiarare una variabile. Quando lo facciamo dobbiamo anteporne il tipo ```c++ int a, b;```
In questo modo abbiamo definito due numeri interi, a e b.
Dopo averli definiti possiamo assegnare un valore alla variabile con 
```c++ a = 1;```
Il valore può poi essere utilizzato per eseguire dei calcoli
```c++ b = a + 1;```

> :warning: Non possiamo utilizzare una variabile se prima non è stata dichiarata!


a e b nei casi precedenti sono degli identificatori di variabili. Possiamo dare identificatori anche a delle costanti, etichette, funzioni, parole riservate. Anche cout è un identificatore, è la funzione che permette di stampare a schermo un determinato testo.

Gli identificatori devono sempre iniziare con un carattere alfabetico; non possiamo utilizzare punteggiatura (eccetto l’underscore “_”); non si può utilizzare lo spazio (che viene simulato tramite l’underscore) e possono contenere numeri.

> :warning: C è case sensitive: fa differenza fra lettera maiuscola e minuscola!

C ha a disposizione alcuni tipi di variabili semplici:
![image](https://user-images.githubusercontent.com/112080821/204814814-90c207f3-bd95-4104-a3b6-73ee60183b4f.png)

 
Con l’int vengono identificati numeri interi. Sono rappresentati su 2 byte. L’intervallo di rappresentazione non è simmetrico —> viene utilizzata la rappresentazione per complemento a 2.

Non è detto gli interi necessitino dello stesso numero di byte su tutte le architetture. Un intero su un computer può essere rappresentato con un numero di byte differenti rispetto agli interi di un’altra macchina. Per sapere quanti byte quella macchina sta utilizzando possiamo utilizzare l’istruzione sizeof(type).

Questo codice, a seconda del programma che utilizziamo (es. moodle, neatbeans ecc…) ci restituisce un numero di byte differenti. Su neatbeans (su un mac) il long int necessita 8 byte mentre su moodle 4 byte:
```c++
#include <iostream>
using namespace std;
int main() {
/*
Programma che restituisce il numero di bytes occupati in memoria da un tipo primitivo o una variabile
*/
int intero;
bool booleano;
float reale;

//Esempi di sizeof applicati a una variabile
cout << "Per memorizzare una variabile intera ho bisogno di "<<sizeof(intero) << " byte"<<endl;
cout << "Per memorizzare una variabile booleana ho bisogno di "<<sizeof(booleano) << " byte"<<endl;
cout << "Per memorizzare una variabile reale a s.p. ho bisogno di "<<sizeof(reale) << " byte"<<endl;

//In generale sizeof può essere applicato direttamente al tipo di dato senza dover dichiarare una variabile.
cout << "Per memorizzare una variabile long int ho bisogno di "<<sizeof(long int) << " byte"<<endl;
cout << "Per memorizzare una variabile reale a d.p. ho bisogno di "<<sizeof(double) << " byte"<<endl;
cout << "Per memorizzare una variabile intera senza segno ho bisogno di "<<sizeof(unsigned int) << " byte"<<endl;

return 0;
}
```

### Programma per lo swap di variabili:
```c++
#include <iostream>
using namespace std;
int main() {
 int v1;
 int v2;
 int v3;
 cout << "Programma per lo swap di variabili"<<endl<<endl;
 cout << "Inserisci il valore della prima variabile v1: ";
 cin >> v1;
 cout <<"Inserisci il valore della seconda variabile v2: ";
 cin >> v2;
 cout << endl;
 cout << "Prima dello scambio v1=" << v1 << " e v2=" << v2 << endl;
 v3 = v1;
 v1 = v2;
 v2 = v3;
 cout << "Dopo lo scambio v1=" << v1 << " e v2=" << v2;
return 0;
}
```

Se abbiamo due variabili V1 e V2 e vogliamo scambiare il valore di queste due ne necessitiamo una terza V3, variabile temporanea, temp, o variabile di appoggio, pivot, per memorizzare il valore di una delle due.

Quando dichiariamo una variabile definiamo anche il tipo. Quando scrivo int v1, v1 è una variabile di tipo intero che può contenere solo un certo range di valori.
Devo avere un’espressione che è dello stesso tipo o compatibile con il tipo della variabile. Quando assegniamo a delle variabili delle espressioni che non sono dello stesso tipo ma sono compatibili si potrebbero avere perdite di informazioni (es. int v1; e v1=8.99 —> v1 diventa 8).

## Type casting o coercizione
In un’istruzione di assegnazione l’espressione a secondo membro deve essere dello stesso tipo o di tipo compatibile con quello della variabile a primo membro. Sono compatibili tra loro i tipi numerici a patto che il valore che si assegna possa essere contenuto nella variabile che lo riceve. Ad esempio tutti i valori interi possono essere assegnati a variabili reali ma non viceversa. Anche se avviene ci può essere perdita di informazione. Il typecasting, detto anche coercizione, forza una variabile di un tipo ad essere di un altro tipo. 
Ci sono due modalità equivalenti di casting:
1.	Casting (esplicito): forzo una variabile ad essere trattata come un’altra variabile. Forzo la double m ad essere trattata come intero:
```
double m;
int n = (int) m;
```
2.	Conversione implicita: assegniamo ad una variabile di un certo tipo un valore che è di tipo differente
```c++
int x = 3.64;
```

Esempi di type casting:
```c++
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
//Esempi di type casting tra vari tipi base in C++

//casting float --> int
int x1=0;
float reale=4.9999;
cout<< "la variabile intera prima del type casting vale: "<<x1<<endl;
x1 = (int) reale;    //COERCIZIONE!
cout<< "la variabile intera dopo il type casting vale: "<<x1<<endl;

//casting int --> float
float f1=7.6;
int i1=5;
cout<< "la variabile float prima del type casting vale: "<<f1<<endl;
f1 = (float) i1;     //COERCIZIONE!
cout<< "la variabile intera dopo il type casting vale: "<<f1<<endl;
//L’intero in questo caso non perde informazioni

//casting char --> int
char carattere = '{';   //Quando assegno una variabile char necessito di apice all’inizio e alla fine.
int casting;
cout << "Il carattere inserito è: " << carattere<<endl;
casting = (int) carattere;
cout << "il type casting del carattere è: "<< casting << endl;
//Viene stampato il 123, codice ASCHI corrispondente

//casting int --> char
/*N.B. ho utilizzato un altro tipo di rappresentazione grafica
per mostrare anche l'utilizzo del carattere speciale \t (di tabulazione)*/

int intero = 84;
char charConversione;
charConversione = (char) intero;   //Casting!
cout<<"il type casting dell'intero inserito in tipo carattere è:"<<endl;
cout<<"int\t\tchar"<<endl;
cout<<intero<<"\t\t"<<charConversione<<endl;

//casting int --> bool
bool logico = false;
logico = (bool) intero;
cout<<"il type casting dell'intero inserito in tipo booleano è:"<<endl; //N.B. ho utilizzato la stessa variabile usata per il casting int --> char
cout<<"int\t\tbool"<<endl;
cout<<intero<<"\t\t"<<logico<<endl;

return 0;
}
```

Il booleano è memorizzato su 1 byte (a prescindere dalla macchina) nonostante siano 2 valori.
In C tutti i valori che sono diversi dallo zero vengono considerati true. Solo lo zero viene considerato falso. In C 88 è vero, 12 è vero, 0 è falso.  Lo 0 booleano diventa 1 in intero e viceversa.

## Costanti
Possiamo definire delle costanti. Identificano valori che non cambiano nel tempo (il peso di una variabile è lo stesso di una costante). Esistono due modi:
1.	Definizione (tramite identificatore e tipo): const nome-tipo nome-costante valore 
```c++
const int 75;
```
2.	Assegnazione (scrittura costante) es. 
```c++
numero = -103;
```

Un’altra modalità attraverso la quale possiamo definire costanti è tramite una direttiva, #define. In questo modo non dobbiamo riportare il tipo di variabile. Dopo non utilizziamo ;. Questa direttiva va inserita prima del main. #define non fa nient’altro che eseguire una sostituzione tra il nome dell’identificatore e il corrispettivo valore. const invece crea spazio di memoria per memorizzare il valore della costante. E’ come se #define non occupasse memoria. L’utilizzo di uno piuttosto che l’altro dipende dal problema che ci si presenta. 
```c++
#define piGreco 3.14
```

## Operazioni
Tra variabili, tra costanti e tra variabili e costanti è possibile effettuare operazioni algebriche (tra numeri), logiche (in genere tra i booleani) e di confronto (per la definizione di proposizioni logiche, < o > e altro).

Operatori algebrici:
- +: somma
- -: sottrazione
- *: moltiplicazione
- /: divisione
- %: detto modulo, riporta il resto della divisione tra due interi

Operatori logici:
- &&: AND o prodotto logico
- ||: OR o somma logica
- !: NOT o negazione logica

Operatori relazionali
Restituiscono un vero o un falso
- ```==:```: uguaglianza, per determinare se due valori sono uguali
- ```!=```': diversità, per determinare se due valori sono diversi
- ```>```: per determinare se il valore a sinistra precede quello a destra (o è più grande)
- ```<```: per determinare se il valore a sinistra segue quello a destra (o è più piccolo)
- ```>=```: per determinare se il valore a sinistra è più grande o uguale di quello a destra
- ```<=```:  per determinare se il valore a sinistra è più grande o uguale di quello a sinistra  

Esempi:
```c++
int x = 3;
x == 3
```
Restituirebbe vero in quanto confronto tra due valori uguali.
```c++
int x = 3;
x == 5
```
Restituirebbe falso.
```c++
int x=3;
x=5
```
Sbagliato in quanto non stiamo verificando se i valori sono uguali ma sto assegnando 5 a x!


### Esercizio operazioni algebriche:
```c++
#include <iostream>
using namespace std;
int main() {
int x;
int y;
cout << "Inserire il primo numero x: ";
cin >> x;
cout << "Inserire il secondo numero y: ";
cin >> y;
cout << endl;  
int op1 = x + y * 3;
int op2 = (x + y) * 3;
//Nella terza opoerazione devo forzare i 2 interi in float tramite coercizione (Casting)
//int op3 = x/y + 3;
float op3 = (float)x/(float)y+3;
cout << "Risulta:" << endl;
cout << "x + 3 * y = " << op1 << endl;
cout << "(x + 3) * y = " << op2 <<endl;
cout << "x/y + 3 = "  << op3 << endl;  
return 0;  
}
```

## Istruzioni sequenziali e diagrammi di flusso
In C ogni blocco sequenziale si trova racchiuso tra parentesi graffe.
Per gli algoritmi possiamo utilizzare i diagrammi di flusso per schematizzare le istruzioni da eseguire.
Nel diagramma di flusso il trapezio indica l’inserimento manuale dei valori, il quadrato indica un’operazione, e il simbolo con la freccia a sinistra indica la rappresentazione di ciò che è contenuto al suo interno.

## Regole di precedenza degli operatori
In C++, per convenzione, l’operatore di moltiplicazione ha precedenza rispetto all’operatore di addizione. Per fare in modo che le operazioni siano effettuate con ordine diverso sarà sufficiente introdurre delle parentesi tonde.
Si definisce una regola di precedenza degli operatori. Gli operatori hanno delle priorità prestabilite da C++. L’uguaglianza, l’assegnazione ha la priorità più bassa.

![image](https://user-images.githubusercontent.com/112080821/204821533-36d07d6e-842f-49a2-87f1-7d775117b832.png)

I numeri che hanno un indice più basso in esecuzione hanno la priorità più alta.

## Operatori di incremento e auto decremento
```i++``` e ```i—``` vengono detti operatori di auto incremento e decremento:
```c++
i = i + 1 //equivale a i++ o ++i
i = i - 1  //equivale a i— o —i
```
Entrambi incrementano e decrementano di 1.
Auto incremento prefisso: ++i
Auto incremento postfisso: i++

Con la notazione prefissa si forza l’incremento o il decremento prima del suo uso. Altrimenti si forza l’incremento dopo l’utilizzo della variabile.
```c++
int i = 3;
int y;
y = i;
cout << i;
cout << y;
```
i=3 e y=3.
```c++
int i = 3;
int y;
y = i++;
cout << i;
cout << y;
```
i=4 e y=3.	
```c++
int i = 3;  
int y;
y = ++i;
cout << i;
cout << y;
```
i=3 e y=4.

Se ++ si trova dopo, uso prima il valore e poi l’incremento. Se ++ si trova prima, uso prima l’incremento e poi il valore.

## I costrutti di controllo o costrutti condizionali (o di selezione)
Alcuni comandi vengono eseguiti solo se determinati predicati logici sono veri. In alcuni casi se il predicato logico è falso vengono eseguiti altri comandi. 
IF-THEN-ELSE

### IF-THEN
![image](https://user-images.githubusercontent.com/112080821/204849266-b2b97a84-222d-4db9-af4f-7a8cdc2c7d2e.png)

Nel rombo si riporta la condizione. Se questa è vera allora si esegue il codice del ramo then. Se la condizione è falsa, esco dall’if e non viene eseguito nulla.
In C usiamo if in questo modo:
```c++
if (condizione da valutare) {
   codice da eseguire quando la condizione è vera;
}
```

### IF-THEN-ELSE
![image](https://user-images.githubusercontent.com/112080821/204849289-2f5510fb-18fd-4920-bb06-e9637fe1fe2b.png)

Rispetto al caso precedente abbiamo anche il blocco del codice else. Se la condizione è vera eseguo il blocco dell’if altrimenti quello dell’else.
```c++
if (condizione da valutare) {
    codice quando la condizione è vera;
} else {
    codice quando la condizione è falsa;
}
```

Esempio codice con costrutti:
```c++
#include <iostream>
using namespace std;

int main() {
  int x;
  cout << "Inserisci il voto: ";
  cin >> x;
  if (x>=18) {
    cout << "Bravo!" << endl << "Studente promosso";
  } else {
    cout << "Peccato!" << endl << "Studente bocciato";
  }
  cout << endl << "Fine programma";
  return 0;
}
```
### Nesting degli if
![image](https://user-images.githubusercontent.com/112080821/204849331-10eb05f5-716e-4b1b-a0f4-3b3cfe28a264.png)

Se la prima condizione è vera entro nel ramo dell’if. Se è falsa entro nel secondo if.
Non innestare mai più di 3 if!

### Switch-case
Switch-case ci permette di risolvere il problema dei troppi innesti. Lo switch inizia con la forma
switch (espressione intera)
Espressione intera significa che dobbiamo inserire una variabile di riferimento che può assumere un valore intero o anche un carattere (in quanto il carattere ha un corrispettivo intero). Dopo si trovano tutti i possibili casi.

Se il blocco termina con break allora il programma esce dallo switch, altrimenti vengono eseguiti anche i blocchi seguenti fino ad un break o fino alla fine. Se nessun blocco corrisponde ad un valore uguale a quello dell’istruzione switch viene eseguito il blocco in default.
```c++
switch (espressione intera)
{
      case (valore costante 1):
              sequenza di istruzioni;
              break;
      case (valore costante 2):
              sequenza di istruzioni;
              break;
     default: 
             sequenza di istruzioni;
}
```

Se vogliamo fare in modo che in corrispondenza di più casi venga eseguito una determinata sequenza di istruzioni, possiamo utilizzare:
```c++
switch (x) {
   case 1:
   case 2:
           sequenza di istruzioni;
   break;
```

## Costrutti iterativi e ciclici
Ci permettono di andare a rieseguire una sequenza di istruzione per un certo numero di volte o fino al verificarsi di un determinato evento. Sono di 3 tipi (1. e 2. iterativi, 3. iterativo ciclico):
1. REPEAT - UNTIL
2. WHILE - DO
3. FOR DO
Nei primi due è necessario che ci siano delle condizioni affinché avvenga la ripetizione. Con il terzo già dobbiamo sapere quante volte vogliamo che l’istruzione sia eseguita.

### While, do…while, for
Il ciclo while impone che l’esecuzione del blocco sia ripetuta finché la condizione non diventa falsa.
Se la condizione è falsa la sequenza non viene eseguita. Se è true le istruzioni vengono ripetute finché la condizione è vera.
```c++
while (condizione) {
   istruzioni;
}
```
Il ciclo do while, detto anche “repeat until”, esegue le istruzioni fintanto che la condizione è vera. La differenza sta nel fatto che, anche se la condizione è falsa, la sequenza di istruzioni viene eseguita almeno una volta.
Se nel while e nel while…do non c’è nessuna condizione che cambia, il ciclo non cambia mai.
```c++
do {
   istruzioni;
} while (condizione)
```
Il ciclo for tra parentesi tonde presenta tre campi, generalmente facoltativi:
- inizializzazione: viene inizializzata la variabile sulla quale opera il ciclo for.
- condizione: tiene conto della variabile inizializzata.
- variazione: ad ogni passaggio, automaticamente, c’è una variazione della variabile inizializzata. In base alla variazione riusciamo a definire il numero di cicli che devono essere eseguiti (combinando condizione e variazione). In genere vengono definiti come gli operatori di auto incremento e decremento.

While e for sono strutture equivalenti.

## Il tipo char
Quando facciamo riferimento a questo tipo di , il carattere deve trovarsi tra apici.
C++ utilizza la tabella ASCII. E’ possibile passare da intero a char tramite coercizione.

## Sequenza di Escape
In C++ ci sono alcune sequenze dette di Escape, servono a rappresentare alcuni caratteri particolari all’interno di una stringa. Possiamo utilizzarle all’interno di una qualsiasi stringa. Sono rappresentate dallo backslash (\) seguito da una sequenza di uno o più caratteri ammessi da C++.

![image](https://user-images.githubusercontent.com/112080821/204822065-18827eea-46cd-4fd3-b4e2-060d5b1ce27c.png)

## Programma e sottoprogramma
L’attivazione del modulo attraverso il nome viene anche detto richiamo. La sequenza che contiene il nome viene anche detto
Il main non può essere mai richiamato da altri.

Il main è l’unità che si interfaccia direttamente con il sistema operativo. Ci sarà una componente del sistema operativo che dovrà per forza caricare in memoria il programma dopo che è stato compilato (il componente è il loader).
La funzione main è il punto da cui comincia l’esecuzione, indipendentemente dalla posizione. La funzione main ha dei parametri d’ingresso che servono per interagire con il sistema operativo e restituisce solitamente un valore intero per andare a codificare eventuali errori che si sono riscontrati durante l’esecuzione. Solitamente gli errori sono indicati tramite numeri negativi 
Tutti i programmi devono contenere la funzione main!

## Forme parametriche delle funzioni
La forma parametrica consente di scrivere un modulo usando variabili generiche. Solo all’atto dell’attivazione del modulo, con adeguati meccanismi, vengono associati ai parametri i dati effettivi sui quali il sottoprogramma deve effettuare i propri calcoli. 
-	Parametri formali: servono a scrivere il sottoprogramma in una forma generalizzata;
-	Parametri attuali (o effettivi): associati ai formali quando il sottoprogramma viene attivato.

Per ogni sottoprogramma parametri attuali e formali devono corrispondere in numero e tipo!

## Definizione di un sottprogramma in C++
Necessitiamo di:
-	Intestazione. Specifica due informazioni: il nome della funzione, che deve essere accompagnato da un tipo di ritorno (int main); l’elenco dei parametri formali (ognuno deve avere il proprio tipo), opzionale.
-	Corpo: sequenza di istruzioni eseguite una volta che il sottoprogramma viene eseguito dalla funzione chiamante.
In un sottoprogramma possono essere una o più variabili, dette locali per il fatto che esistono esclusivamente nel sottoprogramma. Principio di località degli identificatori: garantisce il completo disaccoppiamento completo tra programma chiamante e sottoprogramma garantendo l’autonomia di quest’ultimo.

## Valore di ritorno delle funzioni
Ogni modulo restituisce comunque un risultato. Questo è a sua volta associato al nome della funzione e pertanto nell’intestazione della funzione ne va specificato il tipo.
All’interno di una funzione deve essere presente:
```c++
return <espr>;
```
espr può essere una variabile, una espressione numerica o una costante.
L’istruzione return termina immediatamente l’esecuzione della funzione! Tutto il codice dopo, codice morto, non viene mai eseguito.
Il tipo di espr deve essere compatibile con quello indicato nella intestazione per il nome della funzione (int nel caso del main).

Le funzioni devono essere definite prima del main per poter essere richiamate.

### Void
Funzione senza valore di ritorno, non restituisce nessun risultato di calcolo. Una funzione che non restituisce risultato viene detta procedura. Si può dunque omettere la keyword return (può tuttavia utilizzarlo per pulizia di codice, return senza nulla vicino).
Le funzioni di tipo void non restituiscono un valore ma possono essere sfruttate per andare a modificare lo stato delle variabili, tramite sostituzione per riferimento.
La sostituzione per valore va usata quando i parametri formali sono solo di ingresso al sottoprogramma; in tutti gli altri casi, quando sono di uscita ma anche di ingresso e uscita contemporaneamente, va usata la sostituzione per riferimento. 

### Visibilità o scope
La visibilità di un identificatore rappresenta le regole che un linguaggio definisce per poter utilizzare in maniera adeguata gli identificatori di variabili o di funzioni.
Una variabile per essere utilizzata deve essere prima dichiarata e può quindi essere usato solo dalle istruzioni che la seguono -> C++ segue un ordine lessico grafico.
Se la dichiarazione è interna ad un blocco (insieme di istruzioni racchiuse tra parentesi graffe), la variabile non è visibile all’esterno. Se è dichiarata all’esterno è visibile da tutti i blocchi che la seguono ammenoché in uno dei blocchi successivi non viene ridefinita o ridichiarata una nuova variabile con lo stesso nome.
Sulle variabili locali può agire solo la funzione che l’ha dichiarata. Le funzioni non vedono ciò che è dichiarato in altre funzioni anche se le seguono.

## Array o Vettore
C++ mette a disposizione delle variabili di tipo semplice. Quando vogliamo lavorare su un numero elevato di variabili, su un insieme di variabili. Possiamo allora definire una variabile strutturata: un contenitore di variabili dello stesso tipo. In C++ una struttura composta di questo tipo viene definito array. Non è nient’altro che una struttura composta che contiene al suo interno tutte variabili dello stesso tipo. L’array ha un nome ma ogni qual volta lo definiamo dobbiamo anche dichiarare staticamente la sua cardinalità massima (n. elementi in esso contenuto):
```c++
<tipo> nome_array [dimensione]
```
Quando dichiaro un array di una certa dimensione, l’elaboratore mi alloca lo spazio necessario per andare a contenere un certo numero di elementi dello stesso tipo.

es.
```c++
int vettore[5]
```
Il vettore può contenere al più 5 elementi interi. Questi elementi si trovano tutti in registri diversi e successivi. Il primo elemento del vettore corrisponde alla prima locazione ed è seguito in modo consecutivo dagli altri
Per accedere ad un elemento specifico basta indicare l’indice, tra parentesi quadre, dopo il nome dell’array stesso.
L’indice parte da zero. Se un array ha cardinalità N, l’ultimo elemento ha indice N-1. Per indicare la posizione, tra parentesi quadre, possiamo utilizzare valori costanti, espressioni o variabili ma sempre di tipo intero!

Riempimento effettivo
Allocazione statica

es.
```c++
vettore[1];
vettore [i];
vettore [c+3];
```
L’inizializzazione di un vettore avviene indicando i valori degli elementi tra parentesi graffe separati da virgole.

es.
```c++
double v[3]={0.5, -13.25}
int vett[3]={0} //Inizializza tutti I valori a zero
```

Come caratteristica di un vettore abbiamo la cardinalità massima e il riempimento. Il riempimento è la quantità di elementi contenuti attualmente all’interno di un vettore.
La variabile riempimento, riemp, indica quanti elementi sono contenuti all’interno di un vettore. 0< riemp< Card. Max.
Riemp deve essere al massimo uguale alla dimensione fissata per v, per non generare errori.


Dichiarazione statica: definizione all’inizio del numero massimo di elementi di un certo tipo che il vettore potrà contenere.

###Array multidimensionali
Si dichiarano tramite
```c++
<Tipo> nome_array [dim1] [dim2]…[dimn];
```
Sono strutture in cui sono necessarie più posizioni per identificare un elemento. Una struttura di due dimensioni è anche detta matrice.

Es.
```c++
Int mat[2][3]; //dichiara una matrice di 2 righe e 3 colonne
```
Tramite mat[i][j] indiciamo l’elemento di posto (i, j) in mat. Per accedere ad un elemento generico utulizziamo: matrice[indice riga] [indice colonna].

Anche gli array bidimensionali vengono disposti

La matrice è bidimensionale, la memoria è unidimensionale. Si esegue quindi la linearizzazione della matrice
Int mat[2][3] = {1, 2, 3, 4, 5, 6} stabilisce la seguente associazione:
```c++
mat [0][0] = 1;
mat [0][1] = 2;
mat [0][2] = 3; 
mat [1][0] = 4;
mat [1][1] = 5;
mat [1][2] = 6;
```

## Stringhe di caratteri
Una stringa è una sequenza di caratteri che può essere definita come array di char:
```c++
char nome_stringa [dim]
```
In C++ l’ultimo carattere è automaticamente sostituito con null, o carattere terminatore (\0), che indica il termine della stringa. Se dim è dunque uguale a 20, potrò avere stringhe di al più 19 caratteri.

Per inizializzare 
```c++
char stringa[10] = {‘c’, ‘i’, ‘a’, ‘o’, ‘\0’}; //oppure char stringa[10]=”ciao”; 
```
Nel secondo caso il terminatore viene aggiunto automaticamente in fondo all’array. 
Il cin di una stringa blocca appena incontra uno spazio.

In alternativa si sua il comando cin.get. Ha due parametri, la variabile stringa e la dimensione massima dei caratteri in entrata che vogliamo accettare da terminale. In genere quest’ultimo si pone uguale alla dimensione massima della stringa
```c++
cin.get (stringa, 10);
```
Altro comando è cin.getline. Ha 3 parametri. I primi due sono gli stessi, l’ultimo è il carattere di fine terminazione che appena viene incontrato smette di essere eseguito (carattere escluso).
```c++
cin.getline (stringa, 10, ‘$’);
```
Se abbiamo due cin di fila possiamo ottenere degli errori. Come soluzione possiamo utilizzare l’oggetto string (da usare solo in questo caso):
```c++
string nome;
getline (cin, nome);
```
## String.h
La libreria string.h mi permette di utilizzare l’oggetto string e di trattarlo non come array. Può essere utilizzato anche per gli array.
![image](https://user-images.githubusercontent.com/112080821/204823989-2e3cd06b-04eb-4ab8-921e-69d036b71e84.png)

## Record
Una variabile definita da diversi campi è detta struttura, o record. E’ un tipo di … che contiene dei dati, o membri.
La dichiarazione prevede che ne venga fissato il nome e che ne siano elencati i campi specificando per ognuno di essi il tipo di appartenenza.
```c++
struct nome_record {
     float x1;
     float x2;
     char nome[5];
}
```
Si può mettere prima del main!
Per accedere ai campi:
```c++
nome_record.nome_campo  // si utilizza la dot notation
```
In C++ + possibile definire un nuovo tipo sul quale poter andare ad operare. Si utilizza l’istruzione typedef (istruzione di tipo)
```c++
#define N 10
typedef float arrayDIReali [N];
```
Def

## Puntatori
E’ un indirizzo di una locazione di memoria. Una variabile di tipo puntatore è una variabile predisposta a contenere un indirizzo di memoria, in particolare del primo registro di dati dal quale parte la memorizzazione di un dato tipo.
Il contenuto delle locazioni di memoria è detto valore della variabile. L’indirizzo di memoria è detto indirizzo della variabile. Il nome della variabile india direttamente la prima delle locazioni di memoria contenenti il valore. Una variabile puntatore, dunque, indica la locazione di memoria ad essa associata.

Per dichiarare una variabile puntatore utilizziamo l’asterisco:
```c++
//Nome_tipo* nome_puntatore;
int* puntatore_intero;
```
I puntatori si aggiornano automaticamente in base al tipo di dato che essi puntano. È utile per l’allocazione dinamica degli array.
```c++
int* p1, p2, p3;      //Modalità errata: p1 risulterà puntatore e p2 e p3 interi
int *p1, *p2, *p3;    //Modalità corretta
```
Ad una variabile di tipo puntatore possono essere assegnati solo indirizzi di variabili di tipo uguale con la sua dichiarazione. Non è permessa l’assegnazione:
```c++
punt_intero = punt_reale;
```
La gestione delle variabili di tipo puntatore fa uso degli operatori & e *:
- & restituisce l’indirizzo di una variabile; 
- *, detto di dereferenziazione (azione con cui si toglie il riferimento e si raggiungono i dati a cui il puntatore riferisce), è applicabile solo a variabili di tipo puntatore e consente di accedere all’area di memoria memorizzata all’interno del puntatore (a cui punta il puntatore).

Per esempio, per accedere alla variabile x tramite puntatore per modificarne il valore scriviamo:
```c++
int *punt;
int x, y;
// Assegniamo al puntatore intero punt l’indirizzo di memoria di x:
punt = &x;   
// Assegniamo a x il valore 15:
*punt = 15;       (analogo a scrivere x=15)
```
Con *punt accediamo ai registri associati a punt.
```c++
*punt = 15 //comando di assegnazione del valore
y = *punt  //comando di lettura del valore
```
NULL: puntatore che non punta a niente.
In entrambi i casi se punt ha valore NULL si genera un errore in fase di esecuzione.

### Alias
L’operatore & è detto di riferimento in quanto consente di associare ad una variabile nomi alternativi. Definita v come variabile intera, la dichiarazione:
```c++
int&  alias  =  v;     // o anche     int   &alias  =  v
```
definisce con alias un riferimento a v che comporta che i due identificatori (alias e v) operano sullo stesso registro di memoria. Questo significa che posso usare alias per cambiare il valore di v, come accade nelle funzioni in cui il parametro è passato per riferimento. Però con v si accede direttamente ad esso, con alias si accede indirettamente tramite l’indirizzo di v caricato in alias.




## Allocazione statica vs Allocazione dinamica
Una caratteristica importante di C/C++ è la gestione della memoria in modo dinamico.
L’allocazione dinamica permette di allocare le variabili in memoria durante l’esecuzione del programma utilizzando lo spazio che effettivamente serve. Senza si è costretti in molti casi a fare delle previsioni sulle reali necessità di occupazione della memoria.
Con l’allocazione statica si devono dimensionare le strutture dati prima che il programma venga eseguito, a tempo di compilazione. Non sempre si è in condizioni di poter prevedere quanta memoria sarà necessaria per il suo corretto funzionamento. Un uso eccessivo della memoria porta al dimensionamento esagerato. O viceversa si parla di dimensionamento non sufficiente. In quest’ultimo caso ci si può ritrovare in una situazione di errore di esecuzione.

## Allocazione dinamica
Permette di utilizzare esattamente la quantità di memoria necessaria per l’applicazione che può variare di volta in volta a seconda della specifica esecuzione del programma. Una tale gestione della memoria non è però accompagnata da controlli efficaci da parte del compilatore su come viene gestita la memoria, ma lascia al programmatore questo onere: l’allocazione dinamica non è completamente gestita dal compilatore, siamo noi a dovere allocare e deallocare la memoria all’occorrenza.

## Modalità di allocazione delle variabili
Il linguaggio C consente tre modalità di allocazione delle variabili:
-	Statica: le variabili sono dichiarate all’esterno delle funzioni o mediante la parola chiave static. Tali variabili vengono allocate all’inizio dell’esecuzione del programma e deallocate solo alla sua terminazione. Le variabili statiche hanno la proprietà di preservare il loro valore anche dopo che sono fuori dal loro scope. Sono locali ad una particolare funzione e vengono inizializzate solo una volta. Il valore resta inalterato quando si esce dalla funzione, per cui quando si richiama nuovamente la funzione tale variabile ha ancora il valore assegnatogli precedentemente;
-	Automatica: le variabili sono dichiarate all’interno di una funzione: in questo caso vengono allocate all’attivazione della funzione e deallocate alla sua terminazione; 
-	Dinamica: utilizzato dal programmatore che controlla l’allocazione e la deallocazione in memoria delle variabili tramite gli operatori new e delete o le funzioni malloc e freee; new e delete sono definiti solo in C++.

Una variabile static non muore al termine dell’esecuzione. Questo può essere sfruttato.

## Memoria Heap
La memoria ha due porzioni dette rispettivamente Heap e Stack. Nel caso di allocazione dinamica viene utilizzata la memoria heap. Questa è soggetta a regole di visibilità e tempo di vita completamente diverse da quelle che governano le altre aree di memoria. L’area heap non è allocata automaticamente ma può essere allocata o rimossa solo su esplicita richiesta del programma. Non è identificata da un nome, ma è accessibile esclusivamente tramite puntatori. La sua visibilità è legata a quella della variabile puntatore che ne contiene l’indirizzo. Il suo tempo di vita coincide con l’intera durata del programma, a meno che non venga esplicitamente deallocata.

## Operatore new
L’operatore new alloca uno o più oggetti nell’area heap restituendone l’indirizzo. Se l’area heap è interamente occupata viene restituito il valore NULL come condizione di errore. Solo il tipo deve essere sempre specificato e deve essere compatibile con il tipo della variabile puntatore:
```c++
<T> punt = new <T> [<dimensione>] (<valore iniziale>);
```
In cui:
-	<T>: tipo della variabile da creare;
-	<dimensione>: numero delle variabili da creare, che vengono sistemate nella memoria heap consecutivamente (come gli elementi di un array) e l’indirizzo restituito da new punta alla prima variabile; se il numero non è specificato viene allocata una sola variabile;
-	<valore iniziale>: valore iniziale con cui l’area allocata viene inizializzata.
Esempi:
```c++
int* punt = new int;   //alloca una variabile di tipo int nell’area heap e ne assegna l’indirizzo a punt

int* v = new int [100]  /* alloca un vettore v di 100 variabili intere nell’area heap e si assegna a v l’indirizzo della prima posizione v[0] */

int* v = new int [n] /* molto utile quando non si conosce a priori la dimensione massima del vettore. “n” è una variabile il cui valore è determinato durante l’esecuzione. In tale modo vengono allocate in memoria solo le n variabili che servono al programma */
```

### Null Pointer o Puntatore nullo
Una variabile puntatore a cui non è stato assegnato valore assume il valore zero;
```c++
punt_intero = 0;
```
Il puntatore che contiene il valore zero è indefinito, nel senso che punta a un’area di memoria irraggiungibile. Un puntatore di questo tipo è noto come null pointer o puntatore nullo. Lo standard prevede che nel file “stddef.h” sia definita la costante NULL per rappresentare formalmente un puntatore nullo. L’uso di una variabile puntatore con valore NULL genera un errore in fase di esecuzione.

## Operatore delete
L’operatore unario delete dealloca la memoria dell’area heap riferita dal puntatore specificato. Non restituisce alcun valore.
```c++
delete punt;
```
Dichiara libera la zona di memoria riferita da un puntatore. Tale zona potrà essere utilizzata da un successivo operatore new. L’operatore non cancella il contenuto delle locazioni di memoria rilasciate ne lil contenuto delle variabili puntatore.
È possibile commettere errori continuando ad utilizzare il puntatore dopo il delete, assegnandogli il valore predefinito NULL. Se il puntatore riferisce ad una memoria allocata con dimensione il delete va specificato con una coppia di parentesi quadre senza indicarne la dimensione:
```c++
delete[] v;
```
## Operazioni sui puntatori
Un puntatore è una variabile come tutte le altre, dunque il suo valore può essere manipolato dagli operatori, passato come argomento a una funzione e usato come indice in un ciclo. Il suo valore è trattato come un indirizzo e viene sempre considerato come un valore intero positivo. Le operazioni sono gestite dal compilatore perché dipendono dal loro tipo e in particolare dalla loro dimensione (es. aggiungendo 1 a un puntatore double si ottiene un incremento di 8 byte). Ad un puntatore può essere assegnata la costante NULL per indicare l’assenza di riferimento.

Un puntatore ed un intero possono essere sommati e sottratti:
```c++
punt + n;   // ennesimo elemento che segue quello puntato da n
punt++   //prossimo elemento che segue punt, punt viene aggiornato
(*punt)++  // incrementa di uno all’elemento puntato da punt
(*punt) + n  // incrementa di n l’elemento puntato da punt
(*punt) = 5  // assegna il valore 5 all’elemento puntato da punt
```
La sottrazione tra puntatori è ammissibile, ad esempio, se punt1 e punt2 puntano alla stessa locazione. Se punt1<punt2 allora punt2 - punti1 + 1 è il numero di elementi tra punt1 e punt2.

## Puntatori e vettori
Nel linguaggio C/C++ il nome di un array è il puntatore alla prima locazione di memoria occupata dall’array. Il nome dell’array senza parentesi quadre indica l’indirizzo inziale dell’array che coincide con l’indirizzo del suo primo elemento. La dichiarazione di array ha quindi l’effetto di definire implicitamente il nome dell’array di tipo puntatore e come tale se ne può assegnarne il contenuto ad un’altra variabile dello stesso tipo puntatore.
```c++
int v [10];
int* punt;

punt = v;  // assegna a punt l’indirizzo della prima locazione di memoria occupata dal vettore

punt = &v [6] //assegna a punt l’indirizzo del settimo elemento del vettore, in maniera equivalente a punt=v+6
```

## Differenza tra nomi array e puntatori
I nomi degli array e i puntatori non sono identici. Un puntatore è una variabile che contiene un valore, un array è un identificatore che è usato: con le parentesi quadre per indicare un elemento dell’array; da solo per indicarne l’indirizzo inziale dell’array.
Qualsiasi operazione effettuabile indicizzando un vettore può essere eseguita tramite puntatori:
v[1] è equivalente a *(v+1)
Dunque, la notazione v[i] usata per accedere all’elemento di i-esimo posto è solo una notazione più compatta e semplice di quella consentita dagli operatori sui puntatori.

Avendo eseguito preventivamente l’istruzione punt = v, queste solo alcune istruzioni tra loro equivalenti:
 

Il nome dell’array è un puntatore.
Il puntatore è la variabile, l’array l’identificatore. 

Puntatori a Record
Come per un qualsiasi altro tipo anche per le strutture si può definire un puntatore ad esse.
Definita la struttura:
```c++
struct coordinate {
     float x;
     float y;
} punto;

struct coordinate* pun_punto; //punt_punto punta ad una struttura di tipo coordinate

pun_punto = 8 punto;  /* assegna al puntatore l’indirizzo di memoria di una variabile dello stesso tipo prelevandolo da un’altra struttura  */

pun_punto = new(coordinate) /* assegna al puntatore l’indirizzo di memoria di una variabile dello stesso tipo allcoandolo dinamicamente */
```

Tramite i puntatori a record si accede ai campi della struttura con le seguenti notazioni equivalenti:
```c++
*(pun_punto).x
// oppure, usabile solo per puntatori a strutture:
pun_punto -> x
```
## Puntatori di puntatori
I puntatori possono essere associati a qualsiasi tipo di variabile, compreso un puntatore stesso. Il codice:
```c++
nome_tipo ** nome_punt;
```
dichiara una variabile di tipo puntatore a un puntatore. nome_punt contiene l’indirizzo (punta) di un puntatore che a sua volta contiene (punta) l’indirizzo del registro di memoria contenente il valore di tipo nome_tipo.
```c++
char ** punt_a_punt_char;  // puntatore di puntatore a carattere
int ** punt_a_punt_int;  // puntatore di puntatore a intero
```
I puntatori di puntatori possono essere utilizzati per allocare dinamicamente matrici di dimensione N x M; quest’ultima può essere vista come un vettore di N elementi ognuno dei quali è un vettore di M elementi. Basta allocare dinamicamente i due vettori: il vettore N è un puntatore di puntatori e ognuno di questi è un puntatore agli altri vettori di M elementi.
Una matrice NxM viene rappresentata in memoria per righe: per M[3][2]  
Data una matrice RigheXColonne, per accedere all’elemento di indice (r, c) basta considerare la relazione:
```c++
*(M+(r*colonne)+c))
```
##Parametri formali di tipo strutturato
C++ prevede che possano essere passati ad una funzione variabili strutturate (record, struct e array). In generale il nome di un vettore è l’indirizzo al primo elemento del vettore, dunque il primo indirizzo di questo. Se ad una funzione passiamo il nome di un vettore, stiamo effettuando un passaggio per riferimento. Ogni funzione che opera su un vettore potenzialmente ne può cambiare il contenuto in quanto il passaggio è sempre per riferimento.
```c++
float vet[100]

// Possiamo definire una procedura con vet tra i suoi parametri formali nei seguenti modi:

void calcola(float vet[100], int n); // dichiaraizone completa
void calcola(float vet[], int n); // dichiarazione incompleta
```

Non è necessario dichiarare la cardinalità massima, in quanto il vettore è il puntatore ad un’area di memoria. 
Per non andare a modificare i valori dell’array si può lavorare con una copia del vettore. Un altro modo, più valido, per non modificare i valori è quello di anticipare al nome della variabile passata la keyword const. Opera sul vettore ma non ne cambia i valori all’uscita:
```c++
void calcola(const float v[], int n);
```
Le matrici sono puntatori ad un’area di memoria che viene linearizzata. Lo stesso discorso, quindi, vale anche per le matrici, che vengono sempre passate per riferimento.

Nel caso di allocazione statica e passaggio di una matrice in una funzione deve essere necessariamente riportato il numero massimo di colonne.
```c++
// Il prototipo della procedura avente intestazione:
void funzione(float vettore[], float matrice[] [30]),
// è:
void funzione [float [], float [] [30]);
```
## Strutturazione dei programmi con prototipi di funzioni
I prototipi consentono una strutturazione diversa del programma che semplifica l’uso delle funzioni. In testa al main vengono dapprima elencati i prototipi di tutte le funzioni senza doversi preoccupare del loro ordine; in coda vengono invece riportate le dichiarazioni complete delle funzioni anche in questo caso senza preoccuparsi dell’ ordine.

## Librerie
Le librerie sono raccolte che permettono al programmatore di utilizzare ciò che gli serve senza dover effettuare nuovamente la traduzione del codice. Le funzioni usate hanno infatti un funzionamento già dimostrato e quindi corretto. Le librerie permettono il riuso delle funzioni. Si evita di avere programmi molto lunghi. Il codice può essere organizzato in file differenti e il programma principale, contenente il main, è costituito dal solo codice dell’applicazione specifica con in testa il riferimento a tutte le librerie invocate.

Per richiamare una libreria basta utilizzare la direttiva include:
```c++
#include <filename>  
```
oppure
```c++
#include “filename”
```
La differenza tra le due modalità serve a specificare come cercare il file di libreria con estensione .h: nel primo caso il compilatore “cerca” il file nelle cartelle scelte dall’ambiente di sviluppo; nel secondo caso il compilatore cerca il file nella cartella corrente a meno che non venga aggiunto il percorso del file system in cui trovare il file.

In genere quando si usano le librerie si hanno due file distinti:
-	File intestazione (.h) contenente le informazioni che i programmi che usano la libreria hanno necessità di conoscere: dichiarazione di variabili globali, costanti e tipi e le dichiarazioni delle funzioni.
-	File di implementazione o sorgente (.cpp oppure .c) contenente l’implementazione di tutte le funzioni messe a disposizione dalla libreria.
I due file devono avere lo stesso


