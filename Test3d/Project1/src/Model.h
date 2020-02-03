#pragma once
#include "Texture.h"


	class Model
	{
	private:
		unsigned int vaoID;
		unsigned int eboID;
		int vertexCount;
		//unsigned int texture;
		Texture* texture;
	public:
		Model(unsigned int ID, unsigned int eboID, int vertCnt);
		unsigned int getVAOID();
		unsigned int getEBOID();
		void setTexture(Texture* tex);
		Texture* getTexture();
		int getVertexCount();
	};



