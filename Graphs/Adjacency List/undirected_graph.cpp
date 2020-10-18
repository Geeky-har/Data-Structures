// In this particular program we are assuming that the graph we are using is a undirected graph

#include<bits/stdc++.h>
using namespace std;

class AdjListNode{      // class for list nodes
    public:
        int dest;
        AdjListNode* next;
};

class AdjList{          // class for head of each vertex of the graph
    public:
        AdjListNode* head;
};

class Graph: public AdjList, public AdjListNode{
    int v;
    int e;
    AdjList* arr;       // array of AdjList(head) which contains all header nodes

    public:
        Graph* createGraph(int, int);
        void addEdge(Graph*, int, int);
        AdjListNode* createNode(int);
        void printGraph(Graph*);
        void remEdge(Graph*, int, int);

};

AdjListNode* Graph::createNode(int dest){       // method will create and return a new instance of AdjListNode
    AdjListNode* newNode = new AdjListNode();
    newNode->dest = dest;
    newNode->next = nullptr;

    return newNode;
}

Graph* Graph::createGraph(int v, int e){        // method for creating a new Graph
    Graph* g = new Graph();
    g->v = v;       // set the number of vertices
    g->e = e;       // set the number of edges

    g->arr = new AdjList[g->v];     // dynamically created a arr of AdjList(head ) type of size v

    for(int i=0; i < g->v; ++i){    // init all the headers as nullptr
        g->arr[i].head = nullptr;
    }

    return g;
}

void Graph::addEdge(Graph* g, int src, int dest){   // method to add an bidirectonal edge btw 2 vertices

    // for establishing an edge between SRC -> DEST

    AdjListNode* node = createNode(dest);       // creating a new node with dest vertex as data

    if(g->arr[src].head == nullptr){        // if head of src vertex is null
        g->arr[src].head = node;            // will set the new node as head
        node->next = nullptr;
    }

    else{       // otherwise will traverse through the list and append the new node 
        AdjListNode* tr = g->arr[src].head;
        while(tr->next != nullptr){
            tr = tr->next;
        }

        tr->next = node;
        node->next == nullptr;
    }

    // for establishing an edge between SRC -> DEST

    node = createNode(src);

    if(g->arr[dest].head == nullptr){
        g->arr[dest].head = node;
        node->next = nullptr;
    }

    else{
        AdjListNode* tr = g->arr[dest].head;
        while(tr->next != nullptr){
            tr = tr->next;
        }

        tr->next = node;
        node->next = nullptr;
    }
}

void Graph::remEdge(Graph* g, int src, int dest){   // method to remove an edge
    if(g == nullptr){
        cout<<"Graph not found!"<<endl;
        return;
    }

    // for removing an edge between SRC->DEST

    if(g->arr[src].head == nullptr){    // No edge is inclined
        cout<<"No edge is associated with this source vertex"<<endl;
        return;
    }

    else{   // Linked list node deletion operation implemented below -
        AdjListNode* t = g->arr[src].head;
        AdjListNode* t1 = nullptr;

        if(t->dest == dest){
            g->arr[src].head = t->next;
            delete(t);
        }

        else{
            while(t->dest != dest && t->next != nullptr){
                t1 = t;
                t = t->next;
            }

            if(t->next == nullptr && t->dest != dest){
                cout<<"Destination vertex is not found in the graph!"<<endl;
                return;
            }

            else if(t->next == nullptr && t->dest == dest){
                t1->next = nullptr;
                delete(t);
            }

            else{
                t1->next = t->next;
                delete(t);
            }
        }
    }

    // for removing an edge between DEST->SRC(in Adjacency list)

    AdjListNode* t = g->arr[dest].head;
    AdjListNode* t1 = nullptr;

    if(t->dest == src){
        g->arr[dest].head = t->next;
        delete(t);
    }

    else{
        while(t->dest != src && t->next != nullptr){
            t1 = t;
            t = t->next;
        }

        if(t->next == nullptr && t->dest == src){
            t1->next = nullptr;
            delete(t);
        }

        else{
            t1->next = t->next;
            delete(t);
        }
    }
}

void Graph::printGraph(Graph* g){       // method to print the resultant graph
    if(g == nullptr){           // if graph not created yet!
        cout<<"Graph not found!!"<<endl;
        return;
    }

    for(int i=0; i < g->v; ++i){    // starting from index of AdjList array of headers
        AdjListNode* t = g->arr[i].head;    // t holds the address of header of index i
        cout<<"The edges going from vertex "<<i<<" are: "<<endl;
        cout<<"HEAD";
        while(t){
            cout<<"->"<<t->dest;    // will print the nodes associated with the index i node
            t = t->next;
        }
        cout<<endl;
    }
}

int main(){
    int op;
    Graph g, *gr = nullptr;
    do{
        cout<<"Select an option from below list: "<<endl;
        cout<<"1. To create a Graph"<<endl;
        cout<<"2. To add an edge"<<endl;
        cout<<"3. To remove an edge"<<endl;
        cout<<"4. To print the graph"<<endl;
        cout<<"5. Exit"<<endl;
        cin>>op;

        switch (op)
        {
        case 1:
            int v, e;
            cout<<"Enter the number of vertices and edges in the graph respectfully: "<<endl;
            cin>>v>>e;

            gr = g.createGraph(v, e);
            break;
        
        case 2:
            if(gr == nullptr){
                cout<<"Graph not found!!"<<endl;
                break;
            }

            else{
                int src, dest;
                cout<<"Enter the source and the destination vertex respectfully(in range: 0-v): "<<endl;
                cin>>src>>dest;

                g.addEdge(gr, src, dest);
                break;
            }

        case 3:
            if(gr == nullptr){
                cout<<"Graph not found!!"<<endl;
                break;
            }

            else{
                int src_d, dest_d;
                cout<<"Enter the source and destination vertex from where the edge has to be removed: "<<endl;
                cin>>src_d>>dest_d;

                g.remEdge(gr, src_d, dest_d);
                break;
            }

        case 4:
            g.printGraph(gr);
            break;
        }

    }while(op != 5);

    return 0;
}