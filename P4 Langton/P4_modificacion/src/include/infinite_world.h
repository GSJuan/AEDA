#include "world.h"
#pragma once
class InfiniteWorld: public World 
{

using World::World;

virtual void ReSize(std::vector<Ant>& ants){
    while(AntOut(ants) == true){
int up = 0, down = 0, left = 0, right = 0;

Vector<Vector<Cell>> new_world;

for(int i = 0; i < ants.size(); i++) {       
    
        if(ants[i].GetRow() >= world.GetUpperLimit()){
            up = 20; 
        }
        else if(ants[i].GetRow() < world.GetLowerLimit()) {
            up = 20;
            down = -20;
        }
        else if (ants[i].GetColumn() >= world[0].GetUpperLimit()){
            right = 20;
        }
        else if(ants[i].GetColumn() < world[0].GetLowerLimit()){
            right = 20;
            left = -20;                  
        }
}

    new_world.resize(world.GetSize() + up);
    new_world.SetLowerLimit(world.GetLowerLimit() + down);
    for(int i = new_world.GetLowerLimit(); i < new_world.GetUpperLimit(); i++){
        new_world[i].resize(world[0].GetSize() + right);
        new_world[i].SetLowerLimit(world[0].GetLowerLimit() + left);
    }

    for(int j = world.GetLowerLimit(); j < world.GetUpperLimit(); j++){
        for (int k = world[j].GetLowerLimit(); k < world[j].GetUpperLimit(); k++){
            new_world[j][k] = world[j][k];
        }
    }
    SetWorld(new_world);
}
}

virtual void ReSize(std::vector<Ant*>& ants){
    while(AntOut(ants)){
int up = 0, down = 0, left = 0, right = 0;

Vector<Vector<Cell>> new_world;

for(int i = 0; i < ants.size(); i++) {       
    
        if(ants[i]->GetRow() >= world.GetUpperLimit()){
            up = 20; 
        }
        else if(ants[i]->GetRow() < world.GetLowerLimit()) {
            up = 20;
            down = -20;
        }
        else if (ants[i]->GetColumn() >= world[0].GetUpperLimit()){
            right = 20;
        }
        else if(ants[i]->GetColumn() < world[0].GetLowerLimit()){
            right = 20;
            left = -20;                  
        }
}

    new_world.resize(world.GetSize() + up);
    new_world.SetLowerLimit(world.GetLowerLimit() + down);
    for(int i = new_world.GetLowerLimit(); i < new_world.GetUpperLimit(); i++){
        new_world[i].resize(world[0].GetSize() + right);
        new_world[i].SetLowerLimit(world[0].GetLowerLimit() + left);
    }

    for(int j = world.GetLowerLimit(); j < world.GetUpperLimit(); j++){
        for (int k = world[j].GetLowerLimit(); k < world[j].GetUpperLimit(); k++){
            new_world[j][k] = world[j][k];
        }
    }
    SetWorld(new_world);
}
}

};