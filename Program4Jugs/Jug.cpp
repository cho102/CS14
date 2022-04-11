#include "Jug.h"
#include <iostream>
#include <string>
#include <queue>
#include <list>
using namespace std;



//Source from https://www.tutorialspoint.com/cplusplus-program-to-implement-adjacency-list
Jug::Jug(int n1, int n2,int n3,int n4,int n5,int n6,int n7,int n8,int n9)
{
    Ca = n1;
    Cb = n2;
    N = n3;
    cfA = n4;
    cfB = n5;
    ceA = n6;
    ceB = n7;
    cpAB = n8;
    cpBA = n9;


	// cout << "1" << endl;
	// list<Vertex*> tempList[6];
	adjList[0].front() = new Vertex("fillA");
    adjList[1].front() = new Vertex("fillB");
    adjList[2].front() = new Vertex("emptyA");
    adjList[3].front() = new Vertex("emptyB");
    adjList[4].front() = new Vertex("pourAB");
    adjList[5].front() = new Vertex("pourBA");
	// cout << "1.25" << endl;
    for (unsigned i = 0; i < 6; ++ i) 
	{
    	for (unsigned j = 0; j < 6; ++j) 
		{
    		if (!(i == j)) 
			{
    			adjList[i].front()->path.push_back(adjList[j].front());
    		}
    	}
    }
	// // cout << "1.5" << endl;
	// for (int i = 0; i < 6; ++i)
    // {
    //     adjList[i].push_back(tempList[i]);
    // }
}


Jug::~Jug() 
{
    
}

//solve is used to check input and find the solution if one exists
//returns -1 if invalid inputs. solution set to empty string.
//returns 0 if inputs are valid but a solution does not exist. solution set to empty string.
//returns 1 if solution is found and stores solution steps in solution string.
int Jug::solve(string &solution) 
{
	int cst = 0;
    if (Ca < 0 ||
        Ca >= Cb ||
        Cb >= 1000 ||
        Cb < 1 ||
        N < 1 ||
        cfA < 0 ||
        cfB < 0 ||
        ceA < 0 ||
        ceB < 0 ||
        cpAB < 0 ||
        cpBA < 0 ||
        Cb <= N)
    
    {
        solution = "";
        return -1;
    }

	bool final = shortestPath(solution, cst);
	if (!final)
	{
		solution = "";
		return 0;
	}

	string num = to_string(cst);
	solution = solution + "success " + num;
    //+ "\n";

	return 1;
}


bool Jug::shortestPath(string &solution, int& cst) 
{
	// bool found = false;
	queue<Node> qu;
	
	Node start;
	start.jugs = Status();
	visited.push_back(start.jugs);
	Node first = fillA(start);
	visited.push_back(first.jugs);
	Node sec = fillB(start);
	visited.push_back(sec.jugs);
	qu.push(first);
	qu.push(sec);

	// cout << "show vector\n";
    // for (int i = 0; i < visited.size(); ++i)
    // {
    //     show(visited.at(i));
    // }
    // cout << endl;
	
	// cout << "declare" << endl;
	Node temp;
	while (!qu.empty()) 
	{
		// cout << "entered while" << endl;
		Node curr = qu.front();
		for(unsigned i = 0; i < curr.vertex->path.size(); ++i) 
		// for (std::list<Vertex*>::iterator i = curr->vertex->begin()->action; i != curr.vertex.end(); ++i)
		{
			// cout << "checking" << endl;
			if (curr.vertex->path.at(i)->action == "fillA") 
			{
				// cout << "fillA\n";
				temp = fillA(curr);
				// show(temp);
			} 
			else if (curr.vertex->path.at(i)->action == "fillB") 
			{
				// cout << "fillB\n";
				temp = fillB(curr);
				// show(temp);
			}
			else if (curr.vertex->path.at(i)->action == "emptyA") 
			{
				// cout << "emptyA\n";
				temp = emptyA(curr);
				// show(temp);
			}
			else if (curr.vertex->path.at(i)->action == "emptyB") 
			{
				// cout << "emptyB\n";
				temp = emptyB(curr);
				// show(temp);
			} 
			else if (curr.vertex->path.at(i)->action == "pourAB") 
			{
				// cout << "pourAB\n";
				temp = pourAB(curr);
				// show(temp);
			} 
			else if (curr.vertex->path.at(i)->action == "pourBA")
			{
				// cout << "pourBA\n";
				temp = pourBA(curr);
				// show(temp);
			}   
			// cout << "out of check" << endl;

			if (temp.jugs.JugB == N) 
			{
				// cout << "solutionFound" << endl;
				if (temp.jugs.JugA != 0) 
				{
                    // Node change = temp;
					// temp = emptyA(change);
					temp.cost += ceA;
					temp.sol += "empty A/n";
				}
				temp.cost += curr.cost;
				temp.sol = curr.sol + temp.sol;
				solFound.push_back(temp);
			} 
			else if (!hadVisited(temp.jugs)) 
			{
				visited.push_back(temp.jugs);
				temp.sol = curr.sol + temp.sol;
				temp.cost += curr.cost;
				qu.push(temp);
			}
		}
		qu.pop();
	}
	// cout << "outWhile" << endl;
    if (solFound.size() == 0)
    {
		return false;
        // return nullptr;
    }

	// cout << "short" << endl;
    // string tempSol = "";
	cst = Ca * 100;
    for (unsigned int i = 0; i < solFound.size(); ++i)
    {
        // cout << "enteredtesting" << endl;
        // string tempSol = "";
        // int tempCst = 0;
        if (solFound.at(i).cost < cst)
        {
            cst = solFound.at(i).cost;
			// cout << "cost" << cst << endl;
            solution = solFound.at(i).sol;
            // temp = solFound.at(i);
        }     
    }
	return true;
}

Node Jug::fillA(Node n) 
{
	// cout << "here" << endl;
	Node next = n;
	// cout << "1" << endl;
	next.jugs.JugA = Ca;
	// cout << "1.5" << endl;
	next.sol = "fill A\n";
	// cout << "2" << endl;
	next.cost = cfA;
	next.vertex = adjList[0].front();
	//.front();
	// show(next.jugs);
	// cout << "end" << endl;
	return next;
}

Node Jug::fillB(Node n) 
{
	Node next = n;
	next.jugs.JugB = Cb;
	next.sol = "fill B\n";
	next.cost = cfB;
	next.vertex = adjList[1].front();
	//.front();
	// show(next.jugs);
	return next;
}

Node Jug::emptyA(Node n) 
{
	Node next = n;
	next.jugs.JugA = 0;
	next.sol = "empty A\n";
	next.cost = ceA;
	next.vertex = adjList[2].front();
	//.front();
	// show(next.jugs);
	return next;
}

Node Jug::emptyB(Node n) 
{
	Node next = n;
	next.jugs.JugB = 0;
	next.sol = "empty B\n";
	next.cost = ceB;
	next.vertex = adjList[3].front();
	//.front();
	// show(next.jugs);
	return next;
}

Node Jug::pourAB(Node n) 
{
	Node next = n;
	if (n.jugs.JugB + n.jugs.JugA < Cb) 
	{
		next.jugs.JugA = 0;
		next.jugs.JugB = n.jugs.JugA + n.jugs.JugB;
	} 
	
	else 
	{
		next.jugs.JugA = (n.jugs.JugA + n.jugs.JugB) - Cb;
		next.jugs.JugB = Cb;
	}
	next.sol = "pour A B\n";
	next.cost = cpAB;
	next.vertex = adjList[4].front();
	//.front();
	// show(next.jugs);
	return next;
}

Node Jug::pourBA(Node n) 
{
	Node next = n;
	if (n.jugs.JugB + n.jugs.JugA < Ca) 
	{
		next.jugs.JugA = n.jugs.JugA + n.jugs.JugB;
		next.jugs.JugB = 0;
	}
	else 
	{
		next.jugs.JugA = Ca;
		next.jugs.JugB = (n.jugs.JugA + n.jugs.JugB) - Ca;
	}
	next.sol = "pour B A\n";
	next.cost = cpBA;
	next.vertex = adjList[5].front();
	//.front();
	// show(next.jugs);
	return next;
}

// int Jug::getCost(Node* n)
// {
//     int c = 0;
//     for (Node* i = n; i != nullptr; i = i->cont)
//     {
//         c += i->cost;
//     }
//     return c;
// }

void Jug::show(Status n)
{
	cout << n.JugA << ", " << n.JugB << endl;
}

bool Jug::hadVisited(Status n) 
{
	for (unsigned i = 0; i < visited.size(); ++i) 
	{
		if (n.JugA == visited.at(i).JugA && n.JugB == visited.at(i).JugB) 
		{
			return true;
		}
	}
	return false;
}