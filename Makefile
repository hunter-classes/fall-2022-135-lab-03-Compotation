CXXFLAGS = -Wall
main: main.o reservoir.o
	g++ $(CXXFLAGS) -o main main.o reservoir.o

main.o: main.cpp reservoir.h
	g++ $(CXXFLAGS) -c main.cpp

reservoir.o: reservoir.cpp reservoir.h
	g++ $(CXXFLAGS) -c reservoir.cpp
clean:
	rm -f main.o reservoir.o

