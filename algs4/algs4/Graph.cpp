#include <vector>
using namespace std;
class Graph
{
public:
    Graph(int v):v(v){
        for(int i=0;i<v;i++)
            adj.push_back(vector<int>());
    }
    int V(){return adj.size();}
    int E(){return e;}
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
        e++;
    }
    vector<int> adjs(int v)
    {
        return adj[v];
    }

private:
    int v;
    int e;
    vector<vector<int>> adj;
};

int main()
{

}