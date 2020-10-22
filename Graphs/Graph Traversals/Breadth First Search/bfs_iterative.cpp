// In this program we will use adjacency list to represent our graphs
// also the graphs that we are using is directed and non weighted

#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int v;
        list<int> *adjList;

    public:
        Graph* createGraph(int);
        void addEdge(Graph*, int, int);
        void bfs(Graph*, int);
};

Graph* Graph::createGraph(int v){
    Graph* g = new Graph();

    if(g == nullptr){
        cout<<"Memory Error!"<<endl;
        return nullptr;
    }

    g->v = v;
    g->adjList = new list<int>[v];

    return g;
}

void Graph::addEdge(Graph* g, int src, int dest){
    if (g == nullptr){
        cout<<"Graph is not found!!"<<endl;
        return;
    }

    g->adjList[src].push_back(dest);        // It will add dest to src list of adjacent vertices
}

void Graph::bfs(Graph* g, int start){       // method for implementation of bfs algorithm
    if (g == nullptr){
        cout<<"Graph is not found create a graph first to perfom bfs"<<endl;
        return;
    }

    bool* visited = new bool[g->v];     // array for marking vertex as visited or not

    for(int i=0; i<g->v; i++){          // init the array as false since all the vertices are unvisited
        visited[i] = false;
    }
    
    list<int> queue;        // list representation of a queue

    visited[start] = true;      // will mark the starting vertex as visited

    queue.push_back(start);     // push the start vertex in the queue

    list<int>:: iterator i;     // iterator for traversing the adjacent vertices of a vertex

    cout<<"The Breadth First Search of the graph is:"<<endl;

    while(!queue.empty()){      // will do the following steps while queue is not empty
        start = queue.front();
        cout<<start<<" ";       // print the front of the queue
        queue.pop_front();      // pop the front

        // Now we will push all the vertices that are adjacent to the element just popped

        for(i = g->adjList[start].begin(); i != g->adjList[start].end(); ++i){
            if(!visited[*i]){       // if i is not in visited
                visited[*i] = true;         // mark it as visited
                queue.push_back(*i);        // push it into the queue
            }
        }
    }
    cout<<endl;
}

int main(){
    int op;
    Graph g, *gr = nullptr;

    do{
        cout<<"Select an option from below list: "<<endl;
        cout<<"1. To create a graph"<<endl;
        cout<<"2. To add an edge in the graph"<<endl;
        cout<<"3. To perform Breadth First search operation"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>op;

        switch(op){
            case 1:
                int v;
                cout<<"Enter the number of vertices in the graph: "<<endl;
                cin>>v;

                gr = g.createGraph(v);
                break;

            case 2:
                int vi, ui;
                cout<<"Enter the source and destination vertex respectively: "<<endl;
                cin>>vi>>ui;

                g.addEdge(gr, vi, ui);
                break;

            case 3:
                int t;
                cout<<"Enter the initial vertex: "<<endl;
                cin>>t;

                g.bfs(gr, t);
                break;
        }

    }while(op != 4);

    return 0;
}