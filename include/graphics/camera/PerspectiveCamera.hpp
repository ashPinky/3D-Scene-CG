#ifndef PERSPECTIVE_CAMERA_HPP
#define PERSPECTIVE_CAMERA_HPP

#include "Camera.hpp"

namespace re
{
    class PerspectiveCamera : public Camera
    {
    public:
        F32 m_fov;
        F32 m_aspect;
        F32 m_near, m_far;

    public:
        PerspectiveCamera(F32 fov, F32 aspect);
        PerspectiveCamera(FVec3 position, F32 fov, F32 aspect);
        PerspectiveCamera(FVec3 position, F32 fov, F32 aspect, F32 near, F32 far);

    public:
        void OnUpdate() override;
    };
}

#endif