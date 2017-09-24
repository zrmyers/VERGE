/*
 * Application.h
 *
 *  Created on: Sep 16, 2017
 *      Author: Zane
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <string>
#include <memory>
//#include "GL.h"
#include "VERGE/EntitySystem/EntitySystem.h"
#include "VERGE/ResourceSystem/ResourceSystem.h"

class Application
{
public:
	Application(std::string appName = "OpenGL App");
	~Application();

	void Run();

private:
	std::string appName;

private:
	//SDL
	//SDL_Window* window;
	//SDL_GLContext context;

	std::shared_ptr<VERGE::ResourceSystem> resourceSystem;
	std::shared_ptr<VERGE::EntitySystem> entitySystem;
};

#endif /* APPLICATION_H_ */
