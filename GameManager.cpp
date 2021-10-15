#include "GameManager.h"

bool GameManager::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
      {
				SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 255, 255);

        if(!m_Texture::Instance()->load("Assets/BackGround.png", "Background", m_pRenderer))
        {
          return false;
        }
        if(!m_Texture::Instance()->load("Assets/Bar.png", "bar", m_pRenderer))
        {
          return false;
        }
        if(!m_Texture::Instance()->load("Assets/Clock.png", "clock", m_pRenderer))
        {
          return false;
        }
        if(!m_Texture::Instance()->load("Assets/Clock.png", "ball", m_pRenderer))
        {
          return false;
        }
        if(!m_Texture::Instance()->load("Assets/wall-0.png", "street", m_pRenderer))
        {
          return false;
        }
        if(!m_Texture::Instance()->load("Assets/wall-1.png", "wall", m_pRenderer))
        {
          return false;
        }
      }
			else
      {
				return false;
      }
        
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	m_bRunning = true;
	return true;
}

void GameManager::update()
{
  //deltatime
  timeDeltatime = ( (SDL_GetTicks() - mTicktime ) / 1000.0f);
  mTicktime = SDL_GetTicks() - delayTime;

  if(timeDeltatime > 0.1f)
  {
    timeDeltatime = 0.1f;
  }

  //좌우 
  if((b_PosX + 120) >= 800 || b_PosX < 0)
  {
    b_dirt *= -1;
    if(b_dirt == -1) { delayTime *= 0.2f; }
    else { delayTime *= 1; }
    b_dirt == -1 ? b_flip = SDL_FLIP_HORIZONTAL : b_flip = SDL_FLIP_NONE;
  }

  b_PosX += 150 * b_dirt * timeDeltatime;
  
  //360회전
  if(rotateNum >= 360.0f)
  {
    rotateNum = 1.0f;
  }
  rotateNum += 50.0f * timeDeltatime;
  
  //볼 튀기기
  if((ba_PosX + 64) >= 800 || ba_PosX <= 0)
  {
    ba_dirtX *= -1;
    if(ba_dirtX == -1) { delayTime *= 0.2f; }
    else { delayTime *= 1; }
  }
  
  if((ba_PosY + 64) >= 600 || ba_PosY <= 0)
  {
    ba_dirtY *= -1;
    if(ba_dirtY == -1) { delayTime *= 0.2f; }
    else { delayTime *= 1; }
  }
  ba_PosX += 100 * timeDeltatime * ba_dirtX;
  ba_PosY += 100 * timeDeltatime * ba_dirtY;

  // if(m_iAnimalmove == true)
  // {
  //   m_currentFrame = ( (SDL_GetTicks() / 100) % 7);
  // }
}

void GameManager::render()
{
	SDL_RenderClear(m_pRenderer);
  m_Texture::Instance()->draw("Background", 0, 0, 800, 600, 0, m_pRenderer);
  m_Texture::Instance()->drawFrame("bar", b_PosX, 10, 120, 30, 0, m_currentFrame, m_pRenderer, b_flip);
  m_Texture::Instance()->draw("clock", 0, 300, 64, 64, rotateNum, m_pRenderer);
  m_Texture::Instance()->draw("ball", ba_PosX, ba_PosY, 64, 64, 0, m_pRenderer);

  //맵 19*19
  for(int y = 0; y < 19; y++)
  {
    for(int x = 0; x < 19; x++)
    {
      if(wallTexture[y][x] == 0)
      {
        m_Texture::Instance()->draw("street", 700 - (19 - x) * mapTextureXSize, 600 - (19 - y) * mapTextureYSize, mapTextureXSize, mapTextureYSize, 0, m_pRenderer);
      }
      else if (wallTexture[y][x] == 1)
      {
        m_Texture::Instance()->draw("wall", 700 - (19 - x) * mapTextureXSize, 600 - (19 - y) * mapTextureYSize, mapTextureXSize, mapTextureYSize, 0, m_pRenderer);
      }
    }
  }

	SDL_RenderPresent(m_pRenderer);
}

bool GameManager::running()
{
	return m_bRunning;
}

void GameManager::handleEvents()
{
	if (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
		  case SDL_QUIT:
			  m_bRunning = false;
			  break;
        // [ 3주차 실습 심화]
      case SDL_KEYDOWN:
      {
		    switch (event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            clean();
            m_bRunning = false;
            break;
        }
      }
    }
	}
}

void GameManager::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}