#include <iostream>

#include <vector>

//using namespace std;

#define EMPTY -1
#define OBSTACLE -2

#define PATH 900
#define START 901
#define FINISH 902


class Map
{
private:	
	int sizeX;
	int sizeY;
	std::vector<std::vector<int> > m;

public:

	Map(int sizeX, int sizeY, std::vector<std::vector<int> > map);

    void getSizes(int* sizeX, int* sizeY);

	std::vector<int> operator[](int x)
	{
		return m[x];
	}

	~Map();

	void print();
		
	int findPath(int* from, int* to);	
};
