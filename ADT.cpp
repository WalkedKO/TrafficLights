#include <iostream>
class ADT
{
    protected:
    int capacity;
    int size;
    bool** matrix;
    std::string* values;
    int** edgeValues;
    public:
    //graph is DIRECTED
    ADT(int capacity) : capacity(capacity)
    {
        matrix = new bool*[capacity];
        for(int i = 0; i < capacity; i++) matrix[i] = new bool[capacity];

        size = 0;
        values = new std::string[capacity];
        for(int i = 0; i < capacity; i++) values[i] = "";

        edgeValues = new int*[capacity];
        for(int i = 0; i < capacity; i++) edgeValues[i] = new int[capacity];
    }
    bool adjacent(int x, int y)
    {
        return matrix[x][y];
    }
    void neighbours(int x)
    {
        for(int i = 0; i < size; i++)
        {
            if(matrix[x][i]) std::cout << i << std::endl;
        }
    }
    void addVertex(int x)
    {
        matrix[x][x] = true;
    }
    void removeVertex(int x)
    {
        for(int i = 0; i < capacity; i++)
        {
            matrix[x][i] = false;
            matrix[i][x] = false;
        }
        values[x] = "";
    }
    void addEdge(int x, int y)
    {
        matrix[x][y] = true;
    }
    void removeEdge(int x, int y)
    {
        matrix[x][y] = false;
    }
    std::string getVertexValue(int x)
    {
        return values[x];
    }
    void setVertexValue(int x, std::string v)
    {
        values[x] = v;
    }
    int getEdgeValue(int x, int y)
    {
        return edgeValues[x][y];
    }
    void setEdgeValue(int x, int y, int v)
    {
        edgeValues[x][y] = v;
    }
    ~ADT()
    {
        for(int i = 0; i < capacity; i++) delete matrix[i];
        delete matrix;

        delete values;

        for(int i = 0; i < capacity; i++) delete edgeValues[i];
        delete edgeValues;
    }
};