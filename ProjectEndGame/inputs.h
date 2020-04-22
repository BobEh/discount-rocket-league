#pragma once

#include "includes.h"

//  ___________.__          _________                                     
//  \_   _____/|  | ___.__. \_   ___ \_____    _____   ________________   
//   |    __)  |  |<   |  | /    \  \/\__  \  /     \_/ __ \_  __ \__  \  
//   |     \   |  |_\___  | \     \____/ __ \|  Y Y  \  ___/|  | \// __ \_
//   \___  /   |____/ ____|  \______  (____  /__|_|  /\___  >__|  (____  /
//       \/         \/              \/     \/      \/     \/           \/ 
//

void cursor_enter_callback(GLFWwindow* window, int entered)
{
	if (entered)
	{
		::g_MouseIsInsideWindow = true;
		std::cout << "Mouse moved inside window" << std::endl;
	}
	else
	{
		::g_MouseIsInsideWindow = false;
		std::cout << "Mouse moved outside window" << std::endl;
	}
	return;
}//cursor_enter_callback(...

bool isShiftKeyDownByAlone(int mods)
{
	if (mods == GLFW_MOD_SHIFT)
	{
		// Shift key is down all by itself
		return true;
	}
	return false;
}

bool isCtrlKeyDownByAlone(int mods)
{
	if (mods == GLFW_MOD_CONTROL)
	{
		return true;
	}
	return false;
}

bool isOnlyAltKeyDown(int mods)
{
	if (mods == GLFW_MOD_ALT)
	{
		return true;
	}
	return false;
}

bool isShiftDown(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)) { return true; }
	if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)) { return true; }
	// both are up
	return false;
}

bool isCtrlDown(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL)) { return true; }
	if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)) { return true; }
	// both are up
	return false;
}

bool isADown(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_A)) { return true; }
	
	return false;
}

bool isDDown(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_D)) { return true; }
	// both are up
	return false;
}

bool isWDown(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_W)) { return true; }

	return false;
}

bool isSDown(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_S)) { return true; }
	// both are up
	return false;
}

bool isBDown(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_B)) { return true; }
	// both are up
	return false;
}

bool isAltDown(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_LEFT_ALT)) { return true; }
	if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)) { return true; }
	// both are up
	return false;
}

bool areAllModifiersUp(GLFWwindow* window)
{
	if (isShiftDown(window)) { return false; }
	if (isCtrlDown(window)) { return false; }
	if (isAltDown(window)) { return false; }
	// Yup, they are all UP
	return true;
}

// Mouse (cursor) callback
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{

	return;
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	// A regular mouse wheel returns the y value
	::g_pFlyCamera->setMouseWheelDelta(yoffset);

	//	std::cout << "Mouse wheel: " << yoffset << std::endl;

	return;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		::g_MouseLeftButtonIsDown = true;
		std::cout << "Left Clicked " << std::endl;
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		::g_MouseLeftButtonIsDown = false;
		std::cout << "Left Click released " << std::endl;
	}

	return;
}

void ProcessAsyncMouse(GLFWwindow* window)
{
	double x, y;
	glfwGetCursorPos(window, &x, &y);

	::g_pFlyCamera->setMouseXY(x, y);

	const float MOUSE_SENSITIVITY = 0.1f;

	//	std::cout << ::g_pFlyCamera->getMouseX() << ", " << ::g_pFlyCamera->getMouseY() << std::endl;

		// Mouse left (primary?) button pressed? 
		// AND the mouse is inside the window...
	if ((glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		&& ::g_MouseIsInsideWindow)
	{
		// Mouse button is down so turn the camera
		::g_pFlyCamera->Yaw_LeftRight(-::g_pFlyCamera->getDeltaMouseX() * MOUSE_SENSITIVITY);

		::g_pFlyCamera->Pitch_UpDown(::g_pFlyCamera->getDeltaMouseY() * MOUSE_SENSITIVITY);

	}

	// Adjust the mouse speed
	if (::g_MouseIsInsideWindow)
	{
		const float MOUSE_WHEEL_SENSITIVITY = 0.1f;

		// Adjust the movement speed based on the wheel position
		::g_pFlyCamera->movementSpeed += (::g_pFlyCamera->getMouseWheel() * MOUSE_WHEEL_SENSITIVITY);
		if (::g_pFlyCamera->movementSpeed <= 0.0f)
		{
			::g_pFlyCamera->movementSpeed = 0.0f;
		}
	}


	// HACK 
	::g_pFlyCamera->movementSpeed = 2.0f;

	return;
}//ProcessAsyncMouse(...

void ProcessAsyncKeys(GLFWwindow* window)
{
	const float CAMERA_MOVE_SPEED_SLOW = 0.1f;
	const float CAMERA_MOVE_SPEED_FAST = 1.0f;

	const float CAMERA_TURN_SPEED = 0.1f;

	float cameraMoveSpeed = ::g_pFlyCamera->movementSpeed;

	// If no keys are down, move the camera
	if (areAllModifiersUp(window))
	{

		// Note: The "== GLFW_PRESS" isn't really needed as it's actually "1" 
		// (so the if() treats the "1" as true...)

		if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
		{

		}
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			//			g_CameraEye.z += cameraSpeed;
			::g_pFlyCamera->MoveForward_Z(-cameraMoveSpeed);
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)	// "backwards"
		{
			//			g_CameraEye.z -= cameraSpeed;
			::g_pFlyCamera->MoveForward_Z(+cameraMoveSpeed);
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)	// "left"
		{
			//			g_CameraEye.x -= cameraSpeed;
			::g_pFlyCamera->MoveLeftRight_X(+cameraMoveSpeed);
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)	// "right"
		{
			//			g_CameraEye.x += cameraSpeed;
			::g_pFlyCamera->MoveLeftRight_X(-cameraMoveSpeed);
		}
		if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)	// "up"
		{
			::g_pFlyCamera->MoveUpDown_Y(-cameraMoveSpeed);
			//			::g_pFlyCamera->Roll_CW_CCW( +cameraSpeed );
		}
		if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)	// "down"
		{
			//			g_CameraEye.y -= cameraSpeed;
			::g_pFlyCamera->MoveUpDown_Y(+cameraMoveSpeed);
			//			::g_pFlyCamera->Roll_CW_CCW( -cameraSpeed );
		}
		//g_pFlyCamera->eye = glm::vec3( pEagle->getPositionXYZ().x, pEagle->getPositionXYZ().y, pEagle->getPositionXYZ().z - 50.0f);
	}//if(AreAllModifiersUp(window)

	// If shift is down, do the rotation camera stuff...
	// If no keys are down, move the camera
	if (isShiftDown(window))
	{
		if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)	// "up"
		{
			::g_pFlyCamera->Roll_CW_CCW(-CAMERA_TURN_SPEED);
			//			::g_pFlyCamera->MoveUpDown_Y( +cameraSpeed );
		}
		if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)	// "down"
		{
			::g_pFlyCamera->Roll_CW_CCW(+CAMERA_TURN_SPEED);
			//			::g_pFlyCamera->MoveUpDown_Y( -cameraSpeed );
		}
	}//IsShiftDown(window)


	return;
}// ProcessAsyncKeys(..

//   ___ ___  __ __      ____  ____   ____  __ __  ______  _____
//  |   |   ||  |  |    |    ||    \ |    \|  |  ||      |/ ___/
//  | _   _ ||  |  |     |  | |  _  ||  o  )  |  ||      (   \_ 
//  |  \_/  ||  ~  |     |  | |  |  ||   _/|  |  ||_|  |_|\__  |
//  |   |   ||___, |     |  | |  |  ||  |  |  :  |  |  |  /  \ |
//  |   |   ||     |     |  | |  |  ||  |  |     |  |  |  \    |
//  |___|___||____/     |____||__|__||__|   \__,_|  |__|   \___|
//

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

	const float CAMERASPEED = 1.0f;
	const float MOVESPEED = 2.0f;

	//iObject* pCurrentObject = pFindObjectByFriendlyName("mainCharacter");
	//iObject* pCurrentObject = g_vec_pGameObjects.at(0);

	if (!isShiftKeyDownByAlone(mods) && !isCtrlKeyDownByAlone(mods))
	{

		if (key == GLFW_KEY_B)
		{

		}//if ( key == GLFW_KEY_B )

		if (key == GLFW_KEY_P && action == GLFW_PRESS)
		{
			displayAABBs = !displayAABBs;
		}

	}

	if (isCtrlKeyDownByAlone(mods))
	{
		if (currentRender == renderTag::AI)
		{
			pCurrentObject = pFindObjectByFriendlyName("mainXWing");
			if (key == GLFW_KEY_D)
			{
				glm::quat rotation = glm::quat(glm::vec3(0.0f, glm::radians(-1.5f), 0.0f));
				pCurrentObject->setRotationXYZ(pCurrentObject->getRotationXYZ() * rotation);
			}
			if (key == GLFW_KEY_A)
			{
				//if (pSphere->getPositionXYZ().x < 60.0f)
				//{
					//pSphere->rotationXYZ += glm::vec3(CAMERASPEED, 0.0f, 0.0f);
					//pSphere->setVelocity(pSphere->getVelocity() + glm::vec3(MOVESPEED, 0.0f, 0.0f));		// Move the camera +0.01f units
				glm::quat rotation = glm::quat(glm::vec3(0.0f, glm::radians(1.5f), 0.0f));
				pCurrentObject->setRotationXYZ(pCurrentObject->getRotationXYZ() * rotation);
				//}
				//else
				//{
				//	pSphere->setVelocity(glm::vec3(0.0f, pSphere->getVelocity().y, pSphere->getVelocity().z));
				//}
			}

			if (key == GLFW_KEY_M && action == GLFW_PRESS)
			{
				if (pCurrentObject->getIsWireframe())
				{
					pCurrentObject->setIsWireframe(false);
				}
				else
				{
					pCurrentObject->setIsWireframe(true);
				}
			}

			// Move the camera (W & S for towards and away, along the z axis)
			if (key == GLFW_KEY_S)
			{
				if (pCurrentObject->getPositionXYZ().z < -40.0f)
				{
					pCurrentObject->setVelocity(glm::vec3(pCurrentObject->getVelocity().x, pCurrentObject->getVelocity().y, 0.0f));
				}
				else
				{
					pCurrentObject->setVelocity(pCurrentObject->getVelocity() - glm::vec3(0.0f, 0.0f, MOVESPEED));		// Move the camera -0.01f units
				}
			}
			if (key == GLFW_KEY_W)
			{
				if (pCurrentObject->getPositionXYZ().x > 60.0f)
				{
					pCurrentObject->setVelocity(glm::vec3(0.0f, pCurrentObject->getVelocity().y, pCurrentObject->getVelocity().z));
				}
				else if (pCurrentObject->getPositionXYZ().x < -60.0f)
				{
					pCurrentObject->setVelocity(glm::vec3(0.0f, pCurrentObject->getVelocity().y, pCurrentObject->getVelocity().z));
				}
				else if (pCurrentObject->getPositionXYZ().z > 30.0f)
				{
					pCurrentObject->setVelocity(glm::vec3(pCurrentObject->getVelocity().x, pCurrentObject->getVelocity().y, 0.0f));
				}
				else
				{
					pCurrentObject->setVelocity(pCurrentObject->getVelocity() + glm::vec3(0.0f, 0.0f, MOVESPEED));		// Move the camera +0.01f units
				}
			}
			if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
			{
				glm::vec4 forwardDirObject = glm::vec4(0.0f, 0.0f, 50.0f, 1.0f);

				glm::mat4 matModel = glm::mat4(1.0f);	// Identity

				// Roation
				// Constructor for the GLM mat4x4 can take a quaternion
				glm::mat4 matRotation = glm::mat4(pCurrentObject->getRotationXYZ());
				matModel *= matRotation;
				// *******************

				// Like in the vertex shader, I mulitly the test points
				// by the model matrix (MUST be a VEC4 because it's a 4x4 matrix)
				glm::vec4 forwardInWorldSpace = matModel * forwardDirObject;


				// Add this to the position of the object
				//this->setPositionXYZ(this->getPositionXYZ() + glm::vec3(forwardInWorldSpace));

				gPlayerBullet->setPositionXYZ(pCurrentObject->getPositionXYZ());
				gPlayerBullet->setIsVisible(true);
				gPlayerBullet->setVelocity(glm::vec3(forwardInWorldSpace));
			}
		}
		/*if (key == GLFW_KEY_LEFT)
		{
			pCurrentObject->setRotationXYZ(glm::quat(glm::vec3(0.0f, glm::radians(pCurrentObject->getRotationXYZ().y + 1.0f), 0.0f)));
		}*/
		else
		{
			pCurrentObject = pFindObjectByFriendlyName("mainCar");
			if (key == GLFW_KEY_R && action == GLFW_PRESS)
			{
				bReLoadScene = true;
			}
			if (!pCurrentObject)
			{
				return;
			}
			if (isBDown(window))
			{
				bIsBDown = true;
			}
			if (!isBDown(window))
			{
				bIsBDown = false;
			}
			if (isADown(window))
			{
				bIsADown = true;
			}
			if (!isADown(window))
			{
				bIsADown = false;
			}
			if (isWDown(window))
			{
				bIsWDown = true;
			}
			if (!isWDown(window))
			{
				bIsWDown = false;
			}
			if (isSDown(window))
			{
				bIsSDown = true;
			}
			if (!isSDown(window))
			{
				bIsSDown = false;
			}
			if (key == GLFW_KEY_A)
			{
				//pCurrentObject->setRotationXYZ(glm::vec3(0.0f, glm::radians(90.0f), 0.0f));
				//pCurrentObject->setVelocity(glm::vec3(pCurrentObject->getVelocity().x, 0.0f, 20.0f));
				if (gTurningRadius < 45.0f)
				{
					gTurningRadius += 3.0f;
				}
			}
			if (isDDown(window))
			{
				bIsDDown = true;
			}
			if (!isDDown(window))
			{
				bIsDDown = false;
			}
			if (key == GLFW_KEY_D)
			{
				//pCurrentObject->setRotationXYZ(glm::vec3(0.0f, glm::radians(-90.0f), 0.0f));
				//pCurrentObject->setVelocity(glm::vec3(pCurrentObject->getVelocity().x, 0.0f, 20.0f));
				if (gTurningRadius > -45.0f)
				{
					gTurningRadius -= 3.0f;
				}
			}
			if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
			{
				pCurrentObject->ApplyForce(glm::vec3(0.0f, 400000.0f, 0.0f));
				//jumping = true;
				//currentAnimationName = "Jump";
			}
			if (key == GLFW_KEY_S)
			{
				//if (gEngineForce < 0.0f)
				//{
				//	gEngineForce = 0.0f;
				//}
				//gEngineForce += 5.0f;
				if (pCurrentObject->getPositionXYZ().y < 5.0f)
				{
					gEngineForce = 4000.0f;
				}
				else
				{
					glm::quat rotation = glm::quat(glm::vec3(glm::radians(-1.5f), 0.0f, 0.0f));
					pCurrentObject->setRotationXYZ(pCurrentObject->getRotationXYZ()* rotation);
				}
			}
			if (key == GLFW_KEY_W)
			{
				//if (gEngineForce > 0.0f)
				//{
				//	gEngineForce = 0.0f;
				//}
				//gEngineForce -= 5.0f;
				if (pCurrentObject->getPositionXYZ().y < 5.0f)
				{
					gEngineForce = -4000.0f;
				}
				else
				{
					glm::quat rotation = glm::quat(glm::vec3(glm::radians(1.5f), 0.0f, 0.0f));
					pCurrentObject->setRotationXYZ(pCurrentObject->getRotationXYZ() * rotation);
				}
			}
			if (key == GLFW_KEY_A && key == GLFW_KEY_W)
			{
				if (gTurningRadius < 45.0f)
				{
					gTurningRadius += 3.0f;
				}
				if (pCurrentObject->getPositionXYZ().y < 5.0f)
				{
					gEngineForce = -6000.0f;
				}
				else
				{
					glm::quat rotation = glm::quat(glm::vec3(glm::radians(1.5f), 0.0f, 0.0f));
					pCurrentObject->setRotationXYZ(pCurrentObject->getRotationXYZ() * rotation);
				}
			}
			if (key == GLFW_KEY_A && key == GLFW_KEY_S)
			{
				if (gTurningRadius < 45.0f)
				{
					gTurningRadius += 3.0f;
				}
				if (pCurrentObject->getPositionXYZ().y < 5.0f)
				{
					gEngineForce = 6000.0f;
				}
				else
				{
					glm::quat rotation = glm::quat(glm::vec3(glm::radians(-1.5f), 0.0f, 0.0f));
					pCurrentObject->setRotationXYZ(pCurrentObject->getRotationXYZ() * rotation);
				}
			}
			if (key == GLFW_KEY_D && key == GLFW_KEY_W)
			{
				if (gTurningRadius > -45.0f)
				{
					gTurningRadius -= 3.0f;
				}
				if (pCurrentObject->getPositionXYZ().y < 5.0f)
				{
					gEngineForce = -6000.0f;
				}
				else
				{
					glm::quat rotation = glm::quat(glm::vec3(glm::radians(1.5f), 0.0f, 0.0f));
					pCurrentObject->setRotationXYZ(pCurrentObject->getRotationXYZ() * rotation);
				}
			}
			if (key == GLFW_KEY_D && key == GLFW_KEY_S)
			{
				if (gTurningRadius > -45.0f)
				{
					gTurningRadius -= 3.0f;
				}
				if (pCurrentObject->getPositionXYZ().y < 5.0f)
				{
					gEngineForce = 6000.0f;
				}
				else
				{
					glm::quat rotation = glm::quat(glm::vec3(glm::radians(-1.5f), 0.0f, 0.0f));
					pCurrentObject->setRotationXYZ(pCurrentObject->getRotationXYZ() * rotation);
				}
			}
			if (key == GLFW_KEY_ENTER)
			{
				//attacking = true;
				//currentAnimationName = "Attack";
			}
			if (key == GLFW_KEY_1)
			{
				pLightsVec.at(currentLight)->setConstAtten(pLightsVec.at(currentLight)->getConstAtten() * 0.99f);			// 99% of what it was
			}
			if (key == GLFW_KEY_2)
			{
				pLightsVec.at(currentLight)->setConstAtten(pLightsVec.at(currentLight)->getConstAtten() * 1.01f);
			}
			if (key == GLFW_KEY_3)
			{
				pLightsVec.at(currentLight)->setLinearAtten(pLightsVec.at(currentLight)->getLinearAtten() * 0.99f);			// 99% of what it was
			}
			if (key == GLFW_KEY_4)
			{
				pLightsVec.at(currentLight)->setLinearAtten(pLightsVec.at(currentLight)->getLinearAtten() * 1.01f);			// 1% more of what it was
			}
			if (key == GLFW_KEY_5)
			{
				pLightsVec.at(currentLight)->setQuadraticAtten(pLightsVec.at(currentLight)->getQuadraticAtten() * 0.99f);
			}
			if (key == GLFW_KEY_6)
			{
				pLightsVec.at(currentLight)->setQuadraticAtten(pLightsVec.at(currentLight)->getQuadraticAtten() * 1.01f);
			}
		}
	}

	if (isCtrlKeyDownByAlone(mods) && isShiftKeyDownByAlone(mods))
	{

	}

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}