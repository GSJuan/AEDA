#include <iostream>
#include <exception>

using namespace std;

class MyException: public exception
{
public:
  const char* what() const noexcept { 
    return "C++ Exception";
  }
  
};
