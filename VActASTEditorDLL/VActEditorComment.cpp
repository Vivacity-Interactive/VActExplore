#include "VActEditorComment.h"

using namespace VActExplore::ASTEditor;

VActEditorComment::VActEditorComment()
	: VActEditorComment("Comment", "")
{
}

VActEditorComment::VActEditorComment(const string_t Name, const string_t Content)
	: VActEditorUI(Name)
	, Content(Content)
	, Parent(nullptr)
{
}