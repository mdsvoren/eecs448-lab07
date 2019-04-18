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

  //check non zero sizes with addBack
  bool nonZ = true;
  for (int i = 1; i<4000; i++)
  {
    testableList.addBack(i);
    if (testableList.size()!=i)
    {
      pass = false;
      nonZ = false;
      std::cout << "FAIL:: testSize: Incorrectly identifies size of non-empty list using addBack\n";
      break;
    }
  }

  if (!nonZ)
  {
    std::cout << "testSize: Correctly identifies size of non-empty list using addBack\n";
  }


  //check non zero sizes with addFront
  LinkedListOfInts t1;
  bool non0 = true;
  for (int i = 1; i<4000; i++)
  {
    t1.addBack(i);
    if (t1.size()!=i)
    {
      pass = false;
      non0 = false;
      std::cout << "FAIL:: testSize: Incorrectly identifies size of non-empty list using addFront\n";
      break;
    }
  }

  if (!non0)
  {
    std::cout << "testSize: Correctly identifies size of non-empty list using addFront\n";
  }

  return pass;

}


bool testSuite::testSearch()
{
  LinkedListOfInts testableList;
  bool pass = true;

  //maybe check type of Value?

  //check empty list
  bool found = false;
  for (int i = -100; i<100; i++)
  {
    if (testableList.search(i))
    {
      pass = false;
      found = true;
      std::cout << "FAIL: testSearch: Incorrectly found value in empty list.";
      break;
    }
  }
  if (!found)
  {
    std::cout << "testSearch: Correctly found no value in empty list.";
  }

  //check non empty list
  for (int i= -100; i<100; i++)
  {
    testableList.addFront(i);
  }
  if (!testableList.search(-100))
  {
      pass = false;
      std::cout << "FAIL: testSearch: Failed to find value in list";
  }
  else
  {
    std::cout<< "testSearch: Correctly found negative value in list";
  }

  if (testableList.search(100))
  {
      pass = false;
      std::cout << "FAIL: testSearch: Found item that list doesn't contain";
  }
  else
  {
      std::cout<< "testSearch: Correctly did not find positive value in list";

  }
  if (testableList.search(30000))
  {
      pass = false;
      std::cout << "FAIL: testSearch: Found item that list doesn't contain";
  }
  else
  {
      std::cout<< "testSearch: Correctly did not find very high value in list";

  }
  if (testableList.search(-101))
  {
      pass = false;
      std::cout << "FAIL: testSearch: Found item that list doesn't contain";
  }
  else
  {
    std::cout<< "testSearch: Correctly did not find negative value in list";
  }

  return pass;
  


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
