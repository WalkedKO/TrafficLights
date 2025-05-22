#include "ADT.cpp"
#include <string>
#include <fstream>
class ADTSaver : public ADT
{
    using ADT::ADT;
    std::string path = "./graph.dot";
    public:
    void save()
    {
        std::ofstream file;
        file.open(path);
        std::string first, second;
        file << "digraph B {" << std::endl;
        for(int i = 0; i < capacity; i++)
        {
            if(matrix[i][i])
            {
                //std::cout << i << " " <<values[i] << std::endl;
                if(values[i] != "") first = values[i];
                else first = std::to_string(i);
                for(int j = 0; j < capacity; j++)
                {
                    if(i == j || !matrix[i][j]) continue;
                    if(values[j] != "") second = values[j];
                    else second = std::to_string(j);
                    file << first << " -> " << second << ";" << std::endl;
                }
            }
        }
        file << "}" << std::endl;
        file.close();
    }
};
/*void testADT()
{
    ADTSaver* test = new ADTSaver(10);
    test->addVertex(1);
    test->addVertex(2);
    test->addVertex(3);
    test->setVertexValue(2, "B");
    test->addEdge(1,2);
    test->addEdge(1,3);
    test->save();
    delete test;
}*/