#ifndef TextureManager_H
#define TextureManager_H

#include "SDL.h"
#include "SDL_image.h"
#include <map>
using namespace std;

class TextureManager {
  public:
    static TextureManager* Instance()
    {
      if(s_pInstance == 0)
        s_pInstance = new TextureManager();
      return s_pInstance;
    }
    ~TextureManager() {}

    bool load(string fileName, string id, SDL_Renderer* pRenderer);

    void draw(string id, int x, int y, int width, int height, float angle, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void drawFrame(string id, int x, int y, int width, int height, int currentRow, 
    int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

  private:
    TextureManager() {}
    map<string, SDL_Texture*> m_textureMap;
    
    static TextureManager* s_pInstance;
};
typedef TextureManager m_Texture;

#endif