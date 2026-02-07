//co-authors Madina and Ruslan

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

int spin() {
    return rand() % 5 + 4; // 5 to 9 chances 
}

void spinAnimation(int &a, int &b, int &c) {
    for (int i = 0; i < 15; i++) {
        a = spin();
        b = spin();
        c = spin();

        cout << "\r[ " << a << " | " << b << " | " << c << " ]" << flush;
        this_thread::sleep_for(chrono::milliseconds(120));
    }
    cout << endl;
}

int multiplier(int a, int b, int c) {
    if (a == b && b == c) return 6;
    if (a == b || a == c || b == c) return 2;
    return 0;
}

void playerTurn(string name, int &money) {
    int bet;

    cout << name << " Money: " << money << "$\n";

    while (true) {
        cin >> bet;
        if (bet > 100)
            cout << "Max bet is 100$! Try again: ";
        else if (bet > money)
            cout << "Not enough balance! Try again: ";
        else
            break;
    }

    int s1, s2, s3;

    cout << "Spinning...\n";
    spinAnimation(s1, s2, s3);

    int mult = multiplier(s1, s2, s3);

    if (mult > 0) {
        int win = bet * mult;
        money += win;
        cout << "MATCH! x" << mult << "  +" << win << "$\n";
    }
    else {
        money -= bet;
        cout << "No match! -" << bet << "$\n";
    }
}

int main() {
    srand(time(0));

    string player1, player2;
    int Money1 = 1000, Money2 = 1000;
    cout << "==== WELCOME TO SLOT MACHINE ====\n";
    cout << "Enter Player 1 name: ";
    cin >> player1;
    cout << "Enter Player 2 name: ";
    cin >> player2;

    cout << "\n1. Slot Mode\n";
    int choice;
    cin >> choice;

    if (choice != 1) return 0;

    for (int round = 1; round <= 5; round++) {
        cout << "\n===== ROUND " << round << " =====\n";

        playerTurn(player1, Money1);
        playerTurn(player2, Money2);
    }

    cout << "\n===== GAME OVER =====\n";
    cout << player1 << ": " << Money1 << "$\n";
    cout << player2 << ": " << Money2 << "$\n";

    if (Money1 > Money2)
        cout << player1 << " WINS!\n";
    else if (Money2 > Money1)
        cout << player2 << " WINS!\n";
    else
        cout << "DRAW!\n";

    return 0;
}


