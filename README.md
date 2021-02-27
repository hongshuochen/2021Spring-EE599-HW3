
# HW3 EE599 - Computing Principles for Electrical Engineers

- Plesae clone the repository, edit [README.md](README.md) to answer the questions, and fill up functions to finish the hw.
- For non-coding quesitions, you will find **Answer** below each question. Please write your answer there.
- For coding questions, please make sure that your code can run ```bazel run/test```. In this homework, you will need to fill up [cpplib.cc](src/lib/cpplib.cc) and tests in [tests](tests).
- For submission, please push your answers to Github before the deadline.
- Deadline: Friday, March 5th by 23:59 pm
- Total: 120 points. 100 points is considered full credit.

## Question 1 (20 Points. Easy)

Please compare pros and cons of the following options, and also describe when each option is preferred.

- Passing parameters by value
- Passing parameters using pointers
- Passing parameters using references
- Passing parameters using const references

Answer:

## Question 2 (20 Points. Easy)
Part 1:
Please write a class called Point which has int values ```x```, ```y``` as its coordinates:
- Write a default constructor that initializes ```x```, ```y``` to ```0```, ```0```.
- Write a constructor that takes only one parameter. Use that parameter to initialize ```x``` and set ```y``` to ```0```.
- Write a copy constructor.
- Write a destructor that prints “Destructor is called!”.
- For class Point, you can either set ```x```, ```y``` to be public or if you make them private, write ```GetX()``` and ```GetY()``` functions to return the values. This way you can use their values in your unit tests.

Part 2:
For each of the following snippets, please write down what function will be called:
- You can assume a constructor with 2 parameters exist, which we didn't ask you to implement.
- For all ```PrintPoint``` function given below, you don’t need to write its definition.

Snippet 1:
```
Point p1;
```
Answer:

Snippet 2:
```c++
Point p1(5, 6);
```
Answer:

Snippet 3:
```c++
Point p1(5, 6);
Point p2=p1;
```
Answer:

Snippet 4:
Assuming PrintPoint function is given as below:
```c++
void PrintPoint(Point p);
Point p1;
PrintPoint (p1);
```
Answer:

Snippet 5:
Assuming PrintPoint function is given as below:
```c++
void PrintPoint(Point &p);
Point p1;
PrintPoint(p1);
```
Answer:

Snippet 6:
Assuming PrintPoint function is given as below:
```c++
void PrintPoint(const Point &p);
Point p1;
PrintPoint(p1);
```
Answer:

Snippet 7:
Assuming PrintPoint function is given as below:
```c++
void PrintPoint(Point *p);
Point *ptr;
PrintPoint(ptr);
```
Answer:

Snippet 8:
Assuming PrintPoint function is given as below:
```c++
void PrintPoint(Point *p);
Point *ptr;
ptr = new Point;
PrintPoint(ptr);
```
Answer:

## Question 3 (20 Points. Easy)

Given a vector of integer ```input```, and an integer ```sum```, return a set of sets ```{a,b}```, where ```a```, ```b``` are in the input vector and ```a + b = sum```, which are the numbers in ```input``` such that they can add up to sum. Function is defined as ```std::set<std::set<int>> twoSum(std::vector<int>& input, int sum)```

- You can assume the vector input doesn't contain duplicated numbers.
- You can only use numbers in vector once.
- If there is no answer, the output should return an empty set.
- You should return **all** results in the input vector if there are multiple answers.
- **Hint**: you may try unordered_map.
- Examples:
  - input = {2,3,4,5}, sum = 7, output = {{2,5},{3,4}}
  - input = {2,3,-2,5,0}, sum = 0, output = {{2,-2}}
  - input = {1,5,4,10}, sum = 200, output = {}

Write several tests using GTest for your function in [tests/q3_student_test.cc](tests/q3_student_test.cc).
Please create your test cases and run the following command to verify the functionality of your program.And what's your function's **time complexity**?
```
bazel test tests:q3_student_test
```
Please compute the time complexity of your implementation.

Answer:

## Question 4 (20 Points. Easy)

Write 2 classes to practice how to use the constructor, copy constructor, copy assign operator and destructor and compare the deep copy with shallow copy.

Both of the Student_shallow and Student_deep has one member integer pointer id.

- Student_shallow
  - Write a **default constructor** to initialize id to **nullptr**
  - Write a **parameterized constructor** to initialize id

- Student_deep
  - Write a **default constructor** to initialize id to **nullptr**
  - Write a **parameterized constructor** to initialize id
  - Write a **destructor** to print "Delete Student_deep!" and delete the integer pointer
  - Write a **copy constructor** with **deep copy**
  - Write a **copy assignment operator** with **deep copy**

```c++
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
```

Example:
```
Student_shallow a(0);
Student_shallow b = a;
Student_shallow c;
c = a;
cout << *a.id << *b.id << *c.id << endl;
*c.id = 1;
cout << *a.id << *b.id << *c.id << endl;

Student_deep d(0);
Student_deep e = d;
Student_deep f;
f = e;
cout << *d.id << *e.id << *f.id << endl;
*e.id = 2;
*f.id = 1;
cout << *d.id << *e.id << *f.id << endl;
```
Expected output:
```
000
111
000
021
Delete Student_deep!
Delete Student_deep!
Delete Student_deep!
```

Write several tests using GTest for your function in [tests/q4student_test.cc](tests/q4_student_test.cc).

Please create your test cases and run the following command to verify the functionality of your program. You don't need to test the destructor.
```
bazel test tests:q4_student_test
```

## Question 5 (20 Points. Medium)
Write a class to implement how complex number works in mathematics. A complex number can be expressed 
as **a+bi**, where a and b are real numbers. You are given an incomplete class `Complex`:
```c++
class Complex{
 public:

  Complex():real(0), ima(0){};
  ~Complex();
  float real;
  float ima;
```
Tasks:
1. implement a constructor that takes the initial real and imaginary number as 2 parameters.
2. implement a copy constructor.
3. implement a copy assignment operator.
4. the class will support '++' (as postfix) and '--' (as prefix) operators.
  - `complex++` should increase the real part by 1. 
  - `--complex` should decrease the real part by 1.
    - Example: `c=Complex(1,2); c++;`, *c=2+2i*
    - Example: `c=Complex(1,2); --c;`, *c=0+2i*
5. The class will support '>' operator, which returns boolean data. To compare two complex numbers x= a + bi and y=c+dj, for x > y should return true if  SQRT(a^2 + b^2) > SQRT(c^2 + d^2) 
Example: (1+2i) > (0+3i) = (1^2+2^2) > (0^2 + 3^2) = 5 > 9 = false.
6. the class will support '*' operator, which multiplies a real number:
  - the function returns a Complex object, which is multiplied both the real and imaginary parts.
    - Example: `c=Complex(1,2); d=Complex(); d=c*2;`, *d=2+4i*
7. the class will support '+=' operator on either float number and Complex object:
  - data type before '+=' must be a Complex object.
    - Example: `c=Complex(1,2); d=Complex(3,4); c+=d;`, *c=4+6i*
    - Example: `c=Complex(1,2); float d=2; c+=d;`, *c=3+2i*


Write a test using GTest for your finction in [tests/q5_student_test.cc](tests/q5_student_test.cc).
```
bazel test tests:q5_student_test
```

## Question 6 (20 Points. Medium)
Given an expression string, find if the input has valid brackets (i.e. { } or [ ] or ( ) ). Function is defined as ```bool​ ​CheckValidExpression​(​const​ ​string​&​ ​a​)```

An input expression is valid if:

Open brackets are closed by the same type of brackets.
Open brackets must be closed in the correct order.
An empty string is also considered valid.

You should only check for the validity of brackets based on the above rules, i.e. ‘(‘, ‘)’, ‘[‘, ‘]’, ‘{‘, ‘}’, not the rest of the expression.

Hint: Iterate the input from beginning to end and use a std:stack.

Example 1:
Input: "(a+b)"
Output: true

Example 2:
Input: "(a+b)[c*d]{5g+h}"
Output: true

Example 3:
Input: "(a+b]"
Output: false

Example 4:
Input: "(7h+[5c)+7]"
Output: false

Example 5:
Input: "{2k+[5j]}"
Output: true

Example 6:
Input: "{2k++[5--*j]}"
Output: true

Write a test using GTest for your finction in [tests/q6_student_test.cc](tests/q6_student_test.cc).
```
bazel test tests:q6_student_test
```
Please compute the time complexity of your implementation.

Answer:

