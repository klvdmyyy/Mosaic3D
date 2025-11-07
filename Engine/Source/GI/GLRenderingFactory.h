#include "GI/IRenderingFactory.h"
#include "GLMeshRenderer.h"
#include "GLSpriteRenderer.h"

namespace GI
{
	class GLRenderingFactory : public IRenderingFactory
	{
	private:
		// `GLSpriteRenderer` is used for all 2D stuff.
		GLSpriteRenderer m_spriteRenderer;

		// Otherwise `GLMeshRenderer` is used for all 3D stuff.
		GLMeshRenderer m_meshRenderer;

	public:
		GLRenderingFactory();
		~GLRenderingFactory();

		IMeshRenderer* GetMeshRenderer() override { return &m_meshRenderer;  }
		ISpriteRenderer* GetSpriteRenderer() override { return &m_spriteRenderer; }
	};
}