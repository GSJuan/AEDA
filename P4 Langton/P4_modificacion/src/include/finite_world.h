#include "world.h"
#pragma once
class FiniteWorld: public World 
{

using World::World;

virtual void ReSize(std::vector<Ant>& ants){
    for(int i = 0; i < ants.size(); i++){
        while(AntOut(ants[i]) == true){
            if(ants[i].GetRow() >= world.GetUpperLimit()){
            ants[i].SetRow(world.GetLowerLimit());
            }
            else if(ants[i].GetRow() < world.GetLowerLimit()) {
                ants[i].SetRow(world.GetUpperLimit());
            }
            else if (ants[i].GetColumn() >= world[0].GetUpperLimit()){
                ants[i].SetColumn(world[ants[i].GetRow()].GetLowerLimit());
            }
            else if(ants[i].GetColumn() < world[0].GetLowerLimit()){
                ants[i].SetColumn(world[ants[i].GetRow()].GetUpperLimit());
            }
        }
    }
}

virtual void ReSize(std::vector<Ant*>& ants){
    for(int i = 0; i < ants.size(); i++){
        while(AntOut(*ants[i]) == true){
            if(ants[i]->GetRow() >= world.GetUpperLimit()){
            ants[i]->SetRow(world.GetLowerLimit());
            }
            else if(ants[i]->GetRow() < world.GetLowerLimit()) {
                ants[i]->SetRow(world.GetUpperLimit());
            }
            else if (ants[i]->GetColumn() >= world[0].GetUpperLimit()){
                ants[i]->SetColumn(world[ants[i]->GetRow()].GetLowerLimit());
            }
            else if(ants[i]->GetColumn() < world[0].GetLowerLimit()){
                ants[i]->SetColumn(world[ants[i]->GetRow()].GetUpperLimit());
            }
        }
    }
}

};