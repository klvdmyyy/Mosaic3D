#pragma once

#include "System/Math/Vector.h"

#include <vector>
#include <string>

namespace System
{
	struct Vertex
	{
		System::Math::Vector3f position;
		//System::Math::Vector3f normal;
		//System::Math::Vector2f texCoord;
	};

	struct Texture
	{
		unsigned int id;
		std::string name;
	};

	class Mesh
	{
	public:
		Mesh(
			const std::vector<Vertex>& vertices,
			const std::vector<unsigned int>& indices,
			const std::vector<Texture>& textures
		);

		~Mesh();

	private:
		std::vector<Vertex> m_vertices;
		std::vector<unsigned int> m_indices;
		std::vector<Texture> m_textures;
	};
}