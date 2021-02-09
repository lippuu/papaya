// events.hpp

#pragma once

namespace papaya {
   enum class Key;
   enum class Button;

   struct WindowClosingEvent {
   };

   struct KeyPressedEvent {
      Key keycode{};
      bool repeat{};
   };

   struct KeyReleasedEvent {
      Key keycode{};
   };
} // !papaya
