// Isaac Goldman HW7 Problem 3

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <list>

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
  void findNeighbors(string vertex, list<string>* neighbors);
  void distThreeNeighbors(string vertex);

private: 
  Graph();
  map<string, list<string>* > adjList; // map container for adjacency list to represent the graph
  int numVertices;
  int numEdges;


};

// custom constructor instantiates a graph object from a list of vertices and edges from an input file
Graph::Graph(const char* fileName){ 

  string key, neighbor;
  ifstream inputFile(fileName);

  // uses the first line of the file to define the number of vertices and number of edges
  // NOTE: This works for any file format based on the format of the provided flights.txt which has the number of vertices and number of edges in the first line of the file
  inputFile >> this->numVertices >> this->numEdges;

  for(int i = 0; i < this->numVertices; i++){
    inputFile.ignore(1000, '\n');
    inputFile >> key;
    this->adjList[key] = new list<string>;
  }

  for(int i = 0; i < numEdges; i++){
    inputFile.ignore(1000, '\n');
    inputFile.ignore(2);
    inputFile >> key >> neighbor;
    this->adjList[key]->push_back(neighbor);
    this->adjList[neighbor]->push_back(key);
    //cout << key << " " << neighbor << endl;
  }
}

void Graph::findNeighbors(string vertex, list<string>* nextDoorNeighbors){
  // list<string>* nextDoorNeighbors = new list<string>;
  if(!this->adjList[vertex]->empty()){
    for(list<string>::iterator it = this->adjList[vertex]->begin(); it != this->adjList[vertex]->end(); ++it){
      nextDoorNeighbors->push_back(*it);
    }
  }
  // return nextDoorNeighbors;
}

/*
list<string>* distOneNeighbors(list<string>* vertex){
  list<string>* nextDoorNeighbors = new list<string>;
  for(list<string>::iterator it = vertex->begin(); it != vertex->end(); ++it){
    nextDoorNeighbors->push_back(*it);
  }

  return nextDoorNeighbors;

}
*/

void Graph::distThreeNeighbors(string vertex){
 
  list<string>* dist1Neighbors = new list<string>; 
  this->findNeighbors(vertex, dist1Neighbors);
  //listPrint(dist1Neighbors);
  list<string>* dist2Neighbors = new list<string>;
  list<string>* dist3Neighbors = new list<string>;
  list<string>* totalNeighbors = new list<string>;
  if(!dist1Neighbors->empty()){
    for(list<string>::iterator it = dist1Neighbors->begin(); it != dist1Neighbors->end(); ++it){
      this->findNeighbors(*it, dist2Neighbors);
      totalNeighbors->push_back(*it);
    }
  }


  // listPrint(dist1Neighbors);
  // cout << endl;
  if(!dist2Neighbors->empty()){
    dist2Neighbors->sort();
    dist2Neighbors->unique();
    dist2Neighbors->remove(vertex);
    // listPrint(dist2Neighbors);
    // cout << endl;

    for(list<string>::iterator it = dist2Neighbors->begin(); it != dist2Neighbors->end(); ++it){
      this->findNeighbors(*it, dist3Neighbors);
      totalNeighbors->push_back(*it);
    }
  }

  if(!dist3Neighbors->empty()){
    dist3Neighbors->sort();
    dist3Neighbors->unique();
    dist3Neighbors->remove(vertex);
    //listPrint(dist3Neighbors);

    for(list<string>::iterator it = dist3Neighbors->begin(); it != dist3Neighbors->end(); ++it){
      totalNeighbors->push_back(*it);
    }
  }

  if(!totalNeighbors->empty()){
    totalNeighbors->sort();
    totalNeighbors->unique();
    totalNeighbors->remove(vertex);
    listPrint(totalNeighbors);
  }

}


