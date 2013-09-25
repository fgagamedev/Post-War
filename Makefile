OBJ=collision.o input.o misktasks.o network.o simulated.o updateobjects.o update_time.o renderworld.o main.o
COLL=features/Collision/collision.cpp
INP=features/Input/input.cpp
MISC=features/MiscTasks/misktasks.cpp
NET=features/Network/network.cpp
RENDER=features/RenderWorld/renderworld.cpp
SIMU=features/SimulatedWorld/simulated.cpp
UPOBJ=features/UpdateObjects/updateobjects.cpp
UPTIME=features/UpdateTime/update_time.cpp
MAIN=source/main.cpp
CFLAGS=-W -Wall -pedantic -ansi -lm -I -lSDL.
all: prog
prog: $(OBJ)
	g++ -o prog $(OBJ) -lSDL
collision.o: $(COLL)
	g++ -c $(COLL)
input.o: $(INP)
	g++ -c $(INP)
misktasks.o: $(MISC)
	g++ -c $(MISC)
network.o: $(NET)
	g++ -c $(NET)
simulated.o: $(SIMU)
	g++ -c $(SIMU)
updateobjects.o: $(UPOBJ)
	g++ -c $(UPOBJ)
update_time.o: $(UPTIME)
	g++ -c $(UPTIME)
renderworld.o: $(RENDER)
	g++ -c $(RENDER) -lSDL
main.o: $(MAIN)
	g++ -c $(MAIN) -lSDL
clean:
	rm -rf *.o

