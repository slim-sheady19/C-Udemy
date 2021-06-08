.PHONY: clean All

All:
	@echo "----------Building project:[ 16_Challenge - Debug ]----------"
	@cd "16_Challenge" && "$(MAKE)" -f  "16_Challenge.mk"
clean:
	@echo "----------Cleaning project:[ 16_Challenge - Debug ]----------"
	@cd "16_Challenge" && "$(MAKE)" -f  "16_Challenge.mk" clean
