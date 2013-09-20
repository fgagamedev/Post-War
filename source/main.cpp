#include<iostream>

using namespace std;

int main(){

    while (!IsDone()) {
        UpdateTime();
        GetInput();
        GetNetworkMessages();
        SimulatedWorld();
        CollisionStep();
        UpdateObjetcs();
        RenderWorld();
        MiscTasks();
    }







}
