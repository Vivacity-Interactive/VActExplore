#pragma once

#include "_VActASTEditor.h"
#include "VActEditorUI.h"

namespace VActExplore::ASTEditor
{
    class VACTASTEDITOR_API VActEditorComment :
        public VActEditorUI
    {
	public:
        string_t Content;

		VActEditorUI* Parent;

        _VACTASTEDITOR_DEFAULT_BODY(VActEditorComment);
        
        VActEditorComment();

		VActEditorComment(const string_t Name, const string_t Content);

        virtual ~VActEditorComment() = default;
    };
}
