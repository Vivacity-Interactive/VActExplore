#pragma once

#include "_VActASTEditor.h"

#include <string>

namespace VActExplore::ASTEditor
{
    class VACTASTEDITOR_API VActEditorDefaults
    {
        VActEditorDefaults() = delete;

    public:
        // Default Names

        static string_t Name;

        static string_t FunctionName;

        static string_t VariableName;

        static string_t ControlName;

        static string_t EntityName;

        static string_t StatementName;

        static string_t ScopeName;

        static string_t ConstructName;

        static string_t ReferenceName;

        static string_t ProjectName;

        static string_t FileName;

        static string_t ResourceName;

        static string_t CommentName;


        // Default Types

        static string_t Type;

        static string_t FunctionType;

        static string_t VariableType;

        static string_t ControlType;

        static string_t EntityType;

        static string_t StatementType;

        static string_t ScopeType;

        static string_t ConstructType;

        static string_t ReferenceType;

        static string_t ProjectType;

        static string_t FileType;

        static string_t ResourceType;

        static string_t CommentType;

    };
}