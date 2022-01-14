#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <string.h>

#include "../common/Alias.hpp"

#include "KeyCodes.hpp"
#include "MouseCodes.hpp"
#include "KeyListener.hpp"
#include "MouseListener.hpp"

namespace re
{
    class InputManager
    {
    private:
        static const BYTE* keyboard_state;
        static BYTE* prev_keyboard_state;

    private:
        static const BYTE* mouse_state;
        static BYTE* prev_mouse_state;
        
    private:
        static SI32* mouse_pos_x;
        static SI32* mouse_pos_y;
        static SI32* mouse_scroll_x;
        static SI32* mouse_scroll_y;

    private:
        static SI32 prev_mouse_pos_x;
        static SI32 prev_mouse_pos_y;

    public:
        InputManager() = delete;
       ~InputManager() = delete;

    public:
        static void OnStart();
        static void OnFrameEnd();

    public:
        static bool GetKey(KeyCode code);
        static bool GetKeyDown(KeyCode code);
        static bool GetKeyUp(KeyCode code);
        static bool GetMouseButton(MouseCode button);
        static bool GetMouseButtonDown(MouseCode button);
        static bool GetMouseButtonUp(MouseCode button);
        static void GetMousePosition(SI32& x, SI32& y);
        static void GetMouseScrollDelta(SI32& x, SI32& y);
    };
}

#endif