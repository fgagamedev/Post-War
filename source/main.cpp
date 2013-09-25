#include<iostream>

using namespace std;

extern void update_time();
extern void get_Input();
extern void get_Network_Messages();
extern void simulated_World();
extern void collision_Step();
extern void update_Objects();
extern void render_World();
extern void misc_Tasks();

int main(){

    while (1) {
        update_time();
        get_Input();
        get_Network_Messages();
        simulated_World();
        collision_Step();
        update_Objects();
        render_World();
        misc_Tasks();
        return 0;
    }







}
