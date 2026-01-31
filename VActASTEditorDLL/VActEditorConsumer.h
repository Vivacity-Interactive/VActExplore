#pragma once

#include "VActEditorVisitor.h"

//#pragma warning(push)
//#pragma warning(disable:4146)
#include "clang/AST/ASTConsumer.h"
#include "clang/Frontend/CompilerInstance.h"
//#pragma warning(pop)

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
