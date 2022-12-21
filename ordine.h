#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;


#define INCR 10

#ifndef _myArray_
#define _myArray_

struct <STRUCT>{
}

struct myArray{
  
  int size, used;
  struct * raw;
  
}

#endif  

void intestazione();


void initialize_myArray (myArray *cz, int dim);
void resize_myArray (myArray *cz, int newsize);
void insert_myArray (myArray *cz, <STRUCT> Z1);


void fill_myArray (myArray *cz, const char nomefile_in[]) ;

void initialize_myArrayeliminati (myArrayeliminati *cz, int dim);
void resize_myArrayeliminati(myArrayeliminati *cz, int newsize) ;
void insert_eliminati(myArrayeliminati *eliminati, myArray *pm); //inserisce elementi da eliminare in myarray secondo una condizione

void print_ov_myArray(myArray pm, const char nomefile_out[]);
void print_ov_of_myarray(myArray pm, const char nomefile_out[]);
void remove_at_myArray(myArray *cz, int pos);


void merge(float a[],int low,int mid,int high);
void selection_sort(myArray *pm, int N);
void selection_sort_out(myArray *pm, int N)
void print_ov_of_myArray_sorted(myArray pm, const char nomefile_out[])
