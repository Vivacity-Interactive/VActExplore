#pragma once

#include "VActEditorConsumer.h"

//#pragma warning(push)
//#pragma warning(disable:4146)
#include "clang/Frontend/ASTUnit.h"
#include "clang/Frontend/FrontendAction.h"
//#pragma warning(pop)

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