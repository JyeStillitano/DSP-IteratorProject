#include "CharacterFrequencyIterator.h"

// constructor: takes a read-only reference to character counter and
//                    a Boolean flag to indicate whether or not to sort
// iterator positioned on first non-zero character map, or 257th
CharacterFrequencyIterator::CharacterFrequencyIterator(const CharacterCounter& aCounter, bool aSort)
{
	for (int i = 0; i < 256; i++)
	{
		fMap[i] = CharacterMap((char)i, aCounter.operator[](i));
	}
	fIndex = 0;
	if (aSort) { sort(); }
}

// advance index to the next non-zero frequency
void CharacterFrequencyIterator::advanceIndex()
{
	operator++();
	while (operator*().getFrequency() == 0)
	{
		operator++();
	}
}

// sort method: Bubble Sort, decreasing order (push highest to left)
void CharacterFrequencyIterator::sort()
{
	int i, j;
	for (i = 0; i < 255; i++)
	{
		for (j = 0; j < 255 - i; j++)
		{
			if (!(fMap[j].operator>(fMap[j + 1]))) 
			{
				CharacterMap temp = fMap[j];
				fMap[j] = fMap[j + 1];
				fMap[j + 1] = temp;
			}
		}
	}
}

// forward iterator interface
// returns current frequency map
const CharacterMap& CharacterFrequencyIterator::operator* () const
{
	return fMap[fIndex];
}

// prefix increment
CharacterFrequencyIterator& CharacterFrequencyIterator::operator++()
{
	fIndex++;
	return *this;
}

// postfix increment
CharacterFrequencyIterator CharacterFrequencyIterator::operator++(int)
{
	CharacterFrequencyIterator temp = *this;
	fIndex++;
	return temp;
}

bool CharacterFrequencyIterator::operator==(const CharacterFrequencyIterator& aOther) const
{
	return ((fMap == aOther.fMap) && (fIndex == aOther.fIndex));
}

bool CharacterFrequencyIterator::operator!=(const CharacterFrequencyIterator& aOther) const
{
	return ((fMap != aOther.fMap) && (fIndex != aOther.fIndex));
}

// return iterator positioned at first non-zero
CharacterFrequencyIterator CharacterFrequencyIterator::begin() const
{
	CharacterFrequencyIterator temp = *this;
	temp.fIndex = 0;
	return temp;
}

// return iterator positioned at 256
CharacterFrequencyIterator CharacterFrequencyIterator::end() const
{
	CharacterFrequencyIterator temp = *this;
	temp.fIndex = 256;
	return temp;
}