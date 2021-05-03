.PHONY: clean All

All:
	@echo "----------Building project:[ 8_StatementsOperators - Debug ]----------"
	@cd "StatementsOperators_S8" && "$(MAKE)" -f  "8_StatementsOperators.mk"
clean:
	@echo "----------Cleaning project:[ 8_StatementsOperators - Debug ]----------"
	@cd "StatementsOperators_S8" && "$(MAKE)" -f  "8_StatementsOperators.mk" clean
