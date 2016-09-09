// Isaac Goldman HW8 Problem 4

#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <map>
#include <fstream>
#include <utility>
#include <set>
#include <unordered_set>

class Edge {

public:
  Edge(string city, int distance);
  string edgeKey;


private:
  Edge();

}

using namespace std;

// function to print the elements in a list 
void listPrint(list<string>* stringList){
  for(list<string>::iterator it = stringList->begin(); it != stringList->end(); ++it){
    cout << *it << endl;
  }
}

// declare Graph class
class Graph {

public:

  Graph(const char* fileName);
  // void findNeighbors(string vertex, list<string>* neighbors);
  //void distThreeNeighbors(string vertex);
  list<string>* nearestNeighborPath(string vertex);

private: 
  Graph();
  map<string, list< pair<string, int> >* > adjList; // map container for adjacency list to represent the graph
  int numVertices;
  int numEdges;
  


};

// custom constructor instantiates a graph object from a list of vertices and edges from an input file
Graph::Graph(const char* fileName){ 

  string line, key, neighbor, weight;
  int distance;
  ifstream inputFile(fileName);
  this->numVertices = 0;

  // read in each line as a string, then divide the string into substrings corresponding the vertices and weights
  while(getline(inputFile,line)){
    key = line.substr(0,4);
    neighbor = line.substr(9,4);
    weight = line.substr(15);
    distance = atoi(weight.c_str());
    //cout << key << " " << neighbor << " " << distance << endl;
    
    // if this is a new vertex, create a new index in the map and increment the vertext count
    if(this->adjList.find(key) == this->adjList.end()){
      this->adjList[key] = new list< pair<string, int> >;
      (this->numVertices)++;
    }

    this->adjList[key]->push_back(make_pair(neighbor, distance));

  }

  //cout << this->numVertices << endl;
}

list<string>* Graph::nearestNeighborPath(string vertex, unorderd_set<string>* cheapestPath){
  int max = 0;
  string maxEdge;
  list<string>* pathList;
  
  while(cheapestPath->find(vertex) == cheapestPath->end()){


  }
}
