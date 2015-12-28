##
## Auto Generated makefile, please do not edit
##
ProjectName:=ReSchedule

## Release
ConfigurationName      :=Release
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/WANGMengChang/Projects/FacSim/svn/branches/ReSchedule/CodeLiteProj"
ProjectPath            := "/home/WANGMengChang/Projects/FacSim/svn/branches/ReSchedule/CodeLiteProj"
CurrentFileName        :=
CurrentFulePath        :=
CurrentFileFullPath    :=
User                   :=WANGMengChang
Date                   :=2009年10月24日
CodeLitePath           :="/home/WANGMengChang/.codelite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
CompilerName           :=g++
OutputFile             :=$(IntermediateDirectory)/wxAppMini
Preprocessors          :=$(PreprocessorSwitch)__WX__ 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=
CmpOptions :=  $(shell wx-config --cxxflags --unicode=yes --debug=no) $(Preprocessors)
RcCmpOptions := 
RcCompilerName :=windres
LinkOptions :=  -O2 $(shell wx-config --debug=no --libs --unicode=yes) 
IncludePath :=  "$(IncludeSwitch)." 
RcIncludePath :=
Libs :=
LibPath := "$(LibraryPathSwitch)." 


Objects=$(IntermediateDirectory)/gui$(ObjectSuffix) $(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/MyBase$(ObjectSuffix) $(IntermediateDirectory)/Machine$(ObjectSuffix) $(IntermediateDirectory)/Queue$(ObjectSuffix) $(IntermediateDirectory)/Part$(ObjectSuffix) 

##
## Main Build Tragets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep  $(Objects)
	@mkdir -p $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@test -d ./Release || mkdir -p ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/gui$(ObjectSuffix): gui.cpp $(IntermediateDirectory)/gui$(DependSuffix)
	@test -d ./Release || mkdir -p ./Release
	$(CompilerName) $(SourceSwitch) "/home/WANGMengChang/Projects/FacSim/svn/branches/ReSchedule/CodeLiteProj/gui.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gui$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui$(DependSuffix): gui.cpp
	@test -d ./Release || mkdir -p ./Release
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/gui$(ObjectSuffix) -MF$(IntermediateDirectory)/gui$(DependSuffix) -MM "/home/WANGMengChang/Projects/FacSim/svn/branches/ReSchedule/CodeLiteProj/gui.cpp"

$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	@test -d ./Release || mkdir -p ./Release
	$(CompilerName) $(SourceSwitch) "/home/WANGMengChang/Projects/FacSim/svn/branches/ReSchedule/CodeLiteProj/main.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@test -d ./Release || mkdir -p ./Release
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "/home/WANGMengChang/Projects/FacSim/svn/branches/ReSchedule/CodeLiteProj/main.cpp"

$(IntermediateDirectory)/MyBase$(ObjectSuffix): ../src/MyBase.cpp $(IntermediateDirectory)/MyBase$(DependSuffix)
	@test -d ./Release || mkdir -p ./Release
	$(CompilerName) $(SourceSwitch) "/home/WANGMengChang/Projects/FacSim/svn/branches/ReSchedule/src/MyBase.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/MyBase$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyBase$(DependSuffix): ../src/MyBase.cpp
	@test -d ./Release || mkdir -p ./Release
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/MyBase$(ObjectSuffix) -MF$(IntermediateDirectory)/MyBase$(DependSuffix) -MM "/home/WANGMengChang/Projects/FacSim/svn/branches/ReSchedule/src/MyBase.cpp"

$(IntermediateDirectory)/Machine$(ObjectSuffix): ../src/Machine.cpp $(IntermediateDirectory)/Machine$(DependSuffix)
	@test -d ./Release || mkdir -p ./Release
	$(CompilerName) $(SourceSwitch) "/home/WANGMengChang/Projects/FacSim/svn/branches/ReSchedule/src/Machine.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Machine$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Machine$(DependSuffix): ../src/Machine.cpp
	@test -d ./Release || mkdir -p ./Release
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/Machine$(ObjectSuffix) -MF$(IntermediateDirectory)/Machine$(DependSuffix) -MM "/home/WANGMengChang/Projects/FacSim/svn/branches/ReSchedule/src/Machine.cpp"

$(IntermediateDirectory)/Queue$(ObjectSuffix): ../src/Queue.cpp $(IntermediateDirectory)/Queue$(DependSuffix)
	@test -d ./Release || mkdir -p ./Release
	$(CompilerName) $(SourceSwitch) "/home/WANGMengChang/Projects/FacSim/svn/branches/ReSchedule/src/Queue.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Queue$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Queue$(DependSuffix): ../src/Queue.cpp
	@test -d ./Release || mkdir -p ./Release
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/Queue$(ObjectSuffix) -MF$(IntermediateDirectory)/Queue$(DependSuffix) -MM "/home/WANGMengChang/Projects/FacSim/svn/branches/ReSchedule/src/Queue.cpp"

$(IntermediateDirectory)/Part$(ObjectSuffix): ../src/Part.cpp $(IntermediateDirectory)/Part$(DependSuffix)
	@test -d ./Release || mkdir -p ./Release
	$(CompilerName) $(SourceSwitch) "/home/WANGMengChang/Projects/FacSim/svn/branches/ReSchedule/src/Part.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Part$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Part$(DependSuffix): ../src/Part.cpp
	@test -d ./Release || mkdir -p ./Release
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/Part$(ObjectSuffix) -MF$(IntermediateDirectory)/Part$(DependSuffix) -MM "/home/WANGMengChang/Projects/FacSim/svn/branches/ReSchedule/src/Part.cpp"

##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/gui$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/MyBase$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/MyBase$(DependSuffix)
	$(RM) $(IntermediateDirectory)/MyBase$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Machine$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Machine$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Machine$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Queue$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Queue$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Queue$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Part$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Part$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Part$(PreprocessSuffix)
	$(RM) $(OutputFile)

-include $(IntermediateDirectory)/*$(DependSuffix)


