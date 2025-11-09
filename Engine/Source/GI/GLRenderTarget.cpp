#include "GLRenderTarget.h"

namespace GI
{
	void GLRenderTarget::Draw(IPipeline& rPipeline)
	{
		auto pipeline = reinterpret_cast<GLPipeline&>(rPipeline);
	}
}
