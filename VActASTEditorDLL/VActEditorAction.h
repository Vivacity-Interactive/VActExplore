#pragma once

#include "VActEditorConsumer.h"

#include "clang/Frontend/ASTUnit.h"
#include "clang/Frontend/FrontendAction.h"

namespace VActExplore::ASTEditor
{
    class VActEditorAction :
        public clang::ASTFrontendAction
    {
	public:
        std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
            clang::CompilerInstance& CI,
            llvm::StringRef File
        ) override;
    };
}