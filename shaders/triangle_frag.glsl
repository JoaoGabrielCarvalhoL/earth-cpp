#version 330 core

uniform sampler2D TextureSampler;
uniform sampler2D CloudsTexture;

uniform float Time;

uniform vec2 CloudsRotationSpeed = vec2(0.008, 0.008);

in vec3 Normal;
in vec3 Color; 
in vec2 UV;

uniform vec3 LightDirection; 
uniform float LightIntensity;

out vec4 OutColor;

void main() 
{
	
	vec3 N = normalize(Normal);

	vec3 L = -normalize(LightDirection);

	float Lambertian = max(dot(N, L), 0.0);

	vec3 ViewDirection = vec3(0.0, 0.0, -1.0);
	vec3 V = -ViewDirection;

	vec3 R = reflect(-L, N); 

	float Alpha = 50.0;

	float Specular = pow(dot(R,V), Alpha);
	Specular = max(Specular, 0.0);

	vec3 EarthColor = texture(TextureSampler, UV).rgb;

	vec3 CloudColor = texture(CloudsTexture, UV + Time * CloudsRotationSpeed).rgb;

	vec3 FinalColor = (EarthColor + CloudColor) * LightIntensity * Lambertian + Specular;

	OutColor = vec4(FinalColor, 1.0);
}

