.PHONY: clean All

All:
	@echo ----------Building project:[ ReSchedule - Release ]----------
	@"$(MAKE)" -f "ReSchedule.mk" 
clean:
	@echo ----------Cleaning project:[ ReSchedule - Release ]----------
	@"$(MAKE)" -f "ReSchedule.mk" clean
