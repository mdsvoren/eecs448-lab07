/**
*	@author
*	@date
*	@file main.cpp
*	@brief driver for LinkedList demo
*/
#include <iostream>
//#include "LinkedListOfInts.h"
#include "testSuite.h"

int main(int argc, char** argv)
{
	std::cout << "\nStarting tests.\n\n";

	testSuite t1;
	t1.run();

	std::cout << "\nFinished.\n\n";

	return (0);

}
