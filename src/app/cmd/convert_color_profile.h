// Aseprite
// Copyright (C) 2018  Igara Studio S.A.
//
// This program is distributed under the terms of
// the End-User License Agreement for Aseprite.

#ifndef APP_CMD_CONVERT_COLOR_PROFILE_H_INCLUDED
#define APP_CMD_CONVERT_COLOR_PROFILE_H_INCLUDED
#pragma once

#include "app/cmd.h"
#include "app/cmd/with_sprite.h"
#include "app/cmd_sequence.h"
#include "gfx/color_space.h"

namespace gfx {
  class ColorSpace;
}

namespace app {
namespace cmd {

  class ConvertColorProfile : public Cmd,
                              public WithSprite {
  public:
    ConvertColorProfile(doc::Sprite* sprite, const gfx::ColorSpacePtr& newCS);

  protected:
    void onExecute() override;
    void onUndo() override;
    void onRedo() override;
    size_t onMemSize() const override {
      return sizeof(*this) + m_seq.memSize();
    }

  private:
    CmdSequence m_seq;
  };

} // namespace cmd
} // namespace app

#endif
