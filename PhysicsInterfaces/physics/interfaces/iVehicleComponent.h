#pragma once
#include "iPhysicsComponent.h"

namespace nPhysics
{
	struct sWheelDef
	{
		sWheelDef() :
			ConnectionPoint(0.0f, 0.0f, 1.0f),
			WheelDirection(0.0f, -1.0f, 0.0f),
			Axle(0.0f, 0.0f, 1.0f),
			SuspensionLength(0.0f),
			SuspensionLimit(10.0f),
			Radius(1.0f),
			IsFrontWheel(false),
			SuspensionDampingRelaxation(0.1f),
			SuspensionDampingCompression(5.3f),
			SuspensionStiffness(50.0f),
			RollInfluence(0.0f),
			Friction(3000.0f)
		{}
		glm::vec3 ConnectionPoint; // center point of the wheel, relative to the chassis
		glm::vec3 WheelDirection; // down dirction for this wheel
		glm::vec3 Axle; // axis that the wheel rotates around
		float SuspensionLength; // resting suspension length
		float SuspensionLimit; // max suspension limit
		float Radius;
		bool IsFrontWheel;
		float SuspensionStiffness; // 10.0 - offroad buggy, 50.0 - sports car, 200.0 - f1 car
		float SuspensionDampingRelaxation;
		float SuspensionDampingCompression;
		float RollInfluence; // 0.0 no roll ... 1.0 realistic
		float Friction; // 0.8 - normal ... 10000 - slippery
	};
	struct sVehicleDef
	{
		float Mass;
		glm::vec3 Position;
		std::vector<sWheelDef> Wheels;
		glm::vec3 Width;
	};

	class iVehicleComponent : public iPhysicsComponent
	{
	public:
		virtual ~iVehicleComponent() {}

		virtual void GetChassisTransform(glm::mat4& transformOut) = 0;
		virtual void GetWheelTransform(glm::mat4& transformOut, int wheel) = 0;
		virtual int GetNumWheels() = 0;

		virtual void UpdateWheelTransforms() = 0;
		virtual void ApplyEngineForce(float force, int wheel) = 0;
		virtual void SetBrake(float brakeforce, int wheel) = 0;
		virtual void SetSteering(float steering, int wheel) = 0;

	protected:
		iVehicleComponent() : iPhysicsComponent(eComponentType::vehicle) {}
	private:
		iVehicleComponent(const iVehicleComponent& other) = delete;
		iVehicleComponent& operator=(const iVehicleComponent& other) = delete;
	};
}