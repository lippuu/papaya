// scapegame.hpp

#pragma once

#include <papaya.hpp>

#include "menustate.hpp"
#include "playstate.hpp"

namespace spacegame {
   class SpaceGame : public papaya::Game {
   public:
      SpaceGame(papaya::Runtime &runtime);
      ~SpaceGame();

      virtual bool init();
      virtual void shut();
      virtual bool tick(const papaya::Time &deltatime); 

   private:
      MenuState menu_;
      PlayState play_;
   };
} // !spacegame
