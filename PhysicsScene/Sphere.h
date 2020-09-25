#pragma once
#include "RigidBody.h"
/// Class that contains functions for spheres
class Sphere : public RigidBody
{
public:
	/// constructor for spheres
	Sphere(glm::vec2 position, glm::vec2 velocity,
		float mass, float radius, glm::vec4 colour);
	~Sphere() {}

	/// makes a gizmo for the sphere
	virtual void makeGizmo();
	/// checks for collision
	virtual bool checkCollision(PhysicsObject* other);

	/// gets the radius
	float getRadius() { return m_radius; }
	/// gets the collour
	glm::vec4 getColour() { return m_colour; }

protected:
	float m_radius;
	glm::vec4 m_colour;

};

