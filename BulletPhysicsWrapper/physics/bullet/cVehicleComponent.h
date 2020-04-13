#pragma once
#include <physics/interfaces/iVehicleComponent.h>
#include "btBulletDynamicsCommon.h"
#include "nConvert.h"

namespace nPhysics
{
	class cVehicleComponent : public iVehicleComponent
	{
		friend class cPhysicsWorld;
	public:
		cVehicleComponent(const nPhysics::sVehicleDef& theBallDef, btDiscreteDynamicsWorld* world);
		~cVehicleComponent();

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

		virtual void UpdateWheelTransforms();
		virtual void GetChassisTransform(glm::mat4& transformOut);
		virtual void GetWheelTransform(glm::mat4& transformOut, int wheel);
		virtual int GetNumWheels();

		virtual void ApplyEngineForce(float force, int wheel);
		virtual void SetBrake(float brakeforce, int wheel);
		virtual void SetSteering(float steering, int wheel);

		virtual size_t NumNodes();
		virtual bool GetNodeRadius(size_t index, float& radiusOut);
		virtual bool GetNodePosition(size_t index, glm::vec3& positionOut);

		
	private:
		btRigidBody* mBody;
		btRaycastVehicle* mVehicle;
		btDefaultVehicleRaycaster* mVehicleRayCaster;
		btRaycastVehicle::btVehicleTuning mVehicleTuning;
		btCollisionShape* mWheelShape;
		//glm::mat4 transform;
		//glm::vec3 position;
		//glm::vec3 velocity;
		//std::string planeType;
		//int _physicsType;
	};
}