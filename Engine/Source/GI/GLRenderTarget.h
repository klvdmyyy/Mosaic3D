#pragma once

#include "GI/IRenderTarget.h"
#include "GLPipeline.h"

namespace GI
{
	class GLRenderTarget : public IRenderTarget
	{
	public:
		void Draw(IPipeline& rPipeline) override;
	};
}