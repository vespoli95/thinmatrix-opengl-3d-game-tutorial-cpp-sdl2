#ifndef ENTITYRENDERER_H
#define ENTITYRENDERER_H

#include "../Headers.h"
#include "../models/TexturedModel.h"
#include "../entities/Entity.h"
#include "../shaders/StaticShader.h"

class EntityRenderer {
public:
	EntityRenderer(StaticShader& shader, glm::mat4& projectionMatrix);
	void render(std::map<TexturedModel*, vector<Entity*>*>* entities);
	void prepareTexturedModel(TexturedModel &model);
	void unbindTexturedModel();
	void prepareInstance(Entity &entity);
private:
	StaticShader& shader;
};

#endif
