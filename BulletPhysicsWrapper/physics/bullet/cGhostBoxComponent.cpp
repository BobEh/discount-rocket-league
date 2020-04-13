#include "cGhostBoxComponent.h"

namespace nPhysics
{
	cGhostBoxComponent::cGhostBoxComponent(const sGhostBoxDef& def)
	{
		mGhostObject = new btPairCachingGhostObject();
		mGhostObject->setUserPointer(this);

		mGhostObject->setCollisionShape(new btBoxShape(nConvert::ToBullet(def.Width * 0.5f)));

		btTransform transform;
		transform.setIdentity();
		transform.setOrigin(nConvert::ToBullet(def.Position));
		mGhostObject->setWorldTransform(transform);

		mGhostObject->setCollisionFlags(mGhostObject->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
	}
	cGhostBoxComponent::~cGhostBoxComponent()
	{
		mGhostObject->setUserPointer(0);
		delete mGhostObject->getCollisionShape();
		delete mGhostObject;
		mGhostObject = 0;
	}
	bool cGhostBoxComponent::IsCollidingWith(int uniqueEntityId)
	{
		int num = mGhostObject->getNumOverlappingObjects();
		for (int idx = 0; idx < num; idx++)
		{
			if (mGhostObject->getOverlappingObject(idx)->getUserIndex() == uniqueEntityId)
			{
				return true;
			}
		}
		return false;
	}
	void cGhostBoxComponent::GetTransform(glm::mat4& transformOut)
	{
		btTransform transform(mGhostObject->getWorldTransform());
		nConvert::ToSimple(transform, transformOut);
	}
	void cGhostBoxComponent::ApplyForce(const glm::vec3& force)
	{
	}
	void cGhostBoxComponent::GetPosition(glm::vec3& positionOut)
	{
	}
	void cGhostBoxComponent::SetPosition(glm::vec3 positionIn)
	{
	}
	void cGhostBoxComponent::GetScale(float& scaleOut)
	{
	}
	void cGhostBoxComponent::GetVelocity(glm::vec3& velocityOut)
	{
	}
	int cGhostBoxComponent::GetMassType()
	{
		return 0;
	}
	void cGhostBoxComponent::SetMassType(int physicsType)
	{
	}
	std::string cGhostBoxComponent::GetPlaneType()
	{
		return std::string();
	}
	void cGhostBoxComponent::SetUniqueEntityId(int id)
	{
		mGhostObject->setUserIndex(id);
	}
	int cGhostBoxComponent::GetUniqueEntityId()
	{
		return mGhostObject->getUserIndex();
	}
	size_t cGhostBoxComponent::NumNodes()
	{
		return size_t();
	}
	bool cGhostBoxComponent::GetNodeRadius(size_t index, float& radiusOut)
	{
		return false;
	}
	bool cGhostBoxComponent::GetNodePosition(size_t index, glm::vec3& positionOut)
	{
		return false;
	}
	int cGhostBoxComponent::GetNumWheels()
	{
		return 0;
	}
}