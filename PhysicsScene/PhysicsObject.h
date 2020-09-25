#pragma once
#include "glm\ext.hpp"


enum ShapeType 
{
	PLANE = 0,
	SPHERE,
	SHAPE_COUNT,
	
};

/// This class is a virtual class used by the rigidbody class
class PhysicsObject
{
protected:
	/// Constructor 
	PhysicsObject(ShapeType a_shapeID) : m_shapeID(a_shapeID) {}

public:
	///used to update each object using timestep
	virtual void fixedUpdate(glm::vec2 gravity, float timeStep) = 0; 
	virtual void debug() = 0;
	/// used to make each object
	virtual void makeGizmo() = 0;
	virtual void resetPosition() {};

	/// returns shape id
	ShapeType getShapeID() { return m_shapeID; }

protected:
	//value that stores the shapeid
	ShapeType m_shapeID;


};

