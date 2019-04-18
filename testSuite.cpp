#include <iostream>
#include "LinkedListOfInts.h"
#include "testSuite.h"


//constructor
testSuite::testSuite()
{

}

void testSuite::run()
{
  testCreation();
}

bool testSuite::testCreation()
{
  try
  {
    LinkedListOfInts testableList;
    std::cout<<"Creating empty list succeeded.\n";
    return true;
  }
  catch(int e)
  {
    std::cout<<"Creating empty list failed.\n";
  }
  return false;

}
