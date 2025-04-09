.PHONY: template

template:
	@if [ -z "$(file)" ]; then \
		echo "Usage: make template file=<filepath>"; \
		exit 1; \
	fi
	@cp template.cpp $(file)
	@echo "Template file created at: $(file)"