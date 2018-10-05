TOP_DIR		:= $(PWD)
ECHO_DIR	:= $(TOP_DIR)/FLEX_ECHO
CALC_DIR	:= $(TOP_DIR)/NUM_CALC
SYM_DIR		:= $(TOP_DIR)/SYM_CALC

all:	
	make -C $(CALC_DIR)
	make -C $(ECHO_DIR)
	make -C $(SYM_DIR)
	cp $(ECHO_DIR)/echo $(TOP_DIR)/echo
	cp $(CALC_DIR)/calc $(TOP_DIR)/calc
	cp $(SYM_DIR)/calc $(TOP_DIR)/sym

clean:
	make -C $(CALC_DIR) clean
	make -C $(ECHO_DIR) clean
	make -C $(SYM_DIR) clean
