Dsrc=./src
Dobj=./obj

libs=-lglut -lGL -lstdc++ -lX11 -lGLU

bin: $(Dobj)/collisions.o $(Dobj)/game.o $(Dobj)/main.o $(Dobj)/walls.o $(Dobj)/simple_draw.o $(Dobj)/tanks.o $(Dobj)/player.o $(Dobj)/bullet.o
	gcc -o ./bin $(Dobj)/collisions.o $(Dobj)/game.o $(Dobj)/main.o $(Dobj)/walls.o $(Dobj)/simple_draw.o $(Dobj)/tanks.o $(Dobj)/player.o $(Dobj)/bullet.o $(libs)

$(Dobj)/collisions.o: $(Dobj) $(Dsrc)/collisions.cpp
	gcc -c $(Dsrc)/collisions.cpp -o $(Dobj)/collisions.o

$(Dobj)/game.o: $(Dobj) $(Dsrc)/game.cpp
	gcc -c $(Dsrc)/game.cpp -o $(Dobj)/game.o

$(Dobj)/main.o: $(Dobj) $(Dsrc)/main.cpp
	gcc -c $(Dsrc)/main.cpp -o $(Dobj)/main.o

$(Dobj)/walls.o: $(Dobj) $(Dsrc)/walls.cpp
	gcc -c $(Dsrc)/walls.cpp -o $(Dobj)/walls.o

$(Dobj)/simple_draw.o: $(Dobj) $(Dsrc)/simple_draw.cpp
	gcc -c $(Dsrc)/simple_draw.cpp -o $(Dobj)/simple_draw.o

$(Dobj)/tanks.o: $(Dobj) $(Dsrc)/tanks.cpp
	gcc -c $(Dsrc)/tanks.cpp -o $(Dobj)/tanks.o

$(Dobj)/player.o: $(Dobj) $(Dsrc)/player.cpp
	gcc -c $(Dsrc)/player.cpp -o $(Dobj)/player.o

$(Dobj)/bullet.o: $(Dobj) $(Dsrc)/bullet.cpp
	gcc -c $(Dsrc)/bullet.cpp -o $(Dobj)/bullet.o

$(Dobj):
	mkdir $(Dobj)