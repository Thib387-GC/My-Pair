#include "main.h"
#include "MyPair.hpp"
#include <iostream>
#include "Node.hpp"
#include "Iterator.hpp"

#include "Vector.hpp"

int main()
{



	Vector<int>* yopVect = new Vector<int>;

	yopVect->pushBack(70);
	std::cout << yopVect->Size() << "\n";
	std::cout << yopVect->Size() << "\n";

	std::cout << yopVect[0] << " " << yopVect[1];

	return 0;
}
