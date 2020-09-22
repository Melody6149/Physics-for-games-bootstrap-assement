#pragma once

#include "Application.h"
#include "Renderer2D.h"

class Physics_for_games_assementApp : public aie::Application {
public:

	Physics_for_games_assementApp();
	virtual ~Physics_for_games_assementApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};