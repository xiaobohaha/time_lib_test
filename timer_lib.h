#include "list.h"
#include "timer_def.h"

#define LIB_TIMER_RUN_FOREVER (0xfffffff)

typedef int *(*fun_ptr)(void *param);

typedef struct
{
	struct list_head node;
	struct list_head run_node;
	
	// configure
	int32 set_intvl_real;
	int32 set_start_real;
	int32 set_intvl;
	int32 set_start;
	uint32 set_run_times;
	
	// status
	int32 left_time;
	uint32 run_times;
	bool running;
	
	// usr info
	fun_ptr cb;
	void *param;
}lib_timer_t, *lib_timer_id;


typedef struct
{
	struct list_head timer_list;
	uint32 timer_count;
	int32 max_timer_value;
	pthread_mutex_t mutex;
}lib_timer_head_t;

