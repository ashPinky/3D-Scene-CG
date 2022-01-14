#include "input/InputManager.hpp"
using namespace re;

const BYTE* InputManager::keyboard_state;
BYTE* InputManager::prev_keyboard_state;

const BYTE* InputManager::mouse_state;
BYTE* InputManager::prev_mouse_state;
        
SI32* InputManager::mouse_pos_x;
SI32* InputManager::mouse_pos_y;
SI32* InputManager::mouse_scroll_x;
SI32* InputManager::mouse_scroll_y;

SI32 InputManager::prev_mouse_pos_x;
SI32 InputManager::prev_mouse_pos_y;

void InputManager::OnStart()
{
    keyboard_state = KeyListener::GetInstanceRef().GetKeyboardStates();
    prev_keyboard_state = new BYTE[512];

    mouse_state = MouseListener::GetInstanceRef().GetMouseState(
        mouse_pos_x, 
        mouse_pos_y,
        mouse_scroll_x,
        mouse_scroll_y
    );
    prev_mouse_state = new BYTE[8];
}
void InputManager::OnFrameEnd()
{
    memcpy(prev_keyboard_state, keyboard_state, 512);
    memcpy(prev_mouse_state, mouse_state, 8);

    prev_mouse_pos_x = *mouse_pos_x;
    prev_mouse_pos_y = *mouse_pos_y;

    *mouse_scroll_x = 0;
    *mouse_scroll_y = 0;
}

bool InputManager::GetKey(KeyCode code)
{
    return keyboard_state[(int)code];
}
bool InputManager::GetKeyDown(KeyCode code)
{
    return !prev_keyboard_state[(int)code] && keyboard_state[(int)code];
}
bool InputManager::GetKeyUp(KeyCode code)
{
    return prev_keyboard_state[(int)code] && !keyboard_state[(int)code];
}
bool InputManager::GetMouseButton(MouseCode button)
{
    return mouse_state[(int)button];
}
bool InputManager::GetMouseButtonDown(MouseCode button)
{
    return !prev_mouse_state[(int)button] && mouse_state[(int)button];
}
bool InputManager::GetMouseButtonUp(MouseCode button)
{
    return prev_mouse_state[(int)button] && !mouse_state[(int)button];
}
void InputManager::GetMousePosition(SI32& x, SI32& y)
{
    x = *mouse_pos_x;
    y = *mouse_pos_y;
}
void InputManager::GetMouseScrollDelta(SI32& x, SI32& y)
{
    x = *mouse_scroll_x;
    y = *mouse_scroll_y;
}