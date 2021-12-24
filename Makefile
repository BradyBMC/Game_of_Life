all: compile link

compile:
	g++ -I src/include -c main.cpp cell.cpp graph.cpp
link:
	g++ main.o cell.o graph.o -o main -lsfml-graphics -lsfml-window -lsfml-system
clean:
	rm *.o
	rm main
