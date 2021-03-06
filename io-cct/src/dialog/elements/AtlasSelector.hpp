/**
 * Created by universal on 02.05.2018.
 * This file is part of reloded which is licensed
 * under the MOZILLA PUBLIC LICENSE 2.0 - mozilla.org/en-US/MPL/2.0/
 * github.com/univrsal/input-overlay
 */

#pragma once

#include "../../util/CoordinateSystem.hpp"
#include "../../util/SDL_Helper.hpp"
#include "../../util/Texture.hpp"
#include <SDL.h>
#include "GuiElement.hpp"
#include "../Dialog.hpp"

class SDL_Helper;

class CoordinateSystem;

class Texture;

class AtlasSelector : public GuiElement
{
public:
    AtlasSelector(int8_t id, int x, int y, int w, int h, Texture* t, Dialog* parent);

    ~AtlasSelector();

    void close() override;

    void init(Dialog* parent, SDL_Rect dim, int8_t id) override;

    void draw_foreground() override;

    void draw_background() override;

    bool handle_events(SDL_Event* event, bool was_handled) override;

    bool selection_changing() const { return m_cs->changing_selection(); }

    uint8_t get_cursor() override;

    void set_selection(SDL_Rect* r) const { m_cs->set_selection(r); }
private:
    void resize() override;

    Texture* m_atlas; /* Is loaded in Config, and will be deleted there */
    CoordinateSystem* m_cs{};
};
