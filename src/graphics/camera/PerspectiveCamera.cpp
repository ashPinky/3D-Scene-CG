#include "graphics/camera/PerspectiveCamera.hpp"

namespace re
{
    PerspectiveCamera::PerspectiveCamera(F32 fov, F32 aspect) : Camera()
    {
        m_type = CameraType::PERSPECTIVE;

        m_fov = fov;
        m_aspect = aspect;
        m_near = 0.1f; m_far = 100.0f; 
    }
    PerspectiveCamera::PerspectiveCamera(FVec3 position, F32 fov, F32 aspect) : Camera(position)
    {
        m_type = CameraType::PERSPECTIVE;

        m_fov = fov;
        m_aspect = aspect;
        m_near = 0.1f; m_far = 100.0f;
    }
    PerspectiveCamera::PerspectiveCamera(FVec3 position, F32 fov, F32 aspect, F32 near, F32 far) : Camera(position)
    {
        m_type = CameraType::PERSPECTIVE;

        m_fov = fov;
        m_aspect = aspect;
        m_near = near; m_far = far;
    }

    void PerspectiveCamera::OnUpdate()
    {
        m_view = LookAt(m_position, m_position + m_direction, FVec3::UP);
        m_proj = Perspective(ToRadians(m_fov), m_aspect, m_near, m_far);
    }
}