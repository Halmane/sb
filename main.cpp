#include <iostream>

void fillingFieldsVoid(char firstPlayer[10][10], char secondPlayer[10][10]) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            firstPlayer[i][j] = 'o';
            secondPlayer[i][j] = 'o';
        }
}

bool checkingFieldsWin(char firstPlayer[10][10], char secondPlayer[10][10]) {
    bool win = 1;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            if (secondPlayer[i][j] == '@')
                win = 0;
        }
    if (win != 0) {
        std::cout << "First win!!";
        return 0;
    } else win = 1;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            if (firstPlayer[i][j] == '@')
                win = 0;
        }
    if (win != 0) {
        std::cout << "Second win!!";
        return 0;
    }
    return 1;
}

void showField(char player[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            std::cout << player[i][j] << " ";
        std::cout << std::endl;
    }
}

bool put(int deck, char player[10][10], int x, int y, char direction='N') {
    if (x < 0 or x > 10 or y < 0 or y > 10) {
        return 0;
    }
    if (deck == 1 and player[y - 1][x - 1] == '@') {
        return 0;
    } else if (direction == 'N' or direction == 'n') {
        if (y - deck < 0)
            return 0;
        else {
            for (int i = 0; i < deck; i++) {
                if (player[y - 1][x - 1] == '@')
                    return 0;
                y--;
            }
            y += deck;
        }
        for (int i = 0; i < deck; i++) {
            player[y - 1][x - 1] = '@';
            y--;
        }
    } else if (direction == 'E' or direction == 'e') {
        if (x + deck > 9)
            return 0;
        else {
            for (int i = 0; i < deck; i++) {
                if (player[y - 1][x - 1] == '@')
                    return 0;
                x++;
            }
            x -= deck;
        }
        for (int i = 0; i < deck; i++) {
            player[y - 1][x - 1] = '@';
            x++;
        }
    } else if (direction == 'W' or direction == 'w') {
        if (x - deck < 0)
            return 0;
        else {
            for (int i = 0; i < deck; i++) {
                if (player[y - 1][x - 1] == '@')
                    return 0;
                x--;
            }
            x += deck;
        }
        for (int i = 0; i < deck; i++) {
            player[y - 1][x - 1] = '@';
            x--;
        }
    } else if (direction == 'S' or direction == 's') {
        if (y + deck > 9)
            return 0;
        else {
            for (int i = 0; i < deck; i++) {
                if (player[y - 1][x - 1] == '@')
                    return 0;
                y++;
            }
            y -= deck;
        }
        for (int i = 0; i < deck; i++) {
            player[y - 1][x - 1] = '@';
            y++;
        }
    }

    return 1;
}

void fillingFields(char player[10][10]) {
    int x, y;
    char direction;

    for (int fourDeck = 1; fourDeck > 0; fourDeck--) {
        showField(player);
        std::cout << "Deliver a four-deck ship(x[1-10],y[1-10]): ";
        std::cin >> x >> y;
        std::cout << "Enter direction(NEWS):";
        std::cin >> direction;
        if (put(4, player, x, y, direction) == 0) {
            std::cout << "Error!" << std::endl;
            fourDeck++;
        }
    }
    for (int threeDeck = 2; threeDeck > 0; threeDeck--) {
        showField(player);
        std::cout << "Deliver a three-deck ship(x[1-10],y[1-10]): ";
        std::cin >> x >> y;
        std::cout << "Enter direction(NEWS):";
        std::cin >> direction;
        if (put(3, player, x, y, direction) == 0) {
            std::cout << "Error!" << std::endl;
            threeDeck++;
        }
    }
    for (int twoDeck = 3; twoDeck > 0; twoDeck--) {
        showField(player);
        std::cout << "Deliver a two-deck ship(x[1-10],y[1-10]): ";
        std::cin >> x >> y;
        std::cout << "Enter direction(NEWS):";
        std::cin >> direction;
        if (put(2, player, x, y, direction) == 0) {
            std::cout << "Error!" << std::endl;
            twoDeck++;
        }
    }
    for (int oneDeck = 4; oneDeck > 0; oneDeck--) {
        showField(player);
        std::cout << "Deliver a one-deck ship(x[1-10],y[1-10]): ";
        std::cin >> x >> y;
        if (put(1, player, x, y) == 0) {
            std::cout << "Error!" << std::endl;
            oneDeck++;
        }
    }
}


int main() {

    char firstPlayer[10][10], secondPlayer[10][10];
    bool first = 0;

    fillingFieldsVoid(firstPlayer, secondPlayer);

    std::cout << "First Player" << std::endl;
    fillingFields(firstPlayer);

    std::cout << "Second Player" << std::endl;
    fillingFields(secondPlayer);

    showField(firstPlayer);

    while (checkingFieldsWin(firstPlayer, secondPlayer)) {


    }
}