#include <iostream>
#include <random>

void playGame();

int main() {
    playGame();
    return 0;
}

void playGame() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    int secret = dist(gen);
    int guess = 0;
    int attempts = 0;

    std::cout << "Guess the number (1–100): ";

    while (guess != secret) {
        std::cin >> guess;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Please enter a valid number.\n";
            continue;
        }

        attempts++;

        if (guess < secret)
            std::cout << "Higher!\n";
        else if (guess > secret)
            std::cout << "Lower!\n";
    }

    std::cout << "You win in " << attempts << " attempts!\n";
}
