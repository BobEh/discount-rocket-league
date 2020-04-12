#pragma once
#include "iPhysicsComponent.h"

namespace nPhysics
{
	struct sGhostBoxDef
	{
		glm::vec3 Position;
		glm::vec3 Width;

	};

	class iGhostBoxComponent : public virtual iPhysicsComponent
	{
	public:
		virtual ~iGhostBoxComponent() {}

	protected:
		iGhostBoxComponent() : iPhysicsComponent(eComponentType::ghostBox) {}
	private:
		iGhostBoxComponent(const iGhostBoxComponent& other) = delete;
		iGhostBoxComponent& operator=(const iGhostBoxComponent& other) = delete;
	};
}