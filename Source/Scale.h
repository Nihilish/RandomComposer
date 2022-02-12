#pragma once

#include <string>

enum class ScaleMode
{
	MAJOR,
	MINOR,
	CHROMATIC
};

enum class Key
{
	C = 0,
	Cs = 1,
	D = 2,
	Ds = 3,
	E = 4,
	F = 5,
	Fs = 6,
	G = 7,
	Gs = 8,
	A = 9,
	As = 10,
	B = 11,
};


class Scale
{
public:
	Scale();
	~Scale();

	int getNoteFromDegree(int degree);
	void setKey(Key key);
	void setMode(ScaleMode mode);
	ScaleMode getMode();
	std::string toString();
	
private:
	Key m_Key;
	ScaleMode m_Mode;
	int m_Root;

	const int MIDDLE_C = 60;
};

