#pragma once

#include "_VActASTEditor.h"
#include "VActEditorDefaults.h"
#include "VActEditorUI.h"
#include "VActEditorLink.h"
#include "VActEditorGroup.h"
#include "VActEditorCursor.h"

#include <cstdint>
#include <string>
#include <vector>

namespace VActExplore::ASTEditor
{
	class VACTASTEDITOR_API IVActEditorObserver
	{
	public:
		virtual ~IVActEditorObserver() = default;

		virtual void Notify(size_t Signal, size_t InstanceId, size_t ObserverId) = 0;
	};

	class VACTASTEDITOR_API VActEditorInstance
	{
	private:
		static std::vector<VActEditorInstance*> _Instances;

		std::vector<IVActEditorObserver*> _Observers;

		std::vector<VActEditorLink*> _Links;

		std::vector<VActEditorCursor*> _Cursors;

		std::vector<VActEditorGroup*> _Groups;

		std::vector<VActEditorNode*> _Nodes;

		int8_t _bInitialized : 1;

		size_t _Id;

		VActEditorInstance();

		void Notify(size_t Signal);

	public:
		~VActEditorInstance();

		static VActEditorInstance* GetInstance(size_t Id = 0);

		void Initialize();

		void Shutdown();

		__forceinline size_t Observe(IVActEditorObserver* Observer)
		{
			_Observers.push_back(Observer);
			return _Observers.size() - 1;
		}

		__forceinline void UnObserve(size_t ObserverId)
		{
			if (ObserverId < _Observers.size())
			{
				_Observers[ObserverId] = nullptr;
			}
		}

		__forceinline bool IsInitialized() const
		{
			return _bInitialized;
		}

	public:

		// CLI Helpers

		void CLI_ResolvePath(std::string& FilePath, const int32_t Argc, const char** Argv);

		// Action Helpers

		void ReadSourceFile(std::string& Into, const std::string FilePath);

		// Action Helpers

		void RunASTActionCursor(size_t CursorId = 0);

		void RunASTAction(size_t SourceId);

		void RunASTAction(const std::string& Source);

		void RunASTAction(const std::string& Source, std::string& FilePath);

		void PushASTActionCursor(size_t CursorId = 0);

		void PushASTAction(size_t SourceId);

		void PushASTAction(const std::string& Source);

		void PreviewASTActionCursor(size_t CursorId = 0, size_t DepthMin = 0, size_t DepthMax = 0);

		void PreviewASTAction(size_t SourceId, size_t ScopeId, size_t DepthMin = 0, size_t DepthMax = 0);

		void PreviewASTAction(const std::string& Source, size_t ScopeId, size_t DepthMin = 0, size_t DepthMax = 0);

		void LancheASTActionCursor(size_t CursorId = 0);

		void LancheASTActionCursor(const std::vector<std::string> Arguments, size_t CursorId = 0);

		void LancheASTAction();

		void LancheASTAction(const std::vector<std::string> Arguments);

		void CompileASTActionCursor(size_t CursorId = 0);

		void CompileASTActionCursor(const std::vector<std::string> Arguments, size_t CursorId = 0);

		void CompileASTAction();

		void CompileASTAction(const std::vector<std::string> Arguments);

		// Creation Helpers

		void NewVariable(std::string Name, std::string Type, size_t ScopeId, size_t InsertId);

		void NewVariable(std::string Name, std::string Type, size_t CursorId = 0);

		__forceinline void NewVariable(size_t CursorId = 0)
		{
			NewVariable(VActEditorDefaults::VariableName, VActEditorDefaults::VariableType, CursorId);
		}

		void NewFunction(std::string Name, std::string Type, size_t ScopeId, size_t InsertId);

		void NewFunction(std::string Name, std::string Type, size_t CursorId = 0);

		__forceinline void NewFunction(size_t CursorId = 0)
		{
			NewFunction(VActEditorDefaults::FunctionName, VActEditorDefaults::FunctionType, CursorId);
		}

		void NewControl(std::string Name, std::string Type, size_t ScopeId, size_t InsertId);

		void NewControl(std::string Name, std::string Type, size_t CursorId = 0);

		__forceinline void NewControl(size_t CursorId = 0)
		{
			NewControl(VActEditorDefaults::ControlName, VActEditorDefaults::ControlType, CursorId);
		}

		void NewEntity(std::string Name, std::string Type, size_t ScopeId, size_t InsertId);

		void NewEntity(std::string Name, std::string Type, size_t CursorId = 0);

		__forceinline void NewEntity(size_t CursorId = 0)
		{
			NewEntity(VActEditorDefaults::EntityName, VActEditorDefaults::EntityType, CursorId);
		}

		void NewStatement(std::string Name, std::string Type, size_t ScopeId, size_t InsertId);

		void NewStatement(std::string Name, std::string Type, size_t CursorId = 0);

		__forceinline void NewStatement(size_t CursorId = 0)
		{
			NewStatement(VActEditorDefaults::StatementName, VActEditorDefaults::StatementType, CursorId);
		}

		void NewScope(std::string Name, std::string Type, size_t ScopeId, size_t InsertId);

		void NewScope(std::string Name, std::string Type, size_t CursorId = 0);

		__forceinline void NewScope(size_t CursorId = 0)
		{
			NewScope(VActEditorDefaults::ScopeName, VActEditorDefaults::ScopeType, CursorId);
		}

		void NewConstruct(std::string Name, std::string Type, size_t ScopeId, size_t InsertId);

		void NewConstruct(std::string Name, std::string Type, size_t CursorId = 0);

		__forceinline void NewConstruct(size_t CursorId = 0)
		{
			NewConstruct(VActEditorDefaults::ConstructName, VActEditorDefaults::ConstructType, CursorId);
		}

		void NewReference(std::string Name, std::string Type, size_t ScopeId, size_t InsertId);

		void NewReference(std::string Name, std::string Type, size_t CursorId = 0);

		__forceinline void NewReference(size_t CursorId = 0)
		{
			NewReference(VActEditorDefaults::ReferenceName, VActEditorDefaults::ReferenceType, CursorId);
		}

		void NewProject(std::string Name, std::string Type, size_t ScopeId, size_t InsertId);

		void NewProject(std::string Name, std::string Type, size_t CursorId = 0);

		__forceinline void NewProject(size_t CursorId = 0)
		{
			NewProject(VActEditorDefaults::ProjectName, VActEditorDefaults::ProjectType, CursorId);
		}

		void NewFile(std::string Name, std::string Type, size_t ScopeId, size_t InsertId);

		void NewFile(std::string Name, std::string Type, size_t CursorId = 0);

		__forceinline void NewFile(size_t CursorId = 0)
		{
			NewFile(VActEditorDefaults::FileName, VActEditorDefaults::FileType, CursorId);
		}

		void NewResource(std::string Name, std::string Type, size_t ScopeId, size_t InsertId);

		void NewResource(std::string Name, std::string Type, size_t CursorId = 0);

		__forceinline void NewResource(size_t CursorId = 0)
		{
			NewResource(VActEditorDefaults::ResourceName, VActEditorDefaults::ResourceType, CursorId);
		}

		void NewComment(std::string Name, std::string Type, size_t ScopeId, size_t InsertId);

		void NewComment(std::string Name, std::string Type, size_t CursorId = 0);

		__forceinline void NewComment(size_t CursorId = 0)
		{
			NewComment(VActEditorDefaults::CommentName, VActEditorDefaults::CommentType, CursorId);
		}
	};

}

