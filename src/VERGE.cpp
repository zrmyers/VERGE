//============================================================================
// Name        : VERGE.cpp
// Author      : Zane R. Myers
// Version     : 1.0
// Copyright   : Property of Verge Software
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Application.h"

int main() {

	Application* app = new Application("VR Game");

	app->Run();

	delete app;

	return 0;
}
