#include <SDL.h>
#include <iostream>
int main ( int argc, char *argv[] )
{
try{
	/* initialize SDL */
	SDL_Init(SDL_INIT_VIDEO);
	std::cout << "SDL Init()" << std::endl;

	/* set the title bar */
	SDL_WM_SetCaption("SDL Test", "SDL Test");

	/* create window */
	SDL_Surface* screen = SDL_SetVideoMode(640, 480, 0, 0);

	std::cout << "SDL Surface()" << std::endl;
	/* load bitmap to temp surface */
	SDL_Surface* temp = SDL_LoadBMP("sdl_logo.bmp");

	/* convert bitmap to display format */
	SDL_Surface* bg = SDL_DisplayFormat(temp);

	std::cout << "SDL free Surface()" << std::endl;
	/* free the temp surface */
	SDL_FreeSurface(temp);

	SDL_Event event;
	int gameover = 0;

	std::cout << "Entering loop:" << std::endl;
	/* message pump */
	while (!gameover)
	{
		/* look for an event */
		if (SDL_PollEvent(&event)) {
			/* an event was found */
			switch (event.type) {
				/* close button clicked */
				case SDL_QUIT:
					gameover = 1;
					break;

					/* handle the keyboard */
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
						case SDLK_ESCAPE:
						case SDLK_q:
							gameover = 1;
							break;
					}
					break;
			}
		}

		/* draw the background */
		SDL_BlitSurface(bg, NULL, screen, NULL);

		/* update the screen */
		SDL_UpdateRect(screen, 0, 0, 0, 0);
	}

	/* free the background surface */
	SDL_FreeSurface(bg);

	std::cout << " cleaning up SDL...calling SDL_Quit()" << std::endl;
	/* cleanup SDL */
	SDL_Quit();
	char c=getchar();
}catch(std::exception e) {
	std::cout << "caught exception " << e.what() << std::endl;
}
	return 0;
}
