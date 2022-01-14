#include "graphics/camera/Camera.hpp"

namespace re
{
    Camera::Camera()
        : m_position(FVec3(0.0f)), m_direction(FVec3::FRONT), m_view(FMat4()), m_proj(FMat4()) {}
    Camera::Camera(FVec3 position)
        : m_position(position), m_direction(FVec3::FRONT), m_view(FMat4()), m_proj(FMat4()) {}

    FMat4 Camera::GetViewMatrix()
    {
        return m_view;
    }
    FMat4 Camera::GetProjMatrix()
    {   
        return m_proj;
    }
    CameraType Camera::GetCameraType()
    {
        return m_type;
    }
}