#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

void guess_game() {
    // Random number generation ko seed karna
    srand(time(0));

    // 1 se 100 ke beech ka number select karna
    int secret_number = (rand() % 100) + 1;
    int guess = 0;
    int attempts = 0;
    bool guessed_correctly = false;

    std::cout << "\n--- NUMBER GUESSING GAME (CODSOFT C++) ---\n";
    std::cout << "I have selected a number between 1 and 100. Guess it!\n";

    while (!guessed_correctly) {
        std::cout << "Enter your guess: ";
        if (!(std::cin >> guess)) {
            // Invalid input (jaise text daal diya) handle karna
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        attempts++;

        if (guess == secret_number) {
            std::cout << "\n🥳 CONGRATULATIONS! You guessed the correct number: " << secret_number << ".\n";
            std::cout << "It took you " << attempts << " attempts.\n";
            guessed_correctly = true;
        } else if (guess < secret_number) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Too high! Try again.\n";
        }
    }
}

int main() {
    guess_game();
    return 0;
}