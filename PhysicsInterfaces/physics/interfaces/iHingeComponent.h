#pragma once
#include "iPhysicsComponent.h"

namespace nPhysics
{
	struct sHingeDef
	{
		glm::vec3 Position;
		float Mass;
		float Width;
		float Height;
		float Thickness;
	};

	class iHingeComponent : public iPhysicsComponent
	{
	public:
		virtual ~iHingeComponent() {}

	protected:
		iHingeComponent() : iPhysicsComponent(eComponentType::hinge) {}
	private:
		iHingeComponent(const iHingeComponent& other) = delete;
		iHingeComponent& operator=(const iHingeComponent& other) = delete;
	};
}