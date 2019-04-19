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
	//Example of declaring a LinkedListOfInts
	//LinkedListOfInts testableList;

	//You won't do all the tests in main; that's what your Test class will be for
	//Example:
	//testSuite t1 = new testSuite();
	//t1->run();
	//delete t1;

	testSuite t1;
	t1.run();

	std::cout << "Running...\nAnd we're done.\nGoodbye.\n";

	return (0);

}
