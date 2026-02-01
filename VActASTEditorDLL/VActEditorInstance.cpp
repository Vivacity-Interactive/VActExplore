#include "VActEditorInstance.h"
#include "VActEditorAction.h"

#include "clang/Tooling/Tooling.h"

#include <iostream>
#include <fstream>


using namespace VActExplore::ASTEditor;

std::vector<VActEditorInstance*> VActEditorInstance::_Instances;

VActEditorInstance* VActEditorInstance::GetInstance(size_t Id)
{
	const bool bResize = Id >= _Instances.size();
	if (bResize)
	{ 
		_Instances.resize(Id + 1, nullptr);
	}

	VActEditorInstance* Instance = _Instances[Id];
	if (!Instance)
	{
		Instance = _Instances[Id] = new VActEditorInstance();
		Instance->_Id = Id;
		Instance->Initialize();
	}
	return Instance;
}

VActEditorInstance::VActEditorInstance()
{

}

VActEditorInstance::~VActEditorInstance()
{
	Shutdown();
	const bool bUnset = _Instances.size() > _Id;
	if (bUnset)
	{
		_Instances[_Id] = nullptr;
	}

	Notify(0);	
}

void VActEditorInstance::Notify(size_t Signal)
{
	for (size_t Id = 0; Id < _Observers.size(); ++Id)
	{
		IVActEditorObserver* Listener = _Observers[Id];
		if (Listener)
		{
			Listener->Notify(Signal, _Id, Id);
		}
	}
}

void VActEditorInstance::Initialize()
{
	if (_bInitialized)
	{
		return;
	}

	_bInitialized = true;
}

void VActEditorInstance::Shutdown()
{
	if (!_bInitialized)
	{
		return;
	}

	_bInitialized = false;
}

// CLI Helpers

void VActEditorInstance::CLI_ResolvePath(string_t& Into, const int32_t Argc, const char** Argv)
{
	if (Argc < 2)
	{
		std::cerr << "no input file specified." << std::endl;
		return;
	}
	Into = Argv[1];
}

// Util Helpers

void VActEditorInstance::ReadSourceFile(string_t& Into, const string_t FilePath)
{
	std::ifstream File(FilePath, std::ios::in);
	if (!File)
	{
		std::cerr << "failed to open file: " << FilePath << std::endl;
		return;
	}

	Into.assign((std::istreambuf_iterator<char>(File)), std::istreambuf_iterator<char>());
}

// Action Helpers

void VActEditorInstance::RunASTActionCursor(size_t CursorId)
{

}

void VActEditorInstance::RunASTAction(size_t SourceId)
{

}

void VActEditorInstance::RunASTAction(const string_t& Source)
{
	//clang::tooling::runToolOnCode(std::make_unique<VActEditorAction>(), Source);
	clang::tooling::runToolOnCodeWithArgs(std::make_unique<VActEditorAction>(), Source, { "-std=c++23" });
}

void VActEditorInstance::RunASTAction(const string_t& Source, string_t& FilePath)
{
	//clang::tooling::runToolOnCode(std::make_unique<VActEditorAction>(), Source);
	clang::tooling::runToolOnCodeWithArgs(std::make_unique<VActEditorAction>(), Source, { "-std=c++23" }, FilePath);
}

void VActEditorInstance::PushASTActionCursor(size_t CursorId)
{

}

void VActEditorInstance::PushASTAction(size_t SourceId)
{

}

void VActEditorInstance::PushASTAction(const string_t& Source)
{

}

void VActEditorInstance::PreviewASTActionCursor(size_t CursorId, size_t DepthMin, size_t DepthMax)
{

}

void VActEditorInstance::PreviewASTAction(size_t SourceId, size_t ScopeId, size_t DepthMin, size_t DepthMax)
{

}

void VActEditorInstance::PreviewASTAction(const string_t& Source, size_t ScopeId, size_t DepthMin, size_t DepthMax)
{

}

void VActEditorInstance::LancheASTActionCursor(size_t CursorId)
{

}

void VActEditorInstance::LancheASTActionCursor(const std::vector<string_t> Arguments, size_t CursorId)
{

}

void VActEditorInstance::LancheASTAction()
{

}

void VActEditorInstance::LancheASTAction(const std::vector<string_t> Arguments)
{

}

void VActEditorInstance::CompileASTActionCursor(size_t CursorId)
{

}

void VActEditorInstance::CompileASTActionCursor(const std::vector<string_t> Arguments, size_t CursorId)
{

}

void VActEditorInstance::CompileASTAction()
{

}

void VActEditorInstance::CompileASTAction(const std::vector<string_t> Arguments)
{

}

// Creation Helpers

void VActEditorInstance::NewVariable(string_t Name, string_t Type, size_t ScopeId, size_t InsertId)
{

}

void VActEditorInstance::NewVariable(string_t Name, string_t Type, size_t CursorId)
{

}

void VActEditorInstance::NewFunction(string_t Name, string_t Type, size_t ScopeId, size_t InsertId)
{

}

void VActEditorInstance::NewFunction(string_t Name, string_t Type, size_t CursorId)
{

}

void VActEditorInstance::NewControl(string_t Name, string_t Type, size_t ScopeId, size_t InsertId)
{

}

void VActEditorInstance::NewControl(string_t Name, string_t Type, size_t CursorId)
{

}

void VActEditorInstance::NewEntity(string_t Name, string_t Type, size_t ScopeId, size_t InsertId)
{

}

void VActEditorInstance::NewEntity(string_t Name, string_t Type, size_t CursorId)
{

}

void VActEditorInstance::NewStatement(string_t Name, string_t Type, size_t ScopeId, size_t InsertId)
{

}

void VActEditorInstance::NewStatement(string_t Name, string_t Type, size_t CursorId)
{

}

void VActEditorInstance::NewScope(string_t Name, string_t Type, size_t ScopeId, size_t InsertId)
{

}

void VActEditorInstance::NewScope(string_t Name, string_t Type, size_t CursorId)
{

}

void VActEditorInstance::NewConstruct(string_t Name, string_t Type, size_t ScopeId, size_t InsertId)
{

}

void VActEditorInstance::NewConstruct(string_t Name, string_t Type, size_t CursorId)
{

}

void VActEditorInstance::NewReference(string_t Name, string_t Type, size_t ScopeId, size_t InsertId)
{

}

void VActEditorInstance::NewReference(string_t Name, string_t Type, size_t CursorId)
{

}

void VActEditorInstance::NewProject(string_t Name, string_t Type, size_t ScopeId, size_t InsertId)
{

}

void VActEditorInstance::NewProject(string_t Name, string_t Type, size_t CursorId)
{

}

void VActEditorInstance::NewFile(string_t Name, string_t Type, size_t ScopeId, size_t InsertId)
{

}

void VActEditorInstance::NewFile(string_t Name, string_t Type, size_t CursorId)
{

}

void VActEditorInstance::NewResource(string_t Name, string_t Type, size_t ScopeId, size_t InsertId)
{

}

void VActEditorInstance::NewResource(string_t Name, string_t Type, size_t CursorId)
{

}

void VActEditorInstance::NewComment(string_t Name, string_t Type, size_t ScopeId, size_t InsertId)
{

}

void VActEditorInstance::NewComment(string_t Name, string_t Type, size_t CursorId)
{

}