#pragma once
#include "PhysicsObject.h"
class RigidBody : public PhysicsObject
{
public:
	/// virtual constructor for rigidbody
	RigidBody(ShapeType shapeID, glm::vec2 position, glm::vec2 velocity, float rotation, float mass);
		~RigidBody() {}
	/// updates objects
	virtual void fixedUpdate(glm::vec2 gravity, float timeStep);
	virtual void debug() {};
	/// applys a force to a object
	void applyForce(glm::vec2 force, glm::vec2 pos);
	/// applys a force to a actor
	void applyForceToActor(RigidBody* actor2, glm::vec2 force) {};
	/// checks for collision
	virtual bool checkCollision(PhysicsObject* other) = 0;
	/// resoves collision
	void resolveCollision(RigidBody* actor2, glm::vec2 contact, glm::vec2* collisionNormal = nullptr);

	/// returns the position
	glm::vec2 getPosition() { return m_position; }
	/// returns the rotation
	float getRotation() { return m_rotation; }
	/// returns momentem
	float getMoment() { return m_moment; }
	/// returns velocity
	glm::vec2 getvelocity() { return m_velocity; }
	///returns mass
	float getMass() { return m_mass; }
	/// retuns angular velocity
	float getAngularVelocity() { return m_angularVelocity; }
	/// returns linearDrag
	float getLinearDrag() { return m_linearDrag; }
	/// sets linear drag
	void setLinearDrag(float value) { m_linearDrag = value; }
	/// returns angular drag
	float getAngularDrag() { return m_angularDrag; }
	/// sets angulardrag
	void setAngularDrag(float value) { m_angularDrag = value; }
	/// returns elasticity
	float getElasticity() { return m_elasticity; }
	/// sets elasticity
	void setElasticity(float value) { m_elasticity; }
 
protected:
	glm::vec2 m_position;
	glm::vec2 m_velocity;
	float m_mass;
	float m_rotation;
	float m_angularVelocity;
	float m_moment;
	float m_linearDrag = 0.3f;
	float m_angularDrag = 0.3f;
	float m_elasticity = 0.3f;
};
