compila: funzioni20200212.h funzioni20200212.cc main20200212.cc
	g++ funzioni20200212.h funzioni20200212.cc main20200212.cc -o main20200212.x

esegui: 
	./main20200212.x
	rm main20200212.x
	
	
	
funzioni.o : funzioni.h funzioni.cpp
        g++ -c funzioni.cpp

compila : main.o funzioni.o
        g++ main.o funzioni.o -o main.x

esegui :
        ./main.x
        rm main.x
