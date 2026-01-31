#include "VActEditorComment.h"

using namespace VActExplore::ASTEditor;

VActEditorComment::VActEditorComment(std::string Name, std::string Content)
	: VActEditorUI(std::move(Name))
	, Content(std::move(Content))
{
}