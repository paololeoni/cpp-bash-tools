#include <iostream>

void intestazione();


void initialize_myArray (myArray *cz, int dim);
void resize_myArray (myArray *cz, int newsize);
void insert_myArray (myArray *cz, <struct> Z1);


void fill_myArray (myArray *cz, const char nomefile_in[]) ;

void initialize_myArrayeliminati (myArrayeliminati *cz, int dim);
void resize_myArrayeliminati(myArrayeliminati *cz, int newsize) ;
void insert_eliminati(myArrayeliminati *eliminati, myArray *pm); //inserisce elementi da eliminare in myarray secondo una condizione
void print_ov_of_myarray(myArrayeliminati pm, const char nomefile_in[]);
void remove_at_myArray(myArray *cz, int pos);


void merge(float a[],int low,int mid,int high);
void selection_sort(float a[], int N);
void ordinamento(myArray *pm); //include il merge/selection
void print_post_sort(myArrayinterv pm, const char nomefile_in[]);
