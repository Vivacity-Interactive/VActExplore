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

		FVActUITransform() = default;
	};

	class VACTASTEDITOR_API VActEditorUI
	{
	protected:
		size_t _Id;

		size_t _Class;

		void* _Context;

		uint8_t bEnabled : 1;

		uint8_t bIgnored : 1;

		uint8_t bVisible : 1;

		uint8_t bLocked : 1;

		uint8_t bResizable : 1;

		uint8_t bDraggable : 1;

		uint8_t bSelectable : 1;

		FVActUITransform _Transform;

	public:
		string_t Name;

		_VACTASTEDITOR_DEFAULT_BODY(VActEditorUI);

		VActEditorUI();

		VActEditorUI(const string_t Name);

		virtual ~VActEditorUI();

		virtual void Render() = 0;

		virtual void Pass(size_t PassId = 0, VActEditorUI* Context = nullptr) = 0;

	};
}


