// playstate.cc

#include "playstate.hpp"
#include "menustate.hpp"

#include <platform/time.hpp>
#include <platform/debug.hpp>
#include <input/input.hpp>
#include <scene/renderer.hpp>
#include <game/runtime.hpp>

namespace spacegame {
   PlayState::PlayState(papaya::Runtime &runtime, MenuState *menu)
      : runtime_(runtime)
      , keyboard_(runtime.input().keyboard())
      , next_(nullptr)
      , menu_(menu)
   {
   }

   bool PlayState::init()
   {
      return true;
   }

   void PlayState::shut()
   {
   }

   papaya::State *PlayState::next() const
   {
      return next_;
   }

   bool PlayState::update(const papaya::Time &deltatime)
   {
      using namespace papaya;
      if (keyboard_.pressed(Key::Escape)) {
         next_ = menu_;
         return false;
      }

      return true;
   }

   void PlayState::render(papaya::Renderer &renderer)
   {
   }
} // !spacegame
