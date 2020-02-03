#include "Model.h"

Model::Model(unsigned int ID, unsigned int EboID, int vertCnt)
{
	vaoID = ID;
	eboID = EboID;
	vertexCount = vertCnt;
}

unsigned int Model::getVAOID()
{
	return vaoID;
}

unsigned int Model::getEBOID()
{
	return eboID;
}

void Model::setTexture(Texture* tex)
{
	texture = tex;
}

Texture* Model::getTexture()
{
	return texture;
}

int Model::getVertexCount()
{
	return vertexCount;
}
