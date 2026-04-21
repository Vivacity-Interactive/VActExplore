#include "VActEditorUI.h"

using namespace VActExplore::ASTEditor;

FVActUITransform::FVActUITransform()
	: X(0.0f)
	, Y(0.0f)
	, Z(0.0f)
	, W(1.0f)
	, Width(0.0f)
	, Height(0.0f)
	, Depth(0.0f)
	, Value(1.0f)
	, R(1.0f)
	, G(1.0f)
	, B(1.0f)
	, A(1.0f)
{
}

FVActUIState::FVActUIState()
	: bEnabled(true)
	, bDirty(true)
	, bIgnored(false)
	, bVisible(true)
	, bLocked(false)
	, bResizable(false)
	, bDraggable(false)
	, bSelectable(false)
{
}

VActEditorUI::VActEditorUI()
	: VActEditorUI("EditorUI")
{
}

VActEditorUI::VActEditorUI(const string_t Name)
	: _Id(0)
	, _Class(0)
	, _Context(nullptr)
	, _State()
	, _Transform()
	, Name(Name)
{
}

void VActEditorUI::Render()
{

}

void VActEditorUI::Pass(size_t PassId, VActEditorUI* Subject)
{

}

VActEditorUI::~VActEditorUI() = default;