#include "Demo.h"

void Demo::run() {
    PrimMaze2dGenerator m2g;
    maze2d m = m2g.generate(40,40);
    std::cout << "Maze starting point: " << m.getStartPos().first << "," << m.getStartPos().second << std::endl;
    std::cout << "Maze goal point: " << m.getEndPos().first << "," << m.getEndPos().second << std::endl;
    for (int i = 0; i < m.getMaze().size(); i++) {
		for (int j = 0; j < m.getMaze()[0].size(); j++) {
			cout << m.getMaze()[i][j];
		}
		cout << endl;
	}
    
}