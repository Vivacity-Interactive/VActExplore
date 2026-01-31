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

		VActEditorLink() = default;

		VActEditorLink(const VActEditorLink& Other) = default;

		VActEditorLink(VActEditorLink&& Other) noexcept = default;

		VActEditorLink& operator=(VActEditorLink&& Other) noexcept = default;

		VActEditorLink& operator=(const VActEditorLink& Other) = default;

		virtual ~VActEditorLink() = default;
	};
}

