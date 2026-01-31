#include "VActEditorAction.h"

using namespace VActExplore::ASTEditor;

std::unique_ptr<clang::ASTConsumer> VActEditorAction::CreateASTConsumer(
    clang::CompilerInstance& CI,
    llvm::StringRef File
)
{
    return std::make_unique<VActEditorConsumer>(&CI.getASTContext());
}