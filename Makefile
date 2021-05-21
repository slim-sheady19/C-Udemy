.PHONY: clean All

All:
	@echo "----------Building project:[ 14_Challenge - Debug ]----------"
	@cd "14_Challenge" && "$(MAKE)" -f  "14_Challenge.mk"
clean:
	@echo "----------Cleaning project:[ 14_Challenge - Debug ]----------"
	@cd "14_Challenge" && "$(MAKE)" -f  "14_Challenge.mk" clean
