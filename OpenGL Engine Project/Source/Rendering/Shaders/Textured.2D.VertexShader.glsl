#version 330 core

in vec2 vertexPosition;
in vec2 vertexTextureCoordinate;
in vec3 vertexNormal;

out vec2 interpolatedTextureCoordinate;
out vec3 normal;
out vec3 fragmentPosition;

uniform mat4 translation;
uniform mat4 rotation;
uniform mat4 scale;

uniform mat4 camera;
uniform mat4 projection;

void main()
{
    mat4 _model = translation * rotation * scale;
    vec4 _vertexPositionTransformed = projection * camera * _model * vec4(vertexPosition.xy, 0.0, 1.0);

    gl_Position = _vertexPositionTransformed;
    interpolatedTextureCoordinate = vertexTextureCoordinate;
    normal = (_model * vec4(vertexNormal, 1.0)).xyz;
    fragmentPosition = (_model * vec4(vertexPosition.xy, 0.0, 1.0)).xyz;
}