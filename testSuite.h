#ifndef TESTSUITE_H
#define TESTSUITE_H

#include "LinkedListOfInts.h"

class testSuite
{
public:
  testSuite();
  void run();



private:
  bool testCreation();
  bool testDestructor();
  bool testIsEmpty();
  bool testSize();
  bool testSearch();
  bool testToVector();
  bool testAddBack();
  bool testAddFront();
  bool testRemoveBack();
  bool testRemoveFront();



};
#endif
