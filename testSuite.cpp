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


bool testSuite::testDestructor()
{
  LinkedListOfInts testableList;

}


bool testSuite::testIsEmpty()
{
  LinkedListOfInts testableList;

  bool pass = true;

  if (testableList.isEmpty() == true)
  {
    std::cout << "testIsEmpty: Correctly identifies empty list\n";
  }
  else
  {
    pass = false;
    std::cout << "FAIL: testIsEmpty: incorrectly identifies empty list\n";
  }

  //use both functions just in case one is buggy
  testableList.addBack(4);
  testableList.addFront(3);

  if (testableList.isEmpty() == false)
  {
    std::cout << "testIsEmpty: Correctly identifies non-empty list\n";
  }
  else
  {
    pass = false;
    std::cout << "FAIL: testIsEmpty: incorrectly identifies non-empty list\n";
  }

  return pass;
}


bool testSuite::testSize()
{
  LinkedListOfInts testableList;

  bool pass = true;

  //check 0 size
  if (testableList.size() == 0)
  {
    std::cout << "testSize: Correctly identifies size of empty list\n";
  }
  else
  {
    pass = false;
    std::cout << "FAIL:: testSize: Incorrectly identifies size of empty list\n";
  }

  //check non zero sizes
  bool nonZ = true;
  for (int i = 1; i<4000; i++)
  {
    testableList.addBack(i);
    if (testableList.size()!=i)
    {
      pass = false;
      nonZ = false;
      std::cout << "FAIL:: testSize: Incorrectly identifies size of non-empty list\n";
      break;
    }
  }

  if (!nonZ)
  {
    std::cout << "testSize: Correctly identifies size of non-empty list\n";
  }

  return pass;

}


bool testSuite::testSearch()
{
  LinkedListOfInts testableList;
}


bool testSuite::testToVector()
{
  LinkedListOfInts testableList;
}


bool testSuite::testAddBack()
{
  LinkedListOfInts testableList;
}


bool testSuite::testAddFront()
{
  LinkedListOfInts testableList;
}


bool testSuite::testRemoveBack()
{
  LinkedListOfInts testableList;
}


bool testSuite::testRemoveFront()
{
  LinkedListOfInts testableList;
}
