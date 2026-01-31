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

void VActEditorInstance::CLI_ResolvePath(std::string& Into, const int32_t Argc, const char** Argv)
{
	if (Argc < 2)
	{
		std::cerr << "no input file specified." << std::endl;
		return;
	}
	Into = Argv[1];
}

void VActEditorInstance::ReadSourceFile(std::string& Into, const std::string FilePath)
{
	std::ifstream File(FilePath, std::ios::in);
	if (!File)
	{
		std::cerr << "failed to open file: " << FilePath << std::endl;
		return;
	}

	Into.assign((std::istreambuf_iterator<char>(File)), std::istreambuf_iterator<char>());
}

void VActEditorInstance::RunASTAction(const std::string& Source)
{
	//clang::tooling::runToolOnCode(std::make_unique<VActEditorAction>(), Source);
	clang::tooling::runToolOnCodeWithArgs(std::make_unique<VActEditorAction>(), Source, { "-std=c++23" });
}

void VActEditorInstance::RunASTAction(const std::string& Source, std::string& FilePath)
{
	//clang::tooling::runToolOnCode(std::make_unique<VActEditorAction>(), Source);
	clang::tooling::runToolOnCodeWithArgs(std::make_unique<VActEditorAction>(), Source, { "-std=c++23" }, FilePath);
}