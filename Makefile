.PHONY: clean All

All:
	@echo "----------Building project:[ 10_CharactersStrings - Debug ]----------"
	@cd "10_CharactersStrings" && "$(MAKE)" -f  "10_CharactersStrings.mk"
clean:
	@echo "----------Cleaning project:[ 10_CharactersStrings - Debug ]----------"
	@cd "10_CharactersStrings" && "$(MAKE)" -f  "10_CharactersStrings.mk" clean
