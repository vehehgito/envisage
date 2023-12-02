#version 430 core

void main()
{
    vec2 vertices[6] = 
    {
        //Top left
        vec2(-0.5,0.5),

        //Bottom left
        vec2(-0.5,-0.5),

        //Top right
        vec2(0.5,0.5),

        //Top right
        vec2(0.5,0.5),

        //Bottom left
        vec2(-0.5,-0.5),

        //Bottom right
        vec2(0.5,-0.5)
    };

    gl_Position = vec4(vertices[gl_VertexID], 1.0, 1.0);
}