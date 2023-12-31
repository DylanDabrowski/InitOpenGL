#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "StandardIncludes.h"
#include "Shader.h"
#include "Mesh.h"
#include "WindowController.h"
#include "Camera.h"

class GameController : public Singleton<GameController>
{
public:
	// Constructors / Destructors
	GameController();
	virtual ~GameController() { };

	// Methods
	void Initialize();
	void RunGame();

private:
	// Members
	Shader m_shader;
	Camera m_camera;
	Mesh m_mesh;
};

#endif // GAME_CONTROLLER_H