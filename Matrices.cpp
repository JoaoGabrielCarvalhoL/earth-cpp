#include <iostream>
#include <iomanip>

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>


void PrintMatrix(const glm::mat4& M)
{
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << std::setw(10) << std::setprecision(4) << std::fixed << M[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void PrintMatrixTranslation(const glm::mat4& M)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << std::setw(10) << std::setprecision(4) << std::fixed << M[j][i] << " ";
		}
		std::cout << std::endl;
	}
}

void TranslationMatrix()
{
	std::cout << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "\tTranslation Matrix" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	/*
	glm::mat4 M = glm::identity<glm::mat4>();

	PrintMatrix(M);
	*/

	glm::mat4 I = glm::identity<glm::mat4>();
	glm::vec3 T{ 10, 10, 10 };

	glm::mat4 Translation = glm::translate(I, T);

	PrintMatrixTranslation(Translation); 

	glm::vec4 Position{ 10, 10, 10, 1 };
	glm::vec4 Direction{ 10, 10, 10, 0 };

	std::cout << std::endl;
	/*
	0	0 | px
	0	0 |	py
	0	0 | pz
	*/
	//É utilizado o operador de multiplicação para aplicar uma matriz. Ao lado esquerdo é a matriz simples e por fim o elemento que deseja aplicar no lado direito. 
	Position = Translation * Position;

	std::cout << glm::to_string(Position) << std::endl;
}

void ScaleMatrix()
{
	std::cout << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "\tScale Matrix" << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	glm::mat4 Identity = glm::identity<glm::mat4>();
	glm::vec3 ScaleAmount{ 2, 2, 2 };
	glm::mat4 Scale = glm::scale(Identity, ScaleAmount);

	PrintMatrixTranslation(Scale);

	glm::vec4 Position{ 100, 100, 0, 1 };
	glm::vec4 Direction{ 100, 100, 0, 0 };

	std::cout << std::endl;

	Position = Scale * Position;
	Direction = Scale * Direction;

	std::cout << glm::to_string(Position) << std::endl;
	std::cout << glm::to_string(Direction) << std::endl;
}

void RotationMatrix() 
{
	std::cout << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "\tRotation Matrix" << std::endl;
	std::cout << "--------------------------------------" << std::endl;


	glm::mat4 Identity = glm::identity<glm::mat4>();
	constexpr float Angle = glm::radians(90.0f);
	glm::vec3 Axis{ 0, 0, 1 };

	glm::mat4 Rotation = glm::rotate(Identity, Angle, Axis);

	PrintMatrixTranslation(Rotation);

	glm::vec4 Position{ 100, 0, 0, 1 }; 
	glm::vec4 Direction{ 100, 0, 0, 0 };

	Position = Rotation * Position;
	Direction = Rotation * Direction;

	std::cout << std::endl;
	std::cout << glm::to_string(Position) << std::endl;
	std::cout << glm::to_string(Direction) << std::endl;
}

void ComposedMatrices()
{
	std::cout << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "\tComposed Matrix" << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	glm::mat4 I = glm::identity<glm::mat4>();

	glm::vec3 T{ 0, 10, 0 }; 

	glm::mat4 Translation = glm::translate(I, T);

	constexpr float Angle = glm::radians(45.f);
	glm::vec3 Axis{ 0, 0, 1 }; 
	glm::mat4 Rotation = glm::rotate(I, Angle, Axis);

	glm::vec3 ScaleAmount{ 2, 2, 0 };
	glm::mat4 Scale = glm::scale(I, ScaleAmount);

	std::cout << "Translation" << std::endl;
	PrintMatrixTranslation(Translation);
	std::cout << std::endl;

	std::cout << "Rotation" << std::endl;
	PrintMatrixTranslation(Rotation);
	std::cout << std::endl;

	std::cout << "Scale" << std::endl;
	PrintMatrixTranslation(Scale);
	std::cout << std::endl;

	glm::vec4 Position{ 1, 1, 0, 1 }; 
	glm::vec4 Direction{ 1, 1, 0, 0 }; 

	glm::mat4 ModelMatrix = Translation * Rotation * Scale; //Não é comutativo.

	Position = ModelMatrix * Position; 

	std::cout << "Model Matrix" << std::endl; 
	PrintMatrixTranslation(ModelMatrix);
	std::cout << std::endl;

	Position = ModelMatrix * Position; 
	Direction = ModelMatrix * Direction; 
	
	std::cout << glm::to_string(Position) << std::endl; 
	std::cout << glm::to_string(Direction) << std::endl;

	Position = Scale * Position; 
	Position = Rotation * Position; 
	Position = Translation * Position;
}

void ModelViewProject()
{
	std::cout << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "\tModelViewProject Matrix" << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	//Model vai ser a matriz formada pelas transformações de translação, rotação e escala, sendo uma matriz composta.
	glm::mat4 ModelMatrix = glm::identity<glm::mat4>();

	//View 
	glm::vec3 Eye{0, 0, 10};
	glm::vec3 Center{0, 0, 0};
	glm::vec3 Up{0, 1, 0};

	glm::mat4 ViewMatrix = glm::lookAt(Eye, Center, Up); 
	std::cout << "		View" << std::endl; 
	std::cout << std::endl;

	PrintMatrixTranslation(ViewMatrix);

	constexpr float FoV = glm::radians(45.0f);
	const float AspectRatio = 800.0f / 600.0f;
	const float Near = 1.0f;
	const float Far = 100000.0f; 

	std::cout << std::endl;
	glm::mat4 ProjectionMatrix = glm::perspective(FoV, AspectRatio, Near, Far);
	std::cout << "		ProjectionMatrix" << std::endl;
	std::cout << std::endl;
	PrintMatrixTranslation(ProjectionMatrix);

	glm::mat4 ModelViewProjection = ProjectionMatrix * ViewMatrix * ModelMatrix;

	std::cout << std::endl;
	std::cout << "		ModelViewProjection" << std::endl;
	std::cout << std::endl;
	PrintMatrixTranslation(ModelViewProjection);
	std::cout << std::endl;

	glm::vec4 Position{ 0, 0, 0, 1 };
	Position = ModelViewProjection * Position;
	Position = Position / Position.w;

	std::cout << glm::to_string(Position) << std::endl;
}

int main() 
{
	TranslationMatrix();
	ScaleMatrix();
	RotationMatrix();
	ComposedMatrices();
	ModelViewProject();
	return 0;
}