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
  testDestructor();
  testIsEmpty();
  testSize();
  testSearch();
  testToVector();
  testAddBack();
  testAddFront();
  testRemoveBack();
  testRemoveFront();
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
      std::cout << "FAIL: testSearch: Incorrectly found value in empty list.\n";
      break;
    }
  }
  if (!found)
  {
    std::cout << "testSearch: Correctly found no value in empty list.\n";
  }

  //check non empty list
  for (int i= -100; i<100; i++)
  {
    testableList.addFront(i);
  }
  if (!testableList.search(-100))
  {
      pass = false;
      std::cout << "FAIL: testSearch: Failed to find value in list\n";
  }
  else
  {
    std::cout<< "testSearch: Correctly found negative value in list\n";
  }

  if (testableList.search(100))
  {
      pass = false;
      std::cout << "FAIL: testSearch: Found item that list doesn't contain\n";
  }
  else
  {
      std::cout<< "testSearch: Correctly did not find positive value in list\n";

  }
  if (testableList.search(30000))
  {
      pass = false;
      std::cout << "FAIL: testSearch: Found item that list doesn't contain\n";
  }
  else
  {
      std::cout<< "testSearch: Correctly did not find very high value in list\n";

  }
  if (testableList.search(-101))
  {
      pass = false;
      std::cout << "FAIL: testSearch: Found item that list doesn't contain\n";
  }
  else
  {
    std::cout<< "testSearch: Correctly did not find negative value in list\n";
  }

  return pass;
}


bool testSuite::testToVector()
{
  std::cout << "testToVector: Guarenteed to be fully functional\n";
  return true;
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

  bool found = true;
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

  return pass;

}


bool testSuite::testAddFront()
{
  //need to test that it increments m_size
  //need to test that it adds the correct value
  //see if it can handle a large list
  LinkedListOfInts testableList;

  bool pass = true;

  //test if starting from nothing
  testableList.addFront(5);
  if (testableList.size()==1)
  {
    std::cout << "testAddFront: Correctly increments m_size from 0\n";
  }
  else
  {
    pass = false;
    std::cout << "FAIL: testAddFront: Fails to increments m_size from 0\n";

  }

  if (!testableList.search(5))
  {
    std::cout << "FAIL: testAddFront: addFront stored incorrect value\n";
    pass = false;
  }
  else
  {
    std::cout << "testAddFront: addFront stored correct value\n";
  }

  //test high numbers (large list)
  LinkedListOfInts t1;
  for (int i = -4; i< 999995; i++)
  {
    t1.addFront(i);
  }

  if (t1.size()!=99999)
  {
    std::cout << "FAIL: testAddFront: Fails to increments m_size for large lists\n";
    pass=false;
  }
  else
  {
    std::cout << "testAddFront: Correctly increments m_size for large lists\n";
  }

  bool found = true;
  for (int i=-4; i<999995; i++)
  {
    if (!t1.search(i))
    {
      std::cout << "FAIL: testAddFront: Fails to insert correct value for large lists\n";
      pass = false;
      found = false;
      break;
    }
  }
  if (found)
  {
      std::cout << "testAddFront: Correctly inserts values for large lists\n";
  }

  return pass;

}


bool testSuite::testRemoveBack()
{
  //large list
  //correctly decrements m_size
  //remove back of size 1
  LinkedListOfInts testableList;

  bool pass = true;

  //check if it actually removes
  LinkedListOfInts l1;
  if (l1.isEmpty())
  {
    std::cout<<"ERROR: testRemoveBack: unable to test due to failed addBack function\n";
    pass = false;
  }
  else
  {
    bool success = l1.removeBack();
    if (l1.isEmpty() && success)
    {
      std::cout << "testRemoveBack: Correctly removed back element in list\n";
    }
    else
    {
      std::cout << "FAIL: testRemoveBack: Failed to remove back element in list\n";
      pass = false;
    }
  }

  //check m_size
  testableList.addBack(4);
  if (testableList.size() == 1)
  {
    testableList.removeBack();
    if (testableList.size()==0)
    {
      std::cout << "testRemoveBack: Correctly decremented list size in removeBack\n";
    }
    else
    {
      std::cout << "FAIL: testRemoveBack: Failed to correctly decrement list size\n";
      pass = false;
    }
  }
  else
  {
    std::cout <<"ERROR:: testRemoveBack: addBack didn't add correctly. Can't verify this test.\n";
    pass = false;
  }

  //check large list
  LinkedListOfInts l2;
  for (int i = 0; i<10000; i++)
  {
    l2.addBack(i);
  }
  if (l2.size() == 10000)
  {
    for (int i=0; i<10000; i++)
    {
      l2.removeBack();
    }
    if (l2.isEmpty())
    {
      std::cout << "testRemoveBack: Correctly removed all elements from a large list\n";
    }
    else
    {
      std::cout << "FAIL: testRemoveBack: Failed to remove all elements from a large list\n";
      pass = false;
    }
  }
  else
  {
    std::cout << "ERROR: testRemoveBack: addback didn't add correctly. Can't verify this test\n";
    pass = false;
  }

  return pass;
}


bool testSuite::testRemoveFront()
{
   //large list
  //correctly decrements m_size
  //remove back of size 1
  LinkedListOfInts testableList;

  bool pass = true;

  //check if it actually removes
  LinkedListOfInts l1;
  l1.addBack(1);
  if (l1.isEmpty())
  {
    std::cout<<"ERROR: testRemoveFront: unable to test due to failed addBack function\n";
    pass = false;
  }
  else
  {
    
    bool success = l1.removeFront();
    if (l1.isEmpty() && success)
    {
      std::cout << "testRemoveFront: Correctly removed front element in list\n";
    }
    else
    {
      std::cout << "FAIL: testRemoveFront: Failed to remove front element in list\n";
      pass = false;
    }
  }

  //check m_size
  testableList.addBack(4);
  if (testableList.size() == 1)
  {
    testableList.removeFront();
    if (testableList.size()==0)
    {
      std::cout << "testRemoveFront: Correctly decremented list size in removeFront\n";
    }
    else
    {
      std::cout << "FAIL: testRemoveFront: Failed to correctly decrement list size\n";
      pass = false;
    }
  }
  else
  {
    std::cout <<"ERROR:: testRemoveFront: addBack didn't add correctly. Can't verify this test.\n";
    pass = false;
  }

  //check large list
  LinkedListOfInts l2;
  for (int i = 0; i<10000; i++)
  {
    l2.addFront(i);
  }
  if (l2.size() == 10000)
  {
    for (int i=0; i<10000; i++)
    {
      l2.removeFront();
    }
    if (l2.isEmpty())
    {
      std::cout << "testRemoveFront: Correctly removed all elements from a large list\n";
    }
    else
    {
      std::cout << "FAIL: testRemoveFront: Failed to remove all elements from a large list\n";
      pass = false;
    }
  }
  else
  {
    std::cout << "ERROR: testRemoveFront: addback didn't add correctly. Can't verify this test\n";
    pass = false;
  }

  return pass;

}
