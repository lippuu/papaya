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
      FileSystem filesystem("lippuu", "papaya");
      TextureStorage textures(filesystem);
      Renderer renderer;

      if (!Graphics::init()) {
         throw std::runtime_error("Could not initialize Graphics!");
      }

      dispatcher.register_listener<KeyPressedEvent>(input);
      dispatcher.register_listener<KeyReleasedEvent>(input);
      dispatcher.register_listener<MouseMoveEvent>(input);
      dispatcher.register_listener<MouseButtonEvent>(input);
      dispatcher.register_listener<MouseWheelEvent>(input);

      Debug::log("Platform and window ok!");

      const char *test_image_filename = "assets/test.png";
      textures.load(test_image_filename);
      const Texture *image = textures.find(test_image_filename);

      Sprite sprite({ 64.0f, 64.0f }, { 0.0f, 0.0f, 1.0f, 1.0f }, image);
      Transform transform({ 100.0f, 100.0f });
      transform.set_origin({ 32.0f, 32.0f })
         .set_rotation(45.0f);

      bool running = true;
      while (running) {
         input.update();
         if (!dispatcher.update()) {
            running = false;
         }

         if (input.keyboard().any_released()) {
            running = false;
         }

         float mouse_x = static_cast<float>(input.mouse().x());
         float mouse_y = static_cast<float>(input.mouse().y());
         Vector2 mp = Vector2(mouse_x, mouse_y) / Vector2(1024.0f, 576.0f);

         Graphics::clear({ 1.0f, mp.x_, mp.y_, 1.0f });
         Graphics::set_viewport({ 0, 0, 1024, 576 });
         Graphics::set_projection( Matrix4::orthographic(1024.0f, 576.0f) );
         //Graphics::render(image, 4, vertices);

         renderer.draw(sprite, transform); 
         renderer.flush();

         window.present();
      }

      Graphics::shut();
   } 
   catch (std::exception &e) {
      (void)e;
   }

   return 0;
}
