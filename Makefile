.PHONY: clean All

All:
	@echo "----------Building project:[ 17_Challenge - Debug ]----------"
	@cd "17_Challenge" && "$(MAKE)" -f  "17_Challenge.mk"
clean:
	@echo "----------Cleaning project:[ 17_Challenge - Debug ]----------"
	@cd "17_Challenge" && "$(MAKE)" -f  "17_Challenge.mk" clean
