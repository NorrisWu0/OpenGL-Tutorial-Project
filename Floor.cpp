#pragma once

#include "Floor.h"
#include "colored_2D_shader_program.h"
#include "assets.h"

#define GLEW_STATIC
#include <glew.h>
#include <vector>
#include <math.h>


Floor::Floor(const char* _id) : GameObject(_id)
{
	position = glm::vec3(0.f, -0.75f, 0.f);
	scale = glm::vec3(10.f, 1.25f, 1.f);
}

Floor::~Floor()
{
}

void Floor::SimulateAI(const double, const Assets*, const Scene*, const Configuration*)
{
}

void Floor::Render(const double, const Assets* _assets, const Scene* _scene, const Configuration* _config)
{
	std::vector<GLfloat> _colors =
	{
		RTF(140), RTF(140), RTF(140), 1.0f,
		RTF(140), RTF(140), RTF(140), 1.0f,
		RTF(140), RTF(140), RTF(140), 1.0f,
		RTF(140), RTF(140), RTF(140), 1.0f,
		RTF(140), RTF(140), RTF(140), 1.0f,
		RTF(140), RTF(140), RTF(140), 1.0f,
	};
	
	const Colored_2D_Shader_Program* _program = (Colored_2D_Shader_Program*)_assets->get_asset("Shader_Program.2D.Colored");
	const Mesh* _mesh = (Mesh*)_assets->get_asset("Mesh.Square");
	glm::mat4 _trans = Transformation(_scene, _config);

	_program->Render(_config, _mesh, &_colors, &_trans);
}