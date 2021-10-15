#ifndef Game_H
#define Game_H

#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"

class GameManager
{
public:
	GameManager() { 
    b_flip = SDL_FLIP_NONE; b_dirt = 1; delayTime = 1; rotateNum = 0;
    ba_PosX = 0; ba_PosY = 0; ba_dirtX = 1; ba_dirtY = 1; mapTextureXSize = 16; mapTextureYSize = 16;
  }
	~GameManager() {}

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
  SDL_Event event;

	bool m_bRunning;

  int m_currentFrame;

  //[Flip]
  SDL_RendererFlip b_flip;
  SDL_RendererFlip ba_flip;
  
  
  //[시간]
  float timeDeltatime;
  float delayTime;
  int mTicktime;
  

  //[좌우이동_화살표]
  int b_PosX;
  int b_dirt;

  //[360도 회전 변수]
  float rotateNum;

  //[볼 튕기는 좌표값]
  int ba_PosX;
  int ba_PosY;
  int ba_dirtX;
  int ba_dirtY;

  //[맵 19*19에 해당하는 스프라이트의 크기]]
  int wallTexture[20][20] = {
                          {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                          {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                          {1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1},
                          {1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
                          {1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1},
                          {1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1},
                          {1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1},
                          {1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1},
                          {1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1},
                          {1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1},
                          {1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
                          {1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1},
                          {1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
                          {1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1},
                          {1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1},
                          {1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1},
                          {1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1},
                          {1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0},
                          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
                          };

  int mapTextureXSize;
  int mapTextureYSize;
};

#endif