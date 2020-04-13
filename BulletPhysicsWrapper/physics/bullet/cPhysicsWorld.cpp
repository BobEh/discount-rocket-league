#include "cPhysicsWorld.h"

namespace nPhysics
{
	cPhysicsWorld::~cPhysicsWorld()
	{
		delete mCollisionConfiguration;
		delete mDispatcher;
		delete mOverlappingPairCache;
		delete mGhostPairCallback;
		delete mSolver;
		delete mDynamicsWorld;
		if (collisionListener)
		{
			delete collisionListener;
			collisionListener = 0;
		}
	}
	cPhysicsWorld::cPhysicsWorld()
	{
		collisionListener = 0;
		///collision configuration contains default setup for memory, collision setup. Advanced users can create their own configuration.
		mCollisionConfiguration = new btDefaultCollisionConfiguration();

		///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
		mDispatcher = new btCollisionDispatcher(mCollisionConfiguration);

		///btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
		mOverlappingPairCache = new btDbvtBroadphase();
		mGhostPairCallback = new btGhostPairCallback();
		mOverlappingPairCache->getOverlappingPairCache()->setInternalGhostPairCallback(mGhostPairCallback);

		///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
		mSolver = new btSequentialImpulseConstraintSolver;

		mDynamicsWorld = new btDiscreteDynamicsWorld(mDispatcher, mOverlappingPairCache, mSolver, mCollisionConfiguration);

		mDynamicsWorld->setGravity(btVector3(0, -20, 0));
	}
	void cPhysicsWorld::Update(float deltaTime)
	{
		mDynamicsWorld->stepSimulation(deltaTime, 10);
		if (collisionListener)
		{
			// TODO: COLLISION LISTENING STUFF

		}
	}
	bool cPhysicsWorld::AddComponent(iPhysicsComponent* component)
	{
		if (!component)
		{
			return false; // can't add nothing!
		}
		switch (component->GetComponentType())
		{
		case eComponentType::ball:
			return  AddRigidBodies(dynamic_cast<cBallComponent*>(component));
		case eComponentType::plane:
			return AddRigidBodies(dynamic_cast<cPlaneComponent*>(component));
		case eComponentType::hinge:
			return AddRigidBodies(dynamic_cast<cHingeComponent*>(component));
		case eComponentType::ghostBox:
			return AddRigidBodies(dynamic_cast<cGhostBoxComponent*>(component));
		case eComponentType::vehicle:
			return AddRigidBodies(dynamic_cast<cVehicleComponent*>(component));
		default:
			break;
		}
		return false;
	}
	bool cPhysicsWorld::RemoveComponent(iPhysicsComponent* component)
	{
		if (!component)
		{
			return false;
		}
		switch (component->GetComponentType())
		{
		case eComponentType::ball:
			return RemoveRigidBodies(dynamic_cast<cBallComponent*>(component));
		case eComponentType::plane:
			return RemoveRigidBodies(dynamic_cast<cPlaneComponent*>(component));
		case eComponentType::hinge:
			return RemoveRigidBodies(dynamic_cast<cHingeComponent*>(component));
		case eComponentType::ghostBox:
			return RemoveRigidBodies(dynamic_cast<cGhostBoxComponent*>(component));
		case eComponentType::vehicle:
			return RemoveRigidBodies(dynamic_cast<cVehicleComponent*>(component));
		default:
			break;
		}
		
		return false;
	}
	btDiscreteDynamicsWorld* cPhysicsWorld::GetBulletWorld()
	{
		return this->mDynamicsWorld;
	}
	void cPhysicsWorld::SetCollisionListener(iCollisionListener* _collisionListener)
	{
		if (collisionListener)
		{
			delete collisionListener;
			collisionListener = 0;
		}
		if (_collisionListener)
		{
			
		}
	}
	bool cPhysicsWorld::AddRigidBodies(cBallComponent* component)
	{
		if (!component)
		{
			return false;
		}
		mDynamicsWorld->addRigidBody(component->mBody);
		return true;
	}
	bool cPhysicsWorld::AddRigidBodies(cPlaneComponent* component)
	{
		if (!component)
		{
			return false;
		}
		mDynamicsWorld->addRigidBody(component->mBody);
		return true;
	}
	bool cPhysicsWorld::AddRigidBodies(cHingeComponent* component)
	{
		if (!component)
		{
			return false;
		}
		mDynamicsWorld->addRigidBody(component->mBody);
		mDynamicsWorld->addConstraint(component->mConstraint);
		return true;
	}
	bool cPhysicsWorld::AddRigidBodies(cGhostBoxComponent* component)
	{
		if (!component)
		{
			return false;
		}
		mDynamicsWorld->addCollisionObject(component->mGhostObject);
		return true;
	}
	bool cPhysicsWorld::AddRigidBodies(cVehicleComponent* component)
	{
		if (!component)
		{
			return false;
		}
		mDynamicsWorld->addRigidBody(component->mBody);
		mDynamicsWorld->addVehicle(component->mVehicle);
		return true;
	}
	bool cPhysicsWorld::RemoveRigidBodies(cBallComponent* component)
	{
		if (!component)
		{
			return false;
		}
		mDynamicsWorld->removeRigidBody(component->mBody);
		return true;
	}
	bool cPhysicsWorld::RemoveRigidBodies(cPlaneComponent* component)
	{
		if (!component)
		{
			return false;
		}
		mDynamicsWorld->removeRigidBody(component->mBody);
		return true;
	}
	bool cPhysicsWorld::RemoveRigidBodies(cHingeComponent* component)
	{
		if (!component)
		{
			return false;
		}
		mDynamicsWorld->removeRigidBody(component->mBody);
		mDynamicsWorld->removeConstraint(component->mConstraint);
		return true;
	}
	bool cPhysicsWorld::RemoveRigidBodies(cGhostBoxComponent* component)
	{
		if (!component)
		{
			return false;
		}
		mDynamicsWorld->removeCollisionObject(component->mGhostObject);
		return true;
	}
	bool cPhysicsWorld::RemoveRigidBodies(cVehicleComponent* component)
	{
		if (!component)
		{
			return false;
		}
		mDynamicsWorld->removeRigidBody(component->mBody);
		mDynamicsWorld->removeVehicle(component->mVehicle);
		return true;
	}
}