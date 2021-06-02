.PHONY: clean All

All:
	@echo "----------Building project:[ 15_Challenge - Debug ]----------"
	@cd "15_Challenge" && "$(MAKE)" -f  "15_Challenge.mk"
clean:
	@echo "----------Cleaning project:[ 15_Challenge - Debug ]----------"
	@cd "15_Challenge" && "$(MAKE)" -f  "15_Challenge.mk" clean
