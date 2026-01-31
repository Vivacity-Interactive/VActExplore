#include "VActEditorVisitor.h"

#include "llvm/Support/raw_ostream.h"
#include "clang/Basic/SourceManager.h"

using namespace VActExplore::ASTEditor;

bool VActEditorVisitor::VisitDecl(clang::Decl* Decl)
{
	if (!GuardedVisitDecl(Decl)) { return true; }

	llvm::outs() << "Decl: " << Decl->getDeclKindName() << "\n";
	return true;
}

bool VActEditorVisitor::VisitFunctionDecl(clang::FunctionDecl* Decl)
{
	if (!GuardedVisitDecl(Decl)) { return true; }

	llvm::outs() << "Function: " << Decl->getNameAsString() << "\n";
	return true;
}

//bool VActEditorVisitor::VisitVarDecl(clang::VarDecl* Decl)
//{
//	if (!GuardedVisitDecl(Decl)) { return true; }
//
//	llvm::outs() << "Var: " << Decl->getNameAsString() << "\n";
//	return true;
//}
//
//bool VActEditorVisitor::VisitParmVarDecl(clang::ParmVarDecl* Decl)
//{
//	if (!GuardedVisitDecl(Decl)) { return true; }
//
//	llvm::outs() << "ParmVar: " << Decl->getNameAsString() << "\n";
//	return true;
//}
//
//bool VActEditorVisitor::VisitFieldDecl(clang::FieldDecl* Decl)
//{
//  if (!GuardedVisitDecl(Decl)) { return true; }
//  
//	llvm::outs() << "Field: " << Decl->getNameAsString() << "\n";
//	return true;
//}
//
//bool VActEditorVisitor::VisitRecordDecl(clang::RecordDecl* Decl)
//{
//  if (!GuardedVisitDecl(Decl)) { return true; }
// 
//	llvm::outs() << "Record: " << Decl->getNameAsString() << "\n";
//	return true;
//}
//
//bool VActEditorVisitor::VisitCXXRecordDecl(clang::CXXRecordDecl* Decl)
//{
//  if (!GuardedVisitDecl(Decl)) { return true; }
//	llvm::outs() << "CXXRecord: " << Decl->getNameAsString() << "\n";
//	return true;
//}
//
//bool VActEditorVisitor::VisitEnumDecl(clang::EnumDecl* Decl)
//{
//  if (!GuardedVisitDecl(Decl)) { return true; }
// 
//	llvm::outs() << "Enum: " << Decl->getNameAsString() << "\n";
//	return true;
//}
//
//bool VActEditorVisitor::VisitTypedefDecl(clang::TypedefDecl* Decl)
//{
//  if (!GuardedVisitDecl(Decl)) { return true; }
// 
//	llvm::outs() << "Typedef: " << Decl->getNameAsString() << "\n";
//	return true;
//}
//
//bool VActEditorVisitor::VisitTypeAliasDecl(clang::TypeAliasDecl* Decl)
//{
//  if (!GuardedVisitDecl(Decl)) { return true; }
// 
//	llvm::outs() << "TypeAlias: " << Decl->getNameAsString() << "\n";
//	return true;
//}
//
//bool VActEditorVisitor::VisitNamespaceDecl(clang::NamespaceDecl* Decl)
//{ 
//  if (!GuardedVisitDecl(Decl)) { return true; }
// 
//	llvm::outs() << "Namespace: " << Decl->getNameAsString() << "\n";
//	return true;
//}

bool VActEditorVisitor::VisitStmt(clang::Stmt* Stmt)
{
	if (!GuardedVisitStmt(Stmt)) { return true; }

	llvm::outs() << "Stmt: " << Stmt->getStmtClassName() << "\n";
	return true;
}

//bool VActEditorVisitor::VisitType(clang::Type* Type)
//{
//	if (!GuardedVisitType(Type)) { return true; }
//
//	llvm::outs() << "Type: " << Type->getTypeClassName() << "\n";
//	return true;
//}

bool VActEditorVisitor::VisitAttr(clang::Attr* Attr)
{
	if (!GuardedVisitAttr(Attr)) { return true; }

	llvm::outs() << "Attr: " << Attr->getAttrName() << "\n";
	return true;
}

bool VActEditorVisitor::GuardedVisitDecl(clang::Decl* Decl)
{
	auto& SM = _Context->getSourceManager();
	return SM.isInMainFile(Decl->getLocation());
}

bool VActEditorVisitor::GuardedVisitStmt(clang::Stmt* Stmt)
{
	auto& SM = _Context->getSourceManager();
	return SM.isInMainFile(Stmt->getBeginLoc());
}

//bool VActEditorVisitor::GuardedVisitType(clang::Type* Type)
//{
//	return true;
//}

bool VActEditorVisitor::GuardedVisitAttr(clang::Attr* Attr)
{
	auto& SM = _Context->getSourceManager();
	return SM.isInMainFile(Attr->getLocation());
}