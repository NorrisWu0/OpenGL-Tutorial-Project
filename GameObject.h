#pragma once

#include <string>
#include <iostream>

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/transform.hpp>

#define GLEW_STATIC
#include <glew.h>
#include <vector>

class Assets;
class Input;
struct Configuration;
class Scene;

class GameObject
{
public:
	GameObject(const char* id);
	~GameObject();

	const char* id() const;

	virtual void SimulateAI(const double _deltaTime, const Assets* assets, const Scene* scene, const Configuration* config) = 0;
	virtual void SimulatePhysics(const double _deltaTime, const Assets* assets, const Scene* scene, const Configuration* config);
	virtual void Render(const double _deltaTime, const Assets* assets, const Scene* scene, const Configuration* config) = 0;

	glm::mat4x4 Transformation(const Scene* scene, const Configuration* config);

protected:
	const char* _id;

	double totalTime;

	glm::vec3 m_Position = glm::vec3(0.f, 0.f, 0.f);
	glm::vec3 m_Rotation = glm::vec3(0.f, 0.f, 0.f);
	glm::vec3 m_Scale = glm::vec3(1.f, 1.f, 1.f);

	virtual float RTF(float _value);
	virtual std::vector<GLfloat> RGBA(float, float, float, float);
};