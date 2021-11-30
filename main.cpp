#include <iostream>

void fillingFieldsVoid(char firstPlayer[10][10], char secondPlayer[10][10]) {
    const char emptyField = 'o';
    const int maxHeightAndWidth = 10;
    for (int i = 0; i < maxHeightAndWidth; i++)
        for (int j = 0; j < maxHeightAndWidth; j++) {
            firstPlayer[i][j] = emptyField;
            secondPlayer[i][j] = emptyField;
        }
}

bool checkingFieldsWin(char firstPlayer[10][10], char secondPlayer[10][10]) {
    bool win = 1;
    const char ship = '@';
    const int maxHeightAndWidth = 10;

    for (int i = 0; i < maxHeightAndWidth; i++)
        for (int j = 0; j < maxHeightAndWidth; j++) {
            if (secondPlayer[i][j] == ship)
                win = 0;
        }
    if (win != 0) {
        std::cout << "First win!!";
        return 0;
    } else win = 1;

    for (int i = 0; i < maxHeightAndWidth; i++)
        for (int j = 0; j < maxHeightAndWidth; j++) {
            if (firstPlayer[i][j] == ship)
                win = 0;
        }
    if (win != 0) {
        std::cout << "Second win!!";
        return 0;
    }
    return 1;
}

void showField(char player[10][10]) {
    const int maxHeightAndWidth = 10;
    for (int i = 0; i < maxHeightAndWidth; i++) {
        for (int j = 0; j < maxHeightAndWidth; j++)
            std::cout << player[i][j] << " ";
        std::cout << std::endl;
    }
}

bool put(int deck, char player[10][10], int x, int y, char direction = 'N') {
    x -= 1;
    y -= 1;
    const int maxHeightAndWidth = 10;
    const int minHeightAndWidth = 10;
    const char ship = '@';
    if (x < minHeightAndWidth or x > maxHeightAndWidth or y < minHeightAndWidth or y > maxHeightAndWidth) {
        return 0;
    }
    if (deck == 1 and player[y][x] == ship) {
        return 0;
    } else if (direction == 'N' or direction == 'n') {
        if (y - deck < minHeightAndWidth)
            return 0;
        else {
            for (int i = 0; i < deck; i++) {
                if (player[y][x] == ship)
                    return 0;
                y--;
            }
            y += deck;
        }
        for (int i = 0; i < deck; i++) {
            player[y][x] = ship;
            y--;
        }
    } else if (direction == 'E' or direction == 'e') {
        if (x + deck > maxHeightAndWidth)
            return 0;
        else {
            for (int i = 0; i < deck; i++) {
                if (player[y][x] == ship)
                    return 0;
                x++;
            }
            x -= deck;
        }
        for (int i = 0; i < deck; i++) {
            player[y][x] = ship;
            x++;
        }
    } else if (direction == 'W' or direction == 'w') {
        if (x - deck < minHeightAndWidth)
            return 0;
        else {
            for (int i = 0; i < deck; i++) {
                if (player[y][x] == ship)
                    return 0;
                x--;
            }
            x += deck;
        }
        for (int i = 0; i < deck; i++) {
            player[y][x] = ship;
            x--;
        }
    } else if (direction == 'S' or direction == 's') {
        if (y + deck > maxHeightAndWidth)
            return 0;
        else {
            for (int i = 0; i < deck; i++) {
                if (player[y][x] == ship)
                    return 0;
                y++;
            }
            y -= deck;
        }
        for (int i = 0; i < deck; i++) {
            player[y][x] = ship;
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

void battle(char playerField[10][10], char playerBattleField[10][10], char secondPlayerField[10][10], bool queue) {
    int x, y;
    const char ship = '@';
    const char emptyField = 'o';

    std::cout << "Your field:" << std::endl;
    showField(playerField);
    std::cout << "Your battle field:" << std::endl;
    showField(playerBattleField);
    std::cout << "Enter x(1-10) and y(1-10): ";
    std::cin >> x >> y;
    x -= 1;
    y -= 1;
    if (x < 0 or x > 10 or y < 0 or y > 10 or secondPlayerField[x][y] != ship or
        secondPlayerField[x][y] != emptyField) {
        std::cout << "Error!!" << std::endl << "Try again!" << std::endl;
        if (queue == 1)
            queue = 0;
        else queue = 1;
    } else if (secondPlayerField[x][y] == ship) {
        std::cout << "You hit the target!" << std::endl;
        playerBattleField[x][y] = 'x';
        secondPlayerField[x][y] = 'x';
    } else {
        std::cout << "You missed the target!" << std::endl;
        playerBattleField[x][y] = 'x';
        secondPlayerField[x][y] = 'x';
    }
}


int main() {

    char firstPlayer[10][10], secondPlayer[10][10];
    char firstPlayerBattleField[10][10], secondBattleField[10][10];
    bool queue = 1;

    fillingFieldsVoid(firstPlayer, secondPlayer);
    fillingFieldsVoid(firstPlayerBattleField, secondBattleField);

    std::cout << "First Player" << std::endl;
    fillingFields(firstPlayer);

    std::cout << "Second Player" << std::endl;
    fillingFields(secondPlayer);

    showField(firstPlayer);

    while (checkingFieldsWin(firstPlayer, secondPlayer)) {
        if (queue == 1) {
            std::cout << "First player:" << std::endl;
            battle(firstPlayer, firstPlayerBattleField, secondPlayer, queue);
            queue = 0;
        } else {
            std::cout << "Second player:" << std::endl;
            battle(secondPlayer, secondBattleField, firstPlayer, queue);
            queue = 1;
        }
    }
}