# VActASTEditor
To make adjustments to the `VActAStInstance` managing the AST traversal using LLVM you will have to first build LLVM binaries and generate a `VActASTEditorDll` project to rebuild the `dll` and `lib` used by `VActASTEditor`.
## LLVM Preperation/Build 
To adjust the `VActASTEditor.dll` you need to clone the [llvm-project](https://github.com/llvm/llvm-project) repro
```bash
git clone https://github.com/llvm/llvm-project
```
Generate visual studio files
```bash
cmake -G "Visual Studio 18 2026" -A x64 `
  -S llvm-project\llvm `
  -B llvm-project-vs-build `
  -DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra" `
  -DCMAKE_BUILD_TYPE=Release `
  -DLLVM_ENABLE_RTTI=ON `
  -DLLVM_ENABLE_PIC=ON `
  -DLLVM_INCLUDE_TESTS=OFF `
  -DLLVM_INCLUDE_EXAMPLES=OFF `
  -DLLVM_INCLUDE_UTILS=OFF `
  -DLLVM_INCLUDE_TOOLS=OFF
```
Then build the `llvm-project`
```bash
cmake --build llvm-project-vs-build --config Release
```
## VActASTEditorDLL Preperation/Build
Now we can generate a build project to make changes to `VActASTEditorDLL`
```bash
cmake -G "Visual Studio 18 2026" -A x64 `
  -S VActExplore/VActASTEditorDLL `
  -B VActExplore/VActASTEditorDLL-Build `
  -DLLVM_DIR=llvm-project-vs-build/lib/cmake/llvm `
  -DClang_DIR=llvm-project-vs-build/lib/cmake/clang
```
Finally you can build a `dll` and `lib` via `VActExplore/VActASTEditorDLL-Build` project
```bash
cmake --build VActExplore/VActASTEditorDLL-Build --config Release
```
**Note** that if you will use other functionalities you will need to extend the `CMakeLists.txt` `target_link_libraries` of the `VActASTEditorDLL` project. After that reganerate the project.
## Update VActASTEditor
If not automated/configered via `VActASTEditor` you will have to copy the `lib` and `dll` files to `VActASTEditor/Dep/x64`. Same holds for the includes, copy them to `VActASTEditor/Dep`.
```bash
cp VActExplore/VActASTEditorDLL/Bin/Release/x64/*.dll VActExplore/VActASTEditor/Dep/x64
cp VActExplore/VActASTEditorDLL/Bin/Release/x64/*.lib VActExplore/VActASTEditor/Dep/x64
cp VActExplore/VActASTEditorDLL/Include/*.h VActExplore/VActASTEditor/Dep
```