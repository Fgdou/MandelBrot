#include <iostream>
#include <SDL2/SDL.h>
#include "complex.h"

#define HEIGHT 1000
#define WIDTH 1800

SDL_Renderer* renderer;
SDL_Window* window;
SDL_Event e;

long double scale = 0.005;
int nIter = 50;
long double xOff = 0;
long double yOff = 0;
bool detailed = false;

int mandelbrot(long double x, long double y, int nMax, Complex& c){
    c = {x, y};
    for(int i=0; i<nMax; i++){
        c.pow(2);
        c += {x, y};
        if(c.i()*c.i()+c.r()*c.r() > 4)
            return i;
    }
    return -1;
}

void render(int nIter, bool detailed = false){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    int increment = (detailed) ? 1 : 10;

    for(int i=0; i<HEIGHT; i += increment){
        for(int j=0; j<WIDTH; j += increment){
            long double x = (j-WIDTH/2) * scale + xOff;
            long double y = (i-HEIGHT/2) * scale + yOff;

            Complex c(0,0);

            int n = mandelbrot(x, y, nIter, c);
            if(n == -1)
                continue;

            long double s = (long double)n/nIter*255;
            long double len = (c.r()*c.r()+c.i()*c.i())/2;
            //long double s = n - log(log(c.abs())/2.0);

            int r = s;
            int g = s;
            int b = s;

            SDL_SetRenderDrawColor(renderer, r,g,b,255);
            SDL_RenderDrawPoint(renderer, j, i);
        }
    }

    SDL_RenderPresent(renderer);
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);

    SDL_PollEvent(&e);

    while(e.type != SDL_QUIT){
        long double lot = 5 * scale;

        if(e.type == SDL_KEYDOWN){
            SDL_Keycode key = e.key.keysym.sym;

            if(key == SDLK_LEFT)
                xOff -= lot;
            else if(key == SDLK_RIGHT)
                xOff += lot;
            if(key == SDLK_UP)
                yOff -= lot;
            else if(key == SDLK_DOWN)
                yOff += lot;
            if(key == SDLK_PAGEUP) {
                scale *= 1.05;
            }else if(key == SDLK_PAGEDOWN) {
                scale /= 1.05;
            }if(key == SDLK_p) {
                nIter += 10;
                std::cout << nIter << "\n";
            }else if(key == SDLK_m) {
                nIter -= 10;
                std::cout << nIter << "\n";
            }
            if(key == SDLK_SPACE){
                detailed = !detailed;
            }
        }

        render(nIter, detailed);

        SDL_PollEvent(&e);
    }

    SDL_RenderClear(renderer);
    SDL_Quit();
}