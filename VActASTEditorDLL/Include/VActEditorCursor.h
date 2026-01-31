#pragma once

#include "_VActASTEditor.h"
#include "VActEditorUI.h"
#include "VActEditorNode.h"

namespace VActExplore::ASTEditor
{
	class VACTASTEDITOR_API VActEditorCursor :
		public VActEditorUI
	{
	public:
		std::vector<VActEditorNode*> Selected;

		VActEditorNode* Active;

		VActEditorCursor() = default;

		VActEditorCursor(const VActEditorCursor& Other) = default;

		VActEditorCursor(VActEditorCursor&& Other) noexcept = default;

		VActEditorCursor& operator=(VActEditorCursor&& Other) noexcept = default;

		VActEditorCursor& operator=(const VActEditorCursor& Other) = default;

		virtual ~VActEditorCursor() = default;
	};
}


