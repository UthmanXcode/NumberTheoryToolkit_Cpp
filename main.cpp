#include <iostream>
#include <sstream>
#include <string>

#include "number_theory.h"
#include "display.h"

using namespace std;

// Reads and validates an integer entered by the user.
bool readInteger(int &value)
{
  // Store the complete user input as text.
  string input;

  getline(cin, input);

  // Create a string stream from the user's input.
  stringstream inputStream(input);

  // Temporary variable for the extracted integer.
  int number;

  // Attempt to extract an integer.
  if (!(inputStream >> number))
  {
    return false;
  }

  // Check whether additional non-whitespace characters remain.
  char extra;

  if (inputStream >> extra)
  {
    return false;
  }

  // Store the validated integer in the original variable.
  value = number;

  return true;
}

// Main entry point of the Number Theory Toolkit.
int main()
{
  // Display the startup animation.
  showStartup();

  // Keep the program running until the user chooses to exit.
  while (true)
  {

    // Display the main menu.
    showMainMenu();

    // Store the user's menu selection.
    int choice;

    // Keep asking until valid integer input is received.
    while (!readInteger(choice))
    {
      cout << "\nInvalid input. Please enter a valid integer.\n";
      cout << "SELECT OPERATION >> ";
    }

    // Process the user's selection.
    switch (choice)
    {
    case 1:
    {
      // Store the number entered by the user.
      int number;

      // Ask the user to enter a number.
      cout << "\nEnter an integer: ";

      // Keep asking until valid integer input is received.
      while (!readInteger(number))
      {
        cout << "\nInvalid input. Please enter an integer: ";
      }

      // Check whether the number is prime.
      bool result = isPrime(number);
      // Prepare the result message.
      string message;

      if (result)
      {
        message = to_string(number) + " is a prime number.";
      }
      else
      {
        message = to_string(number) + " is not a prime number.";
      }

      // Display the result.
      showResult(message);

      break;
    }

    case 2:
    {
      // Store the two numbers entered by the user.
      int firstNumber;
      int secondNumber;

      // Ask the user for the first number.
      cout << "\nEnter the first integer: ";

      // Validate the first input.
      while (!readInteger(firstNumber))
      {
        cout << "\nInvalid input. Please enter an integer: ";
      }

      // Ask the user for the second number.
      cout << "Enter the second integer: ";

      // Validate the second input.
      while (!readInteger(secondNumber))
      {
        cout << "\nInvalid input. Please enter an integer: ";
      }

      // Calculate the GCD of the two numbers.
      long long result = gcd(firstNumber, secondNumber);

      // Prepare the result message.
      string message = "GCD of " + to_string(firstNumber) +
                       " and " + to_string(secondNumber) +
                       " is " + to_string(result) + ".";

      // Display the result.
      showResult(message);

      break;
    }

    case 3:
    {
      // Store the two numbers entered by the user.
      int firstNumber;
      int secondNumber;

      // Ask the user for the first number.
      cout << "\nEnter the first integer: ";

      // Validate the first input.
      while (!readInteger(firstNumber))
      {
        cout << "\nInvalid input. Please enter an integer: ";
      }

      // Ask the user for the second number.
      cout << "Enter the second integer: ";

      // Validate the second input.
      while (!readInteger(secondNumber))
      {
        cout << "\nInvalid input. Please enter an integer: ";
      }

      // Calculate the LCM of the two numbers.
      long long result = lcm(firstNumber, secondNumber);

      // Check whether the calculation was unsuccessful due to overflow.
      if (result == -1)
      {
        showResult("LCM calculation failed: the result exceeds the supported range.");
      }
      else
      {
        // Prepare the result message.
        string message = "LCM of " + to_string(firstNumber) +
                         " and " + to_string(secondNumber) +
                         " is " + to_string(result) + ".";

        // Display the result.
        showResult(message);
      }

      break;
    }

    case 4:
    {
      // Store the number entered by the user.
      int number;

      // Ask the user to enter a number.
      cout << "\nEnter an integer: ";

      // Keep asking until valid integer input is received.
      while (!readInteger(number))
      {
        cout << "\nInvalid input. Please enter an integer: ";
      }

      // Check whether the number is perfect.
      bool result = isPerfect(number);

      // Prepare the result message.
      string message;

      if (result)
      {
        message = to_string(number) + " is a perfect number.";
      }
      else
      {
        message = to_string(number) + " is not a perfect number.";
      }

      // Display the result.
      showResult(message);

      break;
    }

    case 5:
    {
      // Store the number entered by the user.
      int number;

      // Ask the user to enter a number.
      cout << "\nEnter an integer: ";

      // Keep asking until valid integer input is received.
      while (!readInteger(number))
      {
        cout << "\nInvalid input. Please enter an integer: ";
      }

      // Check whether the number is an Armstrong number.
      bool result = isArmstrong(number);

      // Prepare the result message.
      string message;

      if (result)
      {
        message = to_string(number) + " is an Armstrong number.";
      }
      else
      {
        message = to_string(number) + " is not an Armstrong number.";
      }

      // Display the result.
      showResult(message);

      break;
    }

    case 6:
    {
      // Store the number entered by the user.
      int number;

      // Ask the user to enter a number.
      cout << "\nEnter an integer (0–20): ";

      // Keep asking until valid integer input is received.
      while (!readInteger(number))
      {
        cout << "\nInvalid input. Please enter an integer: ";
      }

      // Calculate the factorial of the number.
      long long result = factorial(number);

      // Check whether the input is outside the supported range.
      if (result == -1)
      {
        showResult("Factorial calculation failed: please enter a number between 0 and 20.");
      }
      else
      {
        // Prepare the result message.
        string message = to_string(number) + "! = " + to_string(result);

        // Display the result.
        showResult(message);
      }

      break;
    }

    case 0:
      showExit();
      return 0;

    default:
      cout << "Invalid selection. Please try again.\n";
      break;
    }

    // Display the next-step menu only after a valid operation selection.
    if (choice >= 1 && choice <= 6)
    {
      // Store the user's next-step selection.
      int nextChoice;

      // Ask the user what to do next.
      showNextStepMenu();

      // Read the user's next-step selection.
      // Keep asking until valid integer input is received.
      while (!readInteger(nextChoice))
      {
        cout << "\nInvalid input. Please enter a valid integer.\n";
        cout << "SELECT >> ";
      }

      // Process the user's next-step selection.
      switch (nextChoice)
      {
      case 1:
        // Return to the beginning of the main loop.
        break;

      case 0:
        // Display the shutdown animation.
        showExit();

        // Terminate the program successfully.
        return 0;

      default:
        cout << "\nInvalid selection. Returning to main menu.\n";
        break;
      }
    }
  }

  return 0;
}