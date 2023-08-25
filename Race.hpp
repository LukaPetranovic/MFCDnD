#pragma once
class Race
{
private:
	CString name;
	int strengthModifier, dexterityModifier, constitutuionModifier,
		intelligenceModifier, wisdomModifier, charismaModifier;

public:
	Race()
		:strengthModifier(8),
		dexterityModifier(8),
		constitutuionModifier(8),
		intelligenceModifier(8),
		wisdomModifier(8),
		charismaModifier(8)
	{}
};