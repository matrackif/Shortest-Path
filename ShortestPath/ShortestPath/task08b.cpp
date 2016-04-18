#include "Map.hpp"
#include <queue>
#include <stack>
#include <limits>
#include <vector>
	/*
	Finds the shortest path between 'from' and 'to'.
	We can move only one step in each of 8 directions direction (vertically, horizontally or
	diagonally) as long as we stay inside the board.
	We cannot pass through obstacles.

	Fields that are on the shortest path, should be marked as PATH fields.
	Do not change OBSTACLE, START and FINISH fields.
	
	Returns:
	The length of the shortest path between START and FINISH
	(number of edges, i.e. if 'from'='to', then returns 0)
	-1 if the path does not exist

	Points:
	2 : proper distinguishing between existing/non-existing path
	3 : proper length of the shortest path
	4 : everything ok
	*/
typedef struct _Point{
	int x;
	int y;
}Point;

Point minPoint(std::vector<std::vector<int> > dis,std::vector<std::vector<bool> > vis,int sizeX,int sizeY)//returns the the point with the minimum distance value that has not yet been visited
{	
	int min = std::numeric_limits<int>::max();
	Point minPoint;
	minPoint.x = 0;
	minPoint.y = 0;
	for (int i = 0; i < sizeX; i++)
		for (int j = 0; j < sizeY; j++)
		{
			if (dis[i][j] < min && vis[i][j] == false)
			{
				min = dis[i][j];
				minPoint.x = i;
				minPoint.y = j;
			}
		}
	return minPoint;
}

std::vector<Point> getNeighbors(Map* m, Point p){

	//////////////////////////////////////////////////////////////////////////
	//////////Here we find all 8 possible neighbors of a given point//////////
	//////////////////////////////////////////////////////////////////////////
	std::vector<Point> neighbors;
	int sizeX;
	int sizeY;
	m->getSizes(&sizeX,&sizeY);
	if(p.x - 1 >= 0 && p.y -1 >= 0 && (*m)[p.x-1][p.y-1] != OBSTACLE)
	{
		Point pt;
		pt.x = p.x-1;
		pt.y = p.y-1;  //upper left
		neighbors.push_back(pt);
	}
	if(p.x - 1 >= 0  && (*m)[p.x-1][p.y] != OBSTACLE)
	{
		Point pt2;
		pt2.x = p.x-1;
		pt2.y = p.y;  //left
		neighbors.push_back(pt2);
	}
	if(p.x - 1 >= 0 && p.y +1 < sizeY  && (*m)[p.x-1][p.y+1] != OBSTACLE)
	{
		Point pt3;
		pt3.x = p.x-1;
		pt3.y = p.y+1; //lower left
		neighbors.push_back(pt3);
	}
	if( p.y +1 < sizeY  && (*m)[p.x][p.y+1] != OBSTACLE)
	{
		Point pt4;
		pt4.x = p.x; //bottom
		pt4.y = p.y+1;
		neighbors.push_back(pt4);
	}
	if(/*p.x + 1 >= 0 && p.y + 1 >= 0 &&*/ p.x+1 <sizeX && p.y+1 <sizeY && (*m)[p.x+1][p.y+1] != OBSTACLE)
	{
		Point pt5;
		pt5.x = p.x+1;
		pt5.y = p.y+1; //bottom right
		neighbors.push_back(pt5);
	}
	if(/*p.x +1  >= 0 && */p.x+1 < sizeX && (*m)[p.x+1][p.y] != OBSTACLE)
	{
		Point pt6;
		pt6.x = p.x+1; //right
		pt6.y = p.y;
		neighbors.push_back(pt6);
	}
	if(/*p.x + 1 >= 0 && */p.x+1 < sizeX &&  p.y -1 >= 0 && (*m)[p.x+1][p.y-1] != OBSTACLE)
	{
		Point pt7;
		pt7.x = p.x+1; 
		pt7.y = p.y-1; //upper right
		neighbors.push_back(pt7);
	}
	if( p.y -1 >= 0 &&  (*m)[p.x][p.y-1] != OBSTACLE)
	{
		Point pt8;
		pt8.x = p.x; //top
		pt8.y = p.y-1;
		neighbors.push_back(pt8);
	}
	return neighbors;
	
}

std::vector<Point> getReachablePoints(Map* m, Point p) // this function is essentially DFS (depth-first search) in which we return all reachable points from the Point p
{
	
	int sizeX = 0;
	int sizeY = 0;
	m->getSizes(&sizeX,&sizeY);
	//int n = sizeX*sizeY;
	std::vector<Point> solution;
	std::vector<std::vector<bool> > visited;
	std::stack<Point> s;
	std::vector<int>::iterator j;
	Point w;
	for(int i = 0; i < sizeX; i++)
	{
		std::vector<bool> newRow;
		visited.push_back(newRow);
		for(int j = 0; j<sizeY; j++){
			visited[i].push_back(false);
		}
	}
	visited[p.x][p.y] = true;
	s.push(p);
	while(!s.empty())
	{
		w = s.top();
		s.pop();
		solution.push_back(w);
		std::vector<Point> neighbors = getNeighbors(m,w);
		for(unsigned int j = 0; j <neighbors.size(); j++)
		{
			if(!visited[neighbors[j].x][neighbors[j].y])
			{
			  visited[neighbors[j].x][neighbors[j].y] = true;
			  s.push(neighbors[j]);
			}
		}
	}
	return solution;
}

int Map::findPath(int* from, int* to)
{
	//int len = -2;
	int sizeX;
	int sizeY;
	this->getSizes(&sizeX,&sizeY);
	Point start;
	start.x = from[0];
	start.y = from[1];

	Point finish;
	finish.x = to[0];
	finish.y = to[1];

	if (start.x == finish.x && start.y == finish.y)
	{
		std::cout  <<std::endl<< "The starting point is the same as the destination point!" << std::endl;
		return 0;
	}

	/*In the following loop we check if a point is reachable before we calculate the shortest path*/
	bool reachable = false;
	std::vector<Point> reachablePoints = getReachablePoints(this,start);
	for (unsigned int j = 0; j < reachablePoints.size(); j++)
	{
		if (finish.x == reachablePoints[j].x && finish.y == reachablePoints[j].y)
		{
			reachable = true;
			break;
		}
	}
	if (!reachable)
	{
		std::cout  <<std::endl << "Destination  is NOT reachable from the source !"<< std::endl;
		return -1;
	}
	
	std::vector<std::vector<bool> > visited(sizeX, std::vector<bool>(sizeY,false));//2D std::vector of size [sizeX][sizeY], at the beginning we have not visited any vertex so every value is initialized to false

	////// This will compile also on Linux
	int maxInteger = std::numeric_limits<int>::max();
	std::vector<std::vector<int> > dist(sizeX, std::vector<int>(sizeY, maxInteger));//represents the minimum cost to get to a point from a given point. This array is is updated as we find new connections to points. We assume distance to every point except starting point is infinity (minInteger)
	std::vector<std::vector<Point> > prev(sizeX, std::vector<Point>(sizeY, start));//This 2D array of points stores the previous good point on the shortest path, we use this to backtrack from the finish to start and recreate the path
	int minDist;
	Point currentPoint;
	dist[start.x][start.y] = 0; // the distance to reach the starting point is 0
	/*
	for (int i = 0; i < sizeX; i++)
	{
		std::vector<int> newRow;
		std::vector<Point> newPointRow;
		std::vector<bool> newBoolRow;
		dist.push_back(newRow);
		visited.push_back(newBoolRow);
		prev.push_back(newPointRow);
		for(int j = 0; j < sizeY; j++)
		{
		if (start.x == i && start.y == j){
			dist[i].push_back(0);
			visited[i].push_back(false);                          
			prev[i].push_back(start);
		}
		else{
			dist[i].push_back(INT_MAX);
			visited[i].push_back(false);
			prev[i].push_back(start); 
		}
		}
		
	}
	*/
	
	
	//The core of Dijkstra's algorithm
	
	while (!visited[finish.x][finish.y])
	{
		currentPoint = minPoint(dist,visited,sizeX,sizeY); //returns the the point with the minimum distance value that has not yet been visited	
		visited[currentPoint.x][currentPoint.y] = true;  
		std::vector<Point> currentNeighbors = getNeighbors(this,currentPoint); 
		for (unsigned int i = 0; i<currentNeighbors.size(); i++)//loop through all the neighbors of the current point and update the min distance to reach them
		{		
			minDist = dist[currentPoint.x][currentPoint.y] + 1;//getWeight(currentVertex, *it);
			if (minDist < dist[currentNeighbors[i].x][currentNeighbors[i].y]) //if this if-statement is true it means we found a new shortest path to the given point
			{
				dist[currentNeighbors[i].x][currentNeighbors[i].y] = minDist;
				prev[currentNeighbors[i].x][currentNeighbors[i].y] = currentPoint;
			}
			
		}
	}
	for (int i = finish.x, j = finish.y;;)
	{
		if (prev[i][j].x == start.x && prev[i][j].y == start.y)
			break;
		m[prev[i][j].x][prev[i][j].y] = PATH;
		int temp = i; //this temp is necessary so i does not change when we evaluate prev[i][j]
		i = prev[i][j].x;
		j = prev[temp][j].y;
	}

	

	return dist[finish.x][finish.y]; //This is the path length (amount of steps we took) to reach the finish. It is the shortest possible path length
}
