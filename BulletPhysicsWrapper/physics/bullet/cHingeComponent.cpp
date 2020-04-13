#include "cHingeComponent.h"

namespace nPhysics
{
	cHingeComponent::cHingeComponent(const sHingeDef& def)
	{
		btBoxShape* hingeShape = new btBoxShape(btVector3(def.Width * 0.5f, def.Height * 0.5f, def.Thickness * 0.5f));
		
		btTransform transform;
		transform.setIdentity();
		transform.setOrigin(nConvert::ToBullet(def.Position));

		btScalar mass(def.Mass);
		btVector3 localInertia(0.0f, 0.0f, 0.0f);
		hingeShape->calculateLocalInertia(mass, localInertia);

		btDefaultMotionState* motionState = new btDefaultMotionState(transform);
		btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, motionState, hingeShape, localInertia);
		mBody = new btRigidBody(rbInfo);
		mBody->setUserPointer(this);

		mConstraint = new btHingeConstraint(*mBody, btVector3(0.0f, 0.0f, 0.0f), btVector3(0.0f,1.0f,0.0f));



	}
	cHingeComponent::~cHingeComponent()
	{
		delete mConstraint;
		mConstraint = 0;
		
		mBody->setUserPointer(0);
		delete mBody->getMotionState();
		delete mBody;
		mBody = 0;
	}
	bool cHingeComponent::IsCollidingWith(int uniqueEntityId)
	{
		return false;
	}
	void cHingeComponent::GetTransform(glm::mat4& transformOut)
	{
		btTransform transform;
		mBody->getMotionState()->getWorldTransform(transform);
		nConvert::ToSimple(transform, transformOut);
	}
	void cHingeComponent::ApplyForce(const glm::vec3& force)
	{
	}
	void cHingeComponent::GetPosition(glm::vec3& positionOut)
	{
	}
	void cHingeComponent::SetPosition(glm::vec3 positionIn)
	{
	}
	void cHingeComponent::GetScale(float& scaleOut)
	{
	}
	void cHingeComponent::GetVelocity(glm::vec3& velocityOut)
	{
	}
	void cHingeComponent::SetUniqueEntityId(int id)
	{
	}
	int cHingeComponent::GetUniqueEntityId()
	{
		return 0;
	}
	size_t cHingeComponent::NumNodes()
	{
		return size_t();
	}
	bool cHingeComponent::GetNodeRadius(size_t index, float& radiusOut)
	{
		return false;
	}
	bool cHingeComponent::GetNodePosition(size_t index, glm::vec3& positionOut)
	{
		return false;
	}
	int cHingeComponent::GetNumWheels()
	{
		return 0;
	}
}