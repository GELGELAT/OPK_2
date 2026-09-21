# ========================================
# ПУТИ
# ========================================
CC = gcc
BUILD_DIR = build
SRC_DIRS = C_rand_work_lib #<------------- folders with .c files
TARGET = C_rand_work_lib.exe #<------------- program name

# ========================================
# ПОИСК .c ФАЙЛОВ
# ========================================
SRCS = $(shell find $(SRC_DIRS) -name "*.c" -not -path "./$(BUILD_DIR)/*" | sed 's/^\.\///')

# ========================================
# ОБЪЕКТНЫЕ ФАЙЛЫ
# ========================================
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

# ========================================
# ПУТИ К .h
# ========================================
INC_DIRS = $(shell find $(SRC_DIRS) -name "*.h" -not -path "./$(BUILD_DIR)/*" -exec dirname {} \; | sort -u)
INCLUDES = $(addprefix -I, $(INC_DIRS))

# ========================================
# ФЛАГИ
# ========================================
CFLAGS = -g -O0 -pipe -Wall $(INCLUDES) -MMD -MP
LDFLAGS = -lopengl32 -lgdi32 -lwinmm -mconsole

# ========================================
# ПАРАЛЛЕЛЬНАЯ СБОРКА
# ========================================
MAKEFLAGS += -j$(NUMBER_OF_PROCESSORS)

# ========================================
# ВАЖНО: говорим make где искать .c файлы
# ========================================
vpath %.c $(SRC_DIRS)

# ========================================
# ЦЕЛИ
# ========================================
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# ПРАВИЛО ДЛЯ ОБЪЕКТНЫХ ФАЙЛОВ (БЕЗ ЯВНЫХ ЗАВИСИМОСТЕЙ!)
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# ПРАВИЛО ДЛЯ СОЗДАНИЯ ПАПКИ BUILD (ОТДЕЛЬНО)
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEPS)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run