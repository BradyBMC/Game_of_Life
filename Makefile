all: compile link

compile:
	g++ -I src/include -c main.cpp cell.cpp graph.cpp
link:
	g++ main.o cell.o graph.o -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system
clean:
	rm *.o
	rm main
