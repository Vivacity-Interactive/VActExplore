#include "VActEditorUI.h"

using namespace VActExplore::ASTEditor;

VActEditorUI::VActEditorUI()
	: VActEditorUI("EditorUI")
{
}

VActEditorUI::VActEditorUI(const string_t Name)
	: _Id(0)
	, _Class(0)
	, _Context(nullptr)
	, _Transform()
	, Name(Name)
	, bEnabled(true)
	, bIgnored(false)
	, bVisible(true)
	, bLocked(false)
	, bResizable(false)
	, bDraggable(false)
	, bSelectable(false)
{
}

void VActEditorUI::Render()
{

}

void VActEditorUI::Pass(size_t PassId, VActEditorUI* Context)
{

}

VActEditorUI::~VActEditorUI() = default;