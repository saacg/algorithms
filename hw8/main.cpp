// Isaac Goldman HW 7 Problem 3

#include <iostream>
#include <map>
#include <cstdlib>
#include <utility>
#include <list>

using namespace std;

class Graph {

public:
  Graph();
  Graph(const char* fileName);
  //void findNeighbors(string vertex, list<string>* neighbors);
  //void distThreeNeighbors(string vertex);

private: 

  map<string, list< pair<string, int> >* > adjList;
  int numVertices;
  int numEdges;

};


int main(int argc, const char* argv[]){
 


  //Graph* graph = new Graph("testMap.txt");
  Graph* graph = new Graph("map.txt");


  

  return 0;

}
