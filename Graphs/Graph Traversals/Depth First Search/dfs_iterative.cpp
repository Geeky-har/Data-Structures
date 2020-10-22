// In this program we will implement depth first search using adjacency list
// also that the graphs that we are using are directed and non-weighted

#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int v;
        list<int> *adjList;

    public:
        Graph* createGraph(int);
        void addEdge(Graph*, int, int);
        void dfs(Graph*, int);
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

void Graph::dfs(Graph* g, int start){
    if(g == nullptr){
        cout<<"Graph not found!!"<<endl;
        return;
    }

    bool *visited = new bool[g->v];     // marking the vertex whether visited or not

    for(int i=0; i<g->v; ++i){          // initialize the visited array as false since no vertex is visited
        visited[i] = false;
    }

    stack<int> st;      // create stack to store the adjacent vertices of a vertex

    visited[start] = true;      // mark the starting vertex as visited in visited array

    st.push(start);     // push the starting vertex into the stack

    list<int>:: iterator i;     // init a iterator to traverse the adjacent vertices

    cout<<"The depth first traversal of graph is: "<<endl;

    while(!st.empty()){     // while stack is not empty
        start = st.top();
        cout<<start<<" ";   // print the topmost element
        st.pop();           // pop the topmost element

        // Now we will push all the vertices that are adjacent to the element just popped

        for(i = g->adjList[start].begin(); i != g->adjList[start].end(); ++i){
            if(!visited[*i]){       // if i is not in visited
                visited[*i] = true;     // mark it as visited
                st.push(*i);            // push it into the queue
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
        cout<<"3. To perform Depth First search operation"<<endl;
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

                g.dfs(gr, t);
                break;
        }

    }while(op != 4);

    return 0;
}