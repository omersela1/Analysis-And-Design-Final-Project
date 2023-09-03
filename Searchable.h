#pragma once

#include <vector>
#include "State.h"
#include "maze2d.h"

template <class T>
class SearchableInterface
{
public:
	virtual State<T> getStartState() const = 0;
	virtual State<T> getGoalState() const = 0;
	virtual std::vector<State<T> > getAllPossibleStates() = 0;
};




template <class T>
class Searchable : public SearchableInterface<T>
{
	State<T> startState;
	State<T> goalState;
	std::vector<State<T> >* allStates;
public:
	Searchable(): startState(), goalState(), allStates() {};
	Searchable(Searchable& s);
	State<T> getStartState() const { return startState; };
	State<T> getGoalState() const { return goalState; };
	std::vector<State<T> > getAllPossibleStates() { return *allStates; };
	void setStartState(const State<T>& state) { startState = state; };
	void setGoalState(const State<T>& state) { goalState = state; };
	void setAllState(std::vector<State<T> >* states) { delete allStates; allStates = states; };
};


