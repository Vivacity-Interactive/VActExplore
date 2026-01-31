#include "VActEditorUI.h"

using namespace VActExplore::ASTEditor;

VActEditorUI::VActEditorUI(std::string Name)
	: _Id(0)
	, _Class(0)
	, Name(std::move(Name))
{
	bEnabled = true;
	bIgnored = false;
	bVisible = true;
	bLocked = false;
	bResizable = false;
	bDraggable = false;
	bSelectable = false;
}

void VActEditorUI::Render()
{

}

void VActEditorUI::Pass(size_t PassId, VActEditorUI* Context)
{

}