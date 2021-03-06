#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(string fileName, string id, SDL_Renderer* pRenderer)
{
  SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
  if(pTempSurface == 0)
  {
    return false;
  }
  SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);
  if(pTexture != 0)
  {
    m_textureMap[id] = pTexture;
    return true;
  }
  return false;
}

void TextureManager::draw(string id, int x, int y, int width, int height, 
float angle, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect; //원본상자
  SDL_Rect destRect; // 대상상자
  float rotate;

  srcRect.x = 0;
  srcRect.y = 0;
  rotate = angle;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, rotate, 0, flip);
}

void TextureManager::drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect; //원본상자
  SDL_Rect destRect; // 대상상자

  srcRect.x = width * currentFrame;
  srcRect.y = height * currentRow;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}