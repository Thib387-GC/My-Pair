#include "main.h"
#include "MyPair.hpp"
#include <iostream>
#include "Node.hpp"
#include "Iterator.hpp"

#include "Vector.hpp"

int main()
{



	Vector<int> yopVect ;

	yopVect.pushBack(70);
	std::cout << yopVect.Size() << "\n";

	yopVect.pushBack(400);

	std::cout << yopVect.Size() << "\n";
	yopVect.pushBack(450);
	std::cout << yopVect.Size() << "\n";

	std::cout << yopVect[0]<< " " << yopVect[1] << " "<< yopVect[2] << yopVect[3];

	return 0;
}
