#include <stdlib.h>
#include <stdio.h>
#include "include/ir_optimizer.h"

ir_t* ir_from_list(list_t* list, size_t index) {
    return ((ir_t**) list->items)[index];
}

void ir_combine_instructions(list_t** irs) {
    list_t* new_irs = init_list(sizeof(ir_t));

    for (int i = 0; i < (*irs)->size; i++) {
        ir_t* ir = ir_from_list(*irs, i);
        if (new_irs->size) {
            ir_t* last_added = ir_from_list(new_irs, new_irs->size - 1);
            switch (ir->type) {
                case IR_ADDITION:
                    if (last_added->type == IR_ADDITION) {
                        last_added->value += ir->value;
                        if (last_added->value == 0) {
                            list_pop(new_irs);
                        }
                        break;
                    }
                    list_push(new_irs, ir);
                    break;
                case IR_SET_VALUE:
                    if (last_added->type == IR_ADDITION || last_added->type == IR_SET_VALUE) {
                        last_added->type = IR_SET_VALUE;
                        last_added->value = ir->value;
                        break;
                    }
                    list_push(new_irs, ir);
                    break;
                case IR_MOVE_POINTER:
                    if (last_added->type == IR_MOVE_POINTER) {
                        last_added->value += ir->value;
                        if (last_added->value == 0) {
                            list_pop(new_irs);
                        }
                        break;
                    }
                    list_push(new_irs, ir);
                    break;
                case IR_OUTPUT:
                case IR_INPUT:
                case IR_LOOP_START:
                case IR_LOOP_END:
                    list_push(new_irs, ir);
                    break;
            }
        } else {
            list_push(new_irs, ir);
        }
    }
    free(*irs);
    *irs = new_irs;
}

void ir_replace_null_loops(list_t** irs) {
    list_t* new_irs = init_list(sizeof(ir_t));

    for (int i = 0; i < (*irs)->size; i++) {
        ir_t* ir = ir_from_list(*irs, i);
        if (new_irs->size >= 2) {
            if (ir->type == IR_LOOP_END) {
                ir_t* last = ir_from_list(new_irs, new_irs->size - 1);
                ir_t* second_last = ir_from_list(new_irs, new_irs->size - 2);

                if (last->type == IR_ADDITION && (last->value == 1 || last->value == -1) &&
                    second_last->type == IR_LOOP_START) {
                    list_pop(new_irs);
                    list_pop(new_irs);
                    ir_t* set_null = init_ir(IR_SET_VALUE);
                    set_null->value = 0;
                    list_push(new_irs, set_null);
                    continue;
                }
            }
        }
        list_push(new_irs, ir);
    }
    free(*irs);
    *irs = new_irs;
}

void print_optimization_report_stage(char* stage_name, size_t instructions) {
    printf("[OPTIMIZER]  -> %-30s %d\n", stage_name, instructions);
}

void ir_optimize(list_t** irs) {
    printf("[OPTIMIZER] Results (number of IRs):\n");
    print_optimization_report_stage("unoptimized", (*irs)->size);

    ir_combine_instructions(irs);
    print_optimization_report_stage("combined instructions", (*irs)->size);

    ir_replace_null_loops(irs);
    print_optimization_report_stage("replaced null loops", (*irs)->size);
}