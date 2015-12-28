##
## Auto Generated makefile, please do not edit
##
ProjectName:=Lwq

## Debug
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/WANGMengChang/Projects/FacSim/svn/branches/Lwq"
ProjectPath            := "/home/WANGMengChang/Projects/FacSim/svn/branches/Lwq"
CurrentFileName        :=
CurrentFulePath        :=
CurrentFileFullPath    :=
User                   :=WANGMengChang
Date                   :=2009年10月26日
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=
CmpOptions := -g $(Preprocessors)
LinkOptions :=  
IncludePath :=  "$(IncludeSwitch)." "$(IncludeSwitch)." 
RcIncludePath :=
Libs :=
LibPath := "$(LibraryPathSwitch)." 


Objects=$(IntermediateDirectory)/MyBase$(ObjectSuffix) $(IntermediateDirectory)/Machine$(ObjectSuffix) $(IntermediateDirectory)/Queue$(ObjectSuffix) $(IntermediateDirectory)/Part$(ObjectSuffix) $(IntermediateDirectory)/lwqstage$(ObjectSuffix) $(IntermediateDirectory)/main$(ObjectSuffix) 

##
## Main Build Tragets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep PrePreBuild $(Objects)
	@mkdir -p $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@test -d ./Debug || mkdir -p ./Debug
PrePreBuild: 



PreBuild:


##
## Objects
##
$(IntermediateDirectory)/MyBase$(ObjectSuffix): src/MyBase.cpp $(IntermediateDirectory)/MyBase$(DependSuffix)
	@test -d ./Debug || mkdir -p ./Debug
	$(CompilerName) $(SourceSwitch) "/home/WANGMengChang/Projects/FacSim/svn/branches/Lwq/src/MyBase.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/MyBase$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyBase$(DependSuffix): src/MyBase.cpp
	@test -d ./Debug || mkdir -p ./Debug
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/MyBase$(ObjectSuffix) -MF$(IntermediateDirectory)/MyBase$(DependSuffix) -MM "/home/WANGMengChang/Projects/FacSim/svn/branches/Lwq/src/MyBase.cpp"

$(IntermediateDirectory)/Machine$(ObjectSuffix): src/Machine.cpp $(IntermediateDirectory)/Machine$(DependSuffix)
	@test -d ./Debug || mkdir -p ./Debug
	$(CompilerName) $(SourceSwitch) "/home/WANGMengChang/Projects/FacSim/svn/branches/Lwq/src/Machine.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Machine$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Machine$(DependSuffix): src/Machine.cpp
	@test -d ./Debug || mkdir -p ./Debug
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/Machine$(ObjectSuffix) -MF$(IntermediateDirectory)/Machine$(DependSuffix) -MM "/home/WANGMengChang/Projects/FacSim/svn/branches/Lwq/src/Machine.cpp"

$(IntermediateDirectory)/Queue$(ObjectSuffix): src/Queue.cpp $(IntermediateDirectory)/Queue$(DependSuffix)
	@test -d ./Debug || mkdir -p ./Debug
	$(CompilerName) $(SourceSwitch) "/home/WANGMengChang/Projects/FacSim/svn/branches/Lwq/src/Queue.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Queue$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Queue$(DependSuffix): src/Queue.cpp
	@test -d ./Debug || mkdir -p ./Debug
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/Queue$(ObjectSuffix) -MF$(IntermediateDirectory)/Queue$(DependSuffix) -MM "/home/WANGMengChang/Projects/FacSim/svn/branches/Lwq/src/Queue.cpp"

$(IntermediateDirectory)/Part$(ObjectSuffix): src/Part.cpp $(IntermediateDirectory)/Part$(DependSuffix)
	@test -d ./Debug || mkdir -p ./Debug
	$(CompilerName) $(SourceSwitch) "/home/WANGMengChang/Projects/FacSim/svn/branches/Lwq/src/Part.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Part$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Part$(DependSuffix): src/Part.cpp
	@test -d ./Debug || mkdir -p ./Debug
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/Part$(ObjectSuffix) -MF$(IntermediateDirectory)/Part$(DependSuffix) -MM "/home/WANGMengChang/Projects/FacSim/svn/branches/Lwq/src/Part.cpp"

$(IntermediateDirectory)/lwqstage$(ObjectSuffix): lwqstage.cpp $(IntermediateDirectory)/lwqstage$(DependSuffix)
	@test -d ./Debug || mkdir -p ./Debug
	$(CompilerName) $(SourceSwitch) "/home/WANGMengChang/Projects/FacSim/svn/branches/Lwq/lwqstage.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/lwqstage$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lwqstage$(DependSuffix): lwqstage.cpp
	@test -d ./Debug || mkdir -p ./Debug
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/lwqstage$(ObjectSuffix) -MF$(IntermediateDirectory)/lwqstage$(DependSuffix) -MM "/home/WANGMengChang/Projects/FacSim/svn/branches/Lwq/lwqstage.cpp"

$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	@test -d ./Debug || mkdir -p ./Debug
	$(CompilerName) $(SourceSwitch) "/home/WANGMengChang/Projects/FacSim/svn/branches/Lwq/main.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@test -d ./Debug || mkdir -p ./Debug
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "/home/WANGMengChang/Projects/FacSim/svn/branches/Lwq/main.cpp"

##
## Clean
##
clean:
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
	$(RM) $(IntermediateDirectory)/lwqstage$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/lwqstage$(DependSuffix)
	$(RM) $(IntermediateDirectory)/lwqstage$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(OutputFile)

-include $(IntermediateDirectory)/*$(DependSuffix)


