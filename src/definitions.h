#ifndef SRC_DEFINITIONS_H_
#define SRC_DEFINITIONS_H_

#define MODULES_TABLE 1
#define LEVELS_TABLE 2
#define STATUS_EVENTS_TABLE 3

#define RUNNING 0
#define OFF 1
#define ERROR 2

#define INSTRUCTION_MESSAGE "Please choose one operation:\n"\
                            "\t1. SELECT\n"\
                            "\t2. INSERT\n"\
                            "\t3. UPDATE\n"\
                            "\t4. DELETE\n"\
                            "\t5. SELECT ALL\n"\
                            "\t6. Get all active additional modules\n"\
                            "\t7. Get all modules at certain memory level\n"\
                            "\t8. Set protected mode for module by id\n"\
                            "\t9. Move module by id to specified memory "\
                            "level and cell\n"\
                            "\t10. Set protection flag of the specified"\
                            " memory level and cell\n"\
                            "\t11. Save the world!\n"\
                            "\t0. Exit the program\n> "

#define TABLE_CHOOSE_MESSAGE "Please choose a table:\n"\
                             "\t1. Modules\n"\
                             "\t2. Levels\n"\
                             "\t3. Status events\n> "


#endif  // SRC_DEFINITIONS_H_
