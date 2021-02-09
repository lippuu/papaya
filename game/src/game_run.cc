// game_run.cc

#include <papaya.hpp>

#include <stdexcept>

int game_run()
{
   using namespace papaya;

   try {
      Platform platform;
      Window window("papaya", 1024, 576);
      Dispatcher dispatcher;
      Input input;

      dispatcher.register_listener<KeyPressedEvent>(input);
      dispatcher.register_listener<KeyReleasedEvent>(input);

      Debug::log("Platform and window ok!");

      bool running = true;
      while (running) {
         if (!dispatcher.update()) {
            running = false;
         }

         window.present();
      }
   } 
   catch (std::exception &e) {
      (void)e;
   }

   return 0;
}
