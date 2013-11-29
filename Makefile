OBJ=collision.o input.o misktasks.o network.o simulated.o updateobjects.o update_time.o renderworld.o PostWar.o draw.o video.o load_image.o menu.o jogar.o creditos.o client.o server.o fase1.o carregar_fase1.o fontes.o carrega_unidades.o mover_unidade.o blit_tela.o audio.o condicao_fim_do_jogo.o verifica_hexagono.o ataque_unidade.o dano_ataque.o
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
AUDIO=source/features/MiscTasks/audio.cpp
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
ATAQUE_UNIDADE=source/features/UpdateObjects/ataque_unidade.cpp
DANO_ATAQUE=source/features/UpdateObjects/dano_ataque.cpp
VERIFICA_DERROTA=source/features/UpdateObjects/condicao_fim_do_jogo.cpp
BLIT_TELA=source/GameFeatures/blit_tela.cpp
CFLAGS= -lSDL -Wall -W -pedantic -ansi -lm -I. -lSDL_image -lSDL_net -lSDL_ttf -lSDL_mixer

all: PostWar
PostWar: $(OBJ) 
	g++ -o PostWar $(OBJ) $(CFLAGS)
collision.o: $(COLL)  
	g++ -c $(COLL)  $(CFLAGS)
input.o: $(INP)
	g++ -c $(INP)  $(CFLAGS)
load_image.o: $(LOAD_I)
	g++ -c $(LOAD_I) $(CFLAGS)
misktasks.o: $(MISC)
	g++ -c $(MISC) $(CFLAGS)
network.o: $(NET)
	g++ -c $(NET) $(CFLAGS)
simulated.o: $(SIMU)
	g++ -c $(SIMU) $(CFLAGS)
updateobjects.o: $(UPOBJ)
	g++ -c $(UPOBJ) $(CFLAGS)
update_time.o: $(UPTIME)
	g++ -c $(UPTIME) $(CFLAGS)
renderworld.o: $(RENDER)
	g++ -c $(RENDER) $(CFLAGS)
draw.o: $(DRAW)
	g++ -c $(DRAW) $(CFLAGS)
video.o: $(VIDEO)
	g++ -c $(VIDEO) $(CFLAGS)
menu.o: $(MENU)
	g++ -c $(MENU) $(CFLAGS)
creditos.o: $(CRED)
	g++ -c $(CRED) $(CFLAGS)
client.o: $(CLIENT)
	g++ -c $(CLIENT) $(CFLAGS)
server.o: $(SERVER)
	g++ -c $(SERVER) $(CFLAGS)
fase1.o: $(FASE1)
	g++ -c $(FASE1) $(CFLAGS)
carregar_fase1.o: $(CARREGA_FASE1)
	g++ -c $(CARREGA_FASE1) $(CFLAGS)
jogar.o: $(JOGAR)
	g++ -c $(JOGAR) $(CFLAGS)
fontes.o: $(FONTES)
	g++ -c $(FONTES) $(CFLAGS)
carrega_unidades.o: $(CARREGA_UNIDADE)
	g++ -c $(CARREGA_UNIDADE) $(CFLAGS)
mover_unidade.o: $(MOVER_UNIDADE)
	g++ -c $(MOVER_UNIDADE) $(CFLAGS)
dano_ataque.o: $(DANO_ATAQUE)
	g++ -c $(DANO_ATAQUE) $(CFLAGS)
condicao_fim_do_jogo.o: $(VERIFICA_DERROTA)
	g++ -c $(VERIFICA_DERROTA) $(CFLAGS)
ataque_unidade.o: $(ATAQUE_UNIDADE)
	g++ -c $(ATAQUE_UNIDADE) $(CFLAGS)
blit_tela.o: $(BLIT_TELA)
	g++ -c $(BLIT_TELA) $(CFLAGS)
verifica_hexagono.o: $(VERIFICA_HEXAGONO)
	g++ -c $(VERIFICA_HEXAGONO) $(CFLAGS)
audio.o: $(AUDIO)
	g++ -c $(AUDIO) $(CFLAGS)
PostWar.o: $(POSTWAR)
	g++ -c $(POSTWAR) $(CFLAGS)
clean:
	rm -rf *.o *~ PostWar

