#include "CharacterCounter.h"


int fTotalNumberOfCharacters;
int fCharacterCounts[256];

CharacterCounter::CharacterCounter()
{
    for (int i = 0; i < 256; i++)
    {
        fCharacterCounts[i] = 0;
    }
    fTotalNumberOfCharacters = 0;
}

void CharacterCounter::count(unsigned char aCharacter)
{
    fCharacterCounts[aCharacter] ++;
    fTotalNumberOfCharacters++;
}

// new in tutorial 5: indexer
const int CharacterCounter::operator[](unsigned char aCharacter) const
{
	return fCharacterCounts[aCharacter];
}

std::ostream& operator<<(std::ostream& aOStream, const CharacterCounter& aCharacterCounter)
{
	aOStream << "Total Number of Characters: " << aCharacterCounter.fTotalNumberOfCharacters << std::endl;
	for (int i = 0; i < 256; i++)
	{
		if (aCharacterCounter.fCharacterCounts[i] != 0) {
			aOStream << (char)i << " :" << "\t" << aCharacterCounter.fCharacterCounts[i] << std::endl;
		}
	}

	return aOStream;
}