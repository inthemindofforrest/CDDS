#include "raylib.h"
#include <string>

using std::string;

class MAAP
{

private:
	//Vars
	bool enabled = true;
	Texture2D texture;

	Vector2 Position;

	bool PlayerControl;

public:
	// Constructors & Destructors
	MAAP();
	MAAP(bool Enabled, const string FileName, bool NewPlayerControl);
	~MAAP();

	// Misc Functions
	void refresh();
	void Move();


};