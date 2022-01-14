#include "graphics/camera/FlyCamera.hpp"

namespace re
{
    FlyCamera::FlyCamera(Camera* camera) : CameraController(camera)
    {
        m_target_yaw = 0.0f;
        m_target_pitch = 0.0f;
        m_target_position = camera->m_position;
    }
    FlyCamera::FlyCamera(Camera* camera, 
        F32 zoom_speed, F32 movement_speed, F32 rotation_speed) : CameraController(camera, zoom_speed, movement_speed, rotation_speed)
    {
        m_target_yaw = 0.0f;
        m_target_pitch = 0.0f;
        m_target_position = camera->m_position;
    }

    void FlyCamera::OnKeyPress()
    {
        F32 speed = m_movement_speed * Time::GetDeltaTime();

        if(InputManager::GetKey(KeyCode::KEY_D))
            m_target_position = m_target_position + FVec3::RIGHT * speed;
        if(InputManager::GetKey(KeyCode::KEY_A))
            m_target_position = m_target_position + FVec3::LEFT * speed;
        if(InputManager::GetKey(KeyCode::KEY_W))
            m_target_position = m_target_position + FVec3::UP * speed;
        if(InputManager::GetKey(KeyCode::KEY_S))
            m_target_position = m_target_position + FVec3::DOWN * speed;
        if(InputManager::GetKey(KeyCode::KEY_UP))
            m_target_position = m_target_position + FVec3::FRONT * speed;
        if(InputManager::GetKey(KeyCode::KEY_DOWN))
            m_target_position = m_target_position + FVec3::BACK * speed;
    }
    void FlyCamera::OnMouseMove()
    {

    }
    void FlyCamera::OnMouseScroll()
    {

    }

    void FlyCamera::OnUpdate()
    {
        OnKeyPress();
        OnMouseMove();
        OnMouseScroll();

        FVec3& cam_pos = m_controlled_camera->m_position;
        FVec3& cam_dir = m_controlled_camera->m_direction;

        F32 damping = m_dampening_factor * Time::GetDeltaTime();

        // m_yaw = Lerp(m_yaw, m_target_yaw, damping);
        // m_pitch = Lerp(m_pitch, m_target_pitch, damping);
        cam_pos = Lerp(cam_pos, m_target_position, damping);

        //cam_dir.x = Cos(ToRadians(m_pitch)) * Cos(ToRadians(m_yaw));
        //cam_dir.y = Sin(ToRadians(m_pitch));
        //cam_dir.z = Cos(ToRadians(m_pitch)) * Sin(ToRadians(m_yaw));

        //cam_dir = Normalize(cam_dir);

        m_controlled_camera->OnUpdate();
    }
}