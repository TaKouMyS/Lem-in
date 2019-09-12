/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 01:41:06 by amamy             #+#    #+#             */
/*   Updated: 2019/09/12 01:44:43 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL2/SDL.h"
#include <stdio.h>

int main(int argc, char* argv[]) {

SDL_Window *window;                    // Declare a pointer

SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

// Create an application window with the following settings:
window = SDL_CreateWindow(
    "An SDL2 window",                  // window title
    SDL_WINDOWPOS_UNDEFINED,           // initial x position
    SDL_WINDOWPOS_UNDEFINED,           // initial y position
    640,                               // width, in pixels
    480,                               // height, in pixels
    SDL_WINDOW_OPENGL                  // flags - see below
);

// Check that the window was successfully created
if (window == NULL) {
    // In the case that the window could not be made...
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
}

// A basic main loop to prevent blocking
int is_running = 1;
SDL_Event event;
while (is_running) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            is_running = 0;
        }
    }
    SDL_Delay(16);
}

// Close and destroy the window
SDL_DestroyWindow(window);

// Clean up
SDL_Quit();
return 0;

}