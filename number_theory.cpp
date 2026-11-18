
#include <climits> // Provides LLONG_MAX.

#include "number_theory.h"

// ============================================================
// 1. PRIME NUMBER CHECKER
// Algorithm: 6k +/- 1 optimization.
// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)
// ============================================================

bool isPrime(int n)
{
  // Numbers smaller than 2 are not prime.
  if (n < 2)
  {
    return false;
  }

  // Handle divisibility by 2 and 3 first.
  if (n == 2 || n == 3)
  {
    return true;
  }

  if (n % 2 == 0 || n % 3 == 0)
  {
    return false;
  }

  // Every prime greater than 3 has the form 6k - 1 or 6k + 1.
  // Check both possibilities while avoiding multiplication overflow.
  for (int i = 5; i <= n / i; i += 6)
  {
    if (n % i == 0 || n % (i + 2) == 0)
    {
      return false;
    }
  }

  return true;
}

// ============================================================
// 2. GREATEST COMMON DIVISOR (GCD)
// Algorithm: Iterative Euclidean Algorithm.
// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(1)
// ============================================================

long long gcd(int a, int b)
{
  // Convert to long long before changing signs.
  // This safely handles INT_MIN.
  long long x = a;
  long long y = b;

  // Make both values nonnegative.
  if (x < 0)
  {
    x = -x;
  }

  if (y < 0)
  {
    y = -y;
  }

  // Apply the Euclidean Algorithm.
  while (y != 0)
  {
    long long remainder = x % y;

    x = y;
    y = remainder;
  }

  return x;
}

// ============================================================
// 3. LEAST COMMON MULTIPLE (LCM)
// Algorithm: GCD-based calculation with overflow protection.
// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(1)
// ============================================================

long long lcm(int a, int b)
{
  // The LCM of any number and zero is zero.
  if (a == 0 || b == 0)
  {
    return 0;
  }

  // Convert inputs to long long and make them nonnegative.
  long long x = a;
  long long y = b;

  if (x < 0)
  {
    x = -x;
  }

  if (y < 0)
  {
    y = -y;
  }

  // Calculate the GCD.
  long long divisor = gcd(a, b);

  // Divide before multiplying to reduce overflow risk.
  long long first = x / divisor;

  // Check whether multiplication would exceed LLONG_MAX.
  if (first > LLONG_MAX / y)
  {
    return -1;
  }

  return first * y;
}

// ============================================================
// 4. PERFECT NUMBER CHECKER
// Algorithm: Divisor-pair optimization.
// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)
// ============================================================

bool isPerfect(int n)
{
  // Numbers less than or equal to 1 are not perfect.
  if (n <= 1)
  {
    return false;
  }

  // 1 is a proper divisor of every integer greater than 1.
  long long sum = 1;

  // Check possible divisors up to the square root of n.
  for (int i = 2; i <= n / i; ++i)
  {
    if (n % i == 0)
    {
      // Add the divisor.
      sum += i;

      // Find its paired divisor.
      int pairDivisor = n / i;

      // Avoid counting the same divisor twice
      // when n is a perfect square.
      if (pairDivisor != i)
      {
        sum += pairDivisor;
      }
    }
  }

  // A perfect number equals the sum of its proper divisors.
  return sum == n;
}

// ============================================================
// 5. ARMSTRONG NUMBER CHECKER
// Algorithm: Exponentiation by squaring.
// Time Complexity: O(d * log(d))
// Space Complexity: O(1)
// d = number of digits.
// ============================================================

// Internal helper function.
// It is used only inside this source file.
// It does not need to be declared in number_theory.h.

static long long fastPower(int base, int exponent)
{
  long long result = 1;
  long long powerBase = base;

  while (exponent > 0)
  {
    // If the exponent is odd, multiply the result by the base.
    if (exponent % 2 == 1)
    {
      result *= powerBase;
    }

    // Divide the exponent by 2.
    exponent /= 2;

    // Square the base for the next iteration.
    powerBase *= powerBase;
  }

  return result;
}

bool isArmstrong(int n)
{
  // Negative numbers are not Armstrong numbers.
  if (n < 0)
  {
    return false;
  }

  // Keep the original number for comparison.
  int original = n;

  // Count the number of digits.
  int temp = n;
  int digits = 0;

  do
  {
    ++digits;
    temp /= 10;

  } while (temp > 0);

  // Reset temp to process the original number.
  temp = n;

  // Use long long to prevent intermediate overflow.
  long long sum = 0;

  // Extract and process every digit.
  do
  {
    int digit = temp % 10;

    // Raise the digit to the number of digits.
    sum += fastPower(digit, digits);

    // Remove the last digit.
    temp /= 10;

  } while (temp > 0);

  return sum == original;
}

// ============================================================
// 6. FACTORIAL CALCULATOR
// Algorithm: Iterative multiplication.
// Time Complexity: O(n)
// Space Complexity: O(1)
// ============================================================

long long factorial(int n)
{
  // Reject negative numbers and values above 20.
  // 20! fits inside a signed long long.
  if (n < 0 || n > 20)
  {
    return -1;
  }

  // Start at 1 because 0! = 1 and 1! = 1.
  long long result = 1;

  // Calculate the factorial iteratively.
  for (int i = 2; i <= n; ++i)
  {
    result *= i;
  }

  return result;
}