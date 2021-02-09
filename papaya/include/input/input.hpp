// input.hpp

#pragma once

namespace papaya {
   struct KeyPressedEvent;
   struct KeyReleasedEvent;

   class Input {
   public:
      Input();

      void update();

      void on_event(const KeyPressedEvent &event);
      void on_event(const KeyReleasedEvent &event);
   };
} // !papaya
