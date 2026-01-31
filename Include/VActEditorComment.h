#pragma once

#include "_VActASTEditor.h"
#include "VActEditorUI.h"

namespace VActExplore::ASTEditor
{
    class VACTASTEDITOR_API VActEditorComment :
        public VActEditorUI
    {
	public:
        std::string Content;

		VActEditorUI* Parent;

        VActEditorComment() = default;

        VActEditorComment(const VActEditorComment& Other) = default;

        VActEditorComment(VActEditorComment&& Other) noexcept = default;

        VActEditorComment& operator=(VActEditorComment&& Other) noexcept = default;

		VActEditorComment& operator=(const VActEditorComment& Other) = default;

		VActEditorComment(std::string Name, std::string Content);

        virtual ~VActEditorComment() = default;
    };
}
