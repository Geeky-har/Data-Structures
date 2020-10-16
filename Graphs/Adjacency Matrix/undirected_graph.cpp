// In this program we are assuming that the graph is undirected

#include<iostream>
using namespace std;

class Graph{
    private:
        int v;      // for number of vertices
        int** adjMat;       // array of pointers to arrays
        int e;     // for numbers of edges

    public:
        Graph* createGraph(int, int);        // method to set and create the graph
        void addEdge(Graph*, int, int);     // method to add an edge in the graph
        void remEdge(Graph*, int, int);    // method to remove an edge from the graph
        void showAdjMat(Graph*);          // method to show the resultant adj matrix created so far
};

Graph* Graph::createGraph(int u, int v){    // Takes two args: no. of edges & no. of edges
    Graph* g = new Graph();     // new instance of Graph

    if(g == nullptr){       
        cout<<"Memory Error!!"<<endl;
        return nullptr;
    }

    g->v = u;
    g->e = v;

    g->adjMat = new int*[g->v];     // dynamically allocating memory to the 2d array(here only 1d)

    for(int i=0; i < g->v; i++){    // while traversing the newly allocated 2d array
        g->adjMat[i] = new int[g->v];   // we will set each index of the column to an another set of 1d arr
        for(int j=0; j < g->v; j++){
            g->adjMat[i][j] = 0;        // will set all the values to 0
        }
    }

    return g;   
}

void Graph::addEdge(Graph* g, int from, int dest){
    if(g == nullptr){
        cout<<"Graph not found"<<endl;
        return;
    }

    g->adjMat[from][dest] = 1;
    g->adjMat[dest][from] = 1;
}

void Graph::remEdge(Graph* g, int from, int dest){
    if(g ==nullptr){
        cout<<"Graph not found"<<endl;
        return;
    }

    g->adjMat[from][dest] = 0;
    g->adjMat[dest][from] = 0;
}

void Graph::showAdjMat(Graph* g){
    if(g == nullptr){
        cout<<"Graph not found"<<endl;
        return;
    }

    cout<<"Your Adjacency Matrix is as follows: "<<endl;

    for(int i=0; i < g->v; i++){
        for(int j=0; j <g->v; j++){
            cout<<g->adjMat[i][j]<<" ";
        }cout<<endl;
    }
}

int main(){
    int op;
    Graph g, *gr = nullptr;

    do{

        cout<<"Main Menu"<<endl;

        cout<<"Select an option form below: "<<endl;
        cout<<"1. To create a graph"<<endl;
        cout<<"2. To add an edge"<<endl;
        cout<<"3. To remove an edge"<<endl;
        cout<<"4. To see the adjacency Matrix formed"<<endl;
        cout<<"5. Exit"<<endl;
        cin>>op;

        switch(op){
            case 1:
                int v, e;
                cout<<"Enter the number of vertices and edges respectively: "<<endl;
                cin>>v>>e;

                gr = g.createGraph(v, e);
                break;

            case 2:
                int s, d;
                cout<<"Enter the souce and destination vertex respectively(write pos integers): "<<endl;
                cin>>s>>d;

                g.addEdge(gr, s, d);
                break;

            case 3:
                int sr, dr;
                cout<<"Enter the souce and destination vertex respectively that has to be removed: "<<endl;
                cin>>sr>>dr;

                g.remEdge(gr, sr, dr);
                break;

            case 4:
                g.showAdjMat(gr);
                break;

        }
    }while(op != 5);

    return 0;
}