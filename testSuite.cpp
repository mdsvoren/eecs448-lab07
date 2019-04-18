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
  std::cout << "testToVector: Guarenteed to be fully functional";
}


bool testSuite::testAddBack()
{
  //need to test that it increments m_size
  //need to test that it adds the correct value
  //see if it can handle a large list
  LinkedListOfInts testableList;

  bool pass = true;

  //test if starting from nothing
  testableList.addBack(5);
  if (testableList.size()==1)
  {
    std::cout << "testAddBack: Correctly increments m_size from 0\n";
  }
  else
  {
    pass = false;    
    std::cout << "FAIL: testAddBack: Fails to increments m_size from 0\n";

  }

  if (!testableList.search(5))
  {
    std::cout << "FAIL: testAddBack: addBack stored incorrect value\n";
    pass = false;
  }
  else
  {
    std::cout << "testAddBack: addBack stored correct value\n";
  }

  //test high numbers (large list)
  LinkedListOfInts t1;
  for (int i = -4; i< 999995; i++)
  {
    t1.addBack(i);
  }

  if (t1.size()!=99999)
  {
    std::cout << "FAIL: testAddBack: Fails to increments m_size for large lists\n";
    pass=false;
  }
  else
  {
    std::cout << "testAddBack: Correctly increments m_size for large lists\n";
  }

  found = true;
  for (int i=-4; i<999995; i++)
  {
    if (!t1.search(i))
    {
      std::cout << "FAIL: testAddBack: Fails to insert correct value for large lists\n";
      pass = false;
      found = false;
      break;
    }
  }
  if (found)
  {
      std::cout << "testAddBack: Correctly inserts values for large lists\n";
  }

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
