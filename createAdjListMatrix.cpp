//####################################################
//#
//#
//#  Create an adjacency list and matrix
//#
//####################################################

#include <iostream>
#include <string>


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
    

    addEdgeList(ListData, 0, 1); // mum -> del
    addEdgeMatrix(MatData, 0, 1);

    addEdgeList(ListData, 0, 2); // mum -> chennai
    addEdgeMatrix(MatData, 0, 2);

    addEdgeList(ListData, 1, 0); // del -> mum
    addEdgeMatrix(MatData, 1, 0);

    addEdgeList(ListData, 2, 3); // chennai -> pune
    addEdgeMatrix(MatData, 2, 3);

    addEdgeList(ListData, 3, 4); // del -> mum
    addEdgeMatrix(MatData, 3, 4);

    addEdgeList(ListData, 4, 5); // pune -> kolkata
    addEdgeMatrix(MatData, 4, 5);

    addEdgeList(ListData, 5, 3); // bengaluru -> pune
    addEdgeMatrix(MatData, 5, 3);

    DisplayAdjList(ListData);
    DisplayAdjMat(MatData, NUM_CITIES);

    return 0;

}