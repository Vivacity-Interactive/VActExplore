#include "VActEditorNode.h"

using namespace VActExplore::ASTEditor;

VActEditorNode::VActEditorNode()
	: VActEditorNode("EditorNode", "node")
{
}

VActEditorNode::VActEditorNode(const string_t Name, const string_t Type)
	: VActEditorUI(Name)
	, Type(Type)
{
}

VActEditorNode::~VActEditorNode() = default;