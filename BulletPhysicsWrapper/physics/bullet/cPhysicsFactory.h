#pragma once
#include <physics/interfaces/iPhysicsFactory.h>
#include "cBallComponent.h"
#include "cPhysicsWorld.h"

namespace nPhysics
{
	class cPhysicsFactory : public iPhysicsFactory
	{
	public:
		cPhysicsFactory();
		~cPhysicsFactory();
		iPhysicsWorld* CreateWorld();
		// components
		virtual iBallComponent* CreateBall(const sBallDef& def);
		virtual iPlaneComponent* CreatePlane(const sPlaneDef& def);
		virtual iClothComponent* CreateCloth(const sClothDef& def);
		virtual iHingeComponent* CreateHinge(const sHingeDef& def);
		virtual iGhostBoxComponent* CreateGhostBox(const sGhostBoxDef& def);
		virtual iVehicleComponent* CreateVehicle(const sVehicleDef& def, iPhysicsWorld* world);
	};
}