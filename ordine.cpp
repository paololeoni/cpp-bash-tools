#include "funzioni20200212.h"

void intestazione(){
    
    cout << endl;
    cout << "\tEsame Informatica 2022" << endl;
    cout << "\tNome: Paolo;   " << "Cognome: Leoni;   " << "Numero di matricola: 990447" << endl << endl;
    
}


void resize_myArray(myArray *cz, int newsize) {
    <STRUCT> * appo;
    if (newsize>(cz->size)) {
        appo = new <STRUCT> [newsize];
        memcpy ((void *) appo, (void *) cz->raw, cz->size * sizeof (<STRUCT>));
        delete [] cz->raw;
        cz->raw = appo;
    }
    if (newsize<cz->size) {
        appo = new <STRUCT> [newsize];
        memcpy ((void *) appo, (void *) cz->raw, newsize * sizeof (<STRUCT>));
        delete [] cz->raw;
        cz->raw = appo;
    }
    cz->size = newsize;
}

void insert_myArray(myArray *cz, <STRUCT> Z1) {
    if (cz->used == cz->size) {
        resize_myArray (cz, (cz->size+INCR));
    }
    cz->raw[cz->used] = Z1;
    (cz->used)++;
}

void fill_myArray(myArray *cz, const char nomefile_in[]) {

    ifstream flusso_in;
    flusso_in.open (nomefile_in); 
    char * appo;
    for (int i=0; i<3; i++) {
        if (flusso_in.fail()) {
            cout << "\nProblema in apertura del file di input. Reinserire nome: ";
            cin >> appo;
            flusso_in.clear();
            flusso_in.open (appo);
        } 
    }
    initialize_myArray(cz, INCR);
    <STRUCT> poldo;
    flusso_in >> poldo.a >> poldo.b; 
    while (! flusso_in.eof()) {
        insert_myArray(cz, poldo);
        flusso_in >> poldo.a >> poldo.b; 
    }
}

void initialize_myArrayeliminati (myArrayeliminati *cz, int dim) {
    cz->size = dim; 
    cz->used = 0; 
    cz->raw = new <STRUCT> [dim];
}

void resize_myArrayeliminati (myArrayeliminati *cz, int newsize) {
    <STRUCT> * appo;
    if (newsize>(cz->size)) {
        appo = new <STRUCT> [newsize];
        memcpy ((void *) appo, (void *) cz->raw, cz->size * sizeof (<STRUCT>));
        delete [] cz->raw;
        cz->raw = appo;
    }
    if (newsize<cz->size) {
        appo = new <STRUCT> [newsize];
        memcpy ((void *) appo, (void *) cz->raw, newsize * sizeof (<STRUCT>));
        delete [] cz->raw;
        cz->raw = appo;
    }
    cz->size = newsize;
}

void insert_myArrayeliminati (myArrayeliminati *cz, <STRUCT> Z1) {
    if (cz->used == cz->size) {
        resize_myArrayeliminati (cz, (cz->size+INCR));
    }
    cz->raw[cz->used] = Z1;
    (cz->used)++;
}

void remove_at_myArrayinterv(myArrayinterv *cz, int pos) {
    for (int i=pos; i<(cz->size-1); i++) { 
        cz->raw[i] = cz->raw[i+1]; 
    }   
    (cz->used)--;
}

void insert_eliminati(myArrayeliminati *eliminati, myArray *pm){

   initialize_myArrayeliminati(eliminati, INCR);
   
   for (int i=0; i<pm->used; i++)
   {  
      if(pm->raw[i+1].a < pm->raw[i].a < pm->raw[i+1].b || pm->raw[i+1].a < pm->raw[i].b < pm->raw[i+1].b){
         insert_myArrayeliminati(eliminati, pm->raw[i+1]);
         remove_at_myArrayinterv(pm,i+1);
      }
      
   }
}

void print_ov_of_myarray(myArrayeliminati pm, const char nomefile_out[]){


    ofstream flussout;
    flussout.open(nomefile_out);

    char * appo;
    for (int i=0; i<3; i++) {
        if (flussout.fail()) {
            cout << "\nProblema in apertura del file di input. Reinserire nome: ";
            cin >> appo;
            flussout.clear();
            flussout.open (appo);
        } 
    }
    
    flussout << "Informazioni relative agli intervalli ignorati: " << endl << endl;

    for (int i=0; i<pm.used; i++) {
        flussout << "intervallo [" << (i+1) << "] = (";
        flussout << setw (4) << "estremo inferiore =  "<< pm.raw[i].a << ", ";
        flussout << setw (4) << "estremo superiore =  "<< pm.raw[i].b << ")" << endl;
    }

    flussout << endl;
    flussout.clear();
    flussout.close();

    cout << "Informazioni relative agli intervalli ignorati: " <<  endl << endl;     
    for (int i=0; i<pm.used; i++) {
        cout << "intervallo [" << (i+1) << "] = (";
        cout << setw (4) << "estremo inferiore= "<< pm.raw[i].a << ", ";
        cout << setw (4) << "estremo superiore = "<< pm.raw[i].b << ")" << endl;
    }
    cout << endl;

}

void selection_sort(float a[], int N){

     int i, j, min, temp;

    for(i=0;i<N-1;i++)
    {
	min=i;
        for(j=i+1;j<N;j++)
        	if (a[j]<a[min])
        	     min= j;

        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
}

void ordinamento(myArrayinterv *pm){

    float appo[10];

    for(int i=0;i<pm->used;i++){
        appo[i]=pm->raw[i].a;
    }

    selection_sort(appo, 10);

    for(int h=0;h<pm->used;h++){
        pm->raw[h].a=appo[h];
    }
}

void print_post_sort(myArrayinterv pm, const char nomefile_out[]){

    ordinamento(&pm);

    ofstream flussout;
    flussout.open(nomefile_out, ios::app);

    char * appo;
    for (int i=0; i<3; i++) {
        if (flussout.fail()) {
            cout << "\nProblema in apertura del file di input. Reinserire nome: ";
            cin >> appo;
            flussout.clear();
            flussout.open (appo);
        } 
    }
    
    flussout << endl;
    flussout << "Descrizione intervalli rimasti e riordinati: " << endl << endl;

    for (int i=0; i<pm.used; i++) {
        flussout << "intervallo [" << (i+1) << "] = (";
        flussout << setw (4) << "estremo inferiore =  "<< pm.raw[i].a << ", ";
        flussout << setw (4) << "estremo superiore =  "<< pm.raw[i].b << ")" << endl;
    }

    flussout << endl;
    flussout.clear();
    flussout.close();

    cout << endl;
    cout << "Descrizione intervalli rimasti e riordinati: " <<  endl << endl;     
    for (int i=0; i<pm.used; i++) {
        cout << "intervallo [" << (i+1) << "] = (";
        cout << setw (4) << "estremo inferiore= "<< pm.raw[i].a << ", ";
        cout << setw (4) << "estremo superiore = "<< pm.raw[i].b << ")" << endl;
    }
    cout << endl;

}

void fill_myArray_mis(myArrayinterv *pm, const char nomefile_out[]){

    ifstream flusso_in;
    flusso_in.open(nomefile_out); 
    char * appo;
    for (int i=0; i<3; i++) {
        if (flusso_in.fail()) {
            cout << "\nProblema in apertura del file di input. Reinserire nome: ";
            cin >> appo;
            flusso_in.clear();
            flusso_in.open (appo);
        } 
    }
    initialize_myArrayinterv (cz, INCR);
    interv poldo;
    flusso_in >> poldo.mis >> poldo.mis; 
    while (! flusso_in.eof()) {
        insert_myArrayinterv(pm, poldo);
        flusso_in >> poldo.mis; 
    }
}
