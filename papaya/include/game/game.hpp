// game.hpp

#pragma once

namespace papaya {
   class Time;
   class Runtime;
   class State;

   class Game {
   public:
      Game(Runtime &runtime);
      virtual ~Game() = default;

      virtual bool init();
      virtual void shut();
      virtual bool tick(const Time &deltatime); 

   protected:
      Runtime &runtime_;
      State *current_;
   };
} // !papaya
