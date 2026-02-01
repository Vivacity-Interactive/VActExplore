#include "VActEditorInstance.h"

using namespace VActExplore::ASTEditor;

#include <iostream>

int main(int Argc, char* Argv[])
{
	auto* Editor = VActEditorInstance::GetInstance();
	
    const bool bValid = Editor != nullptr && Editor->IsInitialized();
    if (!bValid)
    {
        std::cerr << "failed to get or initialize VActEditorInstance." << std::endl;
        return -1;
    }

    string_t FilePath, Source;

	Editor->CLI_ResolvePath(FilePath, Argc, (const char**)Argv);
	Editor->ReadSourceFile(Source, FilePath);
	Editor->RunASTAction(Source);

    return 0;
}
