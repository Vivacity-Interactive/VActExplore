#pragma once

#include "_VActASTEditor.h"
#include <cstdint>
#include <string>

namespace VActExplore::ASTEditor
{
	struct VACTASTEDITOR_API FVActUITransform
	{
		float X, Y, Z, W;
		float Width, Height, Depth, Value;
		float R, G, B, A;

		_VACTASTEDITOR_DEFAULT_BODY(FVActUITransform);

		FVActUITransform();
	};

	struct VACTASTEDITOR_API FVActUIState
	{
		uint32_t bEnabled : 1;

		uint32_t bDirty : 1;

		uint32_t bIgnored : 1;

		uint32_t bVisible : 1;

		uint32_t bLocked : 1;

		uint32_t bResizable : 1;

		uint32_t bDraggable : 1;

		uint32_t bSelectable : 1;

		uint32_t bAutoWidth : 1;

		uint32_t bAutoHeight : 1;

		uint32_t bAutoDepth : 1;

		uint32_t bAutoValue : 1;

		_VACTASTEDITOR_DEFAULT_BODY(FVActUIState);
		
		FVActUIState();
	};

	class VACTASTEDITOR_API VActEditorUI
	{
	protected:
		size_t _Id;

		size_t _Class;

		void* _Context;

		FVActUIState _State;

		FVActUITransform _Transform;

	public:
		string_t Name;

		_VACTASTEDITOR_DEFAULT_BODY(VActEditorUI);

		VActEditorUI();

		VActEditorUI(const string_t Name);

		virtual ~VActEditorUI();

		virtual void Render() = 0;

		virtual void Pass(size_t PassId = 0, VActEditorUI* Subject = nullptr) = 0;

	};
}


