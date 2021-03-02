// menustate.hpp

#pragma once

#include <game/state.hpp>
#include <input/keyboard.hpp>

namespace papaya {
   class Runtime;
} // !papaya

namespace spacegame {
   class PlayState;

   class MenuState : public papaya::State {
   public:
      MenuState(papaya::Runtime &runtime, PlayState *play);

      bool init();
      void shut();

      virtual papaya::State *next() const;
      virtual bool update(const papaya::Time &deltatime);
      virtual void render(papaya::Renderer &renderer);

   private:
      papaya::Runtime &runtime_;
      const papaya::Keyboard &keyboard_;
      papaya::State *next_;
      PlayState *play_;
   };
} // !spacegame
