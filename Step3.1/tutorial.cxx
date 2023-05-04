#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

// 动态生成的头文件
#include "tutorial.h"

// should we include the MathFunctions header?
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    // report version
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  const double inputValue = atof(argv[1]);

//
#ifdef USE_MYMATH
  const double outputValue = mysqrt(inputValue);
  std::cout << "USE_MYMATH"
            << "\n";
#else
  const double outputValue = sqrt(inputValue);
  std::cout << "USE CODE"
            << "\n";
#endif
  std::cout << "The square root of " << inputValue
            << " is " << outputValue
            << std::endl;

  return 0;
}
