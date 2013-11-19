OBJ=collision.o input.o misktasks.o network.o simulated.o updateobjects.o update_time.o renderworld.o PostWar.o draw.o video.o load_image.o menu.o jogar.o creditos.o client.o server.o fase1.o carregar_fase1.o fontes.o carrega_unidades.o mover_unidade.o blit_tela.o verifica_hexagono.o
COLL=source/features/Collision/collision.cpp
INP=source/features/Input/input.cpp
MISC=source/features/MiscTasks/misktasks.cpp
NET=source/features/Network/network.cpp
CLIENT=source/features/Network/client.cpp
SERVER=source/features/Network/server.cpp
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
CRED=source/GameFeatures/Creditos/creditos.cpp
FASE1=source/GameFeatures/Jogar/Fase1/fase1.cpp
FONTES=source/features/MiscTasks/fontes.cpp
CARREGA_FASE1=source/GameFeatures/Jogar/Fase1/carregar_fase1.cpp
CARREGA_UNIDADE=source/GameFeatures/Jogar/Fase1/carrega_unidades.cpp
VERIFICA_HEXAGONO=source/GameFeatures/Jogar/Fase1/verifica_hexagono.cpp
MOVER_UNIDADE=source/features/UpdateObjects/mover_unidade.cpp
BLIT_TELA=source/GameFeatures/blit_tela.cpp
CFLAGS= `sdl-config --cflags --libs` -Wall -W -pedantic -ansi -lm -I. -lSDL_image -lSDL_net -lSDL_ttf

all: PostWar
PostWar: $(OBJ) 
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
creditos.o: $(CRED)
	g++ -c $(CRED)
client.o: $(CLIENT)
	g++ -c $(CLIENT)
server.o: $(SERVER)
	g++ -c $(SERVER)
fase1.o: $(FASE1)
	g++ -c $(FASE1)
carregar_fase1.o: $(CARREGA_FASE1)
	g++ -c $(CARREGA_FASE1)
jogar.o: $(JOGAR)
	g++ -c $(JOGAR)
fontes.o: $(FONTES)
	g++ -c $(FONTES)
carrega_unidades.o: $(CARREGA_UNIDADE)
	g++ -c $(CARREGA_UNIDADE)
mover_unidade.o: $(MOVER_UNIDADE)
	g++ -c $(MOVER_UNIDADE)
blit_tela.o: $(BLIT_TELA)
	g++ -c $(BLIT_TELA)
verifica_hexagono.o: $(VERIFICA_HEXAGONO)
	g++ -c $(VERIFICA_HEXAGONO)
PostWar.o: $(POSTWAR)
	g++ -c $(POSTWAR)
clean:
	rm -rf *.o *~ PostWar

