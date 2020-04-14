#include "cMeshObject.h"

void cMeshObject::Shoot()
{
	this->pBigShooter->Shoot();
}

cSimpleAssimpSkinnedMesh* cMeshObject::getSM()
{
	return this->pSM;
}

std::vector<glm::vec3> cMeshObject::getTestPoints()
{
	return this->testPoints;
}

std::string cMeshObject::getTextures(int index)
{
	return this->textures[index];
}

float cMeshObject::getTextureRatio(int index)
{
	return this->textureRatio[index];
}

float cMeshObject::getTransprancyValue()
{
	return this->transprancyValue;
}

bool cMeshObject::getIsTranspanrancy()
{
	return this->isTranspanrancy;
}

std::string cMeshObject::getAnimation()
{
	return this->_Animation;
}

std::string cMeshObject::getBehaviour()
{
	return this->_Behaviour;
}

std::string cMeshObject::getMeshName()
{
	return this->_meshName;
}
unsigned int cMeshObject::getFriendlyIDNumber()
{
	return this->_friendlyIDNumber;
}
std::string cMeshObject::getFriendlyName()
{
	return this->_friendlyName;
}
glm::vec3 cMeshObject::getPositionXYZ()
{
	glm::vec3 result = glm::vec3(0.0f);
	if (this->_component != nullptr)
	{
		this->_component->GetPosition(result);
	}
	else
	{
		result = _positionXYZ;
	}
	return result;
}
glm::quat cMeshObject::getRotationXYZ()
{
	return this->qRotation;
}
float cMeshObject::getScale()
{
	return this->_scale;
}
glm::mat4 cMeshObject::getMatWorld()
{
	return this->_matWorld;
}
glm::vec4 cMeshObject::getObjectColourRGBA()
{
	return this->_objectColourRGBA;
}
glm::vec4 cMeshObject::getDiffuseColour()
{
	return this->_diffuseColour;
}
glm::vec4 cMeshObject::getSpecularColour()
{
	return this->_specularColour;
}
glm::vec3 cMeshObject::getVelocity()
{
	return glm::vec3();
}
float cMeshObject::getVelocityX()
{
	return 0.0f;
}
float cMeshObject::getVelocityY()
{
	return 0.0f;
}
float cMeshObject::getVelocityZ()
{
	return 0.0f;
}
glm::vec3 cMeshObject::getAccel()
{
	return glm::vec3();
}
float cMeshObject::getInverseMass()
{
	return this->_inverseMass;
}
std::string cMeshObject::getPhysicsShapeType()
{
	return this->_physicsShapeType;
}
bool cMeshObject::getIsWireframe()
{
	return this->_isWireframe;
}
glm::vec4 cMeshObject::getDebugColour()
{
	return this->_debugColour;
}
float cMeshObject::get_SPHERE_radius()
{
	return 0.0f;
}
bool cMeshObject::getIsVisible()
{
	return this->_isVisible;
}
bool cMeshObject::getDisableDepthBufferTest()
{
	return this->_disableDepthBufferTest;
}
bool cMeshObject::getDisableDepthBufferWrite()
{
	return this->_disableDepthBufferWrite;
}
//setters
void cMeshObject::addTestPoint(glm::vec3 testPoint)
{
	
}
void cMeshObject::setAnimation(std::string animation)
{
	this->_Animation = animation;
}
void cMeshObject::setBehaviour(std::string behaviour)
{
	this->_Behaviour = behaviour;
}
void cMeshObject::setSM(cSimpleAssimpSkinnedMesh* skinnedMesh)
{
	this->pSM = skinnedMesh;
}
void cMeshObject::setMeshName(std::string name)
{
	this->_meshName = name;
}
void cMeshObject::setFriendlyIDNumber(unsigned int IDNumber)
{
	this->_friendlyIDNumber = IDNumber;
}
void cMeshObject::setFriendlyName(std::string friendlyName)
{
	this->_friendlyName = friendlyName;
}
void cMeshObject::setPositionXYZ(glm::vec3 positionXYZ)
{
	
	this->_positionXYZ = positionXYZ;
}
void cMeshObject::setRotationXYZ(glm::quat rotationXYZ)
{
	this->qRotation = rotationXYZ;
}
void cMeshObject::setScale(float scale)
{
	this->_scale = scale;
}
void cMeshObject::setMatWorld(glm::mat4 matWorld)
{
	this->_matWorld = matWorld;
}
void cMeshObject::setObjectColourRGBA(glm::vec4 colourRGBA)
{
	this->_objectColourRGBA = colourRGBA;
}
void cMeshObject::setDiffuseColour(glm::vec4 diffuseColourRGBA)
{
	this->_diffuseColour = diffuseColourRGBA;
}
void cMeshObject::setSpecularColour(glm::vec4 specularColourRGBA)
{
	this->_specularColour = specularColourRGBA;
}
void cMeshObject::setVelocity(glm::vec3 velocityXYZ)
{
	
}
void cMeshObject::setVelocityX(float velocityX)
{
	
}
void cMeshObject::setVelocityY(float velocityY)
{
	
}
void cMeshObject::setVelocityZ(float velocityZ)
{
	
}
void cMeshObject::setAccel(glm::vec3 accelXYZ)
{
	
}
void cMeshObject::setInverseMass(float inverseMass)
{
	this->_inverseMass = inverseMass;
}
void cMeshObject::setPhysicsShapeType(std::string physicsShapeType)
{
	this->_physicsShapeType = physicsShapeType;
}
void cMeshObject::setIsWireframe(bool isWireFrame)
{
	this->_isWireframe = isWireFrame;
}
void cMeshObject::setDebugColour(glm::vec4 debugColourRGBA)
{
	this->_debugColour = debugColourRGBA;
}
void cMeshObject::set_SPHERE_radius(float radius)
{
	
}
void cMeshObject::setIsVisible(bool isVisible)
{
	this->_isVisible = isVisible;
}
void cMeshObject::setDisableDepthBufferTest(bool disableDepthBufferTest)
{
	this->_disableDepthBufferTest = disableDepthBufferTest;
}
void cMeshObject::setDisableDepthBufferWrite(bool disableDepthBufferWrite)
{
	this->_disableDepthBufferWrite = disableDepthBufferWrite;
}

void cMeshObject::MoveInRelativeDirection(glm::vec3 relativeDirection)
{
	// The "forward" vector is +ve Z
	// (the 4th number is because we need a vec4 later)
	glm::vec4 forwardDirObject = glm::vec4(relativeDirection, 1.0f);

	glm::mat4 matModel = glm::mat4(1.0f);	// Identity

	// Roation
	// Constructor for the GLM mat4x4 can take a quaternion
	glm::mat4 matRotation = glm::mat4(this->getRotationXYZ());
	matModel *= matRotation;
	// *******************

	// Like in the vertex shader, I mulitly the test points
	// by the model matrix (MUST be a VEC4 because it's a 4x4 matrix)
	glm::vec4 forwardInWorldSpace = matModel * forwardDirObject;


	// Add this to the position of the object
	this->setPositionXYZ(this->getPositionXYZ() + glm::vec3(forwardInWorldSpace));

	return;
}

void cMeshObject::setTexture(std::string tex, int index)
{
	this->textures[index] = tex;
}

void cMeshObject::setTextureRatio(float texRatio, int index)
{
	this->textureRatio[index] = texRatio;
}

void cMeshObject::setTransprancyValue(float transprancyValue)
{
	this->transprancyValue = transprancyValue;
}

void cMeshObject::setIsTranspanrancy(bool isTranspanrancy)
{
	this->isTranspanrancy = isTranspanrancy;
}


void cMeshObject::GetTransform(glm::mat4& transformOut)
{
	transformOut = this->_matWorld;
}

void cMeshObject::GetPosition(glm::vec3& positionOut)
{
	glm::vec3 result = glm::vec3(0.0f, 0.0f, 0.0f);
	//this->_component->GetPosition(result);
	positionOut = result;
}

void cMeshObject::SetPosition(glm::vec3 positionIn)
{
	//this->_component->SetPosition(positionIn);
}

void cMeshObject::GetVelocity(glm::vec3& velocityOut)
{
	
}

void cMeshObject::ApplyForce(const glm::vec3& force)
{
	//this->_component->ApplyForce(force);
}

int cMeshObject::GetMassType()
{
	return _physicsType;
}

void cMeshObject::SetMassType(int physicsType)
{
	_physicsType = physicsType;
}

std::string cMeshObject::GetPlaneType()
{
	return this->_planeType;
}

void cMeshObject::SetPlaneType(std::string planeType)
{
	this->_planeType = planeType;
}

void cMeshObject::SetComponent(nPhysics::iPhysicsComponent* component)
{
	this->_component = component;
}

nPhysics::iPhysicsComponent* cMeshObject::GetComponent()
{
	return this->_component;
}

void cMeshObject::GetWheelTransform(glm::mat4& transformOut, int wheel)
{
}

void cMeshObject::SetUniqueEntityId(int id)
{
	if (this->_component)
	{
		this->_component->SetUniqueEntityId(id);
	}
}

int cMeshObject::GetUniqueEntityId()
{
	if (this->_component)
	{
		return this->_component->GetUniqueEntityId();
	}
	else
	{
		return -1;
	}
}

bool cMeshObject::IsCollidingWith(int uniqueEntityId)
{
	return this->_component->IsCollidingWith(uniqueEntityId);
}

int cMeshObject::GetNumWheels()
{
	return 0;
}

void cMeshObject::SetIsWheel(bool isWheel)
{
}

bool cMeshObject::GetIsWheel()
{
	return false;
}

cMeshObject::cMeshObject(nPhysics::eComponentType componentType)
{
	this->_scale = 0.0f;
	this->_isVisible = true;
	this->mComponentType = componentType;

	this->_isWireframe = false;
	this->_debugColour = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	this->_inverseMass = 0.0f;	// Infinite mass
	this->_physicsShapeType = "MESH";

	// Set the unique ID
	// Take the value of the static int, 
	//  set this to the instance variable
	this->_m_uniqueID = cMeshObject::next_uniqueID;
	// Then increment the static variable
	cMeshObject::next_uniqueID++;

	this->_disableDepthBufferTest = false;
	this->_disableDepthBufferWrite = false;


	return;
}


unsigned int cMeshObject::getUniqueID(void)
{
	return this->_m_uniqueID;
}

// this variable is static, so common to all objects.
// When the object is created, the unique ID is set, and 
//	the next unique ID is incremented
//static 
unsigned int cMeshObject::next_uniqueID = 1000;	// Starting at 1000, just because
