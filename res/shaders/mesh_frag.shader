#version 330 core

uniform sampler2D sampler;

in vec2 f_tex;
in vec3 f_norm;

out vec4 color;

void main()
{
    vec4 texel = texture(sampler, f_tex);

    if(texel.w < 0.1)
        discard;

    color = texel;
}