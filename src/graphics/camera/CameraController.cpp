#include "graphics/camera/CameraController.hpp"

namespace re
{
    CameraController::CameraController(Camera* camera)
        : m_controlled_camera(camera) 
    {
        m_zoom = 1.0f;

        m_zoom_speed = 200.0f;
        m_movement_speed = 200.0f;
        m_rotation_speed = 200.0f;

        m_mouse_sensitivty = 0.05f;
        m_dampening_factor = 0.9f;
    }
    CameraController::CameraController(Camera* camera, 
        F32 zoom_speed, F32 movement_speed, F32 rotation_speed)
        : m_controlled_camera(camera)
    {
        m_zoom = 1.0f;

        m_zoom_speed = zoom_speed;
        m_movement_speed = movement_speed;
        m_rotation_speed = rotation_speed;

        m_mouse_sensitivty = 0.9f;
        m_dampening_factor = 10.0f;
    }
}