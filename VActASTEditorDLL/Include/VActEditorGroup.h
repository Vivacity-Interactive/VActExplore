#pragma once

#include "_VActASTEditor.h"
#include "VActEditorUI.h"
#include "VActEditorNode.h"

#include <vector>

namespace VActExplore::ASTEditor
{
	class VACTASTEDITOR_API VActEditorGroup :
		public VActEditorUI
	{
	public:
		std::vector<VActEditorNode*> Nodes;

		_VACTASTEDITOR_DEFAULT_BODY(VActEditorGroup);

		VActEditorGroup();

		virtual ~VActEditorGroup() = default;
	};
}


