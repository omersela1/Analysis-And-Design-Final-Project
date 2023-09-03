#include "testMazeGenerator.h"

void TestMazeGenerator::testMazeGenerator(maze2dGenerator* m2g) {
    std::cout << m2g->measureAlgorithmTime() << std::endl;
    maze2d m = m2g->generate(100, 100);
    std::pair<int, int> startPos = m.getStartPos();
    std::pair<int, int> endPos = m.getEndPos();
    std::vector<std::pair<int, int> > allPossibleMoves = m.getPossibleMoves(m.getStartPos());
    for (int i = 0; i < allPossibleMoves.size(); i++) {
        std::cout << allPossibleMoves[i].first << "," << allPossibleMoves[i].second << std::endl;
    }
}