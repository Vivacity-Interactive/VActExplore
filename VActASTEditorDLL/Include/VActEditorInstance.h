#pragma once

#include "_VActASTEditor.h"
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

		int8_t _bInitialized : 1;

		size_t _Id;

		VActEditorInstance();

		void Notify(size_t Signal);

	public:
		~VActEditorInstance();

		static VActEditorInstance* GetInstance(size_t Id = 0);

		void Initialize();

		void Shutdown();

		__forceinline size_t Observe(IVActEditorObserver* Observer) {
			_Observers.push_back(Observer);
			return _Observers.size() - 1;
		}

		__forceinline void UnObserve(size_t ObserverId) {
			if (ObserverId < _Observers.size()) {
				_Observers[ObserverId] = nullptr;
			}
		}

		__forceinline bool IsInitialized() const {
			return _bInitialized;
		}

	public:

		void CLI_ResolvePath(std::string& FilePath, const int32_t Argc, const char** Argv);

		void ReadSourceFile(std::string& Into, const std::string FilePath);

		void RunASTAction(const std::string& Source);

		void RunASTAction(const std::string& Source, std::string& FilePath);
		
	};

}

