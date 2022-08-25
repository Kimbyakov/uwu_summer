COMP=gcc
CFLAGS=-c -Wall -Wextra -Werror
SOURCES=database.c indices.c db_master_modules.c db_master_levels.c db_master_status_events.c input_functions.c shared.c modules_db.c 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=./dbms

all: create_dbms

create_dbms: $(SOURCES) db_structs.h definitions.h $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(COMP) $^ -o $@

.c.a: database.o
	ar rcs $@ $^

.c.o:
	$(COMP) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)


rebuild: clean all

stylecheck:
	cp ../materials/linters/CPPLINT.cfg .
	python3 ../materials/linters/cpplint.py --extensions=c $(SOURCES) *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem ./