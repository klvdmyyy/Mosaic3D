#pragma once

#include "GI/IPipeline.h"

namespace GI
{
	class IRenderTarget
	{
	public:
		virtual void Draw(IPipeline& rPipeline) = 0;
	};
}