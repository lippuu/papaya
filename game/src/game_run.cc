// game_run.cc

#include <papaya.hpp>

#include <stdexcept>

class Foo {
public:
   Foo() {}
   ~Foo() {}

   int bar = 0;
};

int game_run()
{
   using namespace papaya;

   try { 
      Platform platform;
      Window window("papaya", 1024, 576);
      Dispatcher dispatcher;
      Input input;
      FileSystem filesystem("lippuu", "papaya");

      dispatcher.register_listener<KeyPressedEvent>(input);
      dispatcher.register_listener<KeyReleasedEvent>(input);

      dispatcher.register_listener<MouseMoveEvent>(input);
      dispatcher.register_listener<MouseButtonEvent>(input);
      dispatcher.register_listener<MouseWheelEvent>(input);

      Debug::log("Platform and window ok!");

      bool running = true;
      while (running) {
         input.update();
         if (!dispatcher.update()) {
            running = false;
         }

         if (input.mouse().any_released()) {
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
