#include<iostream>

using namespace std;

int main(){

    while (!IsDone()) {
        update_time()Time();
        get_Input();
        get_Network_Messages();
        simulated_World();
        collision_Step();
        update_Objetcs();
        render_World();
        misc_Tasks();
    }







}
