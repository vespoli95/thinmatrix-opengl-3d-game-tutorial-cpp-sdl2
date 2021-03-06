#include "ParticleShader.h"
#include "../toolbox/Maths.h"

const string VERTEX_FILE = "particles/particleVShader.glsl";
const string FRAGMENT_FILE = "particles/particleFShader.glsl";

ParticleShader::ParticleShader() : ShaderProgram(VERTEX_FILE, FRAGMENT_FILE)
{
	bindAttributes();
	linkProgram();
	getAllUniformLocations();
}

void ParticleShader::bindAttributes()
{
	bindAttribute(0, "position");
	bindAttribute(1, "modelViewMatrix");
	bindAttribute(5, "texOffsets");
	bindAttribute(6, "blendFactor");
}

void ParticleShader::loadNumberOfRows(GLfloat numRows)
{
	loadFloat(location_numberOfRows, numRows);
}

void ParticleShader::loadProjectionMatrix(glm::mat4& matrix)
{
	loadMatrix(location_projectionMatrix, matrix);
}

void ParticleShader::getAllUniformLocations()
{
	location_projectionMatrix = getUniformLocation("projectionMatrix");
	location_numberOfRows = getUniformLocation("numberOfRows");
}
