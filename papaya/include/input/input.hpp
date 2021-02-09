// input.hpp

#pragma once

#include <input/keyboard.hpp>

namespace papaya {
   struct KeyPressedEvent;
   struct KeyReleasedEvent;

   class Input {
   public:
      Input();

      void update();

      void on_event(const KeyPressedEvent &event);
      void on_event(const KeyReleasedEvent &event);

      const Keyboard &keyboard() const;

   private:
      Keyboard keyboard_;
   };
} // !papaya
