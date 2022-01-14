#ifndef FLY_CAMERA_HPP
#define FLY_CAMERA_HPP

#include "../../common/Alias.hpp"

#include "../../core/math/Math.hpp"
#include "../../core/math/Vector.hpp"
#include "../../core/Time.hpp"

#include "input/KeyCodes.hpp"
#include "input/MouseCodes.hpp"

#include "CameraController.hpp"

namespace re
{
    class FlyCamera : public CameraController
    {
    private:
        F32 m_target_yaw;
        F32 m_target_pitch;
        FVec3 m_target_position;

    public:
        FlyCamera(Camera* camera);
        FlyCamera(Camera* camera, 
            F32 zoom_speed, F32 movement_speed, F32 rotation_speed);

    private:
        void OnKeyPress() override;
        void OnMouseMove() override;
        void OnMouseScroll() override;

    public:
        void OnUpdate() override;
    };
}

#endif