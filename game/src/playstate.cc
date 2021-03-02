// playstate.cc

#include "playstate.hpp"
#include "menustate.hpp"

#include <platform/time.hpp>
#include <platform/debug.hpp>
#include <input/input.hpp>
#include <graphics/graphics.hpp>
#include <scene/renderer.hpp>
#include <game/runtime.hpp>

using namespace papaya;

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
      if (keyboard_.released(Key::Escape)) {
         next_ = menu_;
         return false;
      }

      return true;
   }

   void PlayState::render(papaya::Renderer &renderer)
   {
      Graphics::clear({ 0.3f, 0.1f, 0.2f, 1.0f });
   }
} // !spacegame
