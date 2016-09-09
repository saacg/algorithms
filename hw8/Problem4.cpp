// Isaac Goldman HW8 Problem 4

#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <map>
#include <fstream>
#include <utility>


using namespace std;

// function to print the elements in a list 
void listPrint(list<string>* stringList){
  for(list<string>::iterator it = stringList->begin(); it != stringList->end(); ++it){
    cout << *it << endl;
  }
}



class graphNode {

public:
  graphNode(int neighbor, int distance);
  int neighbor;
  int distance;
  graphNode* next;

};


graphNode::graphNode(int neighbor, int distance){

  this->neighbor = neighbor;
  this->distance = distance;
  this->next = NULL;

}

class graphList {

public:
  graphNode* head;
};



// declare Graph class
class Graph {

public:

  Graph(const char* fileName);
  // void findNeighbors(string vertex, list<string>* neighbors);
  //void distThreeNeighbors(string vertex);



private: 
  Graph();
  map<string, list< pair<string, int> >* > adjList; // map container for adjacency list to represent the graph
  map<int, string> lookupTable; // maps the strings to integers to allow for easy iterating and indexing if necessary
  map<string, int> stringToInt;
  graphList* newAdjList; 
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
      this->lookupTable[numVertices] = key;
      this->stringToInt[key] = numVertices;
      (this->numVertices)++;
    }

    this->adjList[key]->push_back(make_pair(neighbor, distance));

  }

  this->newAdjList = new graphList[numVertices];

  graphNode* newVertex; 

  /*
  for(int i = 0; i < numVertices; i++){
    newVertex = new graphNode();
    this->newAdjList[i];

  }
  */


  cout << this->numVertices << endl;
  //  cout << this->lookupTable[0] << " " << this->lookupTable[numVertices - 1] << endl;
}
