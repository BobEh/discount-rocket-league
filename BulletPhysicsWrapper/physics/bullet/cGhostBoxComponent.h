#pragma once
#include "btBulletDynamicsCommon.h"
#include <physics/interfaces/iGhostBoxComponent.h>
#include "BulletCollision/CollisionDispatch/btGhostObject.h"
#include "nConvert.h"

namespace nPhysics
{
	class cGhostBoxComponent : public iGhostBoxComponent
	{
		friend class cPhysicsWorld;
	public:
		cGhostBoxComponent(const sGhostBoxDef& def);
		virtual ~cGhostBoxComponent();

		virtual bool IsCollidingWith(int uniqueEntityId);

		virtual void GetTransform(glm::mat4& transformOut);
		virtual void ApplyForce(const glm::vec3& force);
		virtual void GetPosition(glm::vec3& positionOut);
		virtual void SetPosition(glm::vec3 positionIn);
		virtual void GetScale(float& scaleOut);
		virtual void GetVelocity(glm::vec3& velocityOut);
		virtual int GetMassType();
		virtual void SetMassType(int physicsType);
		virtual std::string GetPlaneType();

		virtual void SetUniqueEntityId(int id);
		virtual int GetUniqueEntityId();

		virtual size_t NumNodes();
		virtual bool GetNodeRadius(size_t index, float& radiusOut);
		virtual bool GetNodePosition(size_t index, glm::vec3& positionOut);

	private:
		btPairCachingGhostObject* mGhostObject;

		cGhostBoxComponent() = delete;
		cGhostBoxComponent(const cGhostBoxComponent& other) = delete;
		cGhostBoxComponent& operator=(const cGhostBoxComponent& other) = delete;
	};
}