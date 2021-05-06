.PHONY: clean All

All:
	@echo "----------Building project:[ 11_Functions - Debug ]----------"
	@cd "11_Functions" && "$(MAKE)" -f  "11_Functions.mk"
clean:
	@echo "----------Cleaning project:[ 11_Functions - Debug ]----------"
	@cd "11_Functions" && "$(MAKE)" -f  "11_Functions.mk" clean
