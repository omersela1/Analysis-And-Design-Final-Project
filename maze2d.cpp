#include "maze2d.h"

int randomize(int size) {
    return (std::rand() % size);
}

std::pair<int, int> randomizePair(int rows, int cols) {
    return std::pair<int, int>(randomize(rows), randomize(cols));
}

maze2d::maze2d() {
    _m.resize(40, std::vector<char>(40, '#'));
}

maze2d::maze2d(int rows, int cols) {
    _m.resize(rows, std::vector<char>(cols, '#'));
}

std::string maze2dGenerator::measureAlgorithmTime() {
    int startTime = time(NULL);
    maze2d m = this->generate(1000, 1000);
    int endTime = time(NULL);
    return ("The algorithm time is: " + std::to_string(endTime - startTime) + " seconds (for 1000x1000 sized matrix).");

}

maze2d simpleMaze2dGenerator::generate(int rows, int cols) {
    maze2d m(rows, cols);
    return m;
}

maze2d PrimMaze2dGenerator::generate(int rows, int cols) {
    maze2d m(rows, cols);
    m.setStartPos(randomizePair(rows, cols));
    m.setEndPos(randomizePair(rows, cols));
    m.setCellValue(m.getStartPos(), ' ');
    m.setCellValue(m.getEndPos(), ' ');


    std::vector<std::pair<int, int> > frontier;
    frontier.reserve(rows);
    frontier.push_back(m.getStartPos());
    std::vector<std::pair<int, int> > startNeighbors = findValidNeighbours(m.getMaze(), m.getStartPos());
    while (!startNeighbors.empty()) {
        int randomNeighbor = std::rand() % startNeighbors.size();
         frontier.push_back(startNeighbors[randomNeighbor]);
         startNeighbors.erase(startNeighbors.begin() + randomNeighbor);
    }

    while (!frontier.empty()) {
        int randomIndex = std::rand() % frontier.size();
        std::pair<int, int> randomPosition = frontier[randomIndex];
        frontier.erase(frontier.begin() + randomIndex);
        std::vector<std::pair<int, int> > neighbours = findValidNeighbours(m.getMaze(), randomPosition);
        if (!neighbours.empty()) {
            int getRandomNeighbour = std::rand() % neighbours.size();
             std::pair<int, int> randomNeighbour = neighbours[getRandomNeighbour];
             frontier.push_back(randomNeighbour);
        }
        m.setCellValue(randomPosition, ' ');
    }

     frontier.push_back(m.getEndPos());
     std::vector<std::pair<int, int> > endNeighbors = findValidNeighbours(m.getMaze(), m.getStartPos());
    while (!endNeighbors.empty()) {
        int randomNeighbor = std::rand() % startNeighbors.size();
         frontier.push_back(endNeighbors[randomNeighbor]);
         endNeighbors.erase(endNeighbors.begin() + randomNeighbor);
    }
       while (!frontier.empty()) {
        int randomIndex = std::rand() % frontier.size();
        std::pair<int, int> randomPosition = frontier[randomIndex];
        frontier.erase(frontier.begin() + randomIndex);
        std::vector<std::pair<int, int> > neighbours = findValidNeighbours(m.getMaze(), randomPosition);
        if (!neighbours.empty()) {
            int getRandomNeighbour = std::rand() % neighbours.size();
             std::pair<int, int> randomNeighbour = neighbours[getRandomNeighbour];
             frontier.push_back(randomNeighbour);
        }
        m.setCellValue(randomPosition, ' ');
    }

    m.setCellValue(m.getStartPos(), 'S');
    m.setCellValue(m.getEndPos(), 'E');

    return m;
}

std::vector<std::pair<int, int> > PrimMaze2dGenerator::findValidNeighbours(const std::vector<std::vector<char> >& m, const std::pair<int, int>& pos) {
    std::vector<std::pair<int, int> > neighbours;
    neighbours.clear();
    if ((pos.first > 1) && (m[pos.first - 1][pos.second] == '#')) {
        neighbours.push_back(std::make_pair(pos.first - 1, pos.second));
    }

    if ((pos.first < m.size() - 2) && (m[pos.first + 1][pos.second] == '#')) {
        neighbours.push_back(std::make_pair(pos.first + 1, pos.second));
    }

    if ((pos.second > 1) && (m[pos.first][pos.second - 1] == '#')) {
        neighbours.push_back(std::make_pair(pos.first, pos.second - 1));
    }

    if ((pos.second < m[0].size() - 2) && (m[pos.first][pos.second + 1] == '#')) {
        neighbours.push_back(std::make_pair(pos.first, pos.second + 1));
    }

    return neighbours;
}


std::vector<std::pair<int, int> > maze2d::getPossibleMoves(const std::pair<int, int>& pos) {
    std::vector<std::pair<int,int> > clearCells;
    clearCells.clear();
    if ((pos.first > 0) && ((_m[pos.first - 1][pos.second]) == ' ')) {
        clearCells.push_back(std::make_pair(pos.first - 1, pos.second));
    }
    if ((pos.first < _m.size()) && ((_m[pos.first + 1][pos.second]) == ' ')) {
        clearCells.push_back(std::make_pair(pos.first + 1, pos.second));
    }
     if ((pos.second > 0) && ((_m[pos.first][pos.second - 1]) == ' ')) {
        clearCells.push_back(std::make_pair(pos.first, pos.second - 1));
    }
     if ((pos.second < _m[0].size()) && ((_m[pos.first][pos.second + 1]) == ' ')) {
        clearCells.push_back(std::make_pair(pos.first, pos.second + 1));
    }

    return clearCells;
    
}

void maze2d::setCellValue(const std::pair<int, int>& pos, const char& val) {
    if (_m[pos.first][pos.second] != val) {
        _m[pos.first][pos.second] = val;
    }
    
}

