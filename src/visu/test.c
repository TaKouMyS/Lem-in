/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 23:26:58 by amamy             #+#    #+#             */
/*   Updated: 2019/09/12 04:01:39 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int    ft_quit(SDL_Renderer *renderer, SDL_Window *window, int statut)
{
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return statut;
}

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    int statut = EXIT_FAILURE;
    SDL_Color orange = {255, 127, 40, 255};
    SDL_Color green = {0, 255, 0, 255};
    
    /* Initialisation, création de la fenêtre et du renderer. */
    if(0 != SDL_Init(SDL_INIT_VIDEO))
        ft_quit(renderer, window, EXIT_FAILURE);
    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640, 480, SDL_WINDOW_SHOWN);
    if(NULL == window)
        ft_quit(renderer, window, EXIT_FAILURE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(NULL == renderer)
        ft_quit(renderer, window, EXIT_FAILURE);
    if(0 != SDL_SetRenderDrawColor(renderer, orange.r, orange.g, orange.b, orange.a))
        ft_quit(renderer, window, EXIT_FAILURE);
    if(0 != SDL_RenderClear(renderer))
        ft_quit(renderer, window, EXIT_FAILURE);
    int is_running = 1;
    SDL_Event event;
    if(0 != SDL_SetRenderDrawColor(renderer, green.r, green.g, green.b, green.a))
        ft_quit(renderer, window, EXIT_FAILURE);
    while (is_running) 
    {
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
               is_running = 0;
        }
        SDL_Delay(500);
        SDL_Rect rect1 = {0, 0, 640, 480};
        SDL_RenderDrawRect(renderer, &rect1); 
        SDL_RenderPresent(renderer);
    if(0 != SDL_RenderClear(renderer))
        ft_quit(renderer, window, EXIT_FAILURE);
        SDL_Delay(2000);
        SDL_Rect rect = {100, 100, 100, 100};
        SDL_RenderDrawRect(renderer, &rect); 
        SDL_RenderPresent(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(5000);

        is_running = 0;
    }

    // SDL_Point point[5];
    // point[0].x = 100;
    // point[0].y = 100;
    // point[1].x = 200;
    // point[1].y = 100;
    // point[2].x = 200;
    // point[2].y = 200;
    // point[3].x = 100;
    // point[3].y = 200;   
    // point[4].x = 100;
    // point[4].y = 100;
    // SDL_RenderPresent(renderer);
    // SDL_Delay(5000);
    // SDL_RenderDrawLines(renderer, point, 5);
    // SDL_RenderPresent(renderer);
    
    statut = EXIT_SUCCESS;

    return (ft_quit(renderer, window, EXIT_SUCCESS));
}
