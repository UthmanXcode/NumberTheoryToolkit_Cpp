#include "number_theory.h" // This line allows "number_theory.cpp" to see the function declarations from our header file.

#include <climits> // Provides LLONG_MAX, the maximum value of a long long integer.

// 1. Function implementation for prime check.

bool isPrime(int n)
{

  // Numbers smaller than 2 are not prime.
  if (n < 2)
  {
    return false;
  }

  // Check whether n has any divisor from 2 up to its square root.
  for (int i = 2; i <= n / i; ++i)
  {

    // If n is divisible by i, it is not a prime number.
    if (n % i == 0)
    {
      return false;
    }
  }

  // No divisor was found, so n is prime.
  return true;
}

// 2. Function implementation for GCD of two numbers. The function uses "Euclidean Algorithm".

long long gcd(int a, int b)
{

  // Convert the inputs to long long to handle the full int range safely.
  long long x = a;
  long long y = b;

  // Make both numbers nonnegative.
  if (x < 0)
  {
    x = -x;
  }
  if (y < 0)
  {
    y = -y;
  }

  // Repeat the Euclidean algorithm until the remainder becomes 0.
  while (y != 0)
  {

    // Find the remainder when a is divided by b.
    long long remainder = x % y;

    // Move y into x for the next calculation.
    x = y;

    // Use the remainder as the new value of y.
    y = remainder;
  }

  // When b becomes 0, a contains the GCD.
  return x;
}

// 3. Function implementation for LCM of two numbers.
// long long is a built-in C++ data type that typically uses 64 bits,
// allowing it to store larger integer values than int.

long long lcm(int a, int b)
{

  // The LCM of any number and 0 is 0.
  if (a == 0 || b == 0)
  {
    return 0;
  }

  // Convert both inputs to long long.
  long long x = a;
  long long y = b;

  // Make both numbers nonnegative.
  if (x < 0)
  {
    x = -x;
  }

  if (y < 0)
  {
    y = -y;
  }

  // Calculate the GCD of the two positive values.
  long long divisor = gcd(a, b);

  // Divide before multiplying to reduce overflow risk.
  long long first = x / divisor;

  // Check whether the multiplication would exceed long long.
  if (first > LLONG_MAX / y)
  {
    return -1;
  }

  // Return the calculated LCM.
  return first * y;
}

// 4. Function implementation of Perfect Numbers checking.

bool isPerfect(int n)
{

  // Numbers less than or equal to 1 are not perfect numbers.
  if (n <= 1)
  {
    return false;
  }

  // Start with 1 because it is a proper divisor of every n > 1.
  long long sum = 1;

  // Check possible divisors up to the square root of n.
  for (int i = 2; i <= n / i; ++i)
  {

    // If n is divisible by i, we have found a divisor.
    if (n % i == 0)
    {

      // Add the divisor to the sum.
      sum += i;

      // Find its paired divisor.
      int pair = n / i;

      // Avoid adding the same divisor twice for perfect squares.
      if (pair != i)
      {
        sum += pair;
      }
    }
  }

  // A number is perfect if its proper divisors add up to itself.
  return sum == n;
}

// 5. Function implementation of Armstrong Numbers checking.

bool isArmstrong(int n)
{

  // Negative numbers are not Armstrong numbers.
  if (n < 0)
  {
    return false;
  }

  // Keep the original number for the final comparison.
  int original = n;

  // Use a temporary variable to count the digits.
  int temp = n;
  int digits = 0;

  // Count how many digits the number contains.
  do
  {
    digits++;
    temp /= 10;
  } while (temp > 0);

  // Reset temp so we can process the digits again.
  temp = n;

  // Store the sum of each digit raised to the number of digits.
  long long sum = 0;

  // Extract and process each digit.
  do
  {
    // Get the last digit of the number.
    int digit = temp % 10;

    // Calculate the digit raised to the required power.
    long long digitPower = 1;

    for (int i = 0; i < digits; ++i)
    {
      digitPower *= digit;
    }

    // Add the calculated power to the total sum.
    sum += digitPower;

    // Remove the last digit before the next iteration.
    temp /= 10;

  } while (temp > 0);

  // The number is Armstrong if the calculated sum equals the original.
  return sum == original;
}

// 6. Function implementation of Factorial Calculation using Recursion.

long long factorial(int n)
{

  // Reject negative numbers and values above 20.
  if (n < 0 || n > 20)
  {
    return -1;
  }

  // Base case: 0! = 1 and 1! = 1.
  if (n == 0 || n == 1)
  {
    return 1;
  }

  // Recursive case.
  return static_cast<long long>(n) * factorial(n - 1);
}
