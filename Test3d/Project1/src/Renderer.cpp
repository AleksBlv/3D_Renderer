#include "Renderer.h"

void Renderer::prepare()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.5, 0.5, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
}

void Renderer::render(Model* model)
{
	glBindVertexArray(model->getVAOID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	//glDrawArrays(GL_TRIANGLES, 0, model->getVertexCount());
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model->getEBOID());
	model->getTexture()->bind(0);
	glDrawElements(GL_TRIANGLES, model->getVertexCount(), GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
}