#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "ADTSaver.cpp"
/*
0 AB
1 AC
2 AD
3 BA
4 BC
5 BD
6 DA
7 DB
8 DC
9 EA
10 EB
11 EC
12 ED
*/
int* CalulatePhases(ADTSaver* adt)
{
    int* colors = new int[13];
    for(int i = 0; i < 13; i++) colors[i] = 0;
    colors[0] = 1;
    int lastColor = 1;
    int lastFree = 2;
    bool keep = true;
    bool adjacentToCur = false;
    int uncolored = 12;
    while(uncolored > 0)
    {
        //std::cout << "uncolored " << uncolored << std::endl;
        for(int i = 0; i < 13; i++)
        {
            adjacentToCur = false;
            if(colors[i] == 0)
            {
                for(int j = 0; j < 13; j++)
                {
                    if(adt->adjacent(i,j) && i != j && colors[j] == lastColor){
                        adjacentToCur = true;
                        j = 14;
                    }
                }
                if(!adjacentToCur){
                    colors[i] = lastColor;
                    uncolored--;
                } 
            }
        }
        lastColor++;
    }
    std::cout << lastColor << std::endl;
    return colors;
    
}
int main()
{
    std::vector<std::string> names = {"AB", "AC", "AD", "BA", "BC", "BD", "DA", "DB", "DC", "EA", "EB", "EC", "ED"};
    std::vector<std::vector<int>> vectors = {
        {4, 5, 6, 7, 9, 10,},
        {4, 5, 6, 7, 8, 9, 10, 11,},
        {5, 9, 10, 11, 12},
        {6, 9},
        {7, 8, 11},
        {6, 10, 11, 12},
        {9,10,11},
        {11},
        {11},
        {},
        {},
        {},
        {}
    };
    ADTSaver* adt = new ADTSaver(13);
    for(int i = 0; i < 13; i++){
        adt->addVertex(i);
        adt->setVertexValue(i, names[i]);
        for(int edge : vectors[i]) {
            adt->addEdge(i, edge);
            adt->addEdge(edge, i);
        }
    }
    adt->save();
    int* colors = CalulatePhases(adt);
    std::cout << "\n\n\nRESULT:" << std::endl;
    for(int i = 0; i < 13; i++){
        std::cout << names[i] << " " << colors[i] << std::endl;
    }
    delete adt;
}