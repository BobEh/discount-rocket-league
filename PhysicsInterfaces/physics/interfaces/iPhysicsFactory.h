#pragma once
#include "iBallComponent.h"
#include "iPlaneComponent2.h"
#include "iClothComponent.h"
#include "iPhysicsWorld.h"
#include "iHingeComponent.h"
#include "iGhostBoxComponent.h"
#include "iVehicleComponent.h"

namespace nPhysics
{
	class iPhysicsFactory
	{
	public:
		virtual ~iPhysicsFactory() {}
		virtual iPhysicsWorld* CreateWorld() = 0;
		// components
		virtual iBallComponent* CreateBall(const sBallDef& def) = 0;
		virtual iPlaneComponent* CreatePlane(const sPlaneDef& def) = 0;
		virtual iClothComponent* CreateCloth(const sClothDef& def) = 0;
		virtual iHingeComponent* CreateHinge(const sHingeDef& def) = 0;
		virtual iGhostBoxComponent* CreateGhostBox(const sGhostBoxDef& def) = 0;
		virtual iVehicleComponent* CreateVehicle(const sVehicleDef& def, iPhysicsWorld* world) = 0;
	};
}