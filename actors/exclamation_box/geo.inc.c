// 0x0F000694
const GeoLayout exclamation_box_geo[] = {
   GEO_CULLING_RADIUS(300),
   GEO_OPEN_NODE(),
      GEO_SHADOW(SHADOW_SQUARE_PERMANENT, 0xB4, 70),
      GEO_OPEN_NODE(),
	     #ifdef PURPLE_EXCLAMATION_BLOCK
         GEO_SWITCH_CASE(5, geo_switch_anim_state),
		 #else 
		 GEO_SWITCH_CASE(4, geo_switch_anim_state),
	     #endif
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, exclamation_box_seg8_dl_08019318),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, exclamation_box_seg8_dl_08019378),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, exclamation_box_seg8_dl_080193D8),
			#ifdef PURPLE_EXCLAMATION_BLOCK
			GEO_DISPLAY_LIST(LAYER_OPAQUE, exclamation_box_seg8_dl_purple), //PURPLE
			#endif
            GEO_DISPLAY_LIST(LAYER_OPAQUE, exclamation_box_seg8_dl_08019438),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
