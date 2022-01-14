#ifndef SANDBOX_HPP
#define SANDBOX_HPP

#include <RenderEngine.hpp>
#include "graphics/camera/FlyCamera.hpp"
#include "graphics/platform/opengl/GLShader.hpp"
using namespace re;

class Sandbox : public Application
{
public:
    Sandbox(const ApplicationProps& props) : 
        Application(props) {}

public:
    UI32 shader_ptr;

public:
    PerspectiveCamera* cam;
    FlyCamera* cam_controller;

public:
    Mesh* sphere;

public:
    Texture* sun_texture;
    Texture* earth_texture;
    Texture* pluto_texture;
    Texture* mars_texture;

public:
    FMat4 model_matrix;

public:
    void OnStart() override
    {   
        shader_ptr = GLShader::GenerateShader("res\\shaders\\mesh_vert.shader", "res\\shaders\\mesh_frag.shader");

        cam = new PerspectiveCamera({0.0f, 0.0f, 0.0f}, 60.0f, 800.0f / 600.0f);
        cam_controller = new FlyCamera(cam, 200.0f, 200.0f, 200.0f);
        cam_controller->m_dampening_factor = 15.0f;

        std::vector<UI32> tris;
        std::vector<FVec3> pos;
        std::vector<FVec2> uvs;
        std::vector<FVec3> norms;

        MeshLoader::LoadFile("res\\models\\planet.obj", pos, norms, uvs, tris);
        sphere = new Mesh(pos, norms, uvs, tris);
        sphere->Finalize();

        sun_texture = new Texture("res\\textures\\sun.jpg");
        earth_texture = new Texture("res\\textures\\earth.jpg");
        pluto_texture = new Texture("res\\textures\\pluto.jpg");
        mars_texture = new Texture("res\\textures\\mars.jpg");
    }

    void OnEvent(Event* event) override
    {
        switch(event->GetEventType())
        {
            case EventType::WINDOW_CLOSED  : OnWindowClose((WindowClosedEvent*)event); break;
            case EventType::WINDOW_RESIZED : OnWindowResize((WindowResizedEvent*)event); break;
        }
    }

    void OnUpdate() override
    {
        static F32 pluto_rot_angle = 0.0f;
        static F32 earth_rot_angle = 0.0f;
        static F32 mars_rot_angle = 0.0f;

        cam_controller->OnUpdate();

        GLShader::ActivateShader(shader_ptr);
        GLShader::SetMat4f(shader_ptr, "u_view", cam->GetViewMatrix());
        GLShader::SetMat4f(shader_ptr, "u_proj", cam->GetProjMatrix());

        model_matrix = FMat4(1.0f);
        model_matrix = Scale(FVec3(2.0f, 2.0f, 2.0f));
        GLTexture::ActivateTexture(sun_texture->GetNativePtr());
        GLShader::SetMat4f(shader_ptr, "u_model", model_matrix);
        RendererCommand::DrawArrays(sphere->m_topology, sphere->GetVertexArrayPtr(), sphere->GetVertexCount());

        model_matrix = FMat4(1.0f);
        FMat4 T = Translate(FVec3(10.0f, 0.0f, 0.0f));
        FMat4 R = Rotate(pluto_rot_angle += 0.005f, FVec3(0.0f, 1.0f, 0.0f));
        FMat4 S = Scale(FVec3(0.5f, 0.5f, 0.5f));

        model_matrix = S * R * T;

        GLTexture::ActivateTexture(pluto_texture->GetNativePtr());
        GLShader::SetMat4f(shader_ptr, "u_model", model_matrix);
        RendererCommand::DrawArrays(sphere->m_topology, sphere->GetVertexArrayPtr(), sphere->GetVertexCount());

        model_matrix = FMat4(1.0f);
        T = Translate(FVec3(20.0f, 0.0f, 0.0f));
        R = Rotate(earth_rot_angle += 0.004f, FVec3(0.0f, 1.0f, 0.0f));

        model_matrix = R * T;

        GLTexture::ActivateTexture(earth_texture->GetNativePtr());
        GLShader::SetMat4f(shader_ptr, "u_model", model_matrix);
        RendererCommand::DrawArrays(sphere->m_topology, sphere->GetVertexArrayPtr(), sphere->GetVertexCount());

        model_matrix = FMat4(1.0f);
        T = Translate(FVec3(30.0f, 0.0f, 0.0f));
        R = Rotate(mars_rot_angle += 0.002f, FVec3(0.0f, 1.0f, 0.0f));
        S = Scale(FVec3(1.5f, 1.5f, 1.5f));

        model_matrix = S * R * T;

        GLTexture::ActivateTexture(mars_texture->GetNativePtr());
        GLShader::SetMat4f(shader_ptr, "u_model", model_matrix);
        RendererCommand::DrawArrays(sphere->m_topology, sphere->GetVertexArrayPtr(), sphere->GetVertexCount());
    }
    
    void OnShutDown() override
    {

    }
};

#endif