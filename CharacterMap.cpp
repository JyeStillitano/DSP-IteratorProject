#include "CharacterMap.h"

// constructor with default arguments, it becomes a default constructor
CharacterMap::CharacterMap(unsigned char aCharacter, int aFrequency) 
{
	fCharacter = aCharacter;
	fFrequency = aFrequency;
}

// binary greater than operator, this is left, compare frequencies only
bool CharacterMap::operator>(const CharacterMap& aRight) const
{
	return (fFrequency > aRight.fFrequency);
}

// getters for character and frequency
const unsigned char CharacterMap::getCharacter() const
{
	return fCharacter;
}

const int CharacterMap::getFrequency() const
{
	return fFrequency;
}