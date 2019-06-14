CXX = g++
CXXFLAGS = -std=c++17 

build: LittleGirlAndMaximumSum.cpp 
	$(CXX) $(CXXFLAGS)  LittleGirlAndMaximumSum.cpp -o main.o

clean: 
	rm *.o 
