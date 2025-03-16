//####################################################
//#
//#
//#  Create an adjacency list and matrix
//#  1 . use DFS , BFS to get conn components
//#
//####################################################

#include <iostream>
#include <string>
#include <queue>


using namespace std;

#define NUM_CITIES 6
string cities[NUM_CITIES] = {"Mumbai , Delhi ,Chennai, Pune, Kolkata, Bengaluru"};


// Simply add an edge to the list of cities
void addEdgeList(vector<vector<int> >& AdjList, int source, int destination)
{
	// time to add new edge
	if(source > AdjList.size())
	{
		std::cout << "Incorrect source city!" << std::endl;
	    exit(1);	
	}
	AdjList[source].push_back(destination);
}

// Perform a DFS on a vertex
void DFSDriver(vector<vector<int> >& AdjList, int vertex, vector<bool>& visited)
{
    // Mark the current node as visited and print it
    visited[vertex] = true;
    cout << vertex << " ";
 
    for (int i = 0;i < AdjList[vertex].size(); i++)
    {
        if (!visited[AdjList[vertex][i]])
        {
            DFSDriver(AdjList, AdjList[vertex][i], visited);
        }
    }
}


// BFS from given vertex
void BFSDriver(vector<vector<int> >& AdjList, int vertex, vector<bool>& visited) {
    queue<int> queueData; 

    // Mark source node as visited and enqueue it
    visited[vertex] = true;
    queueData.push(vertex);

    // Iterate over the queue
    while (!queueData.empty()) {
        int curr = queueData.front(); 
        queueData.pop();
        cout << curr << " ";
        for (int x : AdjList[curr]) {
            if (visited[x] == false) {
                visited[x] = true;
                queueData.push(x);
            }
        }
    }
}

// Method to print connected components in an
// undirected graph using BFS
void connectedComponentsBFS(vector<vector<int> >& AdjList)
{
    // Mark all the vertices as not visited
    vector<bool> visited;
    for (int vertex = 0; vertex < AdjList.size(); vertex++)
        visited.push_back(false);
 
    for (int vertex = 0; vertex < AdjList.size(); vertex++) {
        if (visited[vertex] == false) {
            // print all reachable vertices
            // from vertex
            BFSDriver(AdjList, vertex, visited);
 
            cout << "\n";
        }
    }
}

// Method to print connected components in an
// undirected graph using DFS
void connectedComponentsDFS(vector<vector<int> >& AdjList)
{
    // Mark all the vertices as not visited
    vector<bool> visited;
    for (int vertex = 0; vertex < AdjList.size(); vertex++)
        visited.push_back(false);
 
    for (int vertex = 0; vertex < AdjList.size(); vertex++) {
        if (visited[vertex] == false) {
            // print all reachable vertices
            // from vertex
            DFSDriver(AdjList, vertex, visited);
 
            cout << "\n";
        }
    }
}



// Simply add an edge to the matrix of cities
// !! NOTE : There is no concept of self edge to a city here !!
void addEdgeMatrix(vector<vector<int> >& AdjMat, int source, int destination)
{
	// time to add new edge
	AdjMat[source][destination] = 1;
}

// Display the entire adjacency list !
void DisplayAdjList(vector<vector<int> >& AdjList)
{
	std::cout << " BEGIN Display of Adjacency list " << endl;
	for(int source=0;source < AdjList.size();source++)
	{
		std::cout << source << ": ";
        for(int dest=0;dest < AdjList[source].size();dest++)
        {
            std::cout << AdjList[source][dest] << ",";
        }
        std::cout << endl;
	}
	std::cout << " END Display of Adjaceny list " << endl;
}

// Display the entire adjacency matrix !
void DisplayAdjMat(vector<vector<int> > Adjmat, int number_of_cities)
{
	std::cout << " BEGIN Display of Adjacency matrix " << endl;
	for(int source=0;source < number_of_cities;source++)
	{
        std::cout << source << ":";
        for(int dest=0;dest < number_of_cities;dest++)
        {
            std::cout << Adjmat[source][dest] << ",";
        }
        std::cout << endl;
	}
	std::cout << " END Display of Adjaceny matrix " << endl;
}

int main()
{

    vector<vector<int> > ListData(NUM_CITIES);
    vector<vector<int> > MatData(NUM_CITIES);
    for(int i=0;i< NUM_CITIES;i++)
    {
    	MatData[i].insert(MatData[i].begin(), NUM_CITIES, 0);
    }
    

    addEdgeList(ListData, 0, 1);
    addEdgeMatrix(MatData, 0, 1);

    addEdgeList(ListData, 0, 2);
    addEdgeMatrix(MatData, 0, 2);

    addEdgeList(ListData, 1, 2);
    addEdgeMatrix(MatData, 1, 2);

    addEdgeList(ListData, 3, 4);
    addEdgeMatrix(MatData, 3, 4);

    addEdgeList(ListData, 3, 5);
    addEdgeMatrix(MatData, 3, 5);

    addEdgeList(ListData, 4, 5);
    addEdgeMatrix(MatData, 4, 5);


    DisplayAdjList(ListData);
    DisplayAdjMat(MatData, NUM_CITIES);

    std::cout << " Begin Connected Components using DFS ! " << endl;
    connectedComponentsDFS(ListData);
    std::cout << " End Connected Components using DFS ! " << endl;

    std::cout << " Begin Connected Components using BFS ! " << endl;
    connectedComponentsBFS(ListData);
    std::cout << " End Connected Components using BFS ! " << endl;

    return 0;

}