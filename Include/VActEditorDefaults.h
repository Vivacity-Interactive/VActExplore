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

        static std::string Name;

        static std::string FunctionName;

        static std::string VariableName;

        static std::string ControlName;

        static std::string EntityName;

        static std::string StatementName;

        static std::string ScopeName;

        static std::string ConstructName;

        static std::string ReferenceName;

        static std::string ProjectName;

        static std::string FileName;

        static std::string ResourceName;

        static std::string CommentName;


        // Default Types

        static std::string Type;

        static std::string FunctionType;

        static std::string VariableType;

        static std::string ControlType;

        static std::string EntityType;

        static std::string StatementType;

        static std::string ScopeType;

        static std::string ConstructType;

        static std::string ReferenceType;

        static std::string ProjectType;

        static std::string FileType;

        static std::string ResourceType;

        static std::string CommentType;

    };
}