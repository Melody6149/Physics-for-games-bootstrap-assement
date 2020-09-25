#pragma once
#include "glm\ext.hpp"
#include "PhysicsObject.h"
#include <vector>


/// This class is used for all functions related to the scene
class PhysicsScene
{
public:
	/// Constructor used for physicsscene
	PhysicsScene();
	~PhysicsScene();

	///Used to add actors to the scene
	void addActor(PhysicsObject* actor);
	///Used to remove actors from the scene
	void removeActor(PhysicsObject* actor);
	/// updates physics
	void update(float deltaTime);
	/// used to check for collision
	void checkForCollision();
	/// updates gizmos
	void updateGizmos();
	void debugScene();
	
	/// sets the gravity of the scene
	void setGravity(const glm::vec2 gravity) { m_gravity = gravity; }
	/// Gets the gravity
	glm::vec2 getGravity() const { return m_gravity; }
	/// Sets the timestep
	void setTimeStep(const float timeStep) { m_timeStep = timeStep; }
	/// gets the timestep
	float getTimeStep() const { return m_timeStep; }

	///Checks for collision between 2 planes
	static bool planeToPlane(PhysicsObject* object1, PhysicsObject* object2);
	/// Checks for collision between a plane and a sphere
	static bool planeToSphere(PhysicsObject* object1, PhysicsObject* object2);
	/// Checks for collision between a sphere and a plane
	static bool sphereToPlane(PhysicsObject* object1, PhysicsObject* object2);
	/// Checks for collision between 2 spheres
	static bool sphereToSphere(PhysicsObject* object1, PhysicsObject* object2);

protected:
	glm::vec2 m_gravity;
		float m_timeStep;
		/// stores actors in the scene
		std::vector<PhysicsObject*>  m_actors;
};