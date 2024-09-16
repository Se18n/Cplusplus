#include <iostream>
#include <cstdlib> 
#include <ctime>  

int main() {

    std::srand(static_cast<unsigned int>(std::time(0)));
    int randomNumber = std::rand() % 100 + 1;
    int userGuess = 0;
    std::cout << "Guess the number (between 1 and 100): ";
    while (userGuess != randomNumber) {
        std::cin >> userGuess;
        if (userGuess > randomNumber) {
            std::cout << "Too high! Try again: ";
        } else if (userGuess < randomNumber) {
            std::cout << "Too low! Try again: ";
        } else {
            std::cout << "Congratulations! You guessed the correct number.\n";
        }
    }
return 0;
}


