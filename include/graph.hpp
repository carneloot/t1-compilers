#include <vector>

class Graph {

public:
    Graph(int id);
    ~Graph();

private:
    std::vector<int> data;
    int id;
};
