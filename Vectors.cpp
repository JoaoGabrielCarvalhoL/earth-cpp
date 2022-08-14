#include <iostream>
#define GLM_SWIZZLE
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

void Constructors() 
{
	std::cout << std::endl;

	glm::vec2 Point0{ 10.0f, 10.f };
	glm::vec3 Point1{ 10.0f, 0.0f,  0.0f};
	glm::vec4 Point2{ 10.0f, 10.0f, 0.0f, 0.0f};
	glm::ivec2 Point3{ 3, 4 };
	glm::bvec3 Point4{ false, true, false }; 
	glm::dvec2 Point5{ 10.0, 10.0 };
	glm::vec3 Point6{ Point0, 10.0f };
	glm::vec2 Point7{ Point2 };

	std::cout << "Point 0: " << glm::to_string(Point0) << std::endl;
	std::cout << "Point 1: " << glm::to_string(Point1) << std::endl;
	std::cout << "Point 2: " << glm::to_string(Point2) << std::endl;
	std::cout << "Point 3: " << glm::to_string(Point3) << std::endl;
	std::cout << "Point 4: " << glm::to_string(Point4) << std::endl;
	std::cout << "Point 5: " << glm::to_string(Point5) << std::endl;
	std::cout << "Point 6: " << glm::to_string(Point6) << std::endl;
	std::cout << "Point 7: " << glm::to_string(Point7) << std::endl;
}

void Components()
{
	glm::vec3 Point{ 1, 2, 3 };
	std::cout << "X: " << Point.x << " Y: " << Point.y << " Z: " << Point.z << std::endl;
	std::cout << "R: " << Point.r << " G: " << Point.g << " B: " << Point.b << std::endl;
	std::cout << "0: " << Point[0] << " 1: " << Point[1] << " 2: " << Point[2] << std::endl;
}

void Swizzle()
{
	std::cout << std::endl;
	glm::vec4 P{ 1, 2, 3, 4 };

	glm::vec3 Q = P.xxx;
	glm::vec3 R = P.xyx;
	glm::vec4 T = P.xyzw;
	glm::vec4 Y = P.xzzw;

	std::cout << "Y: " << glm::to_string(Y) << std::endl;
}

void Operations()
{
	std::cout << std::endl;
	glm::vec3 P0{ 10.f, 10.0f, 0.0f }; 
	glm::vec3 P1{ 10.0, 10.0f, 10.0f };

	//Soma 
	glm::vec3 Result;

	Result = P0 + P1;

	std::cout << "P0: " << glm::to_string(P0) << std::endl;
	std::cout << "P1: " << glm::to_string(P1) << std::endl;

	std::cout << "P0 + P1: " << glm::to_string(Result) << std::endl;

	//Subtração 
	Result = P0 - P1;
	std::cout << "P0 - P1: " << glm::to_string(Result) << std::endl;

	//Scala 
	Result = P0 * 5.f;
	std::cout << "P0 x 5.f: " << glm::to_string(Result) << std::endl;

	//Multiplicação 
	Result = P0 * P1; 
	std::cout << "P0 * P1: " << glm::to_string(Result) << std::endl;

	//Divisão 
	Result = P0 / P1; 
	std::cout << "P0 / P1: " << glm::to_string(Result) << std::endl;

	//Comprimento do vetor 
	//Raiz 2 de (Elemento ao quadrado + Elemento ao quadrado...)
	float L = glm::length(P0);
	std::cout << "Length P0: " << L << std::endl;

	//Normalizar um vetor 
	glm::vec3 Norm = glm::normalize(P0);

	//Produto Escalar (Dot Product) 
	float Dot = glm::dot(P0, P1);

	//Produto Vetorial
	glm::vec3 Cross = glm::cross(P0, P1);

	//Distancia 
	float Distance = glm::distance(P0, P1); 

	//Reflexão 
	glm::vec3 Reflect = glm::reflect(P0, Norm);

	//Refração 
	glm::vec3 Refract = glm::refract(P0, Norm, 1.0f); 
}

//Procurar representação geométrica das operações com vetores.

int main() {
	std::cout << "Hello" << std::endl;

	Constructors();
	Components();
	Swizzle();
	Operations();
	return 0;
}