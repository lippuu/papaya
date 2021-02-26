// sprite.cc

#include "scene/sprite.hpp"

namespace papaya {
   Sprite::Sprite()
      : color_(1.0f, 1.0f, 1.0f, 1.0f)
      , texture_(nullptr)
   {
   }

   Sprite::Sprite(const Vector2 &size, const Vector4 &texcoords)
      : color_(1.0f, 1.0f, 1.0f, 1.0f)
      , size_(size)
      , texcoords_(texcoords)
      , texture_(nullptr)
   {
   }

   Sprite::Sprite(const Vector2 &size, const Vector4 &texcoords, const Texture *texture)
      : color_(1.0f, 1.0f, 1.0f, 1.0f)
      , size_(size)
      , texcoords_(texcoords)
      , texture_(texture)
   {
   }

   bool Sprite::is_valid() const
   {
      return size_.x_ > 0.0f && size_.y_ > 0.0f;
   }

   bool Sprite::has_texture() const
   {
      return texture_ != nullptr;
   }

   void Sprite::set_color(const Color &color)
   {
      color_ = color;
   }

   void Sprite::set_size(const Vector2 &size)
   {
      size_ = size;
   }

   void Sprite::set_texcoord(const Vector4 &texcoord)
   {
      texcoords_ = texcoord;
   }

   void Sprite::set_texture(const Texture *texture)
   {
      texture_ = texture;

      if (texcoords_.x_ <= 0.0f && texcoords_.y_ <= 0.0f && texcoords_.z_ <= 0.0f && texcoords_.w_ <= 0.0f) {
         texcoords_ = { 0.0f, 0.0f, 1.0f, 1.0f };
      }
   }

   const Color &Sprite::get_color() const
   {
      return color_;
   }

   const Vector2 &Sprite::get_size() const
   {
      return size_;
   }

   const Vector4 &Sprite::get_texcoords() const
   {
      return texcoords_;
   }

   const Texture *Sprite::get_texture() const
   {
      return texture_;
   }
} // !papaya
