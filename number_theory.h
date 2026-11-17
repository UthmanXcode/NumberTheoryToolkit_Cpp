// header guards
#ifndef NUMBER_THEORY_H
#define NUMBER_THEORY_H

// we declare the functions here

bool isPrime(int n);

long long gcd(int a, int b);

long long lcm(int a, int b);

bool isPerfect(int n);

bool isArmstrong(int n);

long long factorial(int n);

// header guards
#endif

// Header guards prevent the same header file from being included multiple times in a way that causes duplicate declaration problems. They are like a protection for our header file.
// ifndef: If this name has not been defined...
// #define: Define this name.
// #endif: End the condition

// This filename ends with ".h" which means it is a header file. The file is used to declare all the functions we are going to use. It tells other files which functions are available to use. It does not contain the actual algorithm. The algorithm will be written in "number_theory.cpp".