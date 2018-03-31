#include "Headers.h"
#include "RawModel.h"
#include "Renderer.h"

void Renderer::prepare()
{
	glClearColor(0, 0, 0.5, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::render(TexturedModel *texturedModel)
{
	RawModel *model = texturedModel->getRawModel();

	glBindVertexArray(model->getVaoID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texturedModel->getTexture()->getID());
	glDrawElements(GL_TRIANGLES, model->getVertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);	
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
}
