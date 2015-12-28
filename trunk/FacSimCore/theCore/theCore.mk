##
## Auto Generated makefile, please do not edit
##
WXWIN:=G:\Temp\wxWidgets-2.8.9
WXCFG:=gcc_dll\mswunivu
ProjectName:=theCore

## Debug
ConfigurationName :=Debug
IntermediateDirectory :=./Debug
OutDir := $(IntermediateDirectory)
LinkerName:=g++
ArchiveTool :=ar rcus
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix :=.o
DependSuffix :=.o.d
PreprocessSuffix :=
DebugSwitch :=-gstab
IncludeSwitch :=-I
LibrarySwitch :=-l
OutputSwitch :=-o 
LibraryPathSwitch :=-L
PreprocessorSwitch :=-D
SourceSwitch :=-c 
CompilerName :=g++
OutputFile :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors :=
ObjectSwitch :=-o 
ArchiveOutputSwitch := 
PreprocessOnlySwitch :=
CmpOptions :=-g $(Preprocessors)
LinkOptions := 
IncludePath :=  "$(IncludeSwitch)." 
RcIncludePath :=
Libs :=
LibPath := 


Objects=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/MyModel$(ObjectSuffix) $(IntermediateDirectory)/simclock$(ObjectSuffix) $(IntermediateDirectory)/simevent$(ObjectSuffix) $(IntermediateDirectory)/simeventlist$(ObjectSuffix) $(IntermediateDirectory)/simmachine$(ObjectSuffix) $(IntermediateDirectory)/simmodel$(ObjectSuffix) $(IntermediateDirectory)/simobject$(ObjectSuffix) $(IntermediateDirectory)/simobjectlist$(ObjectSuffix) $(IntermediateDirectory)/simpart$(ObjectSuffix) \
	$(IntermediateDirectory)/simqueue$(ObjectSuffix) 

##
## Main Build Tragets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep  $(Objects)
	@makedir $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@makedir "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "G:/FacSimCore/theCore/main.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "G:/FacSimCore/theCore/main.cpp"

$(IntermediateDirectory)/MyModel$(ObjectSuffix): MyModel.cpp $(IntermediateDirectory)/MyModel$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "G:/FacSimCore/theCore/MyModel.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/MyModel$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyModel$(DependSuffix): MyModel.cpp
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/MyModel$(ObjectSuffix) -MF$(IntermediateDirectory)/MyModel$(DependSuffix) -MM "G:/FacSimCore/theCore/MyModel.cpp"

$(IntermediateDirectory)/simclock$(ObjectSuffix): simclock.cpp $(IntermediateDirectory)/simclock$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "G:/FacSimCore/theCore/simclock.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/simclock$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/simclock$(DependSuffix): simclock.cpp
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/simclock$(ObjectSuffix) -MF$(IntermediateDirectory)/simclock$(DependSuffix) -MM "G:/FacSimCore/theCore/simclock.cpp"

$(IntermediateDirectory)/simevent$(ObjectSuffix): simevent.cpp $(IntermediateDirectory)/simevent$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "G:/FacSimCore/theCore/simevent.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/simevent$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/simevent$(DependSuffix): simevent.cpp
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/simevent$(ObjectSuffix) -MF$(IntermediateDirectory)/simevent$(DependSuffix) -MM "G:/FacSimCore/theCore/simevent.cpp"

$(IntermediateDirectory)/simeventlist$(ObjectSuffix): simeventlist.cpp $(IntermediateDirectory)/simeventlist$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "G:/FacSimCore/theCore/simeventlist.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/simeventlist$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/simeventlist$(DependSuffix): simeventlist.cpp
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/simeventlist$(ObjectSuffix) -MF$(IntermediateDirectory)/simeventlist$(DependSuffix) -MM "G:/FacSimCore/theCore/simeventlist.cpp"

$(IntermediateDirectory)/simmachine$(ObjectSuffix): simmachine.cpp $(IntermediateDirectory)/simmachine$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "G:/FacSimCore/theCore/simmachine.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/simmachine$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/simmachine$(DependSuffix): simmachine.cpp
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/simmachine$(ObjectSuffix) -MF$(IntermediateDirectory)/simmachine$(DependSuffix) -MM "G:/FacSimCore/theCore/simmachine.cpp"

$(IntermediateDirectory)/simmodel$(ObjectSuffix): simmodel.cpp $(IntermediateDirectory)/simmodel$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "G:/FacSimCore/theCore/simmodel.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/simmodel$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/simmodel$(DependSuffix): simmodel.cpp
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/simmodel$(ObjectSuffix) -MF$(IntermediateDirectory)/simmodel$(DependSuffix) -MM "G:/FacSimCore/theCore/simmodel.cpp"

$(IntermediateDirectory)/simobject$(ObjectSuffix): simobject.cpp $(IntermediateDirectory)/simobject$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "G:/FacSimCore/theCore/simobject.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/simobject$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/simobject$(DependSuffix): simobject.cpp
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/simobject$(ObjectSuffix) -MF$(IntermediateDirectory)/simobject$(DependSuffix) -MM "G:/FacSimCore/theCore/simobject.cpp"

$(IntermediateDirectory)/simobjectlist$(ObjectSuffix): simobjectlist.cpp $(IntermediateDirectory)/simobjectlist$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "G:/FacSimCore/theCore/simobjectlist.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/simobjectlist$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/simobjectlist$(DependSuffix): simobjectlist.cpp
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/simobjectlist$(ObjectSuffix) -MF$(IntermediateDirectory)/simobjectlist$(DependSuffix) -MM "G:/FacSimCore/theCore/simobjectlist.cpp"

$(IntermediateDirectory)/simpart$(ObjectSuffix): simpart.cpp $(IntermediateDirectory)/simpart$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "G:/FacSimCore/theCore/simpart.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/simpart$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/simpart$(DependSuffix): simpart.cpp
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/simpart$(ObjectSuffix) -MF$(IntermediateDirectory)/simpart$(DependSuffix) -MM "G:/FacSimCore/theCore/simpart.cpp"

$(IntermediateDirectory)/simqueue$(ObjectSuffix): simqueue.cpp $(IntermediateDirectory)/simqueue$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "G:/FacSimCore/theCore/simqueue.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/simqueue$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/simqueue$(DependSuffix): simqueue.cpp
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/simqueue$(ObjectSuffix) -MF$(IntermediateDirectory)/simqueue$(DependSuffix) -MM "G:/FacSimCore/theCore/simqueue.cpp"

##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/MyModel$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/MyModel$(DependSuffix)
	$(RM) $(IntermediateDirectory)/MyModel$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/simclock$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/simclock$(DependSuffix)
	$(RM) $(IntermediateDirectory)/simclock$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/simevent$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/simevent$(DependSuffix)
	$(RM) $(IntermediateDirectory)/simevent$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/simeventlist$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/simeventlist$(DependSuffix)
	$(RM) $(IntermediateDirectory)/simeventlist$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/simmachine$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/simmachine$(DependSuffix)
	$(RM) $(IntermediateDirectory)/simmachine$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/simmodel$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/simmodel$(DependSuffix)
	$(RM) $(IntermediateDirectory)/simmodel$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/simobject$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/simobject$(DependSuffix)
	$(RM) $(IntermediateDirectory)/simobject$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/simobjectlist$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/simobjectlist$(DependSuffix)
	$(RM) $(IntermediateDirectory)/simobjectlist$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/simpart$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/simpart$(DependSuffix)
	$(RM) $(IntermediateDirectory)/simpart$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/simqueue$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/simqueue$(DependSuffix)
	$(RM) $(IntermediateDirectory)/simqueue$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe

-include $(IntermediateDirectory)/*$(DependSuffix)


