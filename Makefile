OBJ=collision.o input.o misktasks.o network.o simulated.o updateobjects.o update_time.o renderworld.o PostWar.o draw.o video.o load_image.o menu.o jogar.o
COLL=source/features/Collision/collision.cpp
INP=source/features/Input/input.cpp
MISC=source/features/MiscTasks/misktasks.cpp
NET=source/features/Network/network.cpp
RENDER=source/features/RenderWorld/renderworld.cpp
DRAW=source/features/RenderWorld/draw.cpp
VIDEO=source/features/RenderWorld/video.cpp
SIMU=source/features/SimulatedWorld/simulated.cpp
UPOBJ=source/features/UpdateObjects/updateobjects.cpp
UPTIME=source/features/UpdateTime/update_time.cpp
POSTWAR=source/PostWar.cpp
LOAD_I=source/features/RenderWorld/load_image.cpp
MENU=source/GameFeatures/Menu/menu.cpp
JOGAR=source/GameFeatures/Jogar/jogar.cpp
CFLAGS= `sdl-config --cflags --libs` -Wall -W -pedantic -ansi -lm -I. -lSDL_image

all: PostWar
PostWar: $(OBJ) $(LIB)
	g++ -o PostWar $(OBJ) $(CFLAGS)
collision.o: $(COLL)
	g++ -c $(COLL)
input.o: $(INP)
	g++ -c $(INP)
load_image.o: $(LOAD_I)
	g++ -c $(LOAD_I)
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
draw.o: $(DRAW)
	g++ -c $(DRAW)
video.o: $(VIDEO)
	g++ -c $(VIDEO)
menu.o: $(MENU)
	g++ -c $(MENU)
jogar.o: $(JOGAR)
	g++ -c $(JOGAR)
PostWar.o: $(POSTWAR)
	g++ -c $(POSTWAR)
clean:
	rm -rf *.o *~ PostWar

