/*
  ==================================================================================================================

	Scale.h
	Created: 03 Feb 2022 9:09:55pm
	Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

#include <string>

/// <summary>
/// The available scale modes.
/// </summary>
enum class ScaleMode
{
	// Major scale
	MAJOR,
	// Minor scale
	MINOR,
	// Chromatic scale. The root is always C.
	CHROMATIC
};

/// <summary>
/// The available keys.
/// </summary>
enum class Key
{
	// C
	C = 0,
	// C# / Db
	Cs = 1,
	// D
	D = 2,
	// D# / Eb
	Ds = 3,
	// E
	E = 4,
	// F
	F = 5,
	// F# / Gb
	Fs = 6,
	// G
	G = 7,
	// G# / Ab
	Gs = 8,
	// A
	A = 9,
	// A# / Bb
	As = 10,
	// B
	B = 11,
};

/// <summary>
/// Represents a musical (diatonic or chromatic) scale.
/// </summary>
class Scale
{
public:
	Scale();
	~Scale();

	// MEMBER FUNCTIONS
	//==============================================================================================================
	ScaleMode getMode() const;
	int getNoteFromDegree(int degree) const;
	void setKey(Key key);
	void setMode(ScaleMode mode);
	
private:
	// MEMBER VARIABLES
	//==============================================================================================================
	Key m_Key;
	ScaleMode m_Mode;
	int m_Root;

	// CONSTANTS
	//==============================================================================================================
	const int MIDDLE_C = 60;
};

