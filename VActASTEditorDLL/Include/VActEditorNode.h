#pragma once

#include "_VActASTEditor.h"
#include "VActEditorUI.h"

#include <cstdint>
#include <string>
#include <vector>

namespace VActExplore::ASTEditor
{
	class VACTASTEDITOR_API VActEditorNode :
		public VActEditorUI
	{
	public:
		std::vector<VActEditorNode*> Nodes;

		std::string Type;

		VActEditorNode() = default;
		
		VActEditorNode(const VActEditorNode& Other) = default;

		VActEditorNode(VActEditorNode&& Other) noexcept = default;
		
		VActEditorNode& operator=(VActEditorNode&& Other) noexcept = default;

		VActEditorNode& operator=(const VActEditorNode& Other) = default;
		
		VActEditorNode(std::string Name, std::string Type);

		virtual ~VActEditorNode() = default;
	};
}

