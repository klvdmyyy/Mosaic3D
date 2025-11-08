#include "System/Mesh.h"

namespace System
{
	Mesh::Mesh(
		const std::vector<Vertex>& vertices,
		const std::vector<unsigned int>& indices,
		const std::vector<Texture>& textures
	) : m_vertices(vertices), m_indices(indices), m_textures(textures)
	{
	}

	Mesh::~Mesh()
	{
	}
}