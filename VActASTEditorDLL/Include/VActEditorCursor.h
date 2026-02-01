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

		_VACTASTEDITOR_DEFAULT_BODY(VActEditorCursor);

		VActEditorCursor();

		virtual ~VActEditorCursor() = default;
	};
}


