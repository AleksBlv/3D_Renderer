#include "Renderer.h"



void Renderer::createProjectionMatrix()
{
	projectionMatrix = new glm::mat4x4();
	*projectionMatrix = glm::perspective(glm::radians(FOV), (float)display->getWidth() / (float)display->getHeight(), NEAR_PLANE, FAR_PLANE);
}

Renderer::Renderer(Display* display, ShaderProgram * shader)
{
	this->display = display;
	createProjectionMatrix();
	shader->Use();
	shader->loadProjectionMatrix(glm::value_ptr(*projectionMatrix));
	shader->Stop();
}

void Renderer::prepare()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
}

void Renderer::render(Entity* entity, ShaderProgram* shader)
{
	Model* model = entity->getModel();
	glBindVertexArray(model->getVAOID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glm::mat4x4* transformationMatrix = createTransformationMatrix(entity->getPosition(), entity->getRotX(),
		entity->getRotY(), entity->getRotZ(), entity->getScale());
	shader->loadTransformationMatrix(glm::value_ptr(*transformationMatrix));
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model->getEBOID());

	model->getTexture()->bind(0);
	glDrawElements(GL_TRIANGLES, model->getVertexCount(), GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);
	delete transformationMatrix;
}