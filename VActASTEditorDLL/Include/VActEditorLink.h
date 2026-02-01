#pragma once

#include "_VActASTEditor.h"
#include "VActEditorUI.h"
#include "VActEditorNode.h"

namespace VActExplore::ASTEditor
{
	class VACTASTEDITOR_API VActEditorLink :
		public VActEditorUI
	{
	public:
		VActEditorNode* From;

		VActEditorNode* To;

		_VACTASTEDITOR_DEFAULT_BODY(VActEditorLink);

		VActEditorLink();

		virtual ~VActEditorLink() = default;
	};
}

