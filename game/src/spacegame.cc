// spacegame.cc

#include "spacegame.hpp"

using namespace papaya;

namespace spacegame {
   struct Velocity : Component<Velocity> {
      Velocity(GameObject *parent)
         : Component(parent)
      {
      }

      Vector2 direction_;
   };
   
   struct Position : ComponentBase {
      Position(GameObject *parent)
         : ComponentBase(parent, ComponentRegistry::family<Position>())
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
      return Game::tick(deltatime);
   }
} // !spacegame
