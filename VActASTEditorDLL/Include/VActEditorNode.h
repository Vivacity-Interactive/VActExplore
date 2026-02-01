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

		string_t Type;

		_VACTASTEDITOR_DEFAULT_BODY(VActEditorNode);

		VActEditorNode();
		
		VActEditorNode(const string_t Name, const string_t Type);

		~VActEditorNode();
	};
}

