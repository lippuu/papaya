// input.cc

#include "input/input.hpp"
#include "platform/events.hpp"

namespace papaya {
   Input::Input()
   {
   }

   void Input::update()
   {
      // todo: update mouse 
      keyboard_.update();
   }

   void Input::on_event(const KeyPressedEvent &event)
   {
      keyboard_.on_key_pressed(event.keycode, event.repeat);
   }

   void Input::on_event(const KeyReleasedEvent &event)
   {
      keyboard_.on_key_released(event.keycode);
   }

   const Keyboard &Input::keyboard() const
   {
      return keyboard_;
   }
} // !papaya
