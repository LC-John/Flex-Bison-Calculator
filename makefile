TOP_DIR		:= $(PWD)
ECHO_DIR	:= $(TOP_DIR)/FLEX_ECHO
CALC_DIR	:= $(TOP_DIR)/NUM_CALC

all:	
	make -C $(CALC_DIR)
	make -C $(ECHO_DIR)
	cp $(ECHO_DIR)/echo $(TOP_DIR)/echo
	cp $(CALC_DIR)/calc $(TOP_DIR)/calc

clean:
	make -C $(CALC_DIR) clean
	make -C $(ECHO_DIR) clean
	rm -rf $(TOP_DIR)/echo
	rm -rf $(TOP_DIR)/calc
