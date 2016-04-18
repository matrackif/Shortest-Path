#include "Map.hpp"
#ifndef WIN32
#include <stdexcept> 
#endif


void Example1()
{
	int len;
	std::vector<std::vector<int> > lab;
	int sizeX = 10;
	int sizeY = 15;
	int start[2] = {1,1};
	int finish[2] = {8,10};
	
	lab.resize(sizeX);
	for (int i=0; i<sizeX;++i)	
		lab[i].assign(sizeY, EMPTY);

	lab[start[0]][start[1]]=START;
	lab[finish[0]][finish[1]]=FINISH;
		

	Map m(sizeX, sizeY,lab);

	std::cout <<std::endl<<std::endl<<"-----------Example 1-------------"<<std::endl<<std::endl;
	//m.print();
	
	try{
	    std::cout << "calling m.findPath" << std::endl;
		len = m.findPath(start, finish);
	}
	catch (std::invalid_argument e){
		std::cout  << e.what() << std::endl;
	}
	std::cout <<std::endl<<std::endl;
	std::cout << "Printing now ..." << std::endl;
	m.print();

	std::cout <<std::endl<<"Path length: "<<len<<std::endl<<std::endl;	
}

void Example2()
{
	int len;
	std::vector<std::vector<int> > lab;
	int sizeX = 15;
	int sizeY = 10;
	int start[2] = {1,1};
	int finish[2] = {1,1};
	
	lab.resize(sizeX);
	for (int i=0; i<sizeX;++i)	
		lab[i].assign(sizeY, EMPTY);

	lab[start[0]][start[1]]=START;
	lab[finish[0]][finish[1]]=FINISH;
	
	for (int i=0; i<sizeY; ++i)
		if (i!=4)
			lab[2][i]=OBSTACLE;

	for (int i=0; i<sizeY; ++i)
			lab[4][i]=OBSTACLE;


	for (int i=0; i<sizeY; ++i)
		if (i!=2)
			lab[6][i]=OBSTACLE;

	

	Map m(sizeX, sizeY,lab);

	std::cout <<std::endl<<std::endl<<"-----------Example 2-------------"<<std::endl<<std::endl;
	//m.print();
	try{
		len = m.findPath(start, finish);
	}
	catch (std::invalid_argument e){
		std::cout  << e.what() << std::endl;
	}
	std::cout <<std::endl<<std::endl;
	m.print();

	std::cout <<std::endl<<"Path length: "<<len<<std::endl<<std::endl;

}


void Example3()
{
	int len;
	std::vector<std::vector<int> > lab;
	int sizeX = 14;
	int sizeY = 10;
	int start[2] = {1,1};
	int finish[2] = {12,7};
	lab.resize(sizeX);
	for (int i=0; i<sizeX;++i)	
		lab[i].assign(sizeY, EMPTY);

	lab[start[0]][start[1]]=START;
	lab[finish[0]][finish[1]]=FINISH;
	
	for (int i=0; i<sizeY; ++i)
		if (i!=4)
			lab[2][i]=OBSTACLE;

	for (int i=0; i<sizeY; ++i)
		if (i!=6)
			lab[4][i]=OBSTACLE;


	for (int i=0; i<sizeY; ++i)
		if (i!=2)
			lab[6][i]=OBSTACLE;

	

	Map m(sizeX, sizeY,lab);

	std::cout <<std::endl<<std::endl<<"-----------Example 3-------------"<<std::endl<<std::endl;
	//m.print();
	
	try{
		len = m.findPath(start, finish);
	}
	catch (std::invalid_argument e){
		std::cout  << e.what() << std::endl;
	}
	std::cout <<std::endl<<std::endl;
	m.print();

	std::cout <<std::endl<<"Path length: "<<len<<std::endl<<std::endl;	
}


void Example4()
{
	int len;
	std::vector<std::vector<int> > lab;
	int sizeX = 10;
	int sizeY = 10;
	int start[2] = {1,1};
	int finish[2] = {8,8};
	lab.resize(sizeX);
	for (int i=0; i<sizeX;++i)	
		lab[i].assign(sizeY, EMPTY);

	lab[start[0]][start[1]]=START;
	lab[finish[0]][finish[1]]=FINISH;
	
	for (int i=0; i<sizeY; ++i)
		if (i!=4)
			lab[2][i]=OBSTACLE;

	for (int i=0; i<sizeY; ++i)
			lab[4][i]=OBSTACLE;


	for (int i=0; i<sizeY; ++i)
		if (i!=2)
			lab[6][i]=OBSTACLE;

	

	Map m(sizeX, sizeY,lab);

	std::cout <<std::endl<<std::endl<<"-----------Example 4-------------"<<std::endl<<std::endl;
	//m.print();
	
	try{
		len = m.findPath(start, finish);
	}
	catch (std::invalid_argument e){
		std::cout  << e.what() << std::endl;
	}
	std::cout <<std::endl<<std::endl;
	m.print();

	std::cout <<std::endl<<"Path length: "<<len<<std::endl<<std::endl;


}



void Example5()
{
	int len;
	std::vector<std::vector<int> > lab;
	int sizeX = 11;
	int sizeY = 14;
	int start[2] = {1,1};
	int finish[2] = {3,1};
	lab.resize(sizeX);
	for (int i=0; i<sizeX;++i)	
		lab[i].assign(sizeY, EMPTY);

	lab[start[0]][start[1]]=START;
	lab[finish[0]][finish[1]]=FINISH;
	
	for (int i=0; i<sizeY; ++i)
		if (i!=4)
			lab[2][i]=OBSTACLE;

	for (int i=0; i<sizeY; ++i)
			lab[4][i]=OBSTACLE;


	for (int i=0; i<sizeY; ++i)
		if (i!=2)
			lab[6][i]=OBSTACLE;

	

	Map m(sizeX, sizeY,lab);

	std::cout <<std::endl<<std::endl<<"-----------Example 5-------------"<<std::endl<<std::endl;
	//m.print();
	
	len = m.findPath(start, finish);
	std::cout <<std::endl<<std::endl;
	m.print();

	std::cout <<std::endl<<"Path length: "<<len<<std::endl<<std::endl;

}

int main()
{	
	Example1();
	Example2();
	Example3();
	Example4();
	Example5();

	std::cout <<std::endl<<std::endl;
#ifdef WIN32
	system("pause");
#endif	
	return 0;
}
