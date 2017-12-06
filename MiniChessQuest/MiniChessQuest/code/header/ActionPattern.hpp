#ifndef __ACTION_PATTERN_HEADER__
#define __ACTION_PATTERN_HEADER__

#include <vector>
#include <memory>
#include "Action.hpp"

class ActionPattern
{

public:

	typedef std::vector<std::shared_ptr<Action>> actionSequence;
	typedef std::vector<actionSequence> actionSequences;
	actionSequences possible_actions;

public:

	ActionPattern() {}
	~ActionPattern() { possible_actions.clear(); }

	inline void AddAction(std::shared_ptr<Action> action)
	{
		possible_actions.push_back(actionSequence{ action });
	}
	inline void AddAction(std::shared_ptr<Action> action, int pos)
	{
		possible_actions[pos].push_back(action);
	}

	inline void AddSequence(actionSequence sequence)
	{
		possible_actions.push_back(sequence);
	}

	void TemporalAction() 
	{
		//TODO:
	}
	void TemporalSequence() 
	{
		//TODO:
	}


private:

};

#endif //__ACTION_PATTERN_HEADER__