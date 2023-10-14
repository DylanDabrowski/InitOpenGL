#ifndef TEXTURE_H
#define TEXTURE_H

#include "StandardIncludes.h"

class Texture
{
private:
	// Members
	int m_width;
	int m_height;
	int m_channels;
	GLuint m_texture;

public:
	// Constructors / Destructors
	Texture();
	virtual ~Texture() { }

	// Accessors
	GLuint GetTexture() { return m_texture; }

	// Methods
	void LoadTexture(string _fileName);
	void Cleanup();
};

#endif // TEXTURE_H

