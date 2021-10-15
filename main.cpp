#include "GameManager.h"

GameManager* m_Game = 0;

int main(int argc, char* argv[])
{
	m_Game = new GameManager();
	m_Game->init("SDL-GameFramework - HW", 100, 100, 800, 600, 0);
	while (m_Game->running())
	{
		m_Game->handleEvents();
		m_Game->update();
		m_Game->render();
	}
	m_Game->clean();
	return 0;
}