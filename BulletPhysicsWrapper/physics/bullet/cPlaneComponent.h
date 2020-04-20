#pragma once
#include <physics/interfaces/iPlaneComponent2.h>
#include "cPhysicsComponent.h"
#include <string>
#include "btBulletDynamicsCommon.h"

namespace nPhysics
{
	class cPlaneComponent : public iPlaneComponent
	{
	public:
		cPlaneComponent(nPhysics::sPlaneDef thePlaneDef);
		~cPlaneComponent();

		virtual bool IsCollidingWith(int uniqueEntityId);

		virtual void GetTransform(glm::mat4& transformOut);
		virtual void ApplyForce(const glm::vec3& force);
		virtual void ApplyEngineForce(float force, int wheel);
		virtual void ApplySteering(float value, int wheel);
		virtual void GetPosition(glm::vec3& positionOut);
		virtual void SetPosition(glm::vec3 positionIn);
		virtual void GetVelocity(glm::vec3& velocityOut);
		virtual void GetScale(float& scaleOut);
		virtual int GetMassType();
		virtual void SetMassType(int physicsType);
		virtual std::string GetPlaneType();

		virtual void SetUniqueEntityId(int id);
		virtual int GetUniqueEntityId();

		virtual size_t NumNodes();
		virtual bool GetNodeRadius(size_t index, float& radiusOut);
		virtual bool GetNodePosition(size_t index, glm::vec3& positionOut);

		virtual int GetNumWheels();
		virtual void GetWheelTransform(glm::mat4& transformOut, int wheel);

		btRigidBody* mBody;
	private:

		//glm::mat4 transform;
		glm::vec3 position;
		glm::vec3 velocity;
		std::string planeType;
		int _physicsType;
	};
}