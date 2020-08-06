// Taken from
// https://www.cs.rpi.edu/academics/courses/fall18/csci1200/lectures/01_c++_stl_strings.pdf

#include <cmath>
#include <cstdlib>
#include <iostream>

bool check_root(int a, int b, int c, float root)
{
  float check = a * root * root + b * root + c;
  if (fabs(check) > 0.0001) {
    std::cerr << "ERROR: " << root << " is not a root of this formula."
              << std::endl;
    return false;
  } else {
    return true;
  }
}

bool find_roots(int a, int b, int c, float &root_pos, float &root_neg)
{
  int radical = b * b - 4 * a * c;

  /* This was used as an example for passing by copy vs reference
  a = 7;
  root_pos = 14.2;
  */

  if (radical < 0) {
    std::cerr << "ERROR: Imaginary roots" << std::endl;
    return false;
  }

  // float((1 + 2) / 2) -> equal to 1.0, not 1.5

  float sqrt_radical = sqrt(radical);
  root_pos = (-b + sqrt_radical) / float(2 * a); // changed outside the function
  root_neg = (-b - sqrt_radical) / float(2 * a); // changed outside the function
  return true;
}

// void functions return nothing
void print_hello() { std::cout << "hello!" << std::endl; }

int main()
{
  while (true) {
    std::cout << "Enter 3 integer coefficients to a quadratic function: a*x*x "
                 "+ b*x + c = 0"
              << std::endl;
    // ints are for integers (e.g. -1, 5)
    int my_a, my_b, my_c;
    std::cin >> my_a >> my_b >> my_c;

    // floats are for fractions/decimals (e.g. 0.1)
    float root_1, root_2;
    // bools can be true or false
    std::cout << "Calling find_roots.  my_a is " << my_a << " and root_1 is "
              << root_1 << std::endl;
    bool success = find_roots(my_a, my_b, my_c, root_1, root_2);
    std::cout << "Root 1 did have the ampersand so it was updated, it's now: "
              << root_1 << std::endl;
    std::cout
        << "my_a didn't have the ampersand so it wasn't updated, it's now: "
        << my_a << std::endl;
    if (!success)
      continue;

    std::cout << "The roots are: " << root_1 << " and " << root_2 << std::endl;

    if (check_root(my_a, my_b, my_c, root_1) &&
        check_root(my_a, my_b, my_c, root_2)) {
      break;
    } else {
      std::cerr << "ERROR: Unable to verify "
                   "one or both roots."
                << std::endl;
      exit(1);
    }
  }

  /* for loop syntax:
for (initial condition; run while this is true; do this at the end of each loop)
{}

  example:
  for (unsigned int i = 10; i > 0; i--) {
    std::cout << i << std::endl;
  }
    */

  // strings vs chars vs std::strings
  char somechar = 'a';
  char somechars[2] = "ab"; // same thing as char somechars[2] = { "a", "b" };
  std::string a_string = "hi, i'm a string";
  std::cout << a_string << std::endl;
  std::cout << a_string.size() << std::endl;
}
