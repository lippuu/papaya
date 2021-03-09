// spacegame.cc

#include "spacegame.hpp"
#include "graphics/graphics.hpp"

using namespace papaya;

namespace spacegame {
   namespace {
      bool ends_with(const char *src, const char *end) {
         const auto src_len = strlen(src);
         if (src_len == 0) {
            return false;
         }

         const auto end_len = strlen(end);

         return true;
      }
   } // !anon

   struct Velocity : Component<Velocity> {
      Velocity(GameObject *parent)
         : Component(parent)
      {
      }

      Vector2 direction_;
   };
   
   struct Position : Component<Position> {
      Position(GameObject *parent)
         : Component(parent)
      {
      }

      virtual void update(const Time &deltatime) override
      {
         Velocity *velocity = parent_->get_component<Velocity>();

         position_ += velocity->direction_ * deltatime.as_seconds();
      }

      Vector2 position_;
   };

   SpaceGame::SpaceGame(papaya::Runtime &runtime)
      : Game(runtime)
      , menu_(runtime, &play_)
      , play_(runtime, &menu_)
   {
   }

   SpaceGame::~SpaceGame()
   {
   }

   bool SpaceGame::init()
   {
      GameObject go;
      go.add_component<Position>();
      go.add_component<Velocity>();

      auto loader = [&](const char *filename)
      {
         // todo: if filename ends with ".png" we can do this
         runtime_.textures().load(filename);
      };

      runtime_.filesystem().enumerate_folder("assets/", loader, true);

      if (!menu_.init()) {
         return false;
      }

      if (!play_.init()) {
         return false;
      }

      set_active_state(&menu_);

      return true;
   }

   void SpaceGame::shut()
   {
      menu_.shut();
      play_.shut();
   }

   bool SpaceGame::tick(const papaya::Time &deltatime)
   {
      Graphics::clear(Color::Black);
      Graphics::set_viewport({ 0, 0, 1024, 576 });
      Graphics::set_projection(Matrix4::orthographic(1024.0f, 576.0f));

      return Game::tick(deltatime);
   }
} // !spacegame
