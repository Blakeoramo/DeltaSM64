// red_koopa_shell.inc.c
struct ObjectHitbox sRedKoopaShellHitbox = {
    /* interactType:      */ INTERACT_RED_KOOPA_SHELL,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 150,
    /* hurtboxHeight:     */ 250,
};

void bhv_red_koopa_shell_init(void) {
    o->oGravity = 2.5f;
    o->oFriction = 1.001f;
    o->oBuoyancy = 0;
    cur_obj_scale(1.0f);
    obj_set_hitbox(o, &sRedKoopaShellHitbox);
    o->oAnimState = BREAKABLE_BOX_ANIM_STATE_CORK_BOX;
    o->activeFlags |= ACTIVE_FLAG_DESTRUCTIVE_OBJ_DONT_DESTROY;
}

void red_koopa_shell_act_move(void) {
    s16 collisionFlags = object_step();
	koopa_shell_spawn_sparkles(10.0f);
    obj_attack_collided_from_other_object(o);

    if (collisionFlags == OBJ_COL_FLAG_GROUNDED) {
        cur_obj_play_sound_2(SOUND_GENERAL_SMALL_BOX_LANDING);
    }

    if (collisionFlags & OBJ_COL_FLAG_GROUNDED) {
        if (o->oForwardVel > 0.0f) {
            cur_obj_play_sound_2(SOUND_ENV_SLIDING);
        }
    }

    if (collisionFlags & OBJ_COL_FLAG_HIT_WALL) {
		cur_obj_play_sound_2(SOUND_ACTION_BOUNCE_OFF_OBJECT);
		o->oForwardVel -= 5.0f;
		if (o->oForwardVel > 35.0f) {
			o->oBreakableBoxSmallFramesSinceReleased = o->oBreakableBoxSmallFramesSinceReleased - 120; //old 90
		}
    } else {
		if (o->oBreakableBoxSmallFramesSinceReleased > 0 && o->oFaceAngleYaw != 0) {
			o->oForwardVel = 40.0f;
		}
	}

    obj_check_floor_death(collisionFlags, sObjFloor);
}

void red_koopa_shell_released_loop(void) {

	if (o->oBreakableBoxSmallReleased == TRUE) {
		o->oBreakableBoxSmallFramesSinceReleased++;
	} else {
		o->oBreakableBoxSmallFramesSinceReleased = 0;
	}
	
	if (o->oBreakableBoxSmallFramesSinceReleased < 1) {
		o->oBreakableBoxSmallFramesSinceReleased = 0;
	}

    // Begin flashing
    if (o->oBreakableBoxSmallFramesSinceReleased > 150) {
        COND_BIT((o->oBreakableBoxSmallFramesSinceReleased & 0x1), o->header.gfx.node.flags, GRAPH_RENDER_INVISIBLE);
    }

    if (o->oBreakableBoxSmallFramesSinceReleased > 300) {
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
		obj_mark_for_deletion(o);
    }
}

void red_koopa_shell_idle_loop(void) {
	
	koopa_shell_spawn_sparkles(10.0f);
	
    switch (o->oAction) {
        case BREAKABLE_BOX_SMALL_ACT_MOVE:
			if (o->oBreakableBoxSmallReleased == TRUE) {
				red_koopa_shell_act_move();
			}
            break;

        case OBJ_ACT_LAVA_DEATH:
            obj_lava_death();
            break;

        case OBJ_ACT_DEATH_PLANE_DEATH:
            o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            break;
    }

    red_koopa_shell_released_loop();
}

void red_koopa_shell_get_dropped(void) {
    cur_obj_become_tangible();
    cur_obj_enable_rendering();
    cur_obj_get_dropped();
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    o->oHeldState = HELD_FREE;
    o->oBreakableBoxSmallReleased = FALSE;
    o->oBreakableBoxSmallFramesSinceReleased = 0;
}

void red_koopa_shell_get_thrown(void) {
    cur_obj_become_tangible();
    cur_obj_enable_rendering();
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    o->oHeldState = HELD_FREE;
    o->oForwardVel = 40.0f;
    o->oVelY = 20.0f;
    o->oBreakableBoxSmallReleased = TRUE;
    o->oBreakableBoxSmallFramesSinceReleased = 0;
    o->activeFlags &= ~ACTIVE_FLAG_DESTRUCTIVE_OBJ_DONT_DESTROY;
}

void bhv_red_koopa_shell_loop(void) {
    switch (o->oHeldState) {
        case HELD_FREE:
            red_koopa_shell_idle_loop();
            break;

        case HELD_HELD:
            cur_obj_disable_rendering();
            cur_obj_become_intangible();
            break;

        case HELD_THROWN:
            red_koopa_shell_get_thrown();
            break;

        case HELD_DROPPED:
            red_koopa_shell_get_dropped();
			o->oPosY = o->oFloorHeight;
            break;
    }
	
	if (o->oBreakableBoxSmallReleased == FALSE) {
		o->oFaceAngleYaw = 0;
		cur_obj_update_floor_height_and_get_floor();
		o->oPosY = o->oFloorHeight;
	} else {
		o->oFlags &= ~OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW;
		o->oFaceAngleYaw += 0x1000;
	}
	
	//print_text_fmt_int(5, 50, "YAW %d", o->oFaceAngleYaw);
	//print_text_fmt_int(5, 20, "RLSEFLAG %d", o->oBreakableBoxSmallReleased);

    o->oInteractStatus = INT_STATUS_NONE;
}
