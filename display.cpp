#include <iostream>
#include <thread>
#include <chrono>

#include "display.h"

using namespace std;

// ANSI color codes we use throughout the interface of our terminal.
// this "\033[36m" is called ANSI escape sequence.
// ANSI escape sequences control text colors and formatting in the terminal.
const string RESET = "\033[0m";
const string CYAN = "\033[36m";
const string BLUE = "\033[34m";
const string GREEN = "\033[32m";
const string RED = "\033[31m";
const string YELLOW = "\033[33m";
const string BOLD = "\033[1m";

// Clears the terminal screen.
void clearScreen()
{
  // this does two things: 1. Clears the visible terminal display. 2. Moves the cursor to the top-left corner.

  cout << "\033[2J\033[H";
}

// Displays the startup animation.
void showStartup()
{
  // Clear any previous terminal content.
  clearScreen();

  // Set the title text to cyan and bold.
  cout << CYAN << BOLD;

  // Print two blank lines for spacing.
  cout << "\n\n";

  // Display the title banner.
  cout << "  ==============================================\n";
  cout << "          NUMBER THEORY TOOLKIT v1.0\n";
  cout << "  ==============================================\n";

  // Restore the terminal's normal formatting.
  cout << RESET;

  // Display the initialization message.
  cout << "\n  INITIALIZING MATHEMATICAL ENGINE";

  // Print four animated dots.
  for (int i = 0; i < 4; ++i)
  {
    // Display one dot.
    cout << ".";

    // Force the dot to appear immediately.
    cout.flush();

    // Pause briefly before printing the next dot.
    this_thread::sleep_for(chrono::milliseconds(400));
  }

  // Display the loading message.
  cout << "\n\n  LOADING SYSTEM MODULES...\n\n";

  // Update the loading bar from 0% to 100%.
  for (int i = 0; i <= 20; ++i)
  {
    // Return to the beginning of the current line.
    cout << "\r  " << GREEN << "[";

    // Print the 20 positions of the loading bar.
    for (int j = 0; j < 20; ++j)
    {
      // Display a filled position.
      if (j < i)
      {
        cout << "#";
      }
      // Display an empty position.
      else
      {
        cout << " ";
      }
    }

    // Display the closing bracket and percentage.
    cout << "] " << i * 5 << "%" << RESET;

    // Force the updated progress bar to appear.
    cout.flush();

    // Pause briefly before the next update.
    this_thread::sleep_for(chrono::milliseconds(80));
  }

  // Display the final startup message.
  cout << "\n\n  " << GREEN << "SYSTEM ONLINE." << RESET << "\n";

  // Allow the user to see the final startup message for one second.
  this_thread::sleep_for(chrono::milliseconds(1000));
}

// Displays the main menu.
void showMainMenu()
{
  clearScreen();

  cout << CYAN << BOLD;

  cout << "\n";
  cout << "  +======================================================+\n";
  cout << "  |                                                      |\n";
  cout << "  |              NUMBER THEORY TOOLKIT                   |\n";
  cout << "  |                     VERSION 1.0                      |\n";
  cout << "  |                                                      |\n";
  cout << "  +======================================================+\n";

  cout << RESET;

  cout << "\n  " << BLUE << "MATHEMATICAL OPERATIONS" << RESET << "\n\n";

  cout << "  " << GREEN << "[01]" << RESET << "  Prime Number Checker\n";
  cout << "  " << GREEN << "[02]" << RESET << "  Greatest Common Divisor (GCD)\n";
  cout << "  " << GREEN << "[03]" << RESET << "  Least Common Multiple (LCM)\n";
  cout << "  " << GREEN << "[04]" << RESET << "  Perfect Number Checker\n";
  cout << "  " << GREEN << "[05]" << RESET << "  Armstrong Number Checker\n";
  cout << "  " << GREEN << "[06]" << RESET << "  Factorial Calculator\n";

  cout << "\n  " << RED << "[00]" << RESET << "  Terminate Program\n\n";

  cout << CYAN;
  cout << "  ========================================================\n";
  cout << RESET;

  cout << "\n  " << YELLOW << "SELECT OPERATION >> "
       << RESET;
}

// Displays a calculation result.
// The message is passed by constant reference to avoid copying the string
// and to prevent the function from modifying the original message.
void showResult(const string &message)
{
  // Add spacing before the result box.
  cout << "\n\n";

  // Set the border color to cyan.
  cout << CYAN;

  // Display the result box.
  cout << "  +======================================================+\n";
  cout << "  |                       RESULT                         |\n";
  cout << "  +======================================================+\n";

  // Restore normal formatting.
  cout << RESET;

  // Display the calculation result in green and bold.
  cout << "\n  " << GREEN << BOLD << message << RESET << "\n\n";

  // Display the bottom border in cyan.
  cout << CYAN;
  cout << "  ========================================================\n";
  cout << RESET;
}

// Asks the user what to do after a calculation.
void showNextStepMenu()
{
  cout << "\n";
  cout << BLUE << "  WHAT WOULD YOU LIKE TO DO NEXT?\n\n"
       << RESET;

  cout << GREEN << "  [1]" << RESET << " Return to Main Menu\n";
  cout << RED << "  [0]" << RESET << " Terminate Program\n\n";

  cout << YELLOW << "  SELECT >> " << RESET;
}

// Displays the shutdown animation.
void showExit()
{
  // Add spacing before the shutdown message.
  cout << "\n\n";

  // Display the shutdown message in cyan.
  cout << CYAN << "  SHUTTING DOWN NUMBER THEORY TOOLKIT";

  // Print four animated dots.
  for (int i = 0; i < 4; ++i)
  {
    cout << ".";
    cout.flush();

    this_thread::sleep_for(chrono::milliseconds(400));
  }

  cout << "\n\n";

  // Display the final message in green.
  cout << GREEN << "  SYSTEM TERMINATED SUCCESSFULLY.\n"
       << RESET;

  cout << "\n";
}