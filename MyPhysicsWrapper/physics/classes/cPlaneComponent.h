#pragma once
#include <physics/interfaces/iPlaneComponent2.h>
#include "cPhysicsComponent.h"
#include <string>
#include <phys\cRigidBody.h>
#include <phys/shapes.h>
using namespace phys;

namespace nPhysics
{
	class cPlaneComponent : public iPlaneComponent
	{
	public:
		~cPlaneComponent();
		cPlaneComponent(nPhysics::sPlaneDef thePlaneDef);

		virtual bool IsCollidingWith(int uniqueEntityId);

		virtual size_t NumNodes();
		virtual bool GetNodeRadius(size_t index, float& radiusOut);
		virtual bool GetNodePosition(size_t index, glm::vec3& positionOut);

		virtual void SetUniqueEntityId(int id);
		virtual int GetUniqueEntityId();

		virtual void GetTransform(glm::mat4& transformOut);
		virtual void GetPosition(glm::vec3& positionOut);
		virtual void SetPosition(glm::vec3 positionIn);
		virtual void GetVelocity(glm::vec3& velocityOut);
		virtual void GetScale(float& scaleOut);
		virtual int GetMassType();
		virtual void SetMassType(int physicsType);
		virtual void ApplyForce(const glm::vec3& force);
		virtual void ApplyEngineForce(float force, int wheel);
		virtual void ApplySteering(float value, int wheel);
		virtual std::string GetPlaneType();

		virtual int GetNumWheels();
		virtual void GetWheelTransform(glm::mat4& transformOut, int wheel);

		cRigidBody* mBody;
	private:
		glm::mat4 transform;
		glm::vec3 position;
		glm::vec3 velocity;
		std::string planeType;
		int _physicsType;
	};
}