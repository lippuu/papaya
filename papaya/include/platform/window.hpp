// window.hpp

#pragma once

namespace papaya {
   class Window {
   public:
      Window(const char *title,
             const int width,
             const int height);
      ~Window();

      void present();

      // note: temporary method, will be moved eventually
      bool process();

   private:
      void *window_;
      void *context_;
   };
} // !papaya
