CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
OBJFILES = main.o diccionario.o pagina.o interprete.o tabla_hash.o

a.out: $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o a.out $(OBJFILES)

main.o: main.cpp diccionario.h pagina.h interprete.h tabla_hash.h
	$(CXX) $(CXXFLAGS) -c main.cpp

diccionario.o: diccionario.cpp diccionario.h pagina.h tabla_hash.h
	$(CXX) $(CXXFLAGS) -c diccionario.cpp

pagina.o: pagina.cpp pagina.h
	$(CXX) $(CXXFLAGS) -c pagina.cpp

interprete.o: interprete.cpp interprete.h diccionario.h pagina.h
	$(CXX) $(CXXFLAGS) -c interprete.cpp

tabla_hash.o: tabla_hash.cpp tabla_hash.h pagina.h
	$(CXX) $(CXXFLAGS) -c tabla_hash.cpp

clean:
	rm -f *.o a.out
