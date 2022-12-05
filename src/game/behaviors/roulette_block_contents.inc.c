#ifdef PURPLE_EXCLAMATION_BLOCK
void bhv_roulette_block_contents(void) {
	u8 randomnumber = random_u16();
	switch (randomnumber) {
		case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: 
				spawn_object (o, MODEL_KOOPA_SHELL, bhvKoopaShell);
				obj_mark_for_deletion(o);
			break;
		case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20: 
				spawn_object (o, MODEL_YELLOW_COIN, bhvSingleCoinGetsSpawned);
				obj_mark_for_deletion(o);
			break;
		case 21: case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30: 
				spawn_object (o, MODEL_NONE, bhvThreeCoinsSpawn);
				obj_mark_for_deletion(o);
			break;
		case 31: case 32: case 33: case 34: case 35: case 36: case 37: case 38: case 39: case 40:
				spawn_object (o, MODEL_NONE, bhvTenCoinsSpawn);
				obj_mark_for_deletion(o);
			break;
		case 41: case 42: case 43: case 44: case 45: case 46: case 47: case 48: case 49: case 50:
				spawn_object (o, MODEL_1UP, bhvHidden1upInPole);
				obj_mark_for_deletion(o);
			break;
		case 51: case 52: case 53: case 54: case 55: case 56: case 57: case 58: case 59: case 60:
				spawn_object (o, MODEL_1UP, bhv1upRunningAway);
				obj_mark_for_deletion(o);
			break;
		case 61: case 62: case 63: case 64: case 65: case 66: case 67: case 68: case 69: case 70:
				spawn_object (o, MODEL_GOOMBA, bhvGoomba);
				obj_mark_for_deletion(o);
			break;
		case 71: case 72: case 73: case 74: case 75: case 76: case 77: case 78: case 79: case 80:
				spawn_object (o, MODEL_BLACK_BOBOMB, bhvBobomb);
				obj_mark_for_deletion(o);
			break;
		case 81: case 82: case 83: case 84: case 85: case 86: case 87: case 88: case 89: case 90:
				spawn_object (o, MODEL_CHUCKYA, bhvChuckya);
				obj_mark_for_deletion(o);
			break;
		case 91: case 92: case 93: case 94: case 95: case 96: case 97: case 98: case 99: case 100:
				spawn_object (o, MODEL_FLYGUY, bhvFlyGuy);
				obj_mark_for_deletion(o);
			break;
		case 101: case 102: case 103: case 104: case 105: case 106: case 107: case 108: case 109: case 110:
				spawn_object (o, MODEL_BLUE_COIN, bhvMovingBlueCoin);
				obj_mark_for_deletion(o);
			break;
		case 111: case 112: case 113: case 114: case 115: case 116: case 117: case 118: case 119: case 120:
				cur_obj_play_sound_1(SOUND_MENU_BOWSER_LAUGH); //Makes Mario Lose 3 Health
				gMarioState->health-=0x330;
				obj_mark_for_deletion(o);
			break;
		case 121: case 122: case 123: case 124: case 125: case 126: case 127: case 128: case 129: case 130:
		        cur_obj_play_sound_1(SOUND_MENU_CAMERA_BUZZ);
				obj_mark_for_deletion(o); //NOTHING
			break;
		case 131: case 132: case 133: case 134: case 135: case 136: case 137: case 138: case 139: case 140:
				spawn_object (o, MODEL_RED_FLAME, bhvFlameLargeBurningOut);
				obj_mark_for_deletion(o);
			break;
		case 141: case 142: case 143: case 144: case 145: case 146: case 147: case 148: case 149: case 150:
				spawn_object (o, MODEL_BLUE_FLAME, bhvFlameLargeBurningOut);
				obj_mark_for_deletion(o);
			break;
		case 151: case 152: case 153: case 154: case 155: case 156: case 157: case 158: case 159: case 160:
				spawn_object (o, MODEL_NONE, bhvGoombaTripletSpawner);
				obj_mark_for_deletion(o);
			break;
		case 161: case 162: case 163: case 164: case 165: case 166: case 167: case 168: case 169: case 170:
				spawn_object (o, MODEL_AMP, bhvCirclingAmp);
				obj_mark_for_deletion(o);
			break;
		case 171: case 172: case 173: case 174: case 175: case 176: case 177: case 178: case 179: case 180:
				spawn_object (o, MODEL_AMP, bhvHomingAmp);
				obj_mark_for_deletion(o);
			break;
		case 181: case 182: case 183: case 184: case 185: case 186: case 187: case 188: case 189: case 190:
				cur_obj_play_sound_1(SOUND_MENU_BOWSER_LAUGH); //Makes Mario Lose 2 Health
				gMarioState->health-=0x220;
				obj_mark_for_deletion(o);
			break;
		case 191: case 192: case 193: case 194: case 195: case 196: case 197: case 198: case 199: case 200:
				spawn_object (o, MODEL_BREAKABLE_BOX, bhvBreakableBoxSmall);
				obj_mark_for_deletion(o);
			break;
		case 201: case 202: case 203: case 204: case 205: case 206: case 207: case 208: case 209: case 210:
				spawn_object (o, MODEL_BUTTERFLY, bhvTripletButterfly);
				obj_mark_for_deletion(o);
			break;
		case 211: case 212: case 213: case 214: case 215: case 216: case 217: case 218: case 219: case 220:
				spawn_object (o, MODEL_HEART, bhvRecoveryHeart);
				obj_mark_for_deletion(o);
			break;
		case 221: case 222: case 223: case 224: case 225: case 226: case 227: case 228: case 229: case 230:
				spawn_object (o, MODEL_BUTTERFLY, bhvButterfly);
				obj_mark_for_deletion(o);
			break;
		case 231: case 232: case 233: case 234: case 235: case 236: case 237: case 238: case 239: case 240:
				cur_obj_play_sound_1(SOUND_MENU_STAR_SOUND);
				spawn_object (o, MODEL_NONE, bhvMario); //Increases Mario's Speed
				obj_mark_for_deletion(o);
			break;
		case 241: case 242: case 243: case 244: case 245: case 246: case 247: case 248: case 249: case 250:
				cur_obj_play_sound_1(SOUND_MENU_BOWSER_LAUGH); //Makes Mario Lose 1 Health
				gMarioState->health-=0x110;
				obj_mark_for_deletion(o);
			break;
		case 251: case 252: case 253: case 254: case 255: case 0:
				cur_obj_play_sound_1(SOUND_MENU_STAR_SOUND);
				gMarioState->health+=0x880; //Restores Mario's Health Fully
				obj_mark_for_deletion(o);
			break;
	}
}

#endif