#include <iostream>
#include <queue>
#include "State.h"
#include "Searchable.h"
#include "Adapter.h"
#include "Demo.h"
#include "CLI.h"
#include "maze2d.h"
#include "testMazeGenerator.h"
#include "Controller.h"
#include "Model.h"
#include "BFS.h"


using namespace std;

//creating commands for CLI:
static Model<maze2d> mazeModel;
static Model<Searchable<std::pair<int, int> > > searchableModel;
CLI cli(std::cin, std::cout);
Controller control;


void generate(std::string s);
void display(std::string s);
void solve(std::string s);

int main()
{

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	//Command pattern:
	cli.getOut() << "MAZE PROGRAM - Enter the required action" << std::endl;
	control.addCommandToCLI(cli, "generate maze", generate);
	control.addCommandToCLI(cli, "display maze", display);
	control.addCommandToCLI(cli, "solve maze", solve);
	cli.start();

	//Demo:
	Demo demo;
	demo.run();

	//testMaze:
	PrimMaze2dGenerator* m2g = new PrimMaze2dGenerator();
	TestMazeGenerator tmg;
	tmg.testMazeGenerator(m2g);
	return 0;
}








//functions for command pattern (must have access to main's cli and mazeModel objects):

void generate(std::string s) {
	std::string getName;
	std::istream& is = cli.getIn();
	std::ostream& os = cli.getOut();
	os << "Enter name for new maze: ";
	is >> getName;
	PrimMaze2dGenerator m2g;
	maze2d maze = m2g.generate(40, 40);
	mazeModel.addToModel(getName, &maze);
	os << getName << " added to model." << std::endl;
	is.clear();
	os.clear();
}

void display(std::string s) {
	std::string getName;
	std::istream& is = cli.getIn();
	std::ostream& os = cli.getOut();
	os << "Name of maze to be displayed: ";
	is >> getName;
	maze2d maze = *(mazeModel[getName]);
	for (int i = 0; i < maze.getMaze().size(); i++) {
		for (int j = 0; j < maze.getMaze()[0].size(); j++) {
			cli.getOut() << maze.getMaze()[i][j];
		}
		os << std::endl;
	}
	is.clear();
	os.clear();
}


void solve(std::string s) {
	std::string getName;
	std::istream& is = cli.getIn();
	std::ostream& os = cli.getOut();
	os << "Name of maze to solve: ";
	is >> getName;
	maze2d maze = *(mazeModel[getName]);
	Adapter<std::pair<int, int> > adapter;
	//BFS has implementation but doesn't work because of comparison operators:
	// BFS<std::pair<int, int> >* bfs = new BFS<std::pair<int, int> >();
	// Solution<std::pair<int, int> > solution = bfs->search(adapter.searchAdapt(maze));
}



