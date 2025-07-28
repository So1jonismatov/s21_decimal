# ----------------- #
#  CONFIGURATION    #
# ----------------- #

# Compiler to use
CC = gcc

# Compiler flags: C11 standard, all warnings, treat warnings as errors
CFLAGS = -std=c11 -Wall -Werror -Wextra

# Flags for generating coverage reports
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

# Name of the static library we are creating
LIB_NAME = s21_decimal.a

# Name of the test executable
TEST_RUNNER_NAME = test_runner

# Libraries needed for the test runner (check and math)
CHECK_LIBS = -lcheck -lm -lsubunit

# ----------------- #
#    SOURCE FILES   #
# ----------------- #

# Manually list all your library source files here
SRCS = arithmetic/s21_add.c \
       arithmetic/s21_sub.c \
       arithmetic/s21_mul.c \
       arithmetic/s21_div.c \
       comparison/s21_is_equal.c \
       comparison/s21_is_not_equal.c \
       comparison/s21_is_less.c \
       comparison/s21_is_less_or_equal.c \
       comparison/s21_is_greater.c \
       comparison/s21_is_greater_or_equal.c \
       convertors/s21_int_to_decimal.c \
       convertors/s21_float_to_decimal.c \
       convertors/s21_decimal_to_int.c \
       convertors/s21_decimal_to_float.c \
       others/s21_truncate.c \
       others/s21_floor.c \
       others/s21_round.c \
       others/s21_negate.c \
       utils/add_abs.c \
       utils/bank_round.c \
       utils/copy_decimal.c \
       utils/divide_by_10.c \
       utils/get_bit.c \
       utils/get_exponent.c \
       utils/get_frac.c \
       utils/get_sign.c \
       utils/integer_division.c \
       utils/is_zero.c \
       utils/make_same_exponent.c \
       utils/multiply_by_10.c \
       utils/remove_char.c \
       utils/s21_ceil.c \
       utils/set_bit.c \
       utils/set_exponent.c \
       utils/set_sign.c \
       utils/shift_left.c \
       utils/sub_abs.c \
       utils/unset_sign.c

# Manually list all your test source files here
TEST_SRCS = tests/test.c \
            tests/test_s21_add.c \
            tests/test_s21_sub.c \
            tests/test_s21_mul.c \
            tests/test_s21_div.c \
            tests/test_s21_equal.c \
            tests/test_s21_not_equal.c \
            tests/test_s21_less.c \
            tests/test_s21_less_or_equal.c \
            tests/test_s21_greater.c \
            tests/test_s21_greater_or_equal.c \
            tests/test_s21_int_to_decimal.c \
            tests/test_s21_float_to_decimal.c \
            tests/test_s21_decimal_to_int.c \
            tests/test_s21_decimal_to_float.c \
            tests/test_s21_truncate.c \
            tests/test_s21_floor.c \
            tests/test_s21_round.c \
            tests/test_s21_negate.c

# This line automatically generates the list of object files (e.g., s21_add.o)
# from the list of source files. It's a standard and very useful Make trick.
OBJS = $(SRCS:.c=.o)

# ----------------- #
#      TARGETS      #
# ----------------- #

# The '.PHONY' target tells Make that these are command names, not file names.
.PHONY: all clean test s21_decimal.a gcov_report

# The 'all' target is the default. It builds the library.
all: s21_decimal.a

# The 's21_decimal.a' target builds the static library file.
# It depends on all the object files.
s21_decimal.a: $(OBJS)
	ar rcs $(LIB_NAME) $(OBJS)
	@echo "Library $(LIB_NAME) created successfully."

# This is a pattern rule that tells Make how to create a .o file from a .c file.
# $< is the source file (e.g., s21_add.c)
# $@ is the target file (e.g., s21_add.o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# The 'test' target builds and runs the unit tests.
test: s21_decimal.a
	$(CC) $(CFLAGS) $(TEST_SRCS) $(LIB_NAME) -o $(TEST_RUNNER_NAME) $(CHECK_LIBS)
	@echo "Running tests..."
	./$(TEST_RUNNER_NAME)

# The 'gcov_report' target builds the tests with coverage flags and generates an HTML report.
gcov_report:
	# 1. Compile all source and test files with coverage flags
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(SRCS) $(TEST_SRCS) -o $(TEST_RUNNER_NAME) $(CHECK_LIBS)
	# 2. Run the tests to generate coverage data files (.gcda)
	./$(TEST_RUNNER_NAME)
	# 3. Generate the HTML report using lcov and genhtml
	lcov -t "gcov_report" -o gcov_report.info -c -d .
	genhtml -o gcov_report gcov_report.info
	@echo "Gcov report generated in the 'gcov_report' directory."
	@echo "To view it, open gcov_report/index.html in your browser."

# The 'clean' target removes all generated files.
clean:
	rm -f $(OBJS)
	rm -f $(LIB_NAME)
	rm -f $(TEST_RUNNER_NAME)
	rm -f *.gcno *.gcda *.info
	rm -rf gcov_report
	@echo "Cleanup complete."
