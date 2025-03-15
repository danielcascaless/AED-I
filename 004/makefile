
CXX = g++ 
CXXFLAGS = -std=c++17 -Wall -Wextra 

OBJS = main.o pagina.o diccionario.o interprete.o 

TARGET = a.out 


$(TARGET): $(OBJS) 
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) 


main.o: main.cpp pagina.h diccionario.h interprete.h
	$(CXX) $(CXXFLAGS) -c main.cpp 
	
pagina.o: pagina.cpp pagina.h 
	$(CXX) $(CXXFLAGS) -c pagina.cpp 
	
diccionario.o: diccionario.cpp diccionario.h 
	$(CXX) $(CXXFLAGS) -c diccionario.cpp

interprete.o: interprete.cpp interprete.h
	$(CXX) $(CXXFLAGS) -c interprete.cpp

clean: 
	rm -f $(OBJS) $(TARGET)
