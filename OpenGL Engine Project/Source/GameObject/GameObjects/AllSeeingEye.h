#pragma once
#include "GameObject.h"
#include "ShaderProgram_Textured2D.h"
#include "Assets.h"

class AllSeeingEye : public GameObject
{
public:
	AllSeeingEye(const char* _id);
	~AllSeeingEye();

	virtual void SimulateAI(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config, const Input* _input) override;
	virtual void Render(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config) override;

};

