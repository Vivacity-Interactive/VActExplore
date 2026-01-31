#pragma once

//#pragma warning(push)
//#pragma warning(disable:4146)
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/AST/ASTContext.h"
//#pragma warning(pop)

#include "VActEditorNode.h"

namespace VActExplore::ASTEditor
{
	class VActEditorVisitor :
		public clang::RecursiveASTVisitor<VActEditorVisitor>
	{
	private:
		clang::ASTContext* _Context;
		
		std::vector<VActEditorNode> Nodes;

	public:
		explicit VActEditorVisitor(clang::ASTContext* Context)
			: _Context(Context) {};

		bool VisitDecl(clang::Decl* Decl);

		bool VisitFunctionDecl(clang::FunctionDecl* Decl);

		/*bool VisitVarDecl(clang::VarDecl* Decl);

		bool VisitParmVarDecl(clang::ParmVarDecl* Decl);

		bool VisitFieldDecl(clang::FieldDecl* Decl);

		bool VisitRecordDecl(clang::RecordDecl* Decl);

		bool VisitCXXRecordDecl(clang::CXXRecordDecl* Decl);

		bool VisitEnumDecl(clang::EnumDecl* Decl);

		bool VisitTypedefDecl(clang::TypedefDecl* Decl);

		bool VisitTypeAliasDecl(clang::TypeAliasDecl* Decl);

		bool VisitNamespaceDecl(clang::NamespaceDecl* Decl);*/

		bool VisitStmt(clang::Stmt* Stmt);

		//bool VisitType(clang::Type* Type);

		bool VisitAttr(clang::Attr* Attr);

		bool GuardedVisitDecl(clang::Decl* Decl);

		bool GuardedVisitStmt(clang::Stmt* Stmt);

		//bool GuardedVisitType(clang::Type* Type);

		bool GuardedVisitAttr(clang::Attr* Attr);
	};
}
