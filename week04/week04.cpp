#include "queue.h"
#include <vector>

const int ROWS = 4, COLS = 5;

char kasetka[ROWS][COLS] = { { 'b', 'g', 'x', 'x', 'g'},
                             { 'g', 'x', 'g', 'x', 'x'},
                             { 'g', 'x', 'g', 'b', 'x'},
                             { 'g', 'g', 'g', 'g', 'x'} };

struct Position {
    int row;
    int col;

    Position left() const {
        return {row, col - 1};
    }
    Position right() const {
        return {row, col + 1};
    }
    Position up() const {
        return {row - 1, col};
    }
    Position down() const {
        return {row + 1, col};
    }

    bool isValid() const {
        return row >= 0 && row < ROWS && col >= 0 && col < COLS;
    }
    
    bool operator==(const Position& other) {
        return row == other.row && col == other.col;
    }
};

std::vector<Position> findNeighbors(Position current) {
    std::vector<Position> neighbors;

    if (current.left().isValid()) {
        neighbors.push_back(current.left());
    }
    if (current.right().isValid()) {
        neighbors.push_back(current.right());
    }
    if (current.up().isValid()) {
        neighbors.push_back(current.up());
    }
    if (current.down().isValid()) {
        neighbors.push_back(current.down());
    }

    return neighbors;
}

int timeToRotAll() {
    Queue<Position> q;
    int time = 0;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (kasetka[i][j] == 'b') {
                q.push({i, j});
            }
        }
    }

    Position delimiter{ROWS, COLS};
    q.push(delimiter);

    while (!q.isEmpty()) {
        Position current = q.front();
        q.pop();

        if (current == delimiter) {
            if (!q.isEmpty()) {
                q.push(delimiter);
                ++time;
            } else {
                break;
            }
        }

        std::vector<Position> neighbors = findNeighbors(current);

        for (Position neighbor : neighbors) {
            char& pos = kasetka[neighbor.row][neighbor.col];

            if (pos == 'g') {
                q.push(neighbor);
                pos = 'b';
            }
        }
    }

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (kasetka[i][j] == 'g') {
                return -1;
            }
        }
    }

    return time;
}

int main() {

    std::cout << timeToRotAll() << std::endl;

    return 0;
}