.PHONY: clean All

All:
	@echo "----------Building project:[ 13_OOP - Debug ]----------"
	@cd "13_OOP" && "$(MAKE)" -f  "13_OOP.mk"
clean:
	@echo "----------Cleaning project:[ 13_OOP - Debug ]----------"
	@cd "13_OOP" && "$(MAKE)" -f  "13_OOP.mk" clean
