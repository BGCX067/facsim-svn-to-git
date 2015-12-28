.PHONY: clean All

All:
	@echo ----------Building project:[ theCore - Debug ]----------
	@cd "theCore" && "mingw32-make.exe"  -j 2 -f "theCore.mk" 
clean:
	@echo ----------Cleaning project:[ theCore - Debug ]----------
	@cd "theCore" && "mingw32-make.exe"  -j 2 -f "theCore.mk" clean
