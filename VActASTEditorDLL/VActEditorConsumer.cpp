#include "VActEditorConsumer.h"

using namespace VActExplore::ASTEditor;


void VActEditorConsumer::HandleTranslationUnit(clang::ASTContext& Context)
{
	_Context.TraverseDecl(Context.getTranslationUnitDecl());
}