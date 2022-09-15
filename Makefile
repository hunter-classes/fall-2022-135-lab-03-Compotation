CXXFLAGS = -Wall
main: main.o reservoir.o reverseorder.o
	g++ $(CXXFLAGS) -o main main.o reservoir.o reverseorder.o

main.o: main.cpp reservoir.h reverseorder.h
	g++ $(CXXFLAGS) -c main.cpp

reservoir.o: reservoir.cpp reservoir.h
	g++ $(CXXFLAGS) -c reservoir.cpp
reverseorder.o: reverseorder.cpp reverseorder.h
	g++ $(CXXFLAGS) -c reverseorder.cpp
clean:
	rm -f main.o reservoir.o

