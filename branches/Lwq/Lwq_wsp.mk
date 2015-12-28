.PHONY: clean All

All:
	@echo ----------Building project:[ Lwq - Debug ]----------
	@"$(MAKE)" -f "Lwq.mk" 
clean:
	@echo ----------Cleaning project:[ Lwq - Debug ]----------
	@"$(MAKE)" -f "Lwq.mk" clean
