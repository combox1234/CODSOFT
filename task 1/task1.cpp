#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class GuessingGame {

    int numberToGuess;
    int attempts;

public:

    GuessingGame() {
        srand(static_cast<unsigned int>(time(0)));//contructor for random number.....
        attempts = 0;
    }
    void printHeader(const string& title) { // this function is for formated header display....
        cout << "\n=========================================\n";
        cout << "   " << title << "   \n";
        cout << "=========================================\n";
    }

    void Invalid_value_checker() { // this function is for checking invalid values.....
        cin.clear();
        cin.ignore(10000, '\n');
    }

    void menu() { //menu to start with the game where there are 2 options either custom or normal mode and exit option....
        int choice;
        do {
            printHeader("Number Guessing Game");
            cout << " [1] Normal Mode (1 - 100) \n";
            cout << " [2] Custom Range Mode \n";
            cout << " [3] Exit \n";
            cout << "-----------------------------------------\n";
            cout << "Enter your choice: ";
            cin >> choice;
            if (cin.fail()) Invalid_value_checker();
            else if (choice == 1) play(1, 100);
            else if (choice == 2) customRangeMode();
            else if (choice != 3) cout << "\n[----ERROR----].....Please try again ;-; \n";
        } while (choice != 3);
        cout << "\nExiting........Thanks for playing :)\n";
    }

    int getUserGuess(int low, int high) {// this function is for getting the user input and checking if the input is in the given range or not.....
        int guess;
        cout << "Enter your guess: ";
        cin >> guess;

        if (cin.fail() || guess < low || guess > high) { // checks if input in range or not....
            throw invalid_argument("Out of the given range please enter a valid number. ;-;");
        }
        return guess;
    }

    void play(int low, int high) { // this function is for playing the game where the user has to guess the number between the given range and also cout your attempts....
        numberToGuess = rand() % (high - low + 1) + low; 
        attempts = 0;
        int guess;
        printHeader("Your Guess is: (" + to_string(low) + " - " + to_string(high) + ")");
        while (true) {
            try {
                guess = getUserGuess(low, high);
                attempts++;

                if (guess < numberToGuess) cout << "\n[ITs smaller(than the choosen number)] Try a greater number.\n"; // checks if the guessed number is smaller than the choosen number....
                else if (guess > numberToGuess) cout << "\n[ITs Greater(than the choosen number)] Try a smaller number.\n";// checks if the guessed number is greater than the choosen number....
                else {
                    printHeader("Congrats You Guessed the Correct Number!");
                    cout << "Attempts: " << attempts << "\n-----------------------------------------\n";
                    break;
                }
            } catch (const invalid_argument&) {
                cout << "\n[----ERROR----] Please check the range of numbers once for your next guess :( \n";
            }
        }
    }

    void customRangeMode() { // function for customized range where the user can choose the range of the number to be guessed....
        int low, high;
        printHeader("CUSTOM RANGE MODE");
        while (true) {
            cout << "Enter the minimum value you want: ";
            cin >> low;
            cout << "Enter the maximum value you want: ";
            cin >> high;
            if (cin.fail() || low >= high) {
                Invalid_value_checker();
                cout << "\n[----ERROR----].....Please try again(  hint: max > min ;)  )\n";
            } else break;
        }
        play(low, high);
    }


};
int main() {
    GuessingGame game;
    game.menu();
    return 0;
}
