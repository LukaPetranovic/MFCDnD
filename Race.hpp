#pragma once
class Race
{
public:
	CString name;
	int strengthModifier, dexterityModifier, constitutionModifier,
		intelligenceModifier, wisdomModifier, charismaModifier;

	Race()
		: strengthModifier(8),
		dexterityModifier(8),
		constitutionModifier(8),
		intelligenceModifier(8),
		wisdomModifier(8),
		charismaModifier(8)
	{}
};