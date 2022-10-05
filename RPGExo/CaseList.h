#pragma once

class CaseList
{
private:
	int precValue;
	int nextValue;

public:
	CaseList() = default;
	CaseList(int _precValue, int _nextValue)
	{
		precValue = _precValue;
		nextValue = _nextValue;
	}


};

