#pragma once
#include <physics/interfaces/iHingeComponent.h>
#include "btBulletDynamicsCommon.h"
#include "nConvert.h"

namespace nPhysics
{
	class cHingeComponent : public iHingeComponent
	{
		friend class cPhysicsWorld;
	public:
		cHingeComponent(const sHingeDef& def);
		virtual ~cHingeComponent();

		virtual bool IsCollidingWith(int uniqueEntityId);

		virtual void GetTransform(glm::mat4& transformOut);

		virtual void ApplyForce(const glm::vec3& force);

		virtual void GetPosition(glm::vec3& positionOut);
		virtual void SetPosition(glm::vec3 positionIn);
		virtual void GetScale(float& scaleOut);
		virtual void GetVelocity(glm::vec3& velocityOut);

		virtual void SetUniqueEntityId(int id);
		virtual int GetUniqueEntityId();

		virtual size_t NumNodes();
		virtual bool GetNodeRadius(size_t index, float& radiusOut);
		virtual bool GetNodePosition(size_t index, glm::vec3& positionOut);

		virtual int GetNumWheels();

	private:
		btRigidBody* mBody;
		btHingeConstraint* mConstraint;

		cHingeComponent() = delete;
		cHingeComponent(const cHingeComponent& other) = delete;
		cHingeComponent& operator =(const cHingeComponent& other) = delete;
	};
}