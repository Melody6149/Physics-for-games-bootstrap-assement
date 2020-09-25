#include "PhysicsSceneApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include"PhysicsScene.h"
#include<Gizmos.h>
#include "Sphere.h"
#include "Plane.h"


PhysicsSceneApp::PhysicsSceneApp() {

}

PhysicsSceneApp::~PhysicsSceneApp() {

}

bool PhysicsSceneApp::startup() {
	// increase the 2D line cound to maximize the number of objects
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	glm::vec2  gravity = glm::vec2(0.0f, 0.0f);

	glm::vec2 firstSpherePosition = glm::vec2(0.0f, 0.0f);
	
	Sphere* sphere = new Sphere(glm::vec2(-50.0f, 0.0f), glm::vec2(1000.0f, 0.0f), 1.0f, 3.0f, glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	
	m_physicsScene = new PhysicsScene();
	m_physicsScene->addActor(sphere);

	createballs(firstSpherePosition, 91);

	Plane* rightwall = new Plane(glm::vec2(40.0f, 0.0f), 99.0f);
	Plane* leftwall = new Plane(glm::vec2(40.0f, 0.0f), -99.0f);
	Plane* topwall =  new Plane(glm::vec2(0.0f, 1.0f) , 55.0f);
	Plane* bottomwall =  new Plane(glm::vec2(0.0f, 1.0f) , -50.0f);

	m_physicsScene->setGravity(gravity);
	m_physicsScene->setTimeStep(0.01f);


	/*m_physicsScene->addActor(ball);
	m_physicsScene->addActor(ball2); */
	m_physicsScene->addActor(rightwall);
	m_physicsScene->addActor(leftwall);
	m_physicsScene->addActor(topwall);
	m_physicsScene->addActor(bottomwall);
	//m_physicsScene->addActor(plane2);

	return true;
}



void PhysicsSceneApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void PhysicsSceneApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();


	

	m_physicsScene->update(deltaTime);
	m_physicsScene->updateGizmos();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void PhysicsSceneApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	static float aspectRatio = 16 / 9.0f;
	aie::Gizmos::draw2D(glm::ortho<float>(
		-100.0f, 100.0f,
		-100.0f / aspectRatio, 100.0f / aspectRatio
		));

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}

glm::vec2 PhysicsSceneApp::calculateVelocity(glm::vec2 initialPosition, glm::vec2 finalPosition, float gravity, float time)
{
	glm::vec2 initialVelocity = glm::vec2(0, 0);

	initialVelocity.x = (finalPosition.x - initialPosition.x) / time;
	initialVelocity.y = (finalPosition.y - initialPosition.y - (0.5f * gravity * (time * time)) / time);

	return initialVelocity;
}

void PhysicsSceneApp::createballs(glm::vec2 firstballPosition,int limit)
{
	int ballsNeededForColumn = 1;
	int ballsInColumn = 0;

	glm::vec2 ballposition = firstballPosition;
	glm::vec2 firstballincolumn = ballposition;
	for (int i = 0; i < limit;)
	{
		if (ballsInColumn >= ballsNeededForColumn)
		{
			ballposition = glm::vec2(firstballincolumn.x + 7.0f, firstballincolumn.y + 2.5f);
			ballsInColumn = 0;
			ballsNeededForColumn++;
			firstballincolumn = ballposition;
		}
		else
		{
			Sphere* ball = new Sphere(ballposition, glm::vec2(0.0f, 0.0f), 1.0f, 3.0f, glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
			ballposition = glm::vec2(ballposition.x, ballposition.y - 6.5f);
			m_physicsScene->addActor(ball);
			ballsInColumn++;
			i++;
		}

	}
}
