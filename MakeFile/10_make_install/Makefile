TARGET:=10_main_is
OBJ:=$(TARGET).o
TARGET_PATH:=$(PWD)/tmp/
BIN:=/usr/local/bin/

START_SH:=$(TARGET)_START
STOP_SH:=$(TARGET)_STOP
LOG:=$(TARGET).log

CC=g++

$(TARGET):$(OBJ)


install:$(TARGET)
	if[ -d $(PATH) ];\
 		then echo $(TARGET_PATH) exist;\
 	else\
 	 	mkdir $(TARGET_PATH);\
 		cp $(TARGET) $(TARGET_PATH);\
 		# 加软链，全局可执行\
        ln -sv $(TARGET_PATH)$(TARGET) $(BIN);\
        touch $(TARGET_PATH)$(LOG);\
        chmod a+rwx $(TARGET_PATH)$(LOG);\
		echo "$(TARGET)>$(TARGET_PATH)$(LOG) & echo $(TARGET) is running....">$(TARGET_PATH)$(START_SH);\
		echo "killall $(TARGET)">$(TARGET_PATH)$(STOP_SH);\
		chmod a+x $(TARGET_PATH)$(START_SH);\
		chmod a+x $(TARGET_PATH)$(STOP_SH);\
		ln -sv $(TARGET_PATH)$(START_SH) $(BIN);\
		ln -sv $(TARGET_PATH)$(STOP_SH) $(BIN);\
 	fi


clean:
	$(RM) -f $(TARGET) $(OBJ) $(BIN)$(TARGET) $(BIN)$(START_SH) $(BIN)$(STOP_SH)
	$(RM) -rf $(TARGET_PATH)



.PYOHY:clean install