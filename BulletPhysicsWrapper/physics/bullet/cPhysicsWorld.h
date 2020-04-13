#pragma once
#include <physics/interfaces/iPhysicsWorld.h>
#include <physics/interfaces/iCollisionListener.h>
#include "btBulletDynamicsCommon.h"
#include "BulletCollision/CollisionDispatch/btGhostObject.h"
#include <vector>
#include <cBallComponent.h>
#include <cPlaneComponent.h>
#include "cHingeComponent.h"
#include "cGhostBoxComponent.h"
#include "cVehicleComponent.h"

namespace nPhysics
{
	class cPhysicsWorld : public iPhysicsWorld
	{
	public:
		~cPhysicsWorld();
		cPhysicsWorld();

		virtual void Update(float dt);
		virtual bool AddComponent(iPhysicsComponent* component);
		virtual bool RemoveComponent(iPhysicsComponent* component);
		//virtual void SetGravity(glm::vec3 gravity);
		//virtual std::vector<nPhysics::iPhysicsComponent*> GetComponentVec();
		//virtual std::vector<phys::cRigidBody*> GetWorldBodiesVec();
		//virtual phys::cWorld* GetWorld();
		
		btDiscreteDynamicsWorld* GetBulletWorld();

		void SetCollisionListener(iCollisionListener* collisionListener);

	private:
		bool AddRigidBodies(cBallComponent* component);
		bool AddRigidBodies(cPlaneComponent* component);
		bool AddRigidBodies(cHingeComponent* component);
		bool AddRigidBodies(cGhostBoxComponent* component);
		bool AddRigidBodies(cVehicleComponent* component);
		bool RemoveRigidBodies(cBallComponent* component);
		bool RemoveRigidBodies(cPlaneComponent* component);
		bool RemoveRigidBodies(cHingeComponent* component);
		bool RemoveRigidBodies(cGhostBoxComponent* component);
		bool RemoveRigidBodies(cVehicleComponent* component);
		btDefaultCollisionConfiguration* mCollisionConfiguration;
		btCollisionDispatcher* mDispatcher;
		btBroadphaseInterface* mOverlappingPairCache;
		btGhostPairCallback* mGhostPairCallback;
		btSequentialImpulseConstraintSolver* mSolver;
		btDiscreteDynamicsWorld* mDynamicsWorld;
		//std::vector<nPhysics::iPhysicsComponent*> componentVec;
		iCollisionListener* collisionListener;
		//phys::cWorld* mWorld;
	};
}