.PHONY: clean All

All:
	@echo "----------Building project:[ 9_ControllingProgramFlow - Debug ]----------"
	@cd "9_ControllingProgramFlow" && "$(MAKE)" -f  "9_ControllingProgramFlow.mk"
clean:
	@echo "----------Cleaning project:[ 9_ControllingProgramFlow - Debug ]----------"
	@cd "9_ControllingProgramFlow" && "$(MAKE)" -f  "9_ControllingProgramFlow.mk" clean
