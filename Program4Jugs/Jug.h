#include <iostream>
#include <list>
#include <vector>
using namespace std;

#ifndef __JUG_H___
#define __JUG_H___

struct Vertex {
	vector<Vertex*> path;
	string action;
    Vertex()
    {
        action = "";
    }
	Vertex(string s) {
		action = s;
	}
};

struct Status
{
    int JugA;
    int JugB;
    Status()
    {
        JugA = 0;
        JugB = 0;
    }
};

struct Node {
    Status jugs;
    // int JugA;
    // int JugB;
	string sol;
    int cost;
    // Node* cont;
    // Node* head;
    // Node* tail;
    // list <Vertex*> vertex[6];
    Vertex* vertex;
	Node() {
        // JugA = 0;
        // JugB = 0;
		// jugs = Status();
        sol = "";
        cost = 0;
        // cont = nullptr;
        // vertex.front() = nullptr;
        vertex = nullptr;
        // tail = nullptr;
        // head = nullptr;
	}
};

class Jug {
    public:
        Jug(int,int,int,int,int,int,int,int,int);
        ~Jug();

        //solve is used to check input and find the solution if one exists
        //returns -1 if invalid inputs. solution set to empty string.
        //returns 0 if inputs are valid but a solution does not exist. solution set to empty string.
        //returns 1 if solution is found and stores solution steps in solution string.
        int solve(string &solution);
    private:
        //anything else you need
        Node fillA(Node);
        Node fillB(Node);
        Node emptyA(Node);
        Node emptyB(Node);
        Node pourAB(Node);
        Node pourBA(Node);
        // int getCost(Node*);
        bool hadVisited(Status);
        
        bool shortestPath(string&, int&);
        vector<Status> visited;
        vector<Node> solFound;
        void show(Status);

        int Ca;
        int Cb;
        int N;
        int cfA;
        int cfB;
        int ceA;
        int ceB;
        int cpAB;
        int cpBA;
        // list <list <Vertex*> > adjList[6];
        list <Vertex*> adjList[6];


        
        
};

#endif