/*
  ==================================================================================================================

	Scale.cpp
	Created: 03 Feb 2022 9:09:55pm
	Author:  Nihilish

  ==================================================================================================================
*/

#include "Scale.h"

#include <stdexcept>
#include <iostream>

#include "Defaults.h"


Scale::Scale() :
	m_Key(static_cast<Key>(app::Defaults::defaultKey)),
	m_Mode(ScaleMode::MAJOR)
{
	m_Root = MIDDLE_C;
}

Scale::~Scale()
{
}

/// <summary>
/// Gets the scale's mode.
/// </summary>
/// <returns>The scale's mode.</returns>
ScaleMode Scale::getMode() const
{
	return m_Mode;
}

/// <summary>
/// Takes in a scale degree and returns the corresponding note from the scale.
/// </summary>
/// <param name="degree">The degree for which to return the note.</param>
/// <returns>The MIDI note value (Middle C is 60).</returns>
int Scale::getNoteFromDegree(int degree) const
{
	if (degree < 1 || degree > 12 || !(m_Mode == ScaleMode::CHROMATIC) && degree > 7)
		throw std::invalid_argument
		(
			"Scale degrees should be contained within 1 (root) and 7 (leading tone) for" 
			"diatonic modes or 1 and 12 for chromatic."
		);
	
	switch (m_Mode)
	{
		// T - T - ST - T - T - T (- ST)
		case ScaleMode::MAJOR:
		{
			switch (degree)
			{
			case 1:
				return m_Root;
			case 2:
				return m_Root + 2;
			case 3:
				return m_Root + 4;
			case 4:
				return m_Root + 5;
			case 5:
				return m_Root + 7;
			case 6:
				return m_Root + 9;
			case 7:
				return m_Root + 11;
			default:
				return m_Root;
			}
		}

		// T - ST - T - T - ST - T (- T)
		case ScaleMode::MINOR:
		{
			switch (degree)
			{
			case 1:
				return m_Root;
			case 2:
				return m_Root + 2;
			case 3:
				return m_Root + 3;
			case 4:
				return m_Root + 5;
			case 5:
				return m_Root + 7;
			case 6:
				return m_Root + 8;
			case 7:
				return m_Root + 10;
			default:
				return m_Root;
			}
		}

		case ScaleMode::CHROMATIC:
		{
			switch (degree)
			{
			case 1:
				return MIDDLE_C;
			case 2:
				return MIDDLE_C + 1;
			case 3:
				return MIDDLE_C + 2;
			case 4:
				return MIDDLE_C + 3;
			case 5:
				return MIDDLE_C + 4;
			case 6:
				return MIDDLE_C + 5;
			case 7:
				return MIDDLE_C + 6;
			case 8:
				return MIDDLE_C + 7;
			case 9:
				return MIDDLE_C + 8;
			case 10:
				return MIDDLE_C + 9;
			case 11:
				return MIDDLE_C + 10;
			case 12:
				return MIDDLE_C + 11;
			default:
				return MIDDLE_C;
			}
		}

		default:
			return 0;
	}
}

/// <summary>
/// Sets the scale's key.
/// </summary>
/// <param name="key">The new key.</param>
void Scale::setKey(Key key)
{
	m_Key = key;
	m_Root = MIDDLE_C + static_cast<int>(m_Key);
}

/// <summary>
/// Sets the scale's mode.
/// </summary>
/// <param name="mode">The new mode.</param>
void Scale::setMode(ScaleMode mode)
{
	m_Mode = mode;
}