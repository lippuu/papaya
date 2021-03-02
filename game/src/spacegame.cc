// spacegame.cc

#include "spacegame.hpp"

namespace spacegame {
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
      if (!play_.init()) {
         return false;
      }

      set_active_state(&menu_);

      return true;
   }

   void SpaceGame::shut()
   {
   }

   bool SpaceGame::tick(const papaya::Time &deltatime)
   {
      return Game::tick(deltatime);
   }
} // !spacegame
