#include "cVehicleComponent.h"

namespace nPhysics
{
	cVehicleComponent::cVehicleComponent(const nPhysics::sVehicleDef& def, btDiscreteDynamicsWorld* world)
	{
		// start with the chassis
		btCollisionShape* shape = new btBoxShape(nConvert::ToBullet(def.Width * 0.5f));

		btTransform transform;
		transform.setIdentity();
		transform.setOrigin(nConvert::ToBullet(def.Position));

		btScalar mass(def.Mass);

		//rigidbody is dynamic if and only if mass is non zero, otherwise static
		bool isDynamic = (mass != 0.f);

		btVector3 localInertia(0, 0, 0);
		if (isDynamic)
		{
			shape->calculateLocalInertia(mass, localInertia);
		}

		//using motionstate is optional, it provides interpolation capabilities, and only synchronizes 'active' objects
		btDefaultMotionState* myMotionState = new btDefaultMotionState(transform);
		btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, shape, localInertia);
		rbInfo.m_restitution = 0.5f;
		mBody = new btRigidBody(rbInfo);
		mBody->setUserPointer(this);

		// done chassis

		mVehicleRayCaster = new btDefaultVehicleRaycaster(world);
		mVehicle = new btRaycastVehicle(mVehicleTuning, mBody, mVehicleRayCaster);

		mVehicle->setCoordinateSystem(0, 1, 2);
		size_t numWheels = def.Wheels.size();
		for (size_t idx = 0; idx < numWheels; idx++)
		{
			const sWheelDef& wheel = def.Wheels.at(idx);
			mVehicle->addWheel(
				nConvert::ToBullet(wheel.ConnectionPoint),
				nConvert::ToBullet(wheel.WheelDirection),
				nConvert::ToBullet(wheel.Axle),
				wheel.SuspensionLength,
				wheel.Radius,
				mVehicleTuning,
				wheel.IsFrontWheel
			);
		}
		for (size_t idx = 0; idx < numWheels; idx++)
		{
			const sWheelDef& wheel = def.Wheels.at(idx);
			btWheelInfo& info = mVehicle->getWheelInfo(idx);
			info.m_suspensionStiffness = wheel.SuspensionStiffness;
			info.m_wheelsDampingRelaxation = wheel.SuspensionDampingRelaxation;
			info.m_wheelsDampingCompression = wheel.SuspensionDampingCompression;
			info.m_frictionSlip = wheel.Friction;
			info.m_rollInfluence = wheel.RollInfluence;
		}

		world->getBroadphase()->getOverlappingPairCache()->cleanProxyFromPairs(mBody->getBroadphaseHandle(), world->getDispatcher());
		mVehicle->resetSuspension();
		mBody->activate(true);
		mBody->setActivationState(DISABLE_DEACTIVATION);
	}
	cVehicleComponent::~cVehicleComponent()
	{
		delete mBody->getMotionState();
		delete mBody->getCollisionShape();
		mBody->setUserPointer(0);
		delete mBody;
		mBody = 0;
		delete mVehicleRayCaster;
		delete mVehicle;
	}
	bool cVehicleComponent::IsCollidingWith(int uniqueEntityId)
	{
		return false;
	}
	void cVehicleComponent::GetTransform(glm::mat4& transformOut)
	{
		btTransform transform;
		mBody->getMotionState()->getWorldTransform(transform);
		nConvert::ToSimple(transform, transformOut);
	}
	void cVehicleComponent::ApplyForce(const glm::vec3& force)
	{
	}
	void cVehicleComponent::GetPosition(glm::vec3& positionOut)
	{
	}
	void cVehicleComponent::SetPosition(glm::vec3 positionIn)
	{
	}
	void cVehicleComponent::GetScale(float& scaleOut)
	{
	}
	void cVehicleComponent::GetVelocity(glm::vec3& velocityOut)
	{
	}
	int cVehicleComponent::GetMassType()
	{
		return 0;
	}
	void cVehicleComponent::SetMassType(int physicsType)
	{
	}
	std::string cVehicleComponent::GetPlaneType()
	{
		return std::string();
	}
	void cVehicleComponent::SetUniqueEntityId(int id)
	{
		mBody->setUserIndex(id);
	}
	int cVehicleComponent::GetUniqueEntityId()
	{
		return mBody->getUserIndex();
	}
	void cVehicleComponent::UpdateWheelTransforms()
	{
		int numWheels = mVehicle->getNumWheels();
		for (int idx = 0; idx < numWheels; idx++)
		{
			mVehicle->updateWheelTransform(idx, true);
		}
	}
	void cVehicleComponent::GetChassisTransform(glm::mat4& transformOut)
	{
		btTransform transform;
		mBody->getMotionState()->getWorldTransform(transform);
		nConvert::ToSimple(transform, transformOut);
	}
	void cVehicleComponent::GetWheelTransform(glm::mat4& transformOut, int wheel)
	{
		nConvert::ToSimple(mVehicle->getWheelTransformWS(wheel), transformOut);
	}
	int cVehicleComponent::GetNumWheels()
	{
		return mVehicle->getNumWheels();
	}
	void cVehicleComponent::ApplyEngineForce(float force, int wheel)
	{
		mVehicle->applyEngineForce(force, wheel);
	}
	void cVehicleComponent::SetBrake(float brakeforce, int wheel)
	{
		mVehicle->setBrake(brakeforce, wheel);
	}
	void cVehicleComponent::SetSteering(float steering, int wheel)
	{
		mVehicle->setSteeringValue(steering, wheel);
	}
	size_t cVehicleComponent::NumNodes()
	{
		return size_t();
	}
	bool cVehicleComponent::GetNodeRadius(size_t index, float& radiusOut)
	{
		return false;
	}
	bool cVehicleComponent::GetNodePosition(size_t index, glm::vec3& positionOut)
	{
		return false;
	}
}