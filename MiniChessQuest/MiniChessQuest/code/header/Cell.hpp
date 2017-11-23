#ifndef CELL_HEADER
#define CELL_HEADER

#include <string>

class Cell
{
public:

	char inner;

private:

	char original_inner;

public:
	Cell();
	~Cell();

	inline const char GetCell()
	{
		return inner;
	}

	inline void Reset() { inner = original_inner; }

private:
	
};


#endif //CELL_HEADER