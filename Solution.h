#pragma once
#include <iostream>
#include <vector>
#include "State.h"

template <class T>
class Solution
{
public:
	Solution() {};
	~Solution() {};
	void setSolutionPath(std::priority_queue<State<T> > q) { while (!q.empty()) { m_solution.push_back(std::make_shared(q.pop()));}};

private:
	std::vector<shared_ptr<State<T> > > m_solution;
};

