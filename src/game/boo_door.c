#include "sm64.h"
#include "types.h"
#include "mario.h"
#include "mario_step.h"
#include "area.h"
#include "interaction.h"
#include "mario_actions_object.h"
#include "behavior_data.h"
#include "object_helpers.h"
#include "sm64.h"
#include "helper_macros.h"
#include "mario_actions_cutscene.h"
#include "engine/math_util.h"
#include "memory.h"
#include "level_update.h"
#include "object_list_processor.h"
#include "rendering_graph_node.h"
#include "spawn_object.h"
#include "spawn_sound.h"
#include "engine/surface_collision.h"
#include "engine/geo_layout.h"
#include "ingame_menu.h"
#include "game_init.h"
#include "obj_behaviors.h"
#include "level_table.h"
#include "dialog_ids.h"
#include "print.h"

u8 doorlocker= 0;
u8 keytimer= 0;
u8 timerenabler= 0;
u8 boodoorenabler = 0;


void process_boo_door_interaction(void) {
	f32 distToDoor = 1000.0f;
    struct Object *BooDoor;
	BooDoor = cur_obj_find_nearest_object_with_behavior (bhvBooDoor, &distToDoor);
	//print_text_fmt_int(195, 100, "%d", timerenabler);
	//print_text_fmt_int(220, 100, "%d", keytimer);
	//print_text_fmt_int(75, 75, "%d", cur_obj_dist_to_nearest_object_with_behavior(bhvBooDoor));
	//print_text_fmt_int(220, 50, "%d", doorlocker);
	
	if (cur_obj_dist_to_nearest_object_with_behavior(bhvBooDoor) > 0.0f && cur_obj_dist_to_nearest_object_with_behavior(bhvBooDoor) < 15000 ) {
		boodoorenabler=1;
	} else {
		boodoorenabler=0;
	}
	
	if (boodoorenabler==1) {
		if (cur_obj_dist_to_nearest_object_with_behavior(bhvBooDoor) < 300.0f) {
			if (gMarioState->numKeys == 0) {
				doorlocker = 1;
				if ((gMarioState->action & ACT_FLAG_RIDING_SHELL || gMarioState->action & ACT_FLAG_AIR || gMarioState->action & ACT_FLAG_INTANGIBLE ||
								gMarioState->action & ACT_FLAG_ATTACKING )) {
					doorlocker = 0;
				} else {
					gMarioState->action=ACT_IDLE;
				}
			} else if (gMarioState->numKeys > 0){
				doorlocker = 0;
			}
			if ((doorlocker==0 && gMarioState->action== ACT_PULLING_DOOR || gMarioState->action== ACT_PUSHING_DOOR))
			timerenabler = 1;
		}
	}
	
	if (timerenabler==1 && keytimer < 55) {
		keytimer++;
	} else if (keytimer > 54) {
		timerenabler = 0;
		keytimer = 0;
		gMarioState->numKeys -= 1;
		gHudDisplay.keys -= 1;
	}
	
	if (keytimer==55 && BooDoor!= NULL) {
		obj_set_behavior(BooDoor, bhvDoor);
	}
}