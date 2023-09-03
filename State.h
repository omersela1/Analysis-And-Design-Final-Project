#pragma once

#include <string>
#include <memory>
using namespace std;

template <class T>
class State
{
public:
	State(): m_state(), m_cost(0), m_cameFrom() {};
	State(const T& state): m_state(state), m_cost(0), m_cameFrom(nullptr){}
	State(const State& other) 
        : m_state(other.m_state), m_cost(other.m_cost), m_cameFrom(other.m_cameFrom) {}
	~State() {};

public:
	bool operator == (State& s) { return ((m_state.first == s.m_state.first) && (m_state.second == s.m_state.second)); }
	bool operator != (State& s) { return ((m_state.first != s.m_state.first) || (m_state.second != s.m_state.second));  };
	State& operator= (const State& s) { m_state = s.m_state; m_cost = s.m_cost; m_cameFrom = std::move(s.m_cameFrom); return *this; };
	T& getState() { return m_state; }
	void setCost(double cost) { m_cost = cost; };
	void setCameFrom(State* s) { m_cameFrom = s; };

private:
	T					m_state;
	double				m_cost;
	shared_ptr<State>	m_cameFrom;
};

