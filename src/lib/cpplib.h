#ifndef TEMPLATE_CPPLIB_H
#define TEMPLATE_CPPLIB_H

#include <map>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;
/**
 *  Example class used for GTest demo
 */
class CPPLib {
 public:
  //q3
  std::set<std::set<int>> twoSum(std::vector<int>& input, int sum);
  //q6
  bool CheckValidExpression(const std::string& a);
};

//q2
class Point{	
private:	
    int x;	
    int y;	
public:	
    Point();	
    Point(int);	
    Point(const Point&);	
    ~Point();	
};

// q4
class Student_shallow
{
public:
    int* id;
    Student_shallow();
    Student_shallow(int);
};
class Student_deep
{
public:
    int* id;
    Student_deep();
    Student_deep(int);
    ~Student_deep();
    Student_deep(const Student_deep&);
    Student_deep& operator=(const Student_deep&);
};

//q5
class Complex{
 public:

  // default constructor
  Complex():real(0), ima(0){};
  // default destructor
  ~Complex();
  // implement constructor that takes 2 numbers as input parameters
  
  // implement a copy constructor

  // implement an assignment operator

  // define real and imaginary part
  float real;
  float ima;

  // below here, we assume complex1, complex2 are instances of Complex.
  // define your functions to enable operator overloadings.


  //q5_1 complex++

  //q5_2 --complex

  //q5_3 complex1 > complex2

  //q5_4 complex * (an float number)

  //q5_5 complex1 += complex2

  //q5_6 complex2 += (an float number)
  
};

#endif
