#ifndef CAMERA_CONTROLLER_HPP
#define CAMERA_CONTROLLER_HPP

#include "../../common/Alias.hpp"

#include "../../input/InputManager.hpp"

#include "Camera.hpp"

namespace re
{
    class CameraController
    {
    protected:
        Camera* m_controlled_camera;

    protected:
        F32 m_zoom;

    public:
        F32 m_zoom_speed;
        F32 m_movement_speed;
        F32 m_rotation_speed;
        F32 m_mouse_sensitivty;
        F32 m_dampening_factor;

    public:
        CameraController(Camera* camera);
        CameraController(Camera* camera, 
            F32 zoom_speed, F32 movement_speed, F32 rotation_speed);

    protected:
        virtual void OnKeyPress() = 0;
        virtual void OnMouseMove() = 0;
        virtual void OnMouseScroll() = 0;

    public:
        virtual void OnUpdate() = 0;
    };
}

#endif