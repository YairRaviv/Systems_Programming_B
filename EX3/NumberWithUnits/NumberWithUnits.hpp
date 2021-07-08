#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <stdexcept>
#include <cfloat>



#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <utility>
#include <tuple>


using namespace std;

namespace ariel
{
   




    /////////////////////////////////////////////node/////////////////////////////////////////////
    class Node {

private:

  //neighborMap: List of Nodes that this node has an edge to
  std::unordered_map<std::string, std::multiset<double>>* neighborMap;
  //neighborSet: List of Nodes that have an edge to this Node
  std::unordered_set<std::string> neighborOfSet;

public:
double data;
  std::string name;
  Node(double data, std::string name);
  ~Node();

  void addNeighbor(std::string neighborName, double weight);

  //Access
  double getData();
  std::unordered_map<std::string, std::multiset<double>>* getMapPtr();
  std::unordered_set<std::string>& getSetRef();
};




///////////////////////////////////////////////////////graph////////////////////////////////////////////////////////////


class Graph {

private:
  bool directed = true;
  std::unordered_map<std::string, Node*> nodeMap; 
public:      
  //Constructors & Destructor
  Graph(); //Graphs are directed by default
  Graph(bool directed);
  Graph(const Graph& other); //Copy-Constructor, uses getEdges function
  Graph(std::string inputFileName); //Constructs Graph from .txt file
  ~Graph();

  //Trivial Functions
  bool addNode(double data, std::string name);
  double getNode_data(std::string name);
  bool addNode(std::string name); //Default data-value '1'
  void addNodes(std::vector<std::string> nodes);
  void addNodes(std::vector<std::pair<double, std::string>> nodes);
  bool addEdge(std::string fromNode, std::string toNode, double weight);
  bool addEdge(std::string fromNode, std::string toNode); //Default weight '1'
  bool addEdge(std::tuple<std::string, std::string, double> edge);
  bool deleteNode(std::string targetNode);
  bool deleteEdge(std::string fromNode, std::string toNode, double weight);
  bool deleteEdge(std::string fromNode, std::string toNode); //Default weight '1'

  //Undirected Graph Specific Functions
  bool connected(); //Is the Graph connected?

  //Directed Graph Specific Functions
  bool weaklyConnected() const; //Is the Graph weakly connected?
  bool stronglyConnected();

  //Modification Functions
  Graph transpose() const; //Creates a copy, reverses edges of that copy and returns it.

  //Neighbor Functions
  std::vector<std::string> neighborNames(std::string name);
  std::vector<std::pair<std::string, double>> neighborDistMin(std::string name);
  std::vector<std::pair<std::string, double>> neighborDistMax(std::string name);
  bool deleteNeighbors(std::string name);

  //Explore Functions
  std::unordered_set<std::string> explore(std::string sourceNode); //Returns a set of Nodes reachable from the source Node
  void exploreHelper(std::unordered_set<std::string> &visited, std::string name);
  std::vector<std::string> reachableNames(std::string sourceNode); //Returns a list of Nodes that are reachable from the target
  std::vector<std::pair<std::string, double>> reachableDists(std::string sourceNode); //Includes distances
  bool pathCheck(std::string fromNode, std::string toNode);

  //Core Graph Functions
  std::vector<std::string> BFS(std::string sourceNode, std::string targetNode); //Returns the shortest path from source to target
  std::vector<std::string> DFS(std::string sourceNode, std::string targetNode); //Returns the shortest path from source to target
  void DFShelper(std::string sourceNode, std::string targetNode, std::unordered_map<std::string, std::string> &prevMap);
  std::vector<std::string> Dijktras(std::string sourceNode, std::string targetNode); //Returns the shortest path from source to target
  std::unordered_map<std::string, double> Dijktras(std::string sourceNode); //Returns a map where keys are nodes reachable from source and values are the shortest distance from source

  //BellmanFord: Returns a 3-tuple containing the Dist and Prev maps, as well as a boolean for the existence of a negative cycle
  std::tuple<std::unordered_map<std::string, double>, std::unordered_map<std::string, std::string>, bool> BellmanFord(std::string sourceNode);
  std::unordered_map<std::string, double> BellmanFordDist(std::string sourceNode); //Returns just the Dist map
  std::unordered_map<std::string, std::string> BellmanFordPrev(std::string sourceNode); //Returns just the Prev map
  bool NegativeCycle(); //Does the graph contain a negCycle? Warning!: Exponential Run-Time

  //MST Functions
  Graph Prims();
  Graph Kruskals();

  //About Graph Functions
  std::string getInfo(); //Returns a list of all Nodes along with their Edges.
  std::vector< std::tuple<std::string, std::string, double> > getEdges() const; //Returns a vector of Edges, where Edges are represented with a 3-tuple (nodeA,nodeB,weight)
  std::vector< std::tuple<std::string, std::string, double> > getEdgesAscending() const;
  std::vector< std::tuple<std::string, std::string, double> > getEdgesDescending() const;
  int numNodes(); //Returns the number of Nodes
  int numEdges();
  bool nodeExists(std::string node); //Is the Node in the Graph?

  //Persistent Graph Functions
  bool saveGraph(std::string outputFileName);

};






















/////////////////////////////////////////////////////////////////////
 class NumberWithUnits
    {
        public:
            static ariel::Graph Units;

            string type;
            double sum;
            //constructor
            explicit NumberWithUnits(double sum=0,string type="");
            static void read_units(ifstream& units_file);
            
            //set object
            friend istream& operator>>(istream& os , NumberWithUnits& a);
            //stream object
            friend ostream& operator<<(ostream& os,const NumberWithUnits& a);

            //aritmethic opertors inside class
            NumberWithUnits& operator+=(const NumberWithUnits& b);
            NumberWithUnits& operator-=(const NumberWithUnits& b);
            NumberWithUnits operator++(int a);
            NumberWithUnits operator--(int a);
            friend NumberWithUnits operator*(NumberWithUnits a , double d);
            friend NumberWithUnits operator*(NumberWithUnits a , int d);
            friend const NumberWithUnits operator+(const NumberWithUnits& a, const NumberWithUnits& b);
            friend const NumberWithUnits operator-(const NumberWithUnits& a, const NumberWithUnits& b);
            
            friend const NumberWithUnits operator+(NumberWithUnits a);
            friend const NumberWithUnits operator-(NumberWithUnits a);
            friend NumberWithUnits& operator++(NumberWithUnits& a);
            friend NumberWithUnits& operator--(NumberWithUnits& a);

            
            
            //mult opertors
            friend NumberWithUnits operator*(double d,NumberWithUnits a);
            friend NumberWithUnits operator*(int d,NumberWithUnits a);
            //comparison operators
            friend bool operator>(const NumberWithUnits& a, const NumberWithUnits& b);
            friend bool operator>=(const NumberWithUnits& a, const NumberWithUnits& b);
            friend bool operator<(const NumberWithUnits& a, const NumberWithUnits& b);
            friend bool operator<=(const NumberWithUnits& a, const NumberWithUnits& b);
            friend bool operator==(const NumberWithUnits& a, const NumberWithUnits& b);
            friend bool operator!=(const NumberWithUnits& a, const NumberWithUnits& b);


             bool operator>(const NumberWithUnits& a);
             bool operator>=(const NumberWithUnits& a);
             bool operator<(const NumberWithUnits& a);
             bool operator<=(const NumberWithUnits& a);
             bool operator==(const NumberWithUnits& a);
             bool operator!=(const NumberWithUnits& a);

    };

}

