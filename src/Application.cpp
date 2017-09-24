/*
 * Application.cpp
 *
 *  Created on: Sep 16, 2017
 *      Author: Zane
 */

#include "Application.h"

#include <iostream>
#include <chrono>
#include <memory>

Application::Application(std::string appName) :
	appName(appName)
{
	std::cout << "Initializing Application!" << std::endl;
	// initialize SDL
	/*SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	window = SDL_CreateWindow(appName.c_str(), 100, 100, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	// initialize SDL_image
	IMG_Init(IMG_INIT_PNG);

	// initialize OpenGL
	context = SDL_GL_CreateContext(window);
	glewExperimental = GL_TRUE;
	glewInit();*/

	//Utility::DebugLog("Loading triangle from file...");
	entitySystem = VERGE::EntitySystem::getEntitySystem();
	resourceSystem = VERGE::ResourceSystem::getResourceSystem();
}

Application::~Application() {
	std::cout << "Destroying Application!" << std::endl;
	// destroy img loader
	/*IMG_Quit();

	// destroy SDL
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();*/
}

void Application::Run() {
	std::cout << "Running Application!" << std::endl;

	std::shared_ptr<VERGE::Entity> crate = entitySystem->loadEntityFromFile("Data/Entities/Crate.xml");
	std::cout << "Got a crate with ID: " << crate->getID() << std::endl;

	auto timeStart = std::chrono::high_resolution_clock::now();
	auto timeFrameBegin = timeStart;
	auto timePerFrame = timeStart - timeStart;
	//SDL_Event windowEvent;
	while (true) {
		/*if (SDL_PollEvent(&windowEvent)) {
			if (windowEvent.type == SDL_QUIT || (windowEvent.type == SDL_KEYUP && windowEvent.key.keysym.sym == SDLK_ESCAPE)) {
				break;
			}
		}*/

		// calculate time per frame
		auto timeCurrent = std::chrono::high_resolution_clock::now();
		timePerFrame = timeCurrent - timeFrameBegin;
		timeFrameBegin = timeCurrent;
		float tpf = std::chrono::duration_cast<std::chrono::duration<float>>(timePerFrame).count();
		//glClearColor(0.2f, 0.0f, 0.0f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT);


		//	for each vertexArray object
		//		for each shader program
		//			for each texture
		//				for each vertex buffer
		//					Draw Vertex Buffer



		//SDL_GL_SwapWindow(window);
	}


}



