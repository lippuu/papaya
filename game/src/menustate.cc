// menustate.cc

#include "menustate.hpp"
#include "playstate.hpp"

#include <platform/time.hpp>
#include <platform/debug.hpp>
#include <game/runtime.hpp>
#include <input/input.hpp>
#include <scene/renderer.hpp>

namespace spacegame {
   MenuState::MenuState(papaya::Runtime &runtime, PlayState *play)
      : runtime_(runtime)
      , keyboard_(runtime.input().keyboard())
      , next_(nullptr)
      , play_(play)
   {
   }


   bool MenuState::init()
   {
      return true;
   }

   void MenuState::shut() 
   {
   }

   papaya::State *MenuState::next() const
   {
      return next_;
   }

   bool MenuState::update(const papaya::Time &deltatime)
   {
      using namespace papaya;
      if (keyboard_.released(Key::Escape)) {
         next_ = nullptr;
         return false;
      }
      else if (keyboard_.released(Key::Space)) {
         next_ = play_;
         return false;
      }

      return true;
   }

   void MenuState::render(papaya::Renderer &renderer)
   {
   }
} // !spacegame
