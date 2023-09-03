#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

class maze2d {
    std::vector<std::vector<char> > _m;
    std::pair<int, int> startPos;
    std::pair<int, int> endPos;

    public:
    maze2d();
    maze2d(int rows, int cols);
    std::vector<std::vector<char> > getMaze() { return _m; };
    std::pair<int, int> getStartPos() { return this->startPos; };
    void setStartPos(std::pair<int, int> p) { this->startPos = p; };
    std::pair<int, int> getEndPos() { return this->endPos; };
    void setEndPos(std::pair<int, int> p) { this->endPos = p; };
    void setCellValue(const std::pair<int, int>& pos, const char& val);
    std::vector<std::pair<int, int> > getPossibleMoves(const std::pair<int, int>& pos);
};

class maze2dGeneratorInterface {

    public:
    virtual maze2d generate(int rows, int cols) = 0;
    virtual std::string measureAlgorithmTime() = 0;
};

class maze2dGenerator : public maze2dGeneratorInterface {

    public:
    virtual maze2d generate(int rows, int cols) = 0;
    std::string measureAlgorithmTime();
};

class simpleMaze2dGenerator : public maze2dGenerator {

    public:
    maze2d generate(int rows, int cols);
};

class PrimMaze2dGenerator : public maze2dGenerator {

    public:
    maze2d generate(int rows, int cols);
    std::vector<std::pair<int, int> > findValidNeighbours(const std::vector<std::vector<char> >& m, const std::pair<int, int>& pos);
};