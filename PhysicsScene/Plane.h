#pragma once
#include "PhysicsObject.h"
#include "RigidBody.h"

/// stores all functions used by planes
class Plane : public PhysicsObject
{
public:
	/// Constructor for planes
	Plane();
	Plane(glm::vec2 normal, float distance);
	~Plane();

	/// fixedUpdate function for planes
	virtual void fixedUpdate(glm::vec2 gravity, float timeStep) {};
	virtual void debug() {}
	///Function used to make a plane using gizmos
	virtual void makeGizmo();
	virtual void resetPosition() {};

	///used to resolve collision between to objects
	void resolveCollision(RigidBody* other, glm::vec2 contact);
	///returns the normal vector
	glm::vec2 getNormal() { return m_normal; }
	float getDistance() { return m_distanceToOrigin; }

protected:
	glm::vec2 m_normal;
	float m_distanceToOrigin;
};

