// dispatcher.cc

#include "platform/dispatcher.hpp"
#include "platform/events.hpp"

#include "input/key.hpp"

#include <SDL.h>

namespace papaya {
   Key scancode_to_keycode(SDL_Scancode code)
   {
      if (code == SDL_SCANCODE_ESCAPE) {
         return Key::Escape;
      }

      return Key::None;
   }

   Dispatcher::Dispatcher()
   {
   }

   bool Dispatcher::update()
   {
      SDL_Event event{};
      while (SDL_PollEvent(&event)) {
         if (event.type == SDL_KEYDOWN) {
            Key keycode = scancode_to_keycode(event.key.keysym.scancode);
            if (keycode != Key::None) {
               bool repeat = event.key.repeat != 0 ? true : false;
               submit(KeyPressedEvent{ keycode, repeat });
            }
         }
         else if (event.type == SDL_KEYUP) {
            Key keycode = scancode_to_keycode(event.key.keysym.scancode);
            if (keycode != Key::None) {
               submit(KeyReleasedEvent{ keycode });
            }
         }
         else if (event.type == SDL_QUIT) {
            submit( WindowClosingEvent{} );
            return false;
         }
      }

      return true;
   }
} // !papaya
 