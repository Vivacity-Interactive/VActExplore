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

		VActEditorGroup() = default;
		
		VActEditorGroup(const VActEditorGroup& Other) = default;
		
		VActEditorGroup(VActEditorGroup&& Other) noexcept = default;
		
		VActEditorGroup& operator=(const VActEditorGroup& Other) = default;
		
		VActEditorGroup& operator=(VActEditorGroup&& Other) noexcept = default;

		virtual ~VActEditorGroup() = default;
	};
}


