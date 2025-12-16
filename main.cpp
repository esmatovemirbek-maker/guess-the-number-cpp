#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    int secret = dist(gen);
    int guess = 0;
    int attempts = 0;


    std::cout << "Guess the number (1–100): ";

    while (guess != secret) {
        std::cin >> guess;
        attempts++;
        if (guess < secret) std::cout << "Higher!\n";
        if (guess > secret) std::cout << "Lower!\n";
    }

std::cout << "You win in " << attempts << " attempts!\n";
}
