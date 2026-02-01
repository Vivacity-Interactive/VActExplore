#pragma once

#include "VActEditorVisitor.h"

#include "clang/AST/ASTConsumer.h"
#include "clang/Frontend/CompilerInstance.h"

namespace VActExplore::ASTEditor
{
	class VActEditorConsumer :
		public clang::ASTConsumer
	{
	private:
		VActEditorVisitor _Context;

	public:
		explicit VActEditorConsumer(clang::ASTContext* Context)
			: _Context(Context)
		{
		}

		void HandleTranslationUnit(clang::ASTContext& Context) override;

	};
}
