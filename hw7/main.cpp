// Isaac Goldman HW 7 Problem 3

#include <iostream>
#include <map>
#include <list>

using namespace std;

class Graph {

public:
  Graph();
  Graph(const char* fileName);
  void findNeighbors(string vertex, list<string>* neighbors);
  void distThreeNeighbors(string vertex);

private: 

  map<string, list<string>* > adjList;
  int numVertices;
  int numEdges;

};


int main(int argc, const char* argv[]){
  if(argc != 3){
    cerr << "Incorrect number of arguments" << endl;
    return 0;
  }

  //map<string, list<string>* > adjList(const char* fileName);
  //void distThreeNeighbors(list<string>* vertex);

  //map<string, list<string>* > graph = adjList(argv[1]);

  string vertex = argv[2];

  Graph* graph = new Graph(argv[1]);
  //distThreeNeighbors(graph[key]);
  // list<string>* neighbors = graph->findNeighbors(vertex);
  graph->distThreeNeighbors(vertex);

  /*
  for(list<string>::iterator it = neighbors->begin(); it != neighbors->end(); ++it){
    cout << *it << " ";
  }
  */
  
  

  // cout << endl;
  

  return 0;

}
