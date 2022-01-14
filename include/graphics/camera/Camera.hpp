#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../../common/Alias.hpp"

#include "../../core/math/Vector.hpp"
#include "../../core/math/Matrix.hpp"
#include "../../core/math/Transformations.hpp"

namespace re
{
    enum class CameraType
    {
        PERSPECTIVE,
        ORTHOGRAPHIC
    };

    class Camera
    {
    public:
        FVec3 m_position;
        FVec3 m_direction;

    protected:
        CameraType m_type;

    protected:
        FMat4 m_view;
        FMat4 m_proj;

    public:
        Camera();
        Camera(FVec3 position);

    public:
        FMat4 GetViewMatrix();
        FMat4 GetProjMatrix();
        CameraType GetCameraType();

    public:
        virtual void OnUpdate() = 0;
    };
}

#endif