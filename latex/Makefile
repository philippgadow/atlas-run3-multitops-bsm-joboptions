
# Set the target file
TARGET = presentation.pdf

# Set the source file
SOURCE = presentation.tex

# Default target
all: $(TARGET)

# Rule to build the target file
$(TARGET): $(SOURCE)
	python create_beamer.py
	pdflatex $(SOURCE)
	rm *.aux *.log *.nav *.out *.snm *.toc

# Rule to clean up generated files
clean:
	rm -f $(TARGET) *.aux *.log *.nav *.out *.snm *.toc

.PHONY: all clean
