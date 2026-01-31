#include "VActEditorNode.h"

using namespace VActExplore::ASTEditor;

VActEditorNode::VActEditorNode(std::string Name, std::string Type)
	: VActEditorUI(std::move(Name))
	, Type(std::move(Type))
{
}