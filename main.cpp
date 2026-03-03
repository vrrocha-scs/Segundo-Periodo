#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <iostream>

/*
g++ -std=c++11 -Wall -g main.cpp \
$(pkg-config --libs --cflags allegro-5 allegro_main-5 allegro_audio-5 allegro_image-5 allegro_font-5 allegro_primitives-5 allegro_acodec-5 allegro_ttf-5) \
-o main && ./main
*/

using namespace std;

const float FPS = 30;
const int SCREEN_W = 800;
const int SCREEN_H = 600;

int main(int argc, char **argv) {
    // Initialize Allegro
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;

    // Initialization routines
    al_init();
    al_init_primitives_addon();
    al_install_keyboard();

    event_queue = al_create_event_queue();
    display = al_create_display(SCREEN_W, SCREEN_H);
    timer = al_create_timer(1.0 / FPS);

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    // start timer: important to keep the game speed controlled
    al_start_timer(timer);

    bool playing = true;
    int offset_y = 0;
    int offset_x = 0;
    while (playing) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_TIMER) {
            al_clear_to_color(al_map_rgba_f(1, 1, 1, 1));
            al_draw_circle(SCREEN_W / 2 + offset_x,
                           SCREEN_H / 2 + offset_y,
                           50,
                           al_map_rgb(255, 0, 0), 5);

            al_flip_display();
        } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (ev.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE:
                    playing = false;
                    break;
                case ALLEGRO_KEY_UP:
                    offset_y -= 20;
                    break;
                case ALLEGRO_KEY_DOWN:
                    offset_y += 20;
                    break;
                case ALLEGRO_KEY_LEFT:
                    offset_x -= 20;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    offset_x += 20;
                    break;
            }
        }
        // if the event was to close the game window (using the x button)
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            playing = false;
        }
    }

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    return 0;
}


