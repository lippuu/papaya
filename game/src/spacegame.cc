// spacegame.cc

#include "spacegame.hpp"

namespace spacegame {
   SpaceGame::SpaceGame(papaya::Runtime &runtime)
      : Game(runtime)
   {
   }

   SpaceGame::~SpaceGame()
   {
   }

   bool SpaceGame::init()
   {
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
