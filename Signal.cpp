#include <iostream>
#include <cstdlib>
#include <ctime>

int generateSignal() {
    return std::rand() % 3;
}

void showStatus(int score, int round) {
    std::cout << "\nRound " << round << " complete.\n";
    std::cout << "Current Score: " << score << "\n";
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int score = 0;

    std::cout << "=== Signal Clash Arena ===\n";

    for (int i = 1; i <= 8; i++) {
        int signal = generateSignal();
        int choice;

        std::cout << "\nChoose response (0-2): ";
        std::cin >> choice;

        if (choice == signal) {
            std::cout << "Correct signal match!\n";
            score += 10;
        } else {
            std::cout << "Signal mismatch.\n";
            score += 3;
        }

        if (signal == 0)
            std::cout << "instagram feed burst detected.\n";
        else if (signal == 1)
            std::cout << "telegram channel update received.\n";
        else
            std::cout << "neutral network pulse.\n";

        showStatus(score, i);
    }

    std::cout << "\nFinal Score: " << score << "\n";

    if (score > 60)
        std::cout << "Elite signal controller!\n";
    else
        std::cout << "Training needed.\n";

    return 0;
}
