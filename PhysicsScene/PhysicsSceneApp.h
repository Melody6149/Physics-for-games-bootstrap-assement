#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "PhysicsScene.h"

class PhysicsSceneApp : public aie::Application {
public:

	PhysicsSceneApp();
	virtual ~PhysicsSceneApp();

	/// This runs at startup
	virtual bool startup();
	/// This runs at shutdown
	virtual void shutdown();
	/// updates the program
	virtual void update(float deltaTime);
	/// calls functions related to drawing
	virtual void draw();

	
	/// Used to calculate velocity
	glm::vec2 calculateVelocity(glm::vec2 initialPosition, glm::vec2 finalPosition, float gravity, float time);
	/// The function used to spawn the balls
	void createballs(glm::vec2 firstballPosition , int limit);

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	///The PhysicsScene
	PhysicsScene*		m_physicsScene;
};