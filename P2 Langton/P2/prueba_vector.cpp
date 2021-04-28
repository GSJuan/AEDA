#include "vector.cpp"
int main(void){
int k = 0;
   
    Vector<Vector<Cell>> world(-3, 3);
    std::cout << world.GetSize() << world.GetLowerLimit() << world.GetUpperLimit()<<std::endl;
  
for(int i = world.GetLowerLimit(); i < world.GetUpperLimit(); i++){
    world[i].resize(8);
    world[i].SetLowerLimit(-4);
}
    
    for(int i = world.GetLowerLimit(); i < world.GetUpperLimit(); i++){
       for(int j = world[i].GetLowerLimit(); j < world.GetUpperLimit(); j++) {
            world[i][j].value = 0;
            k++;
        }
    }

    Vector<Vector<Cell>> sec;
    sec = world;
        for(int i = sec.GetLowerLimit(); i < sec.GetUpperLimit(); i++){
       for(int j = sec[i].GetLowerLimit(); j < sec.GetUpperLimit(); j++) {
        std::cout << world[i][j].value;
        }
        std::cout << std::endl;
    }
    
    return 0;
}