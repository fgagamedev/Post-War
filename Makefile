OBJ=collision.o input.o misktasks.o network.o simulated.o updateobjects.o update_time.o renderworld.o main.o
COLL=source/features/Collision/collision.cpp
INP=source/features/Input/input.cpp
MISC=source/features/MiscTasks/misktasks.cpp
NET=source/features/Network/network.cpp
RENDER=source/features/RenderWorld/renderworld.cpp
SIMU=source/features/SimulatedWorld/simulated.cpp
UPOBJ=source/features/UpdateObjects/updateobjects.cpp
UPTIME=source/features/UpdateTime/update_time.cpp
MAIN=source/main.cpp
CFLAGS= -lSDL -Wall -W -pedantic -ansi -lm -I.

all: prog
prog: $(OBJ)
	g++ -o prog $(OBJ) $(CFLAGS)
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
	g++ -c $(RENDER)
main.o: $(MAIN)
	g++ -c $(MAIN)
clean:
	rm -rf *.o *~ prog

