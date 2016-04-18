#include <iostream>
#ifdef WIN32
#include <windows.h>
#else
#include <stdio.h>
#endif
#include <vector>
#include "Map.hpp"

//using namespace std;

#define EMPTY -1
#define OBSTACLE -2

#define PATH 900
#define START 901
#define FINISH 902


	Map::Map(int sizeX, int sizeY, std::vector<std::vector<int> > map)
	{
		this->sizeX = sizeX;
		this->sizeY = sizeY;
		m = map;
	}

	Map::~Map()
	{}

	void Map::getSizes(int* sizeX, int* sizeY)
	{
		(*sizeX) = this->sizeX;
		(*sizeY) = this->sizeY;
	}

    void Map::print()
	{
		for (int x=0; x<sizeX+2; ++x)			
			std::cout <<"X";			
#ifdef WIN32
		HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
		for (int y=0; y<sizeY; ++y)
		{
			std::cout <<std::endl<<"X";
			for (int x=0; x<sizeX; ++x)
			{
				switch (m[x][y])
				{
				case EMPTY:
					std::cout <<" ";
					break;

				case OBSTACLE:
					std::cout <<"|";					
					break;	

				case START:
					SetConsoleTextAttribute(hconsole,30);
					std::cout <<"S";
					SetConsoleTextAttribute(hconsole,15);							
					break;

				case FINISH:
					SetConsoleTextAttribute(hconsole,30);
					std::cout <<"F";
					SetConsoleTextAttribute(hconsole,15);							
					break;

				case PATH:
					SetConsoleTextAttribute(hconsole,BACKGROUND_GREEN);
					std::cout <<" ";
					SetConsoleTextAttribute(hconsole,15);				
					break;

				default:
					std::cout <<"?";					
					break;	
				}				
			}
			std::cout <<"X";
		}
#else

///////////////////////////////////
////        Linux
//// \033[22;30m is black
//// \033[22;31m is red
//// \033[22;32m is green
///////////////////////////////////
		for (int y=0; y<sizeY; ++y)
		{
			std::cout <<std::endl<<"X";
			for (int x=0; x<sizeX; ++x)
			{
				switch (m[x][y])
				{
				case EMPTY:
					//std::cout <<" ";
					printf("\033[22;30mO");
					break;

				case OBSTACLE:
					//std::cout <<"|";
					printf("\033[22;30m|");					
					break;	

				case START:
					//SetConsoleTextAttribute(hconsole,30);
					//std::cout <<"S";
					printf("\033[22;30mS");	
					//SetConsoleTextAttribute(hconsole,15);							
					break;

				case FINISH:
					//SetConsoleTextAttribute(hconsole,30);
					//std::cout <<"F";
					printf("\033[22;30mF");
					//SetConsoleTextAttribute(hconsole,15);							
					break;

				case PATH:
					//SetConsoleTextAttribute(hconsole,BACKGROUND_GREEN);
					//std::cout <<" "; 
					printf("\033[22;32mX");
					//SetConsoleTextAttribute(hconsole,15);				
					break;

				default:
					//std::cout <<"?";	
					printf("\033[22;30m?");				
					break;	
				}				
			}
			std::cout <<"X";
		}

#endif
		std::cout <<std::endl;
		for (int x=0; x<sizeX+2; ++x)			
			std::cout <<"X";

	}
		
